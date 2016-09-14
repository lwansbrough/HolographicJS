#pragma once

using namespace Platform;

namespace HolographicJS
{
	public ref class WebGLActiveInfo sealed
	{
	public:
		WebGLActiveInfo();
		WebGLActiveInfo(GLenum type, String^ name, GLint size);

		property GLint size;
		property GLenum type;
		property String^ name;
	};
}
