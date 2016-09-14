#include "pch.h"
#include "CanvasRenderingContextHolographic.h"

using namespace HolographicJS;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

CanvasRenderingContextHolographic::CanvasRenderingContextHolographic(IMapView<String^, Boolean>^ contextAttributes, HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame)
{
	this->contextAttributes = contextAttributes;
	this->holographicSpace = holographicSpace;
	this->stationaryReferenceFrame = stationaryReferenceFrame;
	CreateContext();
}

void CanvasRenderingContextHolographic::CreateContext() {
	const EGLint configAttributes[] =
	{
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_ALPHA_SIZE, 8,
		EGL_DEPTH_SIZE, 8,
		EGL_STENCIL_SIZE, 8,
		EGL_NONE
	};

	const EGLint contextAttributes[] =
	{
		EGL_CONTEXT_CLIENT_VERSION, 2,
		EGL_NONE
	};

	const EGLint surfaceAttributes[] =
	{
		// EGL_ANGLE_SURFACE_RENDER_TO_BACK_BUFFER is part of the same optimization as EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER (see above).
		// If you have compilation issues with it then please update your Visual Studio templates.
		EGL_ANGLE_SURFACE_RENDER_TO_BACK_BUFFER, EGL_TRUE,
		EGL_NONE
	};

	const EGLint defaultDisplayAttributes[] =
	{
		// These are the default display attributes, used to request ANGLE's D3D11 renderer.
		// eglInitialize will only succeed with these attributes if the hardware supports D3D11 Feature Level 10_0+.
		EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,

		// EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER is an optimization that can have large performance benefits on mobile devices.
		// Its syntax is subject to change, though. Please update your Visual Studio templates if you experience compilation issues with it.
		EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,

		// EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE is an option that enables ANGLE to automatically call 
		// the IDXGIDevice3::Trim method on behalf of the application when it gets suspended. 
		// Calling IDXGIDevice3::Trim when an application is suspended is a Windows Store application certification requirement.
		EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
		EGL_NONE,
	};

	const EGLint fl9_3DisplayAttributes[] =
	{
		// These can be used to request ANGLE's D3D11 renderer, with D3D11 Feature Level 9_3.
		// These attributes are used if the call to eglInitialize fails with the default display attributes.
		EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
		EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE, 9,
		EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE, 3,
		EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,
		EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
		EGL_NONE,
	};

	const EGLint warpDisplayAttributes[] =
	{
		// These attributes can be used to request D3D11 WARP.
		// They are used if eglInitialize fails with both the default display attributes and the 9_3 display attributes.
		EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
		EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_DEVICE_TYPE_WARP_ANGLE,
		EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,
		EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
		EGL_NONE,
	};

	EGLConfig config = NULL;

	// eglGetPlatformDisplayEXT is an alternative to eglGetDisplay. It allows us to pass in display attributes, used to configure D3D11.
	PFNEGLGETPLATFORMDISPLAYEXTPROC eglGetPlatformDisplayEXT = reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(eglGetProcAddress("eglGetPlatformDisplayEXT"));
	if (!eglGetPlatformDisplayEXT)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to get function eglGetPlatformDisplayEXT");
	}

	//
	// To initialize the display, we make three sets of calls to eglGetPlatformDisplayEXT and eglInitialize, with varying 
	// parameters passed to eglGetPlatformDisplayEXT:
	// 1) The first calls uses "defaultDisplayAttributes" as a parameter. This corresponds to D3D11 Feature Level 10_0+.
	// 2) If eglInitialize fails for step 1 (e.g. because 10_0+ isn't supported by the default GPU), then we try again 
	//    using "fl9_3DisplayAttributes". This corresponds to D3D11 Feature Level 9_3.
	// 3) If eglInitialize fails for step 2 (e.g. because 9_3+ isn't supported by the default GPU), then we try again 
	//    using "warpDisplayAttributes".  This corresponds to D3D11 Feature Level 11_0 on WARP, a D3D11 software rasterizer.
	//

	// This tries to initialize EGL to D3D11 Feature Level 10_0+. See above comment for details.
	display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, defaultDisplayAttributes);
	if (display == EGL_NO_DISPLAY)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to get EGL display");
	}

	if (eglInitialize(display, NULL, NULL) == EGL_FALSE)
	{
		// This tries to initialize EGL to D3D11 Feature Level 9_3, if 10_0+ is unavailable (e.g. on some mobile devices).
		display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, fl9_3DisplayAttributes);
		if (display == EGL_NO_DISPLAY)
		{
			throw Exception::CreateException(E_FAIL, L"Failed to get EGL display");
		}

		if (eglInitialize(display, NULL, NULL) == EGL_FALSE)
		{
			// This initializes EGL to D3D11 Feature Level 11_0 on WARP, if 9_3+ is unavailable on the default GPU.
			display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, warpDisplayAttributes);
			if (display == EGL_NO_DISPLAY)
			{
				throw Exception::CreateException(E_FAIL, L"Failed to get EGL display");
			}

			if (eglInitialize(display, NULL, NULL) == EGL_FALSE)
			{
				// If all of the calls to eglInitialize returned EGL_FALSE then an error has occurred.
				throw Exception::CreateException(E_FAIL, L"Failed to initialize EGL");
			}
		}
	}

	EGLint numConfigs = 0;
	if ((eglChooseConfig(display, configAttributes, &config, 1, &numConfigs) == EGL_FALSE) || (numConfigs == 0))
	{
		throw Exception::CreateException(E_FAIL, L"Failed to choose first EGLConfig");
	}

	// Create a PropertySet and initialize with the EGLNativeWindowType.
	PropertySet^ surfaceCreationProperties = ref new PropertySet();
	surfaceCreationProperties->Insert(ref new String(EGLNativeWindowTypeProperty), this->holographicSpace);
	if (this->stationaryReferenceFrame != nullptr)
	{
		surfaceCreationProperties->Insert(ref new String(EGLBaseCoordinateSystemProperty), this->stationaryReferenceFrame);
	}

	// You can configure the surface to render at a lower resolution and be scaled up to
	// the full window size. This scaling is often free on mobile hardware.
	//
	// One way to configure the SwapChainPanel is to specify precisely which resolution it should render at.
	// Size customRenderSurfaceSize = Size(800, 600);
	// surfaceCreationProperties->Insert(ref new String(EGLRenderSurfaceSizeProperty), PropertyValue::CreateSize(customRenderSurfaceSize));
	//
	// Another way is to tell the SwapChainPanel to render at a certain scale factor compared to its size.
	// e.g. if the SwapChainPanel is 1920x1280 then setting a factor of 0.5f will make the app render at 960x640
	// float customResolutionScale = 0.5f;
	// surfaceCreationProperties->Insert(ref new String(EGLRenderResolutionScaleProperty), PropertyValue::CreateSingle(customResolutionScale));

	surface = eglCreateWindowSurface(display, config, reinterpret_cast<IInspectable*>(surfaceCreationProperties), surfaceAttributes);
	if (surface == EGL_NO_SURFACE)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to create EGL fullscreen surface");
	}

	context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttributes);
	if (context == EGL_NO_CONTEXT)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to create EGL context");
	}

	if (eglMakeCurrent(display, surface, surface, context) == EGL_FALSE)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to make fullscreen EGLSurface current");
	}
}

void CanvasRenderingContextHolographic::ActiveTexture(GLenum texture) {
	glActiveTexture(texture);
}

void CanvasRenderingContextHolographic::AttachShader(GLuint program, GLuint shader) {
	glAttachShader(program, shader);
}

void CanvasRenderingContextHolographic::BindAttribLocation(GLuint program, GLuint index, String^ name) {
	std::wstring nameW(name->Begin());
	std::string nameA(nameW.begin(), nameW.end());
	const char* nameChars = nameA.c_str();
	glBindAttribLocation(program, index, nameChars);
}

void CanvasRenderingContextHolographic::BindBuffer(GLenum target, GLuint buffer) {
	glBindBuffer(target, buffer);
}

void CanvasRenderingContextHolographic::BindFramebuffer(GLenum target, GLuint framebuffer) {
	glBindFramebuffer(target, framebuffer);
}

void CanvasRenderingContextHolographic::BindRenderbuffer(GLenum target, GLuint renderbuffer) {
	glBindRenderbuffer(target, renderbuffer);
}

void CanvasRenderingContextHolographic::BindTexture(GLenum target, GLuint texture) {
	glBindTexture(target, texture);
}

void CanvasRenderingContextHolographic::BlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	glBlendColor(red, green, blue, alpha);
}

void CanvasRenderingContextHolographic::BlendEquation(GLenum mode) {
	glBlendEquation(mode);
}

void CanvasRenderingContextHolographic::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
	glBlendEquationSeparate(modeRGB, modeAlpha);
}

void CanvasRenderingContextHolographic::BlendFunc(GLenum sfactor, GLenum dfactor) {
	glBlendFunc(sfactor, dfactor);
}

void CanvasRenderingContextHolographic::BlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void CanvasRenderingContextHolographic::BufferData(GLenum target, GLint size, GLenum usage) {
	glBufferData(target, size, NULL, usage);
}

void CanvasRenderingContextHolographic::BufferData(GLenum target, const Array<GLfloat>^ data, GLenum usage) {
	glBufferData(target, data->Length, data->Data, usage);
}

void CanvasRenderingContextHolographic::BufferSubData(GLenum target, GLint offset, const Array<GLint>^ data) {
	glBufferSubData(target, offset, data->Length, data->Data);
}

GLenum CanvasRenderingContextHolographic::CheckFramebufferStatus(GLenum target) {
	return glCheckFramebufferStatus(target);
}

void CanvasRenderingContextHolographic::Clear(GLbitfield mask) {
	glClear(mask);
}

void CanvasRenderingContextHolographic::ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	glClearColor(red, green, blue, alpha);
}

void CanvasRenderingContextHolographic::ClearDepth(GLclampf depth) {
	glClearDepthf(depth);
}

void CanvasRenderingContextHolographic::ClearStencil(GLint s) {
	glClearStencil(s);
}

void CanvasRenderingContextHolographic::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
	glColorMask(red, green, blue, alpha);
}

void CanvasRenderingContextHolographic::CompileShader(GLuint shader) {
	glCompileShader(shader);
}

GLuint CanvasRenderingContextHolographic::CreateBuffer() {
	GLuint index;
	glGenBuffers(1, &index);
	return index;
}

GLuint CanvasRenderingContextHolographic::CreateFramebuffer() {
	GLuint index;
	glGenFramebuffers(1, &index);
	return index;
}

GLuint CanvasRenderingContextHolographic::CreateProgram() {
	return glCreateProgram();
}

GLuint CanvasRenderingContextHolographic::CreateRenderbuffer() {
	GLuint index;
	glGenRenderbuffers(1, &index);
	return index;
}

GLuint CanvasRenderingContextHolographic::CreateShader(GLenum type) {
	return glCreateShader(type);
}

GLuint CanvasRenderingContextHolographic::CreateTexture() {
	GLuint index;
	glGenTextures(1, &index);
	return index;
}

void CanvasRenderingContextHolographic::CullFace(GLenum mode) {
	glCullFace(mode);
}

void CanvasRenderingContextHolographic::DeleteBuffer(GLuint buffer) {
	glDeleteBuffers(1, &buffer);
}

void CanvasRenderingContextHolographic::DeleteFramebuffer(GLuint framebuffer) {
	glDeleteFramebuffers(1, &framebuffer);
}

void CanvasRenderingContextHolographic::DeleteProgram(GLuint program) {
	glDeleteProgram(program);
}

void CanvasRenderingContextHolographic::DeleteRenderbuffer(GLuint renderbuffer) {
	glDeleteRenderbuffers(1, &renderbuffer);
}

void CanvasRenderingContextHolographic::DeleteShader(GLuint shader) {
	glDeleteShader(shader);
}

void CanvasRenderingContextHolographic::DeleteTexture(GLuint texture) {
	glDeleteTextures(1, &texture);
}

void CanvasRenderingContextHolographic::DepthFunc(GLenum func) {
	glDepthFunc(func);
}

void CanvasRenderingContextHolographic::DepthMask(GLboolean flag) {
	glDepthMask(flag);
}

void CanvasRenderingContextHolographic::DepthRange(GLclampf zNear, GLclampf zFar) {
	glDepthRangef(zNear, zFar);
}

void CanvasRenderingContextHolographic::DetachShader(GLuint program, GLuint shader) {
	glDetachShader(program, shader);
}

void CanvasRenderingContextHolographic::Disable(GLenum cap) {
	glDisable(cap);
}

void CanvasRenderingContextHolographic::DisableVertexAttribArray(GLuint index) {
	glDisableVertexAttribArray(index);
}

void CanvasRenderingContextHolographic::DrawArrays(GLenum mode, GLint first, GLsizei count) {
	glDrawArrays(mode, first, count);
}

void CanvasRenderingContextHolographic::DrawElements(GLenum mode, GLsizei count, GLenum type, GLint offset) {
	glDrawElements(mode, count, type, BUFFER_OFFSET(offset));
}

void CanvasRenderingContextHolographic::Enable(GLenum cap) {
	glEnable(cap);
}

void CanvasRenderingContextHolographic::EnableVertexAttribArray(GLuint index) {
	glEnableVertexAttribArray(index);
}

void CanvasRenderingContextHolographic::Finish() {
	glFinish();
}

void CanvasRenderingContextHolographic::Flush() {
	glFlush();
}

void CanvasRenderingContextHolographic::FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void CanvasRenderingContextHolographic::FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

void CanvasRenderingContextHolographic::FrontFace(GLenum mode) {
	glFrontFace(mode);
}

void CanvasRenderingContextHolographic::GenerateMipmap(GLenum target) {
	glGenerateMipmap(target);
}

WebGLActiveInfo^ CanvasRenderingContextHolographic::GetActiveAttrib(GLuint program, GLuint index) {
	GLint buffsize;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &buffsize);

	GLchar *namebuffer = (GLchar *)malloc(buffsize);
	GLsizei length;
	GLint size;
	GLenum type;
	glGetActiveAttrib(program, index, buffsize, &length, &size, &type, namebuffer);

	String^ name = StringFromAscIIChars(namebuffer);

	free(namebuffer);

	return ref new WebGLActiveInfo(type, name, size);
}


WebGLActiveInfo^ CanvasRenderingContextHolographic::GetActiveUniform(GLuint program, GLuint index) {
	GLint buffsize;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &buffsize);

	GLchar *namebuffer = (GLchar *)malloc(buffsize);
	GLsizei length;
	GLint size;
	GLenum type;
	glGetActiveUniform(program, index, buffsize, &length, &size, &type, namebuffer);

	String^ name = StringFromAscIIChars(namebuffer);

	free(namebuffer);

	return ref new WebGLActiveInfo(type, name, size);
}

GLint CanvasRenderingContextHolographic::GetAttribLocation(GLuint program, String^ name) {
	std::wstring nameW(name->Begin());
	std::string nameA(nameW.begin(), nameW.end());
	const char* nameChars = nameA.c_str();
	return glGetAttribLocation(program, nameChars);
}

IVector<GLuint>^ CanvasRenderingContextHolographic::GetAttachedShaders(GLuint program) {
	GLint count;
	glGetProgramiv(program, GL_ATTACHED_SHADERS, &count);

	GLuint *list = (GLuint *)malloc(count * sizeof(GLuint));
	glGetAttachedShaders(program, count, NULL, list);

	IVector<GLuint>^ shaders = ref new Vector<GLuint>();

	for (int i = 0; i < count; i++) {
		shaders->Append(list[i]);
	}

	free(list);

	return shaders;
}

GLint CanvasRenderingContextHolographic::GetBufferParameter(GLenum target, GLenum pname) {
	GLint param;
	glGetBufferParameteriv(target, pname, &param);
	return param;
}

IMapView<String^, Boolean>^ CanvasRenderingContextHolographic::GetContextAttributes() {
	return contextAttributes;
}

GLenum CanvasRenderingContextHolographic::GetError() {
	return glGetError();
}

Object^ CanvasRenderingContextHolographic::GetExtension(String^ name) {
	return nullptr;
}

Object^ CanvasRenderingContextHolographic::GetParameter(GLenum pname) {
	Array<Boolean>^ mask;
	Array<GLfloat>^ floatData;
	Array<GLint>^ intData;
	int intbuffer[4];
	switch (pname) {
	case GL_COMPRESSED_TEXTURE_FORMATS:
		return ref new Array<GLfloat>(0);
	case GL_ALIASED_LINE_WIDTH_RANGE:
	case GL_ALIASED_POINT_SIZE_RANGE:
	case GL_DEPTH_RANGE:
		floatData = ref new Array<GLfloat>(2);
		glGetFloatv(pname, floatData->Data);
		return floatData;
	case GL_BLEND_COLOR:
	case GL_COLOR_CLEAR_VALUE:
		floatData = ref new Array<GLfloat>(4);
		glGetFloatv(pname, floatData->Data);
		return floatData;
	case GL_MAX_VIEWPORT_DIMS:
		intData = ref new Array<GLint>(2);
		glGetIntegerv(pname, intData->Data);
		return intData;
	case GL_SCISSOR_BOX:
	case GL_VIEWPORT:
		intData = ref new Array<GLint>(4);
		glGetIntegerv(pname, intData->Data);
		return intData;
	case GL_COLOR_WRITEMASK:
		mask = ref new Array<Boolean>(4);
		glGetIntegerv(pname, intbuffer);
		for (int i = 0; i < 4; i++) {
			mask[i] = (bool)intbuffer[i];
		}
		return mask;
	case GL_ARRAY_BUFFER_BINDING:
	case GL_ELEMENT_ARRAY_BUFFER_BINDING:
		glGetIntegerv(pname, intbuffer);
		return intbuffer[0];
	case GL_CURRENT_PROGRAM:
		glGetIntegerv(pname, intbuffer);
		return intbuffer[0];
	case GL_FRAMEBUFFER_BINDING:
		glGetIntegerv(pname, intbuffer);
		return intbuffer[0];
	case GL_RENDERBUFFER_BINDING:
		glGetIntegerv(pname, intbuffer);
		return intbuffer[0];
	case GL_TEXTURE_BINDING_2D:
	case GL_TEXTURE_BINDING_CUBE_MAP:
		glGetIntegerv(pname, intbuffer);
		return intbuffer[0];
	case GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS:
		return CANVAS_MAX_TEXTURE_UNITS;
	case GL_UNPACK_FLIP_Y_WEBGL:
		return unpackFlipY;
	case GL_UNPACK_PREMULTIPLY_ALPHA_WEBGL:
		return premultiplyAlpha;
	case GL_UNPACK_COLORSPACE_CONVERSION_WEBGL:
		return false;
	case GL_RENDERER:
	case GL_SHADING_LANGUAGE_VERSION:
	case GL_VENDOR:
	case GL_VERSION:
		return StringFromAscIIChars((char *)glGetString(pname));
	}
}

String^ CanvasRenderingContextHolographic::GetProgramInfoLog(GLuint program) {
	GLint size;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &size);

	GLchar *message = (GLchar *)malloc(size);

	glGetProgramInfoLog(program, size, &size, message);

	String^ messageRT = StringFromAscIIChars(message);

	free(message);

	return messageRT;
}

GLint CanvasRenderingContextHolographic::GetProgramParameter(GLuint program, GLenum pname) {
	GLint value;
	glGetProgramiv(program, pname, &value);
	return value;
}

String^ CanvasRenderingContextHolographic::GetShaderInfoLog(GLuint shader) {
	GLint size;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);

	GLchar *message = (GLchar *)malloc(size);

	glGetShaderInfoLog(shader, size, &size, message);

	String^ messageRT = StringFromAscIIChars(message);

	free(message);

	return messageRT;
}

GLint CanvasRenderingContextHolographic::GetShaderParameter(GLuint shader, GLenum pname) {
	GLint value;
	glGetShaderiv(shader, pname, &value);

	if (pname == GL_DELETE_STATUS || pname == GL_COMPILE_STATUS) {
		return value;
	}
	else { // GL_SHADER_TYPE || GL_INFO_LOG_LENGTH || GL_SHADER_SOURCE_LENGTH
		return value;
	}
}

String^ CanvasRenderingContextHolographic::GetShaderSource(GLuint shader) {
	GLint size;
	glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &size);

	GLchar *source = (GLchar *)malloc(size);
	glGetShaderSource(shader, size, &size, source);

	String^ sourceRT = StringFromAscIIChars(source);

	free(source);

	return sourceRT;
}

IVector<String^>^ CanvasRenderingContextHolographic::GetSupportedExtensions() {
	return ref new Vector<String^>();
}

GLint CanvasRenderingContextHolographic::GetUniformLocation(GLuint program, String^ name) {
	std::wstring nameW(name->Begin());
	std::string nameA(nameW.begin(), nameW.end());
	const char* nameChars = nameA.c_str();
	return glGetUniformLocation(program, nameChars);
}

Object^ CanvasRenderingContextHolographic::GetVertexAttrib(GLuint index, GLenum pname) {
	if (pname == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING) {
		GLint buffer;
		glGetVertexAttribiv(index, pname, &buffer);
		return buffer;
	}
	else if (pname == GL_CURRENT_VERTEX_ATTRIB) {
		Array<GLint>^ data = ref new Array<GLint>(4);
		glGetVertexAttribiv(index, pname, data->Data);
		return data;
	}
	else {
		GLint value;
		glGetVertexAttribiv(index, pname, &value);
		return value;
	}
}

GLint CanvasRenderingContextHolographic::GetVertexAttribOffset(GLuint index, GLenum pname) {
	GLvoid *pointer;
	glGetVertexAttribPointerv(index, pname, &pointer);
	return (GLint)pointer;
}

void CanvasRenderingContextHolographic::Hint(GLenum target, GLenum mode) {
	glHint(target, mode);
}

GLboolean CanvasRenderingContextHolographic::IsBuffer(GLuint buffer) {
	return glIsBuffer(buffer);
}

bool CanvasRenderingContextHolographic::IsContextLost() {
	return false;
}

GLboolean CanvasRenderingContextHolographic::IsEnabled(GLenum cap) {
	return glIsEnabled(cap);
}

GLboolean CanvasRenderingContextHolographic::IsFramebuffer(GLuint framebuffer) {
	return glIsFramebuffer(framebuffer);
}

GLboolean CanvasRenderingContextHolographic::IsProgram(GLuint program) {
	return glIsProgram(program);
}

GLboolean CanvasRenderingContextHolographic::IsRenderbuffer(GLuint renderbuffer) {
	return glIsRenderbuffer(renderbuffer);
}

GLboolean CanvasRenderingContextHolographic::IsShader(GLuint shader) {
	return glIsShader(shader);
}

GLboolean CanvasRenderingContextHolographic::IsTexture(GLuint texture) {
	return glIsTexture(texture);
}

void CanvasRenderingContextHolographic::LineWidth(GLfloat width) {
	glLineWidth(width);
}

void CanvasRenderingContextHolographic::LinkProgram(GLuint program) {
	glLinkProgram(program);
}

void CanvasRenderingContextHolographic::PixelStorei(GLenum pname, GLint param) {
	glPixelStorei(pname, param);
}

void CanvasRenderingContextHolographic::PolygonOffset(GLfloat factor, GLfloat units) {
	glPolygonOffset(factor, units);
}

void CanvasRenderingContextHolographic::RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	glRenderbufferStorage(target, internalformat, width, height);
}

void CanvasRenderingContextHolographic::SampleCoverage(GLclampf value, GLboolean invert) {
	glSampleCoverage(value, invert);
}

void CanvasRenderingContextHolographic::Scissor(GLint x, GLint y, GLsizei width, GLsizei height) {
	glScissor(x, y, width, height);
}

void CanvasRenderingContextHolographic::ShaderSource(GLuint shader, String^ source) {
	std::wstring sourceW(source->Begin());
	std::string sourceA(sourceW.begin(), sourceW.end());
	const char* sourceChars = sourceA.c_str();
	glShaderSource(shader, 1, &sourceChars, nullptr);
}

void CanvasRenderingContextHolographic::StencilFunc(GLenum func, GLint ref, GLuint mask) {
	glStencilFunc(func, ref, mask);
}

void CanvasRenderingContextHolographic::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
	glStencilFuncSeparate(face, func, ref, mask);
}

void CanvasRenderingContextHolographic::StencilMask(GLuint mask) {
	glStencilMask(mask);
}

void CanvasRenderingContextHolographic::StencilMaskSeparate(GLenum face, GLuint mask) {
	glStencilMaskSeparate(face, mask);
}

void CanvasRenderingContextHolographic::StencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
	glStencilOp(fail, zfail, zpass);
}

void CanvasRenderingContextHolographic::StencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) {
	glStencilOpSeparate(face, fail, zfail, zpass);
}

void CanvasRenderingContextHolographic::TexParameterf(GLenum target, GLenum pname, GLfloat param) {
	glTexParameterf(target, pname, param);
}

void CanvasRenderingContextHolographic::TexParameteri(GLenum target, GLenum pname, GLint param) {
	glTexParameteri(target, pname, param);
}

void CanvasRenderingContextHolographic::UseProgram(GLuint program) {
	glUseProgram(program);
}

void CanvasRenderingContextHolographic::ValidateProgram(GLuint program) {
	glValidateProgram(program);
}

void CanvasRenderingContextHolographic::VertexAttrib1f(GLuint indx, GLfloat x) {
	glVertexAttrib1f(indx, x);
}

void CanvasRenderingContextHolographic::VertexAttrib2f(GLuint indx, GLfloat x, GLfloat y) {
	glVertexAttrib2f(indx, x, y);
}

void CanvasRenderingContextHolographic::VertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z) {
	glVertexAttrib3f(indx, x, y, z);
}

void CanvasRenderingContextHolographic::VertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	glVertexAttrib4f(indx, x, y, z, w);
}

void CanvasRenderingContextHolographic::VertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLint offset) {
	glVertexAttribPointer(indx, size, type, normalized, stride, BUFFER_OFFSET(offset));
}

void CanvasRenderingContextHolographic::Viewport(GLint x, GLint y, GLsizei width, GLsizei height) {
	glViewport(x, y, width, height);
}

String^ CanvasRenderingContextHolographic::StringFromAscIIChars(char* chars)
{
	size_t newsize = strlen(chars) + 1;
	wchar_t * wcstring = new wchar_t[newsize];
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wcstring, newsize, chars, _TRUNCATE);
	String^ str = ref new Platform::String(wcstring);
	delete[] wcstring;
	return str;
}
