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
	members.insert({ L"log", log });
	members.insert({ L"error", log });
	members.insert({ L"info", log });
	members.insert({ L"warn", log });
	return members;
}

std::map<const wchar_t *, JsValueRef> Console::getProperties() {
	std::map<const wchar_t *, JsValueRef> properties;
	return properties;
}

JsValueRef CALLBACK Console::log(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	std::string entry;
	for (int i = 1; i < argumentCount; i++) {
		if (i > 1)
		{
			OutputDebugString(L" ");
		}

		JsValueRef stringValue;
		JsConvertValueToString(arguments[i], &stringValue);

		const wchar_t *string;
		size_t length;
		JsStringToPointer(stringValue, &string, &length);

		OutputDebugString(string);
	}
	OutputDebugString(L"\r\n");
	
	return JS_INVALID_REFERENCE;
}
