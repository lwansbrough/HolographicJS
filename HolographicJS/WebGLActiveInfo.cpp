#include "pch.h"
#include "WebGLActiveInfo.h"

using namespace HolographicJS;

WebGLActiveInfo::WebGLActiveInfo()
{
}

WebGLActiveInfo::WebGLActiveInfo(GLenum type, String^ name, GLint size) {
	this->type = type;
	this->name = name;
	this->size = size;
}
