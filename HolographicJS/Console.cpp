#include "pch.h"
#include "Console.h"
#include "Binding.h"
#include <assert.h>

Console::Console()
{
}

JsValueRef Console::prototype;

JsValueRef CALLBACK Console::constructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
{
	assert(isConstructCall);
	JsValueRef output = JS_INVALID_REFERENCE;
	Console* console = new Console();
	JsCreateExternalObject(console, nullptr, &output);
	JsSetPrototype(output, Console::prototype);
	return output;
}

std::map<const wchar_t *, JsNativeFunction> Console::getMembers() {
	std::map<const wchar_t *, JsNativeFunction> members;
	members.insert({ L"log", Console::log });
	return members;
}

std::map<const wchar_t *, JsValueRef> Console::getProperties() {
	std::map<const wchar_t *, JsValueRef> properties;
	return properties;
}

JsValueRef CALLBACK Console::log(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	OutputDebugString(Binding::valueToString(arguments[1]));
	return JS_INVALID_REFERENCE;
}
