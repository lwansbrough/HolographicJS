#include "pch.h"
#include "Engine.h"
#include "Console.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace HolographicJS;
using namespace Platform;

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

	Console^ console = ref new Console();
	Engine^ engine = this;
	window = ref new Window(this->holographicSpace, this->stationaryReferenceFrame);

	ProjectClassToGlobal(L"console", console);
	ProjectClassToGlobal(L"window", window);
	//ProjectFunctionToGlobal(L"requestAnimationFrame", JSRequestAnimationFrame);

	JsSetCurrentContext(JS_INVALID_REFERENCE);
}

String^ Engine::RunScript(String^ script) {
	JsValueRef result;

	if (script->IsEmpty()) {
		throw ref new Exception(-1, L"Unable to load script or script was empty");
	}

	if (script->IsEmpty()) {
		throw ref new Exception(-1, L"invalid script");
	}

	JsSetCurrentContext(context);

	JsErrorCode errorCode = JsRunScript(script->Data(), currentSourceContext++, L"", &result);

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

	return ref new String();
}


void Engine::ProjectClassToGlobal(String^ name, Object^ object) {
	JsValueRef globalObject;
	JsGetGlobalObject(&globalObject);

	JsPropertyIdRef objectPropertyId;
	JsGetPropertyIdFromName(name->Data(), &objectPropertyId);

	IInspectable* inspectableObject = reinterpret_cast<IInspectable*>(object);

	JsValueRef jsObject;
	if (JsInspectableToObject(inspectableObject, &jsObject) != JsNoError)
		throw ref new Exception(-1, L"Unable to project object to global space");

	JsSetProperty(globalObject, objectPropertyId, jsObject, true);

	unsigned int refCount;
	JsAddRef(inspectableObject, &refCount);
}

void Engine::ProjectFunctionToGlobal(String^ name, JsNativeFunction callback) {
	JsValueRef globalObject;
	JsGetGlobalObject(&globalObject);

	JsPropertyIdRef propertyId;
	JsGetPropertyIdFromName(name->Data(), &propertyId);

	JsValueRef function;
	JsCreateFunction(callback, nullptr, &function);

	JsSetProperty(globalObject, propertyId, function, true);
}

void Engine::ThrowException(wstring errorString) {
	JsValueRef errorValue;
	JsValueRef errorObject;

	JsPointerToString(errorString.c_str(), errorString.length(), &errorValue);
	JsCreateError(errorValue, &errorObject);
	JsSetException(errorObject);
}

// Binding
//
//JsValueRef CALLBACK JSRequestAnimationFrame(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
//	Window::RequestAnimationFrame(arguments[1]);
//}
//
//JsValueRef CALLBACK JSSetTimeout(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
//{
//	JsValueRef func = arguments[1];
//	int delay = 0;
//	JsNumberToInt(arguments[2], &delay);
//	host->taskQueue.push(new Task(func, delay, arguments[0], JS_INVALID_REFERENCE));
//	return JS_INVALID_REFERENCE;
//}
//
//// JsNativeFunction for setInterval(func, delay)
//JsValueRef CALLBACK JSSetInterval(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
//{
//	JsValueRef func = arguments[1];
//	int delay = 0;
//	JsNumberToInt(arguments[2], &delay);
//	host->taskQueue.push(new Task(func, delay, arguments[0], JS_INVALID_REFERENCE, true));
//	return JS_INVALID_REFERENCE;
//}