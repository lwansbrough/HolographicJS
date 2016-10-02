#include "pch.h"
#include "Engine.h"
#include "CanvasRenderingContextHolographic.h"
#include "Console.h"
#include "Binding.h"
#include <string>
#include <iostream>
#include <sstream>

Engine::Engine(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame) {
	this->holographicSpace = holographicSpace;
	this->stationaryReferenceFrame = stationaryReferenceFrame;

	CreateContext();
}

void Engine::CreateContext() {

	currentSourceContext = 0;

	if (JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &runtime) != JsNoError)
		throw ref new Exception(-1, L"Failed to create runtime.");

	if (JsCreateContext(runtime, &context) != JsNoError)
		throw ref new Exception(-1, L"Failed to create execution context.");

	if (JsSetCurrentContext(context) != JsNoError)
		throw ref new Exception(-1, L"Failed to set execution context.");

	if (JsSetPromiseContinuationCallback(PromiseContinuationCallback, &taskQueue) != JsNoError)
		throw ref new Exception(-1, L"Failed to set up promise continuations.");

	CanvasRenderingContextHolographic::engine = this;

	Binding::engine = this;
	Binding::bind(holographicSpace, stationaryReferenceFrame);

	Binding::projectNativeClassToGlobal(
		L"Console",
		Console::constructor,
		Console::prototype,
		Console::getMembers(),
		Console::getProperties()
	);

	Binding::projectNativeClassToGlobal(
		L"CanvasRenderingContextHolographic",
		CanvasRenderingContextHolographic::constructor,
		CanvasRenderingContextHolographic::prototype,
		CanvasRenderingContextHolographic::getMembers(),
		CanvasRenderingContextHolographic::getProperties()
	);

	JsSetCurrentContext(JS_INVALID_REFERENCE);
}

String^ Engine::runScript(const wchar_t * script) {
	JsValueRef result;

	if (wcslen(script) == 0) {
		throw ref new Exception(-1, L"Unable to load script or script was empty");
	}

	JsSetCurrentContext(context);

	JsErrorCode errorCode = JsRunScript(script, currentSourceContext++, L"", &result);

	if (errorCode != JsNoError) {
		JsValueRef exception;
		if (JsGetAndClearException(&exception) != JsNoError)
			throw ref new Exception(-1, L"failed to get and clear exception");

		JsPropertyIdRef messageName;
		if (JsGetPropertyIdFromName(L"message", &messageName) != JsNoError)
			throw ref new Exception(-1, L"failed to get error message id");

		JsValueRef messageValue;
		if (JsGetProperty(exception, messageName, &messageValue))
			throw ref new Exception(-1, L"failed to get error message");

		const wchar_t *message;
		size_t length;
		if (JsStringToPointer(messageValue, &message, &length) != JsNoError)
			throw ref new Exception(-1, L"failed to convert error message");

		return ref new String(message);
	}

	while (!taskQueue.empty()) {
		Task* task = taskQueue.front();
		taskQueue.pop();
		int currentTime = clock() / (double)(CLOCKS_PER_SEC / 1000);
		if (currentTime - task->_time > task->_delay) {
			task->invoke();
			if (task->_repeat) {
				task->_time = currentTime;
				taskQueue.push(task);
			}
			else {
				delete task;
			}
		}
		else {
			taskQueue.push(task);
		}
	}

	return ref new String();
}

// Save promises in task queue
void CALLBACK Engine::PromiseContinuationCallback(JsValueRef task, void *callbackState)
{
	JsValueRef global;
	JsGetGlobalObject(&global);
	queue<Task*> * q = (queue<Task*> *)callbackState;
	q->push(new Task(task, 0, global, JS_INVALID_REFERENCE));
}