#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>

class Console
{
public:
	Console();
	static JsValueRef CALLBACK constructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	static JsValueRef prototype;
	static std::map<const wchar_t *, JsNativeFunction> getMembers();
	static std::map<const wchar_t *, JsValueRef> getProperties();

	static JsValueRef CALLBACK log(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
};


