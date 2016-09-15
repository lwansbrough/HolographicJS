#pragma once
#include "WebGLActiveInfo.h"

#define GL_UNPACK_FLIP_Y_WEBGL 0x9240
#define GL_UNPACK_PREMULTIPLY_ALPHA_WEBGL 0x9241
#define GL_CONTEXT_LOST_WEBGL 0x9242
#define GL_UNPACK_COLORSPACE_CONVERSION_WEBGL 0x9243
#define GL_BROWSER_DEFAULT_WEBGL 0x9244

#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A

#define CANVAS_MAX_TEXTURE_UNITS 8
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

#define HJS_BIND_CONST_GL(PROP) property GLint PROP { GLint get() { return GL_##PROP; } }
#define HJS_BIND_CONST(NAME, VALUE) property GLint NAME { GLint get() { return VALUE; } }

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

namespace HolographicJS
{
	public ref class CanvasRenderingContextHolographic sealed
	{
	public:
		CanvasRenderingContextHolographic(IMapView<String^, Boolean>^ contextAttributes, HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
		property int drawingBufferHeight;
		property int drawingBufferWidth;

		// ClearBufferMask
		HJS_BIND_CONST_GL(DEPTH_BUFFER_BIT);
		HJS_BIND_CONST_GL(STENCIL_BUFFER_BIT);
		HJS_BIND_CONST_GL(COLOR_BUFFER_BIT);

		// Boolean
#pragma push_macro("FALSE")
#undef FALSE
		HJS_BIND_CONST_GL(FALSE);
#pragma pop_macro("FALSE")
#pragma push_macro("TRUE")
#undef TRUE
		HJS_BIND_CONST_GL(TRUE);
#pragma pop_macro("TRUE")

		HJS_BIND_CONST_GL(POINTS);
		HJS_BIND_CONST_GL(LINES);
		HJS_BIND_CONST_GL(LINE_LOOP);
		HJS_BIND_CONST_GL(LINE_STRIP);
		HJS_BIND_CONST_GL(TRIANGLES);
		HJS_BIND_CONST_GL(TRIANGLE_STRIP);
		HJS_BIND_CONST_GL(TRIANGLE_FAN);

		// AlphaFunction (not supported in ES20);
		// GL_NEVER
		// GL_LESS
		// GL_EQUAL
		// GL_LEQUAL
		// GL_GREATER
		// GL_NOTEQUAL
		// GL_GEQUAL
		// GL_ALWAYS

		// BlendingFactorDest
		HJS_BIND_CONST_GL(ZERO);
		HJS_BIND_CONST_GL(ONE);
		HJS_BIND_CONST_GL(SRC_COLOR);
		HJS_BIND_CONST_GL(ONE_MINUS_SRC_COLOR);
		HJS_BIND_CONST_GL(SRC_ALPHA);
		HJS_BIND_CONST_GL(ONE_MINUS_SRC_ALPHA);
		HJS_BIND_CONST_GL(DST_ALPHA);
		HJS_BIND_CONST_GL(ONE_MINUS_DST_ALPHA);

		// BlendingFactorSrc
		// GL_ZERO
		// GL_ONE
		HJS_BIND_CONST_GL(DST_COLOR);
		HJS_BIND_CONST_GL(ONE_MINUS_DST_COLOR);
		HJS_BIND_CONST_GL(SRC_ALPHA_SATURATE);
		// GL_SRC_ALPHA

		// GL_ONE_MINUS_SRC_ALPHA
		// GL_DST_ALPHA
		// GL_ONE_MINUS_DST_ALPHA

		// BlendEquationSeparate
		HJS_BIND_CONST_GL(FUNC_ADD);
		HJS_BIND_CONST_GL(BLEND_EQUATION);
		HJS_BIND_CONST_GL(BLEND_EQUATION_RGB);
		HJS_BIND_CONST_GL(BLEND_EQUATION_ALPHA);

		// BlendSubtract
		HJS_BIND_CONST_GL(FUNC_SUBTRACT);
		HJS_BIND_CONST_GL(FUNC_REVERSE_SUBTRACT);

		// Separate Blend Functions
		HJS_BIND_CONST_GL(BLEND_DST_RGB);
		HJS_BIND_CONST_GL(BLEND_SRC_RGB);
		HJS_BIND_CONST_GL(BLEND_DST_ALPHA);
		HJS_BIND_CONST_GL(BLEND_SRC_ALPHA);
		HJS_BIND_CONST_GL(CONSTANT_COLOR);
		HJS_BIND_CONST_GL(ONE_MINUS_CONSTANT_COLOR);
		HJS_BIND_CONST_GL(CONSTANT_ALPHA);
		HJS_BIND_CONST_GL(ONE_MINUS_CONSTANT_ALPHA);
		HJS_BIND_CONST_GL(BLEND_COLOR);

		// Buffer Objects
		HJS_BIND_CONST_GL(ARRAY_BUFFER);
		HJS_BIND_CONST_GL(ELEMENT_ARRAY_BUFFER);
		HJS_BIND_CONST_GL(ARRAY_BUFFER_BINDING);
		HJS_BIND_CONST_GL(ELEMENT_ARRAY_BUFFER_BINDING);

		HJS_BIND_CONST_GL(STREAM_DRAW);
		HJS_BIND_CONST_GL(STATIC_DRAW);
		HJS_BIND_CONST_GL(DYNAMIC_DRAW);

		HJS_BIND_CONST_GL(BUFFER_SIZE);
		HJS_BIND_CONST_GL(BUFFER_USAGE);

		HJS_BIND_CONST_GL(CURRENT_VERTEX_ATTRIB);

		// CullFaceMode
		HJS_BIND_CONST_GL(FRONT);
		HJS_BIND_CONST_GL(BACK);
		HJS_BIND_CONST_GL(FRONT_AND_BACK);

		// EnableCap
		HJS_BIND_CONST_GL(TEXTURE_2D);
		HJS_BIND_CONST_GL(CULL_FACE);
		HJS_BIND_CONST_GL(BLEND);
		HJS_BIND_CONST_GL(DITHER);
		HJS_BIND_CONST_GL(STENCIL_TEST);
		HJS_BIND_CONST_GL(DEPTH_TEST);
		HJS_BIND_CONST_GL(SCISSOR_TEST);
		HJS_BIND_CONST_GL(POLYGON_OFFSET_FILL);
		HJS_BIND_CONST_GL(SAMPLE_ALPHA_TO_COVERAGE);
		HJS_BIND_CONST_GL(SAMPLE_COVERAGE);

		// ErrorCode
#pragma push_macro("NO_ERROR")
#undef NO_ERROR
		HJS_BIND_CONST_GL(NO_ERROR);
#pragma pop_macro("NO_ERROR")
		HJS_BIND_CONST_GL(INVALID_ENUM);
		HJS_BIND_CONST_GL(INVALID_VALUE);
		HJS_BIND_CONST_GL(INVALID_OPERATION);
		HJS_BIND_CONST_GL(OUT_OF_MEMORY);

		// FrontFaceDirection
		HJS_BIND_CONST_GL(CW);
		HJS_BIND_CONST_GL(CCW);

		// GetPName
		HJS_BIND_CONST_GL(LINE_WIDTH);
		HJS_BIND_CONST_GL(ALIASED_POINT_SIZE_RANGE);
		HJS_BIND_CONST_GL(ALIASED_LINE_WIDTH_RANGE);
		HJS_BIND_CONST_GL(CULL_FACE_MODE);
		HJS_BIND_CONST_GL(FRONT_FACE);
		HJS_BIND_CONST_GL(DEPTH_RANGE);
		HJS_BIND_CONST_GL(DEPTH_WRITEMASK);
		HJS_BIND_CONST_GL(DEPTH_CLEAR_VALUE);
		HJS_BIND_CONST_GL(DEPTH_FUNC);
		HJS_BIND_CONST_GL(STENCIL_CLEAR_VALUE);
		HJS_BIND_CONST_GL(STENCIL_FUNC);
		HJS_BIND_CONST_GL(STENCIL_FAIL);
		HJS_BIND_CONST_GL(STENCIL_PASS_DEPTH_FAIL);
		HJS_BIND_CONST_GL(STENCIL_PASS_DEPTH_PASS);
		HJS_BIND_CONST_GL(STENCIL_REF);
		HJS_BIND_CONST_GL(STENCIL_VALUE_MASK);
		HJS_BIND_CONST_GL(STENCIL_WRITEMASK);
		HJS_BIND_CONST_GL(STENCIL_BACK_FUNC);
		HJS_BIND_CONST_GL(STENCIL_BACK_FAIL);
		HJS_BIND_CONST_GL(STENCIL_BACK_PASS_DEPTH_FAIL);
		HJS_BIND_CONST_GL(STENCIL_BACK_PASS_DEPTH_PASS);
		HJS_BIND_CONST_GL(STENCIL_BACK_REF);
		HJS_BIND_CONST_GL(STENCIL_BACK_VALUE_MASK);
		HJS_BIND_CONST_GL(STENCIL_BACK_WRITEMASK);
		HJS_BIND_CONST_GL(VIEWPORT);
		HJS_BIND_CONST_GL(SCISSOR_BOX);
		// GL_SCISSOR_TEST
		HJS_BIND_CONST_GL(COLOR_CLEAR_VALUE);
		HJS_BIND_CONST_GL(COLOR_WRITEMASK);
		HJS_BIND_CONST_GL(UNPACK_ALIGNMENT);
		HJS_BIND_CONST_GL(PACK_ALIGNMENT);
		HJS_BIND_CONST_GL(MAX_TEXTURE_SIZE);
		HJS_BIND_CONST_GL(MAX_VIEWPORT_DIMS);
		HJS_BIND_CONST_GL(SUBPIXEL_BITS);
		HJS_BIND_CONST_GL(RED_BITS);
		HJS_BIND_CONST_GL(GREEN_BITS);
		HJS_BIND_CONST_GL(BLUE_BITS);
		HJS_BIND_CONST_GL(ALPHA_BITS);
		HJS_BIND_CONST_GL(DEPTH_BITS);
		HJS_BIND_CONST_GL(STENCIL_BITS);
		HJS_BIND_CONST_GL(POLYGON_OFFSET_UNITS);
		// GL_POLYGON_OFFSET_FILL
		HJS_BIND_CONST_GL(POLYGON_OFFSET_FACTOR);
		HJS_BIND_CONST_GL(TEXTURE_BINDING_2D);
		HJS_BIND_CONST_GL(SAMPLE_BUFFERS);
		HJS_BIND_CONST_GL(SAMPLES);
		HJS_BIND_CONST_GL(SAMPLE_COVERAGE_VALUE);
		HJS_BIND_CONST_GL(SAMPLE_COVERAGE_INVERT);

		// GetTextureParameter
		// GL_TEXTURE_MAG_FILTER
		// GL_TEXTURE_MIN_FILTER
		// GL_TEXTURE_WRAP_S
		// GL_TEXTURE_WRAP_T

		HJS_BIND_CONST_GL(NUM_COMPRESSED_TEXTURE_FORMATS);
		HJS_BIND_CONST_GL(COMPRESSED_TEXTURE_FORMATS);

		// HintMode
		HJS_BIND_CONST_GL(DONT_CARE);
		HJS_BIND_CONST_GL(FASTEST);
		HJS_BIND_CONST_GL(NICEST);

		// HintTarget
		HJS_BIND_CONST_GL(GENERATE_MIPMAP_HINT);

		// DataType
		HJS_BIND_CONST_GL(BYTE);
		HJS_BIND_CONST_GL(UNSIGNED_BYTE);
		HJS_BIND_CONST_GL(SHORT);
		HJS_BIND_CONST_GL(UNSIGNED_SHORT);
		HJS_BIND_CONST_GL(INT);
		HJS_BIND_CONST_GL(UNSIGNED_INT);
		HJS_BIND_CONST_GL(FLOAT);
		HJS_BIND_CONST_GL(FIXED);

		// PixelFormat
		HJS_BIND_CONST_GL(DEPTH_COMPONENT);
		HJS_BIND_CONST_GL(ALPHA);
#pragma push_macro("RGB")
#undef RGB
		HJS_BIND_CONST_GL(RGB);
#pragma pop_macro("RGB")
		HJS_BIND_CONST_GL(RGBA);
		HJS_BIND_CONST_GL(LUMINANCE);
		HJS_BIND_CONST_GL(LUMINANCE_ALPHA);

		// PixelType
		// GL_UNSIGNED_BYTE
		HJS_BIND_CONST_GL(UNSIGNED_SHORT_4_4_4_4);
		HJS_BIND_CONST_GL(UNSIGNED_SHORT_5_5_5_1);
		HJS_BIND_CONST_GL(UNSIGNED_SHORT_5_6_5);

		// Shaders
		HJS_BIND_CONST_GL(FRAGMENT_SHADER);
		HJS_BIND_CONST_GL(VERTEX_SHADER);
		HJS_BIND_CONST_GL(MAX_VERTEX_ATTRIBS);
		HJS_BIND_CONST_GL(MAX_VERTEX_UNIFORM_VECTORS);
		HJS_BIND_CONST_GL(MAX_VARYING_VECTORS);
		HJS_BIND_CONST_GL(MAX_COMBINED_TEXTURE_IMAGE_UNITS);
		HJS_BIND_CONST_GL(MAX_VERTEX_TEXTURE_IMAGE_UNITS);
		HJS_BIND_CONST_GL(MAX_TEXTURE_IMAGE_UNITS);
		HJS_BIND_CONST_GL(MAX_FRAGMENT_UNIFORM_VECTORS);
		HJS_BIND_CONST_GL(SHADER_TYPE);
		HJS_BIND_CONST_GL(DELETE_STATUS);
		HJS_BIND_CONST_GL(LINK_STATUS);
		HJS_BIND_CONST_GL(VALIDATE_STATUS);
		HJS_BIND_CONST_GL(ATTACHED_SHADERS);
		HJS_BIND_CONST_GL(ACTIVE_UNIFORMS);
		HJS_BIND_CONST_GL(ACTIVE_UNIFORM_MAX_LENGTH);
		HJS_BIND_CONST_GL(ACTIVE_ATTRIBUTES);
		HJS_BIND_CONST_GL(ACTIVE_ATTRIBUTE_MAX_LENGTH);
		HJS_BIND_CONST_GL(SHADING_LANGUAGE_VERSION);
		HJS_BIND_CONST_GL(CURRENT_PROGRAM);

		// StencilFunction
		HJS_BIND_CONST_GL(NEVER);
		HJS_BIND_CONST_GL(LESS);
		HJS_BIND_CONST_GL(EQUAL);
		HJS_BIND_CONST_GL(LEQUAL);
		HJS_BIND_CONST_GL(GREATER);
		HJS_BIND_CONST_GL(NOTEQUAL);
		HJS_BIND_CONST_GL(GEQUAL);
		HJS_BIND_CONST_GL(ALWAYS);

		// StencilOp
		// GL_ZERO
		HJS_BIND_CONST_GL(KEEP);
		HJS_BIND_CONST_GL(REPLACE);
		HJS_BIND_CONST_GL(INCR);
		HJS_BIND_CONST_GL(DECR);
		HJS_BIND_CONST_GL(INVERT);
		HJS_BIND_CONST_GL(INCR_WRAP);
		HJS_BIND_CONST_GL(DECR_WRAP);

		// StringName
		HJS_BIND_CONST_GL(VENDOR);
		HJS_BIND_CONST_GL(RENDERER);
		HJS_BIND_CONST_GL(VERSION);
		HJS_BIND_CONST_GL(EXTENSIONS);

		// TextureMagFilter
		HJS_BIND_CONST_GL(NEAREST);
		HJS_BIND_CONST_GL(LINEAR);

		// TextureMinFilter
		// GL_NEAREST
		// GL_LINEAR
		HJS_BIND_CONST_GL(NEAREST_MIPMAP_NEAREST);
		HJS_BIND_CONST_GL(LINEAR_MIPMAP_NEAREST);
		HJS_BIND_CONST_GL(NEAREST_MIPMAP_LINEAR);
		HJS_BIND_CONST_GL(LINEAR_MIPMAP_LINEAR);

		// TextureParameterName
		HJS_BIND_CONST_GL(TEXTURE_MAG_FILTER);
		HJS_BIND_CONST_GL(TEXTURE_MIN_FILTER);
		HJS_BIND_CONST_GL(TEXTURE_WRAP_S);
		HJS_BIND_CONST_GL(TEXTURE_WRAP_T);

		// TextureTarget
		// GL_TEXTURE_2D
		HJS_BIND_CONST_GL(TEXTURE);

		HJS_BIND_CONST_GL(TEXTURE_CUBE_MAP);
		HJS_BIND_CONST_GL(TEXTURE_BINDING_CUBE_MAP);
		HJS_BIND_CONST_GL(TEXTURE_CUBE_MAP_POSITIVE_X);
		HJS_BIND_CONST_GL(TEXTURE_CUBE_MAP_NEGATIVE_X);
		HJS_BIND_CONST_GL(TEXTURE_CUBE_MAP_POSITIVE_Y);
		HJS_BIND_CONST_GL(TEXTURE_CUBE_MAP_NEGATIVE_Y);
		HJS_BIND_CONST_GL(TEXTURE_CUBE_MAP_POSITIVE_Z);
		HJS_BIND_CONST_GL(TEXTURE_CUBE_MAP_NEGATIVE_Z);
		HJS_BIND_CONST_GL(MAX_CUBE_MAP_TEXTURE_SIZE);

		// TextureUnit
		HJS_BIND_CONST_GL(TEXTURE0);
		HJS_BIND_CONST_GL(TEXTURE1);
		HJS_BIND_CONST_GL(TEXTURE2);
		HJS_BIND_CONST_GL(TEXTURE3);
		HJS_BIND_CONST_GL(TEXTURE4);
		HJS_BIND_CONST_GL(TEXTURE5);
		HJS_BIND_CONST_GL(TEXTURE6);
		HJS_BIND_CONST_GL(TEXTURE7);
		HJS_BIND_CONST_GL(TEXTURE8);
		HJS_BIND_CONST_GL(TEXTURE9);
		HJS_BIND_CONST_GL(TEXTURE10);
		HJS_BIND_CONST_GL(TEXTURE11);
		HJS_BIND_CONST_GL(TEXTURE12);
		HJS_BIND_CONST_GL(TEXTURE13);
		HJS_BIND_CONST_GL(TEXTURE14);
		HJS_BIND_CONST_GL(TEXTURE15);
		HJS_BIND_CONST_GL(TEXTURE16);
		HJS_BIND_CONST_GL(TEXTURE17);
		HJS_BIND_CONST_GL(TEXTURE18);
		HJS_BIND_CONST_GL(TEXTURE19);
		HJS_BIND_CONST_GL(TEXTURE20);
		HJS_BIND_CONST_GL(TEXTURE21);
		HJS_BIND_CONST_GL(TEXTURE22);
		HJS_BIND_CONST_GL(TEXTURE23);
		HJS_BIND_CONST_GL(TEXTURE24);
		HJS_BIND_CONST_GL(TEXTURE25);
		HJS_BIND_CONST_GL(TEXTURE26);
		HJS_BIND_CONST_GL(TEXTURE27);
		HJS_BIND_CONST_GL(TEXTURE28);
		HJS_BIND_CONST_GL(TEXTURE29);
		HJS_BIND_CONST_GL(TEXTURE30);
		HJS_BIND_CONST_GL(TEXTURE31);
		HJS_BIND_CONST_GL(ACTIVE_TEXTURE);

		// TextureWrapMode
		HJS_BIND_CONST_GL(REPEAT);
		HJS_BIND_CONST_GL(CLAMP_TO_EDGE);
		HJS_BIND_CONST_GL(MIRRORED_REPEAT);

		// Uniform Types
		HJS_BIND_CONST_GL(FLOAT_VEC2);
		HJS_BIND_CONST_GL(FLOAT_VEC3);
		HJS_BIND_CONST_GL(FLOAT_VEC4);
		HJS_BIND_CONST_GL(INT_VEC2);
		HJS_BIND_CONST_GL(INT_VEC3);
		HJS_BIND_CONST_GL(INT_VEC4);
		HJS_BIND_CONST_GL(BOOL);
		HJS_BIND_CONST_GL(BOOL_VEC2);
		HJS_BIND_CONST_GL(BOOL_VEC3);
		HJS_BIND_CONST_GL(BOOL_VEC4);
		HJS_BIND_CONST_GL(FLOAT_MAT2);
		HJS_BIND_CONST_GL(FLOAT_MAT3);
		HJS_BIND_CONST_GL(FLOAT_MAT4);
		HJS_BIND_CONST_GL(SAMPLER_2D);
		HJS_BIND_CONST_GL(SAMPLER_CUBE);

		// Vertex Arrays
		HJS_BIND_CONST_GL(VERTEX_ATTRIB_ARRAY_ENABLED);
		HJS_BIND_CONST_GL(VERTEX_ATTRIB_ARRAY_SIZE);
		HJS_BIND_CONST_GL(VERTEX_ATTRIB_ARRAY_STRIDE);
		HJS_BIND_CONST_GL(VERTEX_ATTRIB_ARRAY_TYPE);
		HJS_BIND_CONST_GL(VERTEX_ATTRIB_ARRAY_NORMALIZED);
		HJS_BIND_CONST_GL(VERTEX_ATTRIB_ARRAY_POINTER);
		HJS_BIND_CONST_GL(VERTEX_ATTRIB_ARRAY_BUFFER_BINDING);

		// Read Format
		HJS_BIND_CONST_GL(IMPLEMENTATION_COLOR_READ_TYPE);
		HJS_BIND_CONST_GL(IMPLEMENTATION_COLOR_READ_FORMAT);

		// Shader Source
		HJS_BIND_CONST_GL(COMPILE_STATUS);
		HJS_BIND_CONST_GL(INFO_LOG_LENGTH);
		HJS_BIND_CONST_GL(SHADER_SOURCE_LENGTH);
		HJS_BIND_CONST_GL(SHADER_COMPILER);

		// Shader Binary
		HJS_BIND_CONST_GL(SHADER_BINARY_FORMATS);
		HJS_BIND_CONST_GL(NUM_SHADER_BINARY_FORMATS);

		// Shader Precision-Specified Types
		HJS_BIND_CONST_GL(LOW_FLOAT);
		HJS_BIND_CONST_GL(MEDIUM_FLOAT);
		HJS_BIND_CONST_GL(HIGH_FLOAT);
		HJS_BIND_CONST_GL(LOW_INT);
		HJS_BIND_CONST_GL(MEDIUM_INT);
		HJS_BIND_CONST_GL(HIGH_INT);

		// Framebuffer Object.
		HJS_BIND_CONST_GL(FRAMEBUFFER);
		HJS_BIND_CONST_GL(RENDERBUFFER);

		HJS_BIND_CONST_GL(RGBA4);
		HJS_BIND_CONST_GL(RGB5_A1);
		HJS_BIND_CONST_GL(RGB565);
		HJS_BIND_CONST_GL(DEPTH_COMPONENT16);

		// Not sure if it makes sense to alias STENCIL_INDEX or if it should be
		// removed completely.
		HJS_BIND_CONST(STENCIL_INDEX, GL_DEPTH_STENCIL_OES);
		HJS_BIND_CONST(STENCIL_INDEX8, GL_DEPTH_STENCIL_OES);
		HJS_BIND_CONST(DEPTH_STENCIL, GL_DEPTH_STENCIL_OES);

		HJS_BIND_CONST_GL(RENDERBUFFER_WIDTH);
		HJS_BIND_CONST_GL(RENDERBUFFER_HEIGHT);
		HJS_BIND_CONST_GL(RENDERBUFFER_INTERNAL_FORMAT);
		HJS_BIND_CONST_GL(RENDERBUFFER_RED_SIZE);
		HJS_BIND_CONST_GL(RENDERBUFFER_GREEN_SIZE);
		HJS_BIND_CONST_GL(RENDERBUFFER_BLUE_SIZE);
		HJS_BIND_CONST_GL(RENDERBUFFER_ALPHA_SIZE);
		HJS_BIND_CONST_GL(RENDERBUFFER_DEPTH_SIZE);
		HJS_BIND_CONST_GL(RENDERBUFFER_STENCIL_SIZE);

		HJS_BIND_CONST_GL(FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE);
		HJS_BIND_CONST_GL(FRAMEBUFFER_ATTACHMENT_OBJECT_NAME);
		HJS_BIND_CONST_GL(FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL);
		HJS_BIND_CONST_GL(FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE);

		HJS_BIND_CONST_GL(COLOR_ATTACHMENT0);
		HJS_BIND_CONST_GL(DEPTH_ATTACHMENT);
		HJS_BIND_CONST_GL(STENCIL_ATTACHMENT);
		HJS_BIND_CONST_GL(DEPTH_STENCIL_ATTACHMENT);


		HJS_BIND_CONST_GL(NONE);

		HJS_BIND_CONST_GL(FRAMEBUFFER_COMPLETE);
		HJS_BIND_CONST_GL(FRAMEBUFFER_INCOMPLETE_ATTACHMENT);
		HJS_BIND_CONST_GL(FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT);
		HJS_BIND_CONST_GL(FRAMEBUFFER_INCOMPLETE_DIMENSIONS);
		HJS_BIND_CONST_GL(FRAMEBUFFER_UNSUPPORTED);

		HJS_BIND_CONST_GL(FRAMEBUFFER_BINDING);
		HJS_BIND_CONST_GL(RENDERBUFFER_BINDING);
		HJS_BIND_CONST_GL(MAX_RENDERBUFFER_SIZE);

		HJS_BIND_CONST_GL(INVALID_FRAMEBUFFER_OPERATION);

		// WebGL-specific enums
		HJS_BIND_CONST_GL(UNPACK_FLIP_Y_WEBGL);
		HJS_BIND_CONST_GL(UNPACK_PREMULTIPLY_ALPHA_WEBGL);
		HJS_BIND_CONST_GL(CONTEXT_LOST_WEBGL);
		HJS_BIND_CONST_GL(UNPACK_COLORSPACE_CONVERSION_WEBGL);
		HJS_BIND_CONST_GL(BROWSER_DEFAULT_WEBGL);

		IMapView<String^, Boolean>^ GetContextAttributes();
		bool IsContextLost();
		IVector<String^>^ GetSupportedExtensions();
		Object^ GetExtension(String^ name);

		void Render();

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
		void BufferData(GLenum target, GLint size, GLenum usage);
		void BufferData(GLenum target, const Array<GLfloat>^ data, GLenum usage);
		void BufferSubData(GLenum target, GLint offset, const Array<GLint>^ data);
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
		//void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
		//void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
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
		void DrawElements(GLenum mode, GLsizei count, GLenum type, GLint offset);
		void DrawElementsInstancedANGLE(GLenum mode, GLsizei count, GLenum type, GLint offset, GLsizei primcount);
		void Enable(GLenum cap);
		void EnableVertexAttribArray(GLuint index);
		void Finish();
		void Flush();
		void FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
		void FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		void FrontFace(GLenum mode);
		void GenerateMipmap(GLenum target);
		WebGLActiveInfo^ GetActiveAttrib(GLuint program, GLuint index);
		WebGLActiveInfo^ GetActiveUniform(GLuint program, GLuint index);
		IVector<GLuint>^ GetAttachedShaders(GLuint program);
		GLint GetAttribLocation(GLuint program, String^ name);
		GLint GetBufferParameter(GLenum target, GLenum pname);
		Object^ GetParameter(GLenum pname);
		GLenum GetError();
		//any GetFramebufferAttachmentParameter(GLenum target, GLenum attachment, GLenum pname);
		GLint GetProgramParameter(GLuint program, GLenum pname);
		String^ GetProgramInfoLog(GLuint program);
		//any GetRenderbufferParameter(GLenum target, GLenum pname);
		GLint GetShaderParameter(GLuint shader, GLenum pname);
		//WebGLShaderPrecisionFormat ? GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype);
		String^ GetShaderInfoLog(GLuint shader);
		String^ GetShaderSource(GLuint shader);
		//any GetTexParameter(GLenum target, GLenum pname);
		// GetUniform(GLuint program, WebGLUniformLocation ? location);
		GLint GetUniformLocation(GLuint program, String^ name);
		Object^ GetVertexAttrib(GLuint index, GLenum pname);
		GLint GetVertexAttribOffset(GLuint index, GLenum pname);
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
		void UniformMatrix4fv(GLint location, GLboolean transpose, const Array<GLfloat>^ value);
		//void UniformMatrix4fv(WebGLUniformLocation ? location, GLboolean transpose, sequence<GLfloat> value);
		void UseProgram(GLuint program);
		void ValidateProgram(GLuint program);
		void VertexAttrib1f(GLuint index, GLfloat x);
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
		void VertexAttribDivisorANGLE(GLuint index, GLuint divisor);
		void VertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLint offset);
		void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);

		property String^ TEST { String^ get() { return ref new String(L"test123"); } };
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
		static String^ StringFromAscIIChars(char* chars);
	};
}

#undef HJS_BIND_CONST_GL