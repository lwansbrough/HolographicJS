#include "pch.h"
#include "WebGLActiveInfo.h"
#include <assert.h>

JsValueRef WebGLActiveInfo::prototype;

JsValueRef CALLBACK WebGLActiveInfo::constructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
{
	assert(isConstructCall);
	JsValueRef output = JS_INVALID_REFERENCE;
	WebGLActiveInfo* activeInfo = new WebGLActiveInfo();
	JsCreateExternalObject(activeInfo, nullptr, &output);
	JsSetPrototype(output, WebGLActiveInfo::prototype);
	return output;
}

std::map<const wchar_t *, JsNativeFunction> WebGLActiveInfo::getMembers() {
	std::map<const wchar_t *, JsNativeFunction> members;
	return members;
}

std::map<const wchar_t *, JsValueRef> WebGLActiveInfo::getProperties() {
	std::map<const wchar_t *, JsValueRef> properties;
	return properties;
}

WebGLActiveInfo::WebGLActiveInfo()
{
}

WebGLActiveInfo::WebGLActiveInfo(GLenum type, const wchar_t * name, GLint size) {
	this->type = type;
	this->name = name;
	this->size = size;
}
