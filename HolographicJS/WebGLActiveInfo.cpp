#include "pch.h"
#include "WebGLActiveInfo.h"
#include "Binding.h"
#include <assert.h>

JsValueRef WebGLActiveInfo::prototype;

JsValueRef CALLBACK WebGLActiveInfo::constructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
{
	assert(isConstructCall);
	JsValueRef output = JS_INVALID_REFERENCE;
	WebGLActiveInfo* activeInfo = new WebGLActiveInfo();
	JsCreateExternalObject(activeInfo, nullptr, &output);

	Binding::setProperty(output, L"type", Binding::intToValue(activeInfo->type));
	Binding::setProperty(output, L"name", Binding::stringToValue(activeInfo->name, wcslen(activeInfo->name)));
	Binding::setProperty(output, L"size", Binding::intToValue(activeInfo->size));

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
