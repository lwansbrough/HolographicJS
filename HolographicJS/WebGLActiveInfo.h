#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>

class WebGLActiveInfo
{
public:
	WebGLActiveInfo();
	WebGLActiveInfo(GLenum type, const wchar_t * name, GLint size);
	static JsValueRef CALLBACK constructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	static JsValueRef prototype;
	static std::map<const wchar_t *, JsNativeFunction> getMembers();
	static std::map<const wchar_t *, JsValueRef> getProperties();

	GLint size;
	GLenum type;
	const wchar_t * name;
};