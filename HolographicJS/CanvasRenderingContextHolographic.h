#pragma once

using namespace Platform;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

namespace HolographicJS
{
	public ref class CanvasRenderingContextHolographic sealed
	{
	public:
		CanvasRenderingContextHolographic(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
		int GetDrawingBufferHeight();
		int GetDrawingBufferWidth();
		Object^ GetContextAttributes();
		bool IsContextLost();
		Object^ GetSupportedExtensions();
		Object^ GetExtension(String^ name);
		void ActiveTexture(GLenum texture);
		void AttachShader(GLuint program, GLuint shader);
		void BindAttribLocation(GLuint program, GLuint index, String^ name);
		void BindBuffer(GLenum target, GLuint buffer);
		void BindFramebuffer(GLenum target, GLuint framebuffer);
		void BindRenderbuffer(GLenum target, GLuint renderbuffer);
		void BindTexture(GLenum target, GLuint texture);
		void BlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
		void BlendEquation(GLenum mode);
		void BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
		void BlendFunc(GLenum sfactor, GLenum dfactor);
		void BlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
		void BufferData(GLenum target, GLsizeiptr size, GLenum usage);
		//void BufferData(GLenum target, BufferDataSource ? data, GLenum usage);
		//void BufferSubData(GLenum target, GLintptr offset, BufferDataSource ? data);
		GLenum CheckFramebufferStatus(GLenum target);
		void Clear(GLbitfield mask);
		void ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
		void ClearDepth(GLclampf depth);
		void ClearStencil(GLint s);
		void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
		void CompileShader(GLuint shader);
		//void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat,
		//	GLsizei width, GLsizei height, GLint border,
		//	ArrayBufferView data);
		//void CompressedTexSubImage2D(GLenum target, GLint level,
		//	GLint xoffset, GLint yoffset,
		//	GLsizei width, GLsizei height, GLenum format,
		//	ArrayBufferView data);
		void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
		void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
		GLuint CreateBuffer();
		GLuint CreateFramebuffer();
		GLuint CreateProgram();
		GLuint CreateRenderbuffer();
		GLuint CreateShader(GLenum type);
		GLuint CreateTexture();
		void CullFace(GLenum mode);
		void DeleteBuffer(GLuint buffer);
		void DeleteFramebuffer(GLuint framebuffer);
		void DeleteProgram(GLuint program);
		void DeleteRenderbuffer(GLuint renderbuffer);
		void DeleteShader(GLuint shader);
		void DeleteTexture(GLuint texture);
		void DepthFunc(GLenum func);
		void DepthMask(GLboolean flag);
		void DepthRange(GLclampf zNear, GLclampf zFar);
		void DetachShader(GLuint program, GLuint shader);
		void Disable(GLenum cap);
		void DisableVertexAttribArray(GLuint index);
		void DrawArrays(GLenum mode, GLint first, GLsizei count);
		void DrawElements(GLenum mode, GLsizei count, GLenum type, GLintptr offset);
		void Enable(GLenum cap);
		void EnableVertexAttribArray(GLuint index);
		void Finish();
		void Flush();
		void FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
		void FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		void FrontFace(GLenum mode);
		void GenerateMipmap(GLenum target);
		//WebGLActiveInfo ? GetActiveAttrib(GLuint program, GLuint index);
		//WebGLActiveInfo ? GetActiveUniform(GLuint program, GLuint index);
		//sequence<WebGLShader> ? getAttachedShaders(GLuint program);
		GLint GetAttribLocation(GLuint program, String^ name);
		//any GetBufferParameter(GLenum target, GLenum pname);
		//any GetParameter(GLenum pname);
		GLenum GetError();
		//any GetFramebufferAttachmentParameter(GLenum target, GLenum attachment, GLenum pname);
		//any GetProgramParameter(GLuint program, GLenum pname);
		String^ GetProgramInfoLog(GLuint program);
		//any GetRenderbufferParameter(GLenum target, GLenum pname);
		//any GetShaderParameter(GLuint shader, GLenum pname);
		//WebGLShaderPrecisionFormat ? GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype);
		String^ GetShaderInfoLog(GLuint shader);
		String^ GetShaderSource(GLuint shader);
		//any GetTexParameter(GLenum target, GLenum pname);
		//any GetUniform(GLuint program, WebGLUniformLocation ? location);
		//WebGLUniformLocation ? GetUniformLocation(GLuint program, DOMString name);
		//any GetVertexAttrib(GLuint index, GLenum pname);
		GLsizeiptr GetVertexAttribOffset(GLuint index, GLenum pname);
		void Hint(GLenum target, GLenum mode);
		GLboolean IsBuffer(GLuint buffer);
		GLboolean IsEnabled(GLenum cap);
		GLboolean IsFramebuffer(GLuint framebuffer);
		GLboolean IsProgram(GLuint program);
		GLboolean IsRenderbuffer(GLuint renderbuffer);
		GLboolean IsShader(GLuint shader);
		GLboolean IsTexture(GLuint texture);
		void LineWidth(GLfloat width);
		void LinkProgram(GLuint program);
		void PixelStorei(GLenum pname, GLint param);
		void PolygonOffset(GLfloat factor, GLfloat units);
		//void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView ? pixels);
		void RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
		void SampleCoverage(GLclampf value, GLboolean invert);
		void Scissor(GLint x, GLint y, GLsizei width, GLsizei height);
		void ShaderSource(GLuint shader, String^ source);
		void StencilFunc(GLenum func, GLint ref, GLuint mask);
		void StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
		void StencilMask(GLuint mask);
		void StencilMaskSeparate(GLenum face, GLuint mask);
		void StencilOp(GLenum fail, GLenum zfail, GLenum zpass);
		void StencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
		//void TexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, ArrayBufferView ? pixels);
		//void TexImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, TexImageSource ? source); // May throw DOMException
		void TexParameterf(GLenum target, GLenum pname, GLfloat param);
		void TexParameteri(GLenum target, GLenum pname, GLint param);
		//void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView ? pixels);
		//void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, TexImageSource ? source); // May throw DOMException
		//void Uniform1f(WebGLUniformLocation ? location, GLfloat x);
		//void Uniform1fv(WebGLUniformLocation ? location, Float32Array v);
		//void Uniform1fv(WebGLUniformLocation ? location, sequence<GLfloat> v);
		//void Uniform1i(WebGLUniformLocation ? location, GLint x);
		//void Uniform1iv(WebGLUniformLocation ? location, Int32Array v);
		//void Uniform1iv(WebGLUniformLocation ? location, sequence<long> v);
		//void Uniform2f(WebGLUniformLocation ? location, GLfloat x, GLfloat y);
		//void Uniform2fv(WebGLUniformLocation ? location, Float32Array v);
		//void Uniform2fv(WebGLUniformLocation ? location, sequence<GLfloat> v);
		//void Uniform2i(WebGLUniformLocation ? location, GLint x, GLint y);
		//void Uniform2iv(WebGLUniformLocation ? location, Int32Array v);
		//void Uniform2iv(WebGLUniformLocation ? location, sequence<long> v);
		//void Uniform3f(WebGLUniformLocation ? location, GLfloat x, GLfloat y, GLfloat z);
		//void Uniform3fv(WebGLUniformLocation ? location, Float32Array v);
		//void Uniform3fv(WebGLUniformLocation ? location, sequence<GLfloat> v);
		//void Uniform3i(WebGLUniformLocation ? location, GLint x, GLint y, GLint z);
		//void Uniform3iv(WebGLUniformLocation ? location, Int32Array v);
		//void Uniform3iv(WebGLUniformLocation ? location, sequence<long> v);
		//void Uniform4f(WebGLUniformLocation ? location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		//void Uniform4fv(WebGLUniformLocation ? location, Float32Array v);
		//void Uniform4fv(WebGLUniformLocation ? location, sequence<GLfloat> v);
		//void Uniform4i(WebGLUniformLocation ? location, GLint x, GLint y, GLint z, GLint w);
		//void Uniform4iv(WebGLUniformLocation ? location, Int32Array v);
		//void Uniform4iv(WebGLUniformLocation ? location, sequence<long> v);
		//void UniformMatrix2fv(WebGLUniformLocation ? location, GLboolean transpose, Float32Array value);
		//void UniformMatrix2fv(WebGLUniformLocation ? location, GLboolean transpose, sequence<GLfloat> value);
		//void UniformMatrix3fv(WebGLUniformLocation ? location, GLboolean transpose, Float32Array value);
		//void UniformMatrix3fv(WebGLUniformLocation ? location, GLboolean transpose, sequence<GLfloat> value);
		//void UniformMatrix4fv(WebGLUniformLocation ? location, GLboolean transpose, Float32Array value);
		//void UniformMatrix4fv(WebGLUniformLocation ? location, GLboolean transpose, sequence<GLfloat> value);
		void UseProgram(GLuint program);
		void ValidateProgram(GLuint program);
		void VertexAttrib1f(GLuint indx, GLfloat x);
		//void VertexAttrib1fv(GLuint indx, Float32Array values);
		//void VertexAttrib1fv(GLuint indx, sequence<GLfloat> values);
		void VertexAttrib2f(GLuint indx, GLfloat x, GLfloat y);
		//void VertexAttrib2fv(GLuint indx, Float32Array values);
		//void VertexAttrib2fv(GLuint indx, sequence<GLfloat> values);
		void VertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z);
		//void VertexAttrib3fv(GLuint indx, Float32Array values);
		//void vertexAttrib3fv(GLuint indx, sequence<GLfloat> values);
		void VertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		//void VertexAttrib4fv(GLuint indx, Float32Array values);
		//void VertexAttrib4fv(GLuint indx, sequence<GLfloat> values);
		void VertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
		void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);
	private:
		EGLContext context;
		EGLDisplay display;
		EGLSurface surface;
		HolographicSpace^ holographicSpace;
		SpatialStationaryFrameOfReference^ stationaryReferenceFrame;

		void CreateContext();
	};
}

