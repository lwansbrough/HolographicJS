#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>
#include "WebGLActiveInfo.h"

#define GL_UNPACK_FLIP_Y_WEBGL 0x9240
#define GL_UNPACK_PREMULTIPLY_ALPHA_WEBGL 0x9241
#define GL_CONTEXT_LOST_WEBGL 0x9242
#define GL_UNPACK_COLORSPACE_CONVERSION_WEBGL 0x9243
#define GL_BROWSER_DEFAULT_WEBGL 0x9244

#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A

#define CANVAS_MAX_TEXTURE_UNITS 8
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

class CanvasRenderingContextHolographic
{
public:
	CanvasRenderingContextHolographic(IMapView<String^, Boolean>^ contextAttributes, HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
	int drawingBufferHeight;
	int drawingBufferWidth;

	static JsValueRef CALLBACK constructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	static JsValueRef prototype;
	static std::map<const wchar_t *, JsNativeFunction> getMembers();
	static std::map<const wchar_t *, JsValueRef> getProperties();

	static JsValueRef CALLBACK getContextAttributes(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	static JsValueRef CALLBACK isContextLost(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	static JsValueRef CALLBACK getSupportedExtensions(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK getExtension(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//String^ name

	static JsValueRef CALLBACK render(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//

	static JsValueRef CALLBACK activeTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	static JsValueRef CALLBACK attachShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, GLuint shader
	static JsValueRef CALLBACK bindAttribLocation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, GLuint index, String^ name
	static JsValueRef CALLBACK bindBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLuint buffer
	static JsValueRef CALLBACK bindFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLuint framebuffer
	static JsValueRef CALLBACK bindRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLuint renderbuffer
	static JsValueRef CALLBACK bindTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLuint texture
	static JsValueRef CALLBACK blendColor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha
	static JsValueRef CALLBACK blendEquation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum mode
	static JsValueRef CALLBACK blendEquationSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum modeRGB, GLenum modeAlpha
	static JsValueRef CALLBACK blendFunc(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum sfactor, GLenum dfactor
	static JsValueRef CALLBACK blendFuncSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha
	static JsValueRef CALLBACK bufferData(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint size, GLenum usage
	static JsValueRef CALLBACK bufferData(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, const Array<GLfloat>^ data, GLenum usage
	static JsValueRef CALLBACK bufferSubData(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint offset, const Array<GLint>^ data
	static JsValueRef CALLBACK checkFramebufferStatus(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target
	static JsValueRef CALLBACK clear(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLbitfield mask
	static JsValueRef CALLBACK clearColor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha
	static JsValueRef CALLBACK clearDepth(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLclampf depth
	static JsValueRef CALLBACK clearStencil(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLint s
	static JsValueRef CALLBACK colorMask(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha
	static JsValueRef CALLBACK compileShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint shader
	//void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat,
	//	GLsizei width, GLsizei height, GLint border,
	//	ArrayBufferView data);
	//void CompressedTexSubImage2D(GLenum target, GLint level,
	//	GLint xoffset, GLint yoffset,
	//	GLsizei width, GLsizei height, GLenum format,
	//	ArrayBufferView data);
	//static JsValueRef CALLBACK CopyTexImage2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border
	//static JsValueRef CALLBACK CopyTexSubImage2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height
	static JsValueRef CALLBACK createBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK createFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK createProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK createRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK createShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum type
	static JsValueRef CALLBACK createTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK cullFace(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum mode
	static JsValueRef CALLBACK deleteBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint buffer
	static JsValueRef CALLBACK deleteFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint framebuffer
	static JsValueRef CALLBACK deleteProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program
	static JsValueRef CALLBACK deleteRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint renderbuffer
	static JsValueRef CALLBACK deleteShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint shader
	static JsValueRef CALLBACK deleteTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint texture
	static JsValueRef CALLBACK depthFunc(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum func
	static JsValueRef CALLBACK depthMask(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLboolean flag
	static JsValueRef CALLBACK depthRange(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLclampf zNear, GLclampf zFar
	static JsValueRef CALLBACK detachShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, GLuint shader
	static JsValueRef CALLBACK disable(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum cap
	static JsValueRef CALLBACK disableVertexAttribArray(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint index
	static JsValueRef CALLBACK drawArrays(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum mode, GLint first, GLsizei count
	static JsValueRef CALLBACK drawElements(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum mode, GLsizei count, GLenum type, GLint offset
	static JsValueRef CALLBACK drawElementsInstancedANGLE(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum mode, GLsizei count, GLenum type, GLint offset, GLsizei primcount
	static JsValueRef CALLBACK enable(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum cap
	static JsValueRef CALLBACK enableVertexAttribArray(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint index
	static JsValueRef CALLBACK finish(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK flush(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	static JsValueRef CALLBACK framebufferRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer
	static JsValueRef CALLBACK framebufferTexture2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level
	static JsValueRef CALLBACK frontFace(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum mode
	static JsValueRef CALLBACK generateMipmap(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target
	static JsValueRef CALLBACK getActiveAttrib(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, GLuint index
	static JsValueRef CALLBACK getActiveUniform(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, GLuint index
	static JsValueRef CALLBACK getAttachedShaders(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program
	static JsValueRef CALLBACK getAttribLocation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, String^ name
	static JsValueRef CALLBACK getBufferParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLenum pname
	static JsValueRef CALLBACK getParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum pname
	static JsValueRef CALLBACK getError(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//
	//any GetFramebufferAttachmentParameter(GLenum target, GLenum attachment, GLenum pname);
	static JsValueRef CALLBACK getProgramParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, GLenum pname
	static JsValueRef CALLBACK getProgramInfoLog(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program
	//any GetRenderbufferParameter(GLenum target, GLenum pname);
	static JsValueRef CALLBACK getShaderParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint shader, GLenum pname
	//static JsValueRef CALLBACK GetShaderPrecisionFormat(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum shadertype, GLenum precisiontype
	static JsValueRef CALLBACK getShaderInfoLog(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint shader
	static JsValueRef CALLBACK getShaderSource(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint shader
	//any GetTexParameter(GLenum target, GLenum pname);
	// GetUniform(GLuint program, WebGLUniformLocation ? location);
	static JsValueRef CALLBACK getUniformLocation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program, String^ name
	static JsValueRef CALLBACK getVertexAttrib(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint index, GLenum pname
	static JsValueRef CALLBACK getVertexAttribOffset(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint index, GLenum pname
	static JsValueRef CALLBACK hint(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLenum mode
	static JsValueRef CALLBACK isBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	//GLuint buffer
	static JsValueRef CALLBACK isEnabled(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	//GLboolean IsEnabled(GLenum cap);
	static JsValueRef CALLBACK isFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	//GLboolean IsFramebuffer(GLuint framebuffer);
	static JsValueRef CALLBACK isProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	//GLboolean IsProgram(GLuint program);
	static JsValueRef CALLBACK isRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	//GLboolean IsRenderbuffer(GLuint renderbuffer);
	static JsValueRef CALLBACK isShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	//GLboolean IsShader(GLuint shader);
	static JsValueRef CALLBACK isTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	//GLboolean IsTexture(GLuint texture);
	static JsValueRef CALLBACK lineWidth(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLfloat width
	static JsValueRef CALLBACK linkProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program
	static JsValueRef CALLBACK pixelStorei(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum pname, GLint param
	static JsValueRef CALLBACK polygonOffset(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLfloat factor, GLfloat units
	//static JsValueRef CALLBACK ReadPixels(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView ? pixels
	static JsValueRef CALLBACK renderbufferStorage(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLenum internalformat, GLsizei width, GLsizei height
	static JsValueRef CALLBACK sampleCoverage(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLclampf value, GLboolean invert
	static JsValueRef CALLBACK scissor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLint x, GLint y, GLsizei width, GLsizei height
	static JsValueRef CALLBACK shaderSource(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint shader, String^ source
	static JsValueRef CALLBACK stencilFunc(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum func, GLint ref, GLuint mask
	static JsValueRef CALLBACK stencilFuncSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum face, GLenum func, GLint ref, GLuint mask
	static JsValueRef CALLBACK stencilMask(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint mask
	static JsValueRef CALLBACK stencilMaskSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum face, GLuint mask
	static JsValueRef CALLBACK stencilOp(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum fail, GLenum zfail, GLenum zpass
	static JsValueRef CALLBACK stencilOpSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum face, GLenum fail, GLenum zfail, GLenum zpass
	//static JsValueRef CALLBACK TexImage2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, ArrayBufferView ? pixels
	//static JsValueRef CALLBACK TexImage2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, TexImageSource ? source // May throw DOMException
	static JsValueRef CALLBACK texParameterf(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLenum pname, GLfloat param
	static JsValueRef CALLBACK texParameteri(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLenum pname, GLint param
	//static JsValueRef CALLBACK TexSubImage2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView ? pixels
	//static JsValueRef CALLBACK TexSubImage2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, TexImageSource ? source // May throw DOMException
	//static JsValueRef CALLBACK Uniform1f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLfloat x
	//static JsValueRef CALLBACK Uniform1fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Float32Array v
	//static JsValueRef CALLBACK Uniform1fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<GLfloat> v
	//static JsValueRef CALLBACK Uniform1i(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLint x
	//static JsValueRef CALLBACK Uniform1iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Int32Array v
	//static JsValueRef CALLBACK Uniform1iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<long> v
	//static JsValueRef CALLBACK Uniform2f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLfloat x, GLfloat y
	//static JsValueRef CALLBACK Uniform2fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Float32Array v
	//static JsValueRef CALLBACK Uniform2fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<GLfloat> v
	//static JsValueRef CALLBACK Uniform2i(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLint x, GLint y
	//static JsValueRef CALLBACK Uniform2iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Int32Array v
	//static JsValueRef CALLBACK Uniform2iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<long> v
	//static JsValueRef CALLBACK Uniform3f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLfloat x, GLfloat y, GLfloat z
	//static JsValueRef CALLBACK Uniform3fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Float32Array v
	//static JsValueRef CALLBACK Uniform3fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<GLfloat> v
	//static JsValueRef CALLBACK Uniform3i(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLint x, GLint y, GLint z
	//static JsValueRef CALLBACK Uniform3iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Int32Array v
	//static JsValueRef CALLBACK Uniform3iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<long> v
	//static JsValueRef CALLBACK Uniform4f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLfloat x, GLfloat y, GLfloat z, GLfloat w
	//static JsValueRef CALLBACK Uniform4fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Float32Array v
	//static JsValueRef CALLBACK Uniform4fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<GLfloat> v
	//static JsValueRef CALLBACK Uniform4i(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLint x, GLint y, GLint z, GLint w
	//static JsValueRef CALLBACK Uniform4iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, Int32Array v
	//static JsValueRef CALLBACK Uniform4iv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, sequence<long> v
	//static JsValueRef CALLBACK UniformMatrix2fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLboolean transpose, Float32Array value
	//static JsValueRef CALLBACK UniformMatrix2fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLboolean transpose, sequence<GLfloat> value
	//static JsValueRef CALLBACK UniformMatrix3fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLboolean transpose, Float32Array value
	//static JsValueRef CALLBACK UniformMatrix3fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLboolean transpose, sequence<GLfloat> value
	static JsValueRef CALLBACK uniformMatrix4fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLint location, GLboolean transpose, const Array<GLfloat>^ value
	//static JsValueRef CALLBACK UniformMatrix4fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//WebGLUniformLocation ? location, GLboolean transpose, sequence<GLfloat> value
	static JsValueRef CALLBACK useProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program
	static JsValueRef CALLBACK validateProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint program
	static JsValueRef CALLBACK vertexAttrib1f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint index, GLfloat x
	//static JsValueRef CALLBACK VertexAttrib1fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, Float32Array values
	//static JsValueRef CALLBACK VertexAttrib1fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, sequence<GLfloat> values
	static JsValueRef CALLBACK vertexAttrib2f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, GLfloat x, GLfloat y
	//static JsValueRef CALLBACK VertexAttrib2fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, Float32Array values
	//static JsValueRef CALLBACK VertexAttrib2fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, sequence<GLfloat> values
	static JsValueRef CALLBACK vertexAttrib3f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, GLfloat x, GLfloat y, GLfloat z
	//static JsValueRef CALLBACK VertexAttrib3fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, Float32Array values
	//static JsValueRef CALLBACK vertexAttrib3fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, sequence<GLfloat> values
	static JsValueRef CALLBACK vertexAttrib4f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w
	//static JsValueRef CALLBACK VertexAttrib4fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, Float32Array values
	//static JsValueRef CALLBACK VertexAttrib4fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, sequence<GLfloat> values
	static JsValueRef CALLBACK vertexAttribDivisorANGLE(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint index, GLuint divisor
	static JsValueRef CALLBACK vertexAttribPointer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLint offset
	static JsValueRef CALLBACK viewport(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
//GLint x, GLint y, GLsizei width, GLsizei height
private:
	EGLContext context;
	EGLDisplay display;
	EGLSurface surface;
	HolographicSpace^ holographicSpace;
	SpatialStationaryFrameOfReference^ stationaryReferenceFrame;
	IMapView<String^, Boolean>^ contextAttributes;
	bool unpackFlipY;
	bool premultiplyAlpha;

	void CreateContext();
	static const wchar_t * CanvasRenderingContextHolographic::StringFromAscIIChars(char* chars);
	static const char* AscIICharsFromString(const wchar_t * str);
};
