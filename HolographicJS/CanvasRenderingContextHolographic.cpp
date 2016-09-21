#include "pch.h"
#include "CanvasRenderingContextHolographic.h"
#include "Binding.h"

using namespace HolographicJS;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

std::map<const wchar_t *, JsNativeFunction> CanvasRenderingContextHolographic::getMembers() {
	std::map<const wchar_t *, JsNativeFunction> members;

	members.insert({ L"activeTexture", activeTexture });
	members.insert({ L"attachShader", attachShader });
	members.insert({ L"bindAttribLocation", bindAttribLocation });
	members.insert({ L"bindBuffer", bindBuffer });
	members.insert({ L"bindFramebuffer", bindFramebuffer });
	members.insert({ L"bindRenderbuffer", bindRenderbuffer });
	members.insert({ L"bindTexture", bindTexture });
	members.insert({ L"blendColor", blendColor });
	members.insert({ L"blendEquation", blendEquation });
	members.insert({ L"blendEquationSeparate", blendEquationSeparate });
	members.insert({ L"blendFunc", blendFunc });
	members.insert({ L"blendFuncSeparate", blendFuncSeparate });
	members.insert({ L"bufferData", bufferData });
	members.insert({ L"bufferSubData", bufferSubData });
	members.insert({ L"checkFramebufferStatus", checkFramebufferStatus });
	members.insert({ L"clear", clear });
	members.insert({ L"clearColor", clearColor });
	members.insert({ L"clearDepth", clearDepth });
	members.insert({ L"clearStencil", clearStencil });
	members.insert({ L"colorMask", colorMask });
	members.insert({ L"compileShader", compileShader });
	members.insert({ L"createBuffer", createBuffer });
	members.insert({ L"createFramebuffer", createFramebuffer });
	members.insert({ L"createProgram", createProgram });
	members.insert({ L"createRenderbuffer", createRenderbuffer });
	members.insert({ L"createShader", createShader });
	members.insert({ L"createTexture", createTexture });
	members.insert({ L"cullFace", cullFace });
	members.insert({ L"deleteBuffer", deleteBuffer });
	members.insert({ L"deleteFramebuffer", deleteFramebuffer });
	members.insert({ L"deleteProgram", deleteProgram });
	members.insert({ L"deleteRenderbuffer", deleteRenderbuffer });
	members.insert({ L"deleteShader", deleteShader });
	members.insert({ L"deleteTexture", deleteTexture });
	members.insert({ L"depthFunc", depthFunc });
	members.insert({ L"depthMask", depthMask });
	members.insert({ L"depthRange", depthRange });
	members.insert({ L"detachShader", detachShader });
	members.insert({ L"disable", disable });
	members.insert({ L"disableVertexAttribArray", disableVertexAttribArray });
	members.insert({ L"drawArrays", drawArrays });
	members.insert({ L"drawElements", drawElements });
	members.insert({ L"drawElementsInstancedANGLE", drawElementsInstancedANGLE });
	members.insert({ L"enable", enable });
	members.insert({ L"enableVertexAttribArray", enableVertexAttribArray });
	members.insert({ L"finish", finish });
	members.insert({ L"flush", flush });
	members.insert({ L"framebufferRenderbuffer", framebufferRenderbuffer });
	members.insert({ L"framebufferTexture2D", framebufferTexture2D });
	members.insert({ L"frontFace", frontFace });
	members.insert({ L"generateMipmap", generateMipmap });
	members.insert({ L"getActiveAttrib", getActiveAttrib });
	members.insert({ L"getActiveUniform", getActiveUniform });
	members.insert({ L"getAttachedShaders", getAttachedShaders });
	members.insert({ L"getAttribLocation", getAttribLocation });
	members.insert({ L"getBufferParameter", getBufferParameter });
	members.insert({ L"getParameter", getParameter });
	members.insert({ L"getError", getError });
	members.insert({ L"getProgramParameter", getProgramParameter });
	members.insert({ L"getProgramInfoLog", getProgramInfoLog });
	members.insert({ L"getShaderParameter", getShaderParameter });
	members.insert({ L"getShaderInfoLog", getShaderInfoLog });
	members.insert({ L"getShaderSource", getShaderSource });
	members.insert({ L"getUniformLocation", getUniformLocation });
	members.insert({ L"getVertexAttrib", getVertexAttrib });
	members.insert({ L"getVertexAttribOffset", getVertexAttribOffset });
	members.insert({ L"hint", hint });
	members.insert({ L"isBuffer", isBuffer });
	members.insert({ L"isEnabled", isEnabled });
	members.insert({ L"isFramebuffer", isFramebuffer });
	members.insert({ L"isProgram", isProgram });
	members.insert({ L"isRenderbuffer", isRenderbuffer });
	members.insert({ L"isShader", isShader });
	members.insert({ L"isTexture", isTexture });
	members.insert({ L"lineWidth", lineWidth });
	members.insert({ L"linkProgram", linkProgram });
	members.insert({ L"pixelStorei", pixelStorei });
	members.insert({ L"polygonOffset", polygonOffset });
	members.insert({ L"renderbufferStorage", renderbufferStorage });
	members.insert({ L"sampleCoverage", sampleCoverage });
	members.insert({ L"scissor", scissor });
	members.insert({ L"shaderSource", shaderSource });
	members.insert({ L"stencilFunc", stencilFunc });
	members.insert({ L"stencilFuncSeparate", stencilFuncSeparate });
	members.insert({ L"stencilMask", stencilMask });
	members.insert({ L"stencilMaskSeparate", stencilMaskSeparate });
	members.insert({ L"stencilOp", stencilOp });
	members.insert({ L"stencilOpSeparate", stencilOpSeparate });
	members.insert({ L"texParameterf", texParameterf });
	members.insert({ L"texParameteri", texParameteri });
	members.insert({ L"uniformMatrix4fv", uniformMatrix4fv });
	members.insert({ L"useProgram", useProgram });
	members.insert({ L"validateProgram", validateProgram });
	members.insert({ L"vertexAttrib1f", vertexAttrib1f });
	members.insert({ L"vertexAttrib2f", vertexAttrib2f });
	members.insert({ L"vertexAttrib3f", vertexAttrib3f });
	members.insert({ L"vertexAttrib4f", vertexAttrib4f });
	members.insert({ L"vertexAttribDivisorANGLE", vertexAttribDivisorANGLE });
	members.insert({ L"vertexAttribPointer", vertexAttribPointer });
	members.insert({ L"viewport", viewport });
	
	return members;
}

std::map<const wchar_t *, JsValueRef> CanvasRenderingContextHolographic::getProperties() {
	std::map<const wchar_t *, JsValueRef> properties;

	properties.insert({ L"DEPTH_BUFFER_BIT", Binding::intToValue(GL_DEPTH_BUFFER_BIT) });

	properties.insert({ L"DEPTH_BUFFER_BIT", Binding::intToValue(GL_DEPTH_BUFFER_BIT) });
	properties.insert({ L"STENCIL_BUFFER_BIT", Binding::intToValue(GL_STENCIL_BUFFER_BIT) });
	properties.insert({ L"COLOR_BUFFER_BIT", Binding::intToValue(GL_COLOR_BUFFER_BIT) });

	// Boolean
	properties.insert({ L"FALSE", Binding::intToValue(GL_FALSE) });
	properties.insert({ L"TRUE", Binding::intToValue(GL_TRUE) });

	properties.insert({ L"POINTS", Binding::intToValue(GL_POINTS) });
	properties.insert({ L"LINES", Binding::intToValue(GL_LINES) });
	properties.insert({ L"LINE_LOOP", Binding::intToValue(GL_LINE_LOOP) });
	properties.insert({ L"LINE_STRIP", Binding::intToValue(GL_LINE_STRIP) });
	properties.insert({ L"TRIANGLES", Binding::intToValue(GL_TRIANGLES) });
	properties.insert({ L"TRIANGLE_STRIP", Binding::intToValue(GL_TRIANGLE_STRIP) });
	properties.insert({ L"TRIANGLE_FAN", Binding::intToValue(GL_TRIANGLE_FAN) });

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
	properties.insert({ L"ZERO", Binding::intToValue(GL_ZERO) });
	properties.insert({ L"ONE", Binding::intToValue(GL_ONE) });
	properties.insert({ L"SRC_COLOR", Binding::intToValue(GL_SRC_COLOR) });
	properties.insert({ L"ONE_MINUS_SRC_COLOR", Binding::intToValue(GL_ONE_MINUS_SRC_COLOR) });
	properties.insert({ L"SRC_ALPHA", Binding::intToValue(GL_SRC_ALPHA) });
	properties.insert({ L"ONE_MINUS_SRC_ALPHA", Binding::intToValue(GL_ONE_MINUS_SRC_ALPHA) });
	properties.insert({ L"DST_ALPHA", Binding::intToValue(GL_DST_ALPHA) });
	properties.insert({ L"ONE_MINUS_DST_ALPHA", Binding::intToValue(GL_ONE_MINUS_DST_ALPHA) });

	// BlendingFactorSrc
	// GL_ZERO
	// GL_ONE
	properties.insert({ L"DST_COLOR", Binding::intToValue(GL_DST_COLOR) });
	properties.insert({ L"ONE_MINUS_DST_COLOR", Binding::intToValue(GL_ONE_MINUS_DST_COLOR) });
	properties.insert({ L"SRC_ALPHA_SATURATE", Binding::intToValue(GL_SRC_ALPHA_SATURATE) });
	// GL_SRC_ALPHA

	// GL_ONE_MINUS_SRC_ALPHA
	// GL_DST_ALPHA
	// GL_ONE_MINUS_DST_ALPHA

	// BlendEquationSeparate
	properties.insert({ L"FUNC_ADD", Binding::intToValue(GL_FUNC_ADD) });
	properties.insert({ L"BLEND_EQUATION", Binding::intToValue(GL_BLEND_EQUATION) });
	properties.insert({ L"BLEND_EQUATION_RGB", Binding::intToValue(GL_BLEND_EQUATION_RGB) });
	properties.insert({ L"BLEND_EQUATION_ALPHA", Binding::intToValue(GL_BLEND_EQUATION_ALPHA) });

	// BlendSubtract
	properties.insert({ L"FUNC_SUBTRACT", Binding::intToValue(GL_FUNC_SUBTRACT) });
	properties.insert({ L"FUNC_REVERSE_SUBTRACT", Binding::intToValue(GL_FUNC_REVERSE_SUBTRACT) });

	// Separate Blend Functions
	properties.insert({ L"BLEND_DST_RGB", Binding::intToValue(GL_BLEND_DST_RGB) });
	properties.insert({ L"BLEND_SRC_RGB", Binding::intToValue(GL_BLEND_SRC_RGB) });
	properties.insert({ L"BLEND_DST_ALPHA", Binding::intToValue(GL_BLEND_DST_ALPHA) });
	properties.insert({ L"BLEND_SRC_ALPHA", Binding::intToValue(GL_BLEND_SRC_ALPHA) });
	properties.insert({ L"CONSTANT_COLOR", Binding::intToValue(GL_CONSTANT_COLOR) });
	properties.insert({ L"ONE_MINUS_CONSTANT_COLOR", Binding::intToValue(GL_ONE_MINUS_CONSTANT_COLOR) });
	properties.insert({ L"CONSTANT_ALPHA", Binding::intToValue(GL_CONSTANT_ALPHA) });
	properties.insert({ L"ONE_MINUS_CONSTANT_ALPHA", Binding::intToValue(GL_ONE_MINUS_CONSTANT_ALPHA) });
	properties.insert({ L"BLEND_COLOR", Binding::intToValue(GL_BLEND_COLOR) });

	// Buffer Objects
	properties.insert({ L"ARRAY_BUFFER", Binding::intToValue(GL_ARRAY_BUFFER) });
	properties.insert({ L"ELEMENT_ARRAY_BUFFER", Binding::intToValue(GL_ELEMENT_ARRAY_BUFFER) });
	properties.insert({ L"ARRAY_BUFFER_BINDING", Binding::intToValue(GL_ARRAY_BUFFER_BINDING) });
	properties.insert({ L"ELEMENT_ARRAY_BUFFER_BINDING", Binding::intToValue(GL_ELEMENT_ARRAY_BUFFER_BINDING) });

	properties.insert({ L"STREAM_DRAW", Binding::intToValue(GL_STREAM_DRAW) });
	properties.insert({ L"STATIC_DRAW", Binding::intToValue(GL_STATIC_DRAW) });
	properties.insert({ L"DYNAMIC_DRAW", Binding::intToValue(GL_DYNAMIC_DRAW) });

	properties.insert({ L"BUFFER_SIZE", Binding::intToValue(GL_BUFFER_SIZE) });
	properties.insert({ L"BUFFER_USAGE", Binding::intToValue(GL_BUFFER_USAGE) });

	properties.insert({ L"CURRENT_VERTEX_ATTRIB", Binding::intToValue(GL_CURRENT_VERTEX_ATTRIB) });

	// CullFaceMode
	properties.insert({ L"FRONT", Binding::intToValue(GL_FRONT) });
	properties.insert({ L"BACK", Binding::intToValue(GL_BACK) });
	properties.insert({ L"FRONT_AND_BACK", Binding::intToValue(GL_FRONT_AND_BACK) });

	// EnableCap
	properties.insert({ L"TEXTURE_2D", Binding::intToValue(GL_TEXTURE_2D) });
	properties.insert({ L"CULL_FACE", Binding::intToValue(GL_CULL_FACE) });
	properties.insert({ L"BLEND", Binding::intToValue(GL_BLEND) });
	properties.insert({ L"DITHER", Binding::intToValue(GL_DITHER) });
	properties.insert({ L"STENCIL_TEST", Binding::intToValue(GL_STENCIL_TEST) });
	properties.insert({ L"DEPTH_TEST", Binding::intToValue(GL_DEPTH_TEST) });
	properties.insert({ L"SCISSOR_TEST", Binding::intToValue(GL_SCISSOR_TEST) });
	properties.insert({ L"POLYGON_OFFSET_FILL", Binding::intToValue(GL_POLYGON_OFFSET_FILL) });
	properties.insert({ L"SAMPLE_ALPHA_TO_COVERAGE", Binding::intToValue(GL_SAMPLE_ALPHA_TO_COVERAGE) });
	properties.insert({ L"SAMPLE_COVERAGE", Binding::intToValue(GL_SAMPLE_COVERAGE) });

	// ErrorCode
	properties.insert({ L"NO_ERROR", Binding::intToValue(GL_NO_ERROR) });
	properties.insert({ L"INVALID_ENUM", Binding::intToValue(GL_INVALID_ENUM) });
	properties.insert({ L"INVALID_VALUE", Binding::intToValue(GL_INVALID_VALUE) });
	properties.insert({ L"INVALID_OPERATION", Binding::intToValue(GL_INVALID_OPERATION) });
	properties.insert({ L"OUT_OF_MEMORY", Binding::intToValue(GL_OUT_OF_MEMORY) });

	// FrontFaceDirection
	properties.insert({ L"CW", Binding::intToValue(GL_CW) });
	properties.insert({ L"CCW", Binding::intToValue(GL_CCW) });

	// GetPName
	properties.insert({ L"LINE_WIDTH", Binding::intToValue(GL_LINE_WIDTH) });
	properties.insert({ L"ALIASED_POINT_SIZE_RANGE", Binding::intToValue(GL_ALIASED_POINT_SIZE_RANGE) });
	properties.insert({ L"ALIASED_LINE_WIDTH_RANGE", Binding::intToValue(GL_ALIASED_LINE_WIDTH_RANGE) });
	properties.insert({ L"CULL_FACE_MODE", Binding::intToValue(GL_CULL_FACE_MODE) });
	properties.insert({ L"FRONT_FACE", Binding::intToValue(GL_FRONT_FACE) });
	properties.insert({ L"DEPTH_RANGE", Binding::intToValue(GL_DEPTH_RANGE) });
	properties.insert({ L"DEPTH_WRITEMASK", Binding::intToValue(GL_DEPTH_WRITEMASK) });
	properties.insert({ L"DEPTH_CLEAR_VALUE", Binding::intToValue(GL_DEPTH_CLEAR_VALUE) });
	properties.insert({ L"DEPTH_FUNC", Binding::intToValue(GL_DEPTH_FUNC) });
	properties.insert({ L"STENCIL_CLEAR_VALUE", Binding::intToValue(GL_STENCIL_CLEAR_VALUE) });
	properties.insert({ L"STENCIL_FUNC", Binding::intToValue(GL_STENCIL_FUNC) });
	properties.insert({ L"STENCIL_FAIL", Binding::intToValue(GL_STENCIL_FAIL) });
	properties.insert({ L"STENCIL_PASS_DEPTH_FAIL", Binding::intToValue(GL_STENCIL_PASS_DEPTH_FAIL) });
	properties.insert({ L"STENCIL_PASS_DEPTH_PASS", Binding::intToValue(GL_STENCIL_PASS_DEPTH_PASS) });
	properties.insert({ L"STENCIL_REF", Binding::intToValue(GL_STENCIL_REF) });
	properties.insert({ L"STENCIL_VALUE_MASK", Binding::intToValue(GL_STENCIL_VALUE_MASK) });
	properties.insert({ L"STENCIL_WRITEMASK", Binding::intToValue(GL_STENCIL_WRITEMASK) });
	properties.insert({ L"STENCIL_BACK_FUNC", Binding::intToValue(GL_STENCIL_BACK_FUNC) });
	properties.insert({ L"STENCIL_BACK_FAIL", Binding::intToValue(GL_STENCIL_BACK_FAIL) });
	properties.insert({ L"STENCIL_BACK_PASS_DEPTH_FAIL", Binding::intToValue(GL_STENCIL_BACK_PASS_DEPTH_FAIL) });
	properties.insert({ L"STENCIL_BACK_PASS_DEPTH_PASS", Binding::intToValue(GL_STENCIL_BACK_PASS_DEPTH_PASS) });
	properties.insert({ L"STENCIL_BACK_REF", Binding::intToValue(GL_STENCIL_BACK_REF) });
	properties.insert({ L"STENCIL_BACK_VALUE_MASK", Binding::intToValue(GL_STENCIL_BACK_VALUE_MASK) });
	properties.insert({ L"STENCIL_BACK_WRITEMASK", Binding::intToValue(GL_STENCIL_BACK_WRITEMASK) });
	properties.insert({ L"VIEWPORT", Binding::intToValue(GL_VIEWPORT) });
	properties.insert({ L"SCISSOR_BOX", Binding::intToValue(GL_SCISSOR_BOX) });
	// GL_SCISSOR_TEST
	properties.insert({ L"COLOR_CLEAR_VALUE", Binding::intToValue(GL_COLOR_CLEAR_VALUE) });
	properties.insert({ L"COLOR_WRITEMASK", Binding::intToValue(GL_COLOR_WRITEMASK) });
	properties.insert({ L"UNPACK_ALIGNMENT", Binding::intToValue(GL_UNPACK_ALIGNMENT) });
	properties.insert({ L"PACK_ALIGNMENT", Binding::intToValue(GL_PACK_ALIGNMENT) });
	properties.insert({ L"MAX_TEXTURE_SIZE", Binding::intToValue(GL_MAX_TEXTURE_SIZE) });
	properties.insert({ L"MAX_VIEWPORT_DIMS", Binding::intToValue(GL_MAX_VIEWPORT_DIMS) });
	properties.insert({ L"SUBPIXEL_BITS", Binding::intToValue(GL_SUBPIXEL_BITS) });
	properties.insert({ L"RED_BITS", Binding::intToValue(GL_RED_BITS) });
	properties.insert({ L"GREEN_BITS", Binding::intToValue(GL_GREEN_BITS) });
	properties.insert({ L"BLUE_BITS", Binding::intToValue(GL_BLUE_BITS) });
	properties.insert({ L"ALPHA_BITS", Binding::intToValue(GL_ALPHA_BITS) });
	properties.insert({ L"DEPTH_BITS", Binding::intToValue(GL_DEPTH_BITS) });
	properties.insert({ L"STENCIL_BITS", Binding::intToValue(GL_STENCIL_BITS) });
	properties.insert({ L"POLYGON_OFFSET_UNITS", Binding::intToValue(GL_POLYGON_OFFSET_UNITS) });
	// GL_POLYGON_OFFSET_FILL
	properties.insert({ L"POLYGON_OFFSET_FACTOR", Binding::intToValue(GL_POLYGON_OFFSET_FACTOR) });
	properties.insert({ L"TEXTURE_BINDING_2D", Binding::intToValue(GL_TEXTURE_BINDING_2D) });
	properties.insert({ L"SAMPLE_BUFFERS", Binding::intToValue(GL_SAMPLE_BUFFERS) });
	properties.insert({ L"SAMPLES", Binding::intToValue(GL_SAMPLES) });
	properties.insert({ L"SAMPLE_COVERAGE_VALUE", Binding::intToValue(GL_SAMPLE_COVERAGE_VALUE) });
	properties.insert({ L"SAMPLE_COVERAGE_INVERT", Binding::intToValue(GL_SAMPLE_COVERAGE_INVERT) });

	// GetTextureParameter
	// GL_TEXTURE_MAG_FILTER
	// GL_TEXTURE_MIN_FILTER
	// GL_TEXTURE_WRAP_S
	// GL_TEXTURE_WRAP_T

	properties.insert({ L"NUM_COMPRESSED_TEXTURE_FORMATS", Binding::intToValue(GL_NUM_COMPRESSED_TEXTURE_FORMATS) });
	properties.insert({ L"COMPRESSED_TEXTURE_FORMATS", Binding::intToValue(GL_COMPRESSED_TEXTURE_FORMATS) });

	// HintMode
	properties.insert({ L"DONT_CARE", Binding::intToValue(GL_DONT_CARE) });
	properties.insert({ L"FASTEST", Binding::intToValue(GL_FASTEST) });
	properties.insert({ L"NICEST", Binding::intToValue(GL_NICEST) });

	// HintTarget
	properties.insert({ L"GENERATE_MIPMAP_HINT", Binding::intToValue(GL_GENERATE_MIPMAP_HINT) });

	// DataType
	properties.insert({ L"BYTE", Binding::intToValue(GL_BYTE) });
	properties.insert({ L"UNSIGNED_BYTE", Binding::intToValue(GL_UNSIGNED_BYTE) });
	properties.insert({ L"SHORT", Binding::intToValue(GL_SHORT) });
	properties.insert({ L"UNSIGNED_SHORT", Binding::intToValue(GL_UNSIGNED_SHORT) });
	properties.insert({ L"INT", Binding::intToValue(GL_INT) });
	properties.insert({ L"UNSIGNED_INT", Binding::intToValue(GL_UNSIGNED_INT) });
	properties.insert({ L"FLOAT", Binding::intToValue(GL_FLOAT) });
	properties.insert({ L"FIXED", Binding::intToValue(GL_FIXED) });

	// PixelFormat
	properties.insert({ L"DEPTH_COMPONENT", Binding::intToValue(GL_DEPTH_COMPONENT) });
	properties.insert({ L"ALPHA", Binding::intToValue(GL_ALPHA) });
	properties.insert({ L"RGB", Binding::intToValue(GL_RGB) });
	properties.insert({ L"RGBA", Binding::intToValue(GL_RGBA) });
	properties.insert({ L"LUMINANCE", Binding::intToValue(GL_LUMINANCE) });
	properties.insert({ L"LUMINANCE_ALPHA", Binding::intToValue(GL_LUMINANCE_ALPHA) });

	// PixelType
	// GL_UNSIGNED_BYTE
	properties.insert({ L"UNSIGNED_SHORT_4_4_4_4", Binding::intToValue(GL_UNSIGNED_SHORT_4_4_4_4) });
	properties.insert({ L"UNSIGNED_SHORT_5_5_5_1", Binding::intToValue(GL_UNSIGNED_SHORT_5_5_5_1) });
	properties.insert({ L"UNSIGNED_SHORT_5_6_5", Binding::intToValue(GL_UNSIGNED_SHORT_5_6_5) });

	// Shaders
	properties.insert({ L"FRAGMENT_SHADER", Binding::intToValue(GL_FRAGMENT_SHADER) });
	properties.insert({ L"VERTEX_SHADER", Binding::intToValue(GL_VERTEX_SHADER) });
	properties.insert({ L"MAX_VERTEX_ATTRIBS", Binding::intToValue(GL_MAX_VERTEX_ATTRIBS) });
	properties.insert({ L"MAX_VERTEX_UNIFORM_VECTORS", Binding::intToValue(GL_MAX_VERTEX_UNIFORM_VECTORS) });
	properties.insert({ L"MAX_VARYING_VECTORS", Binding::intToValue(GL_MAX_VARYING_VECTORS) });
	properties.insert({ L"MAX_COMBINED_TEXTURE_IMAGE_UNITS", Binding::intToValue(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS) });
	properties.insert({ L"MAX_VERTEX_TEXTURE_IMAGE_UNITS", Binding::intToValue(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS) });
	properties.insert({ L"MAX_TEXTURE_IMAGE_UNITS", Binding::intToValue(GL_MAX_TEXTURE_IMAGE_UNITS) });
	properties.insert({ L"MAX_FRAGMENT_UNIFORM_VECTORS", Binding::intToValue(GL_MAX_FRAGMENT_UNIFORM_VECTORS) });
	properties.insert({ L"SHADER_TYPE", Binding::intToValue(GL_SHADER_TYPE) });
	properties.insert({ L"DELETE_STATUS", Binding::intToValue(GL_DELETE_STATUS) });
	properties.insert({ L"LINK_STATUS", Binding::intToValue(GL_LINK_STATUS) });
	properties.insert({ L"VALIDATE_STATUS", Binding::intToValue(GL_VALIDATE_STATUS) });
	properties.insert({ L"ATTACHED_SHADERS", Binding::intToValue(GL_ATTACHED_SHADERS) });
	properties.insert({ L"ACTIVE_UNIFORMS", Binding::intToValue(GL_ACTIVE_UNIFORMS) });
	properties.insert({ L"ACTIVE_UNIFORM_MAX_LENGTH", Binding::intToValue(GL_ACTIVE_UNIFORM_MAX_LENGTH) });
	properties.insert({ L"ACTIVE_ATTRIBUTES", Binding::intToValue(GL_ACTIVE_ATTRIBUTES) });
	properties.insert({ L"ACTIVE_ATTRIBUTE_MAX_LENGTH", Binding::intToValue(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH) });
	properties.insert({ L"SHADING_LANGUAGE_VERSION", Binding::intToValue(GL_SHADING_LANGUAGE_VERSION) });
	properties.insert({ L"CURRENT_PROGRAM", Binding::intToValue(GL_CURRENT_PROGRAM) });

	// StencilFunction
	properties.insert({ L"NEVER", Binding::intToValue(GL_NEVER) });
	properties.insert({ L"LESS", Binding::intToValue(GL_LESS) });
	properties.insert({ L"EQUAL", Binding::intToValue(GL_EQUAL) });
	properties.insert({ L"LEQUAL", Binding::intToValue(GL_LEQUAL) });
	properties.insert({ L"GREATER", Binding::intToValue(GL_GREATER) });
	properties.insert({ L"NOTEQUAL", Binding::intToValue(GL_NOTEQUAL) });
	properties.insert({ L"GEQUAL", Binding::intToValue(GL_GEQUAL) });
	properties.insert({ L"ALWAYS", Binding::intToValue(GL_ALWAYS) });

	// StencilOp
	// GL_ZERO
	properties.insert({ L"KEEP", Binding::intToValue(GL_KEEP) });
	properties.insert({ L"REPLACE", Binding::intToValue(GL_REPLACE) });
	properties.insert({ L"INCR", Binding::intToValue(GL_INCR) });
	properties.insert({ L"DECR", Binding::intToValue(GL_DECR) });
	properties.insert({ L"INVERT", Binding::intToValue(GL_INVERT) });
	properties.insert({ L"INCR_WRAP", Binding::intToValue(GL_INCR_WRAP) });
	properties.insert({ L"DECR_WRAP", Binding::intToValue(GL_DECR_WRAP) });

	// StringName
	properties.insert({ L"VENDOR", Binding::intToValue(GL_VENDOR) });
	properties.insert({ L"RENDERER", Binding::intToValue(GL_RENDERER) });
	properties.insert({ L"VERSION", Binding::intToValue(GL_VERSION) });
	properties.insert({ L"EXTENSIONS", Binding::intToValue(GL_EXTENSIONS) });

	// TextureMagFilter
	properties.insert({ L"NEAREST", Binding::intToValue(GL_NEAREST) });
	properties.insert({ L"LINEAR", Binding::intToValue(GL_LINEAR) });

	// TextureMinFilter
	// GL_NEAREST
	// GL_LINEAR
	properties.insert({ L"NEAREST_MIPMAP_NEAREST", Binding::intToValue(GL_NEAREST_MIPMAP_NEAREST) });
	properties.insert({ L"LINEAR_MIPMAP_NEAREST", Binding::intToValue(GL_LINEAR_MIPMAP_NEAREST) });
	properties.insert({ L"NEAREST_MIPMAP_LINEAR", Binding::intToValue(GL_NEAREST_MIPMAP_LINEAR) });
	properties.insert({ L"LINEAR_MIPMAP_LINEAR", Binding::intToValue(GL_LINEAR_MIPMAP_LINEAR) });

	// TextureParameterName
	properties.insert({ L"TEXTURE_MAG_FILTER", Binding::intToValue(GL_TEXTURE_MAG_FILTER) });
	properties.insert({ L"TEXTURE_MIN_FILTER", Binding::intToValue(GL_TEXTURE_MIN_FILTER) });
	properties.insert({ L"TEXTURE_WRAP_S", Binding::intToValue(GL_TEXTURE_WRAP_S) });
	properties.insert({ L"TEXTURE_WRAP_T", Binding::intToValue(GL_TEXTURE_WRAP_T) });

	// TextureTarget
	// GL_TEXTURE_2D
	properties.insert({ L"TEXTURE", Binding::intToValue(GL_TEXTURE) });

	properties.insert({ L"TEXTURE_CUBE_MAP", Binding::intToValue(GL_TEXTURE_CUBE_MAP) });
	properties.insert({ L"TEXTURE_BINDING_CUBE_MAP", Binding::intToValue(GL_TEXTURE_BINDING_CUBE_MAP) });
	properties.insert({ L"TEXTURE_CUBE_MAP_POSITIVE_X", Binding::intToValue(GL_TEXTURE_CUBE_MAP_POSITIVE_X) });
	properties.insert({ L"TEXTURE_CUBE_MAP_NEGATIVE_X", Binding::intToValue(GL_TEXTURE_CUBE_MAP_NEGATIVE_X) });
	properties.insert({ L"TEXTURE_CUBE_MAP_POSITIVE_Y", Binding::intToValue(GL_TEXTURE_CUBE_MAP_POSITIVE_Y) });
	properties.insert({ L"TEXTURE_CUBE_MAP_NEGATIVE_Y", Binding::intToValue(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y) });
	properties.insert({ L"TEXTURE_CUBE_MAP_POSITIVE_Z", Binding::intToValue(GL_TEXTURE_CUBE_MAP_POSITIVE_Z) });
	properties.insert({ L"TEXTURE_CUBE_MAP_NEGATIVE_Z", Binding::intToValue(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z) });
	properties.insert({ L"MAX_CUBE_MAP_TEXTURE_SIZE", Binding::intToValue(GL_MAX_CUBE_MAP_TEXTURE_SIZE) });

	// TextureUnit
	properties.insert({ L"TEXTURE0", Binding::intToValue(GL_TEXTURE0) });
	properties.insert({ L"TEXTURE1", Binding::intToValue(GL_TEXTURE1) });
	properties.insert({ L"TEXTURE2", Binding::intToValue(GL_TEXTURE2) });
	properties.insert({ L"TEXTURE3", Binding::intToValue(GL_TEXTURE3) });
	properties.insert({ L"TEXTURE4", Binding::intToValue(GL_TEXTURE4) });
	properties.insert({ L"TEXTURE5", Binding::intToValue(GL_TEXTURE5) });
	properties.insert({ L"TEXTURE6", Binding::intToValue(GL_TEXTURE6) });
	properties.insert({ L"TEXTURE7", Binding::intToValue(GL_TEXTURE7) });
	properties.insert({ L"TEXTURE8", Binding::intToValue(GL_TEXTURE8) });
	properties.insert({ L"TEXTURE9", Binding::intToValue(GL_TEXTURE9) });
	properties.insert({ L"TEXTURE10", Binding::intToValue(GL_TEXTURE10) });
	properties.insert({ L"TEXTURE11", Binding::intToValue(GL_TEXTURE11) });
	properties.insert({ L"TEXTURE12", Binding::intToValue(GL_TEXTURE12) });
	properties.insert({ L"TEXTURE13", Binding::intToValue(GL_TEXTURE13) });
	properties.insert({ L"TEXTURE14", Binding::intToValue(GL_TEXTURE14) });
	properties.insert({ L"TEXTURE15", Binding::intToValue(GL_TEXTURE15) });
	properties.insert({ L"TEXTURE16", Binding::intToValue(GL_TEXTURE16) });
	properties.insert({ L"TEXTURE17", Binding::intToValue(GL_TEXTURE17) });
	properties.insert({ L"TEXTURE18", Binding::intToValue(GL_TEXTURE18) });
	properties.insert({ L"TEXTURE19", Binding::intToValue(GL_TEXTURE19) });
	properties.insert({ L"TEXTURE20", Binding::intToValue(GL_TEXTURE20) });
	properties.insert({ L"TEXTURE21", Binding::intToValue(GL_TEXTURE21) });
	properties.insert({ L"TEXTURE22", Binding::intToValue(GL_TEXTURE22) });
	properties.insert({ L"TEXTURE23", Binding::intToValue(GL_TEXTURE23) });
	properties.insert({ L"TEXTURE24", Binding::intToValue(GL_TEXTURE24) });
	properties.insert({ L"TEXTURE25", Binding::intToValue(GL_TEXTURE25) });
	properties.insert({ L"TEXTURE26", Binding::intToValue(GL_TEXTURE26) });
	properties.insert({ L"TEXTURE27", Binding::intToValue(GL_TEXTURE27) });
	properties.insert({ L"TEXTURE28", Binding::intToValue(GL_TEXTURE28) });
	properties.insert({ L"TEXTURE29", Binding::intToValue(GL_TEXTURE29) });
	properties.insert({ L"TEXTURE30", Binding::intToValue(GL_TEXTURE30) });
	properties.insert({ L"TEXTURE31", Binding::intToValue(GL_TEXTURE31) });
	properties.insert({ L"ACTIVE_TEXTURE", Binding::intToValue(GL_ACTIVE_TEXTURE) });

	// TextureWrapMode
	properties.insert({ L"REPEAT", Binding::intToValue(GL_REPEAT) });
	properties.insert({ L"CLAMP_TO_EDGE", Binding::intToValue(GL_CLAMP_TO_EDGE) });
	properties.insert({ L"MIRRORED_REPEAT", Binding::intToValue(GL_MIRRORED_REPEAT) });

	// Uniform Types
	properties.insert({ L"FLOAT_VEC2", Binding::intToValue(GL_FLOAT_VEC2) });
	properties.insert({ L"FLOAT_VEC3", Binding::intToValue(GL_FLOAT_VEC3) });
	properties.insert({ L"FLOAT_VEC4", Binding::intToValue(GL_FLOAT_VEC4) });
	properties.insert({ L"INT_VEC2", Binding::intToValue(GL_INT_VEC2) });
	properties.insert({ L"INT_VEC3", Binding::intToValue(GL_INT_VEC3) });
	properties.insert({ L"INT_VEC4", Binding::intToValue(GL_INT_VEC4) });
	properties.insert({ L"BOOL", Binding::intToValue(GL_BOOL) });
	properties.insert({ L"BOOL_VEC2", Binding::intToValue(GL_BOOL_VEC2) });
	properties.insert({ L"BOOL_VEC3", Binding::intToValue(GL_BOOL_VEC3) });
	properties.insert({ L"BOOL_VEC4", Binding::intToValue(GL_BOOL_VEC4) });
	properties.insert({ L"FLOAT_MAT2", Binding::intToValue(GL_FLOAT_MAT2) });
	properties.insert({ L"FLOAT_MAT3", Binding::intToValue(GL_FLOAT_MAT3) });
	properties.insert({ L"FLOAT_MAT4", Binding::intToValue(GL_FLOAT_MAT4) });
	properties.insert({ L"SAMPLER_2D", Binding::intToValue(GL_SAMPLER_2D) });
	properties.insert({ L"SAMPLER_CUBE", Binding::intToValue(GL_SAMPLER_CUBE) });

	// Vertex Arrays
	properties.insert({ L"VERTEX_ATTRIB_ARRAY_ENABLED", Binding::intToValue(GL_VERTEX_ATTRIB_ARRAY_ENABLED) });
	properties.insert({ L"VERTEX_ATTRIB_ARRAY_SIZE", Binding::intToValue(GL_VERTEX_ATTRIB_ARRAY_SIZE) });
	properties.insert({ L"VERTEX_ATTRIB_ARRAY_STRIDE", Binding::intToValue(GL_VERTEX_ATTRIB_ARRAY_STRIDE) });
	properties.insert({ L"VERTEX_ATTRIB_ARRAY_TYPE", Binding::intToValue(GL_VERTEX_ATTRIB_ARRAY_TYPE) });
	properties.insert({ L"VERTEX_ATTRIB_ARRAY_NORMALIZED", Binding::intToValue(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED) });
	properties.insert({ L"VERTEX_ATTRIB_ARRAY_POINTER", Binding::intToValue(GL_VERTEX_ATTRIB_ARRAY_POINTER) });
	properties.insert({ L"VERTEX_ATTRIB_ARRAY_BUFFER_BINDING", Binding::intToValue(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING) });

	// Read Format
	properties.insert({ L"IMPLEMENTATION_COLOR_READ_TYPE", Binding::intToValue(GL_IMPLEMENTATION_COLOR_READ_TYPE) });
	properties.insert({ L"IMPLEMENTATION_COLOR_READ_FORMAT", Binding::intToValue(GL_IMPLEMENTATION_COLOR_READ_FORMAT) });

	// Shader Source
	properties.insert({ L"COMPILE_STATUS", Binding::intToValue(GL_COMPILE_STATUS) });
	properties.insert({ L"INFO_LOG_LENGTH", Binding::intToValue(GL_INFO_LOG_LENGTH) });
	properties.insert({ L"SHADER_SOURCE_LENGTH", Binding::intToValue(GL_SHADER_SOURCE_LENGTH) });
	properties.insert({ L"SHADER_COMPILER", Binding::intToValue(GL_SHADER_COMPILER) });

	// Shader Binary
	properties.insert({ L"SHADER_BINARY_FORMATS", Binding::intToValue(GL_SHADER_BINARY_FORMATS) });
	properties.insert({ L"NUM_SHADER_BINARY_FORMATS", Binding::intToValue(GL_NUM_SHADER_BINARY_FORMATS) });

	// Shader Precision-Specified Types
	properties.insert({ L"LOW_FLOAT", Binding::intToValue(GL_LOW_FLOAT) });
	properties.insert({ L"MEDIUM_FLOAT", Binding::intToValue(GL_MEDIUM_FLOAT) });
	properties.insert({ L"HIGH_FLOAT", Binding::intToValue(GL_HIGH_FLOAT) });
	properties.insert({ L"LOW_INT", Binding::intToValue(GL_LOW_INT) });
	properties.insert({ L"MEDIUM_INT", Binding::intToValue(GL_MEDIUM_INT) });
	properties.insert({ L"HIGH_INT", Binding::intToValue(GL_HIGH_INT) });

	// Framebuffer Object.
	properties.insert({ L"FRAMEBUFFER", Binding::intToValue(GL_FRAMEBUFFER) });
	properties.insert({ L"RENDERBUFFER", Binding::intToValue(GL_RENDERBUFFER) });

	properties.insert({ L"RGBA4", Binding::intToValue(GL_RGBA4) });
	properties.insert({ L"RGB5_A1", Binding::intToValue(GL_RGB5_A1) });
	properties.insert({ L"RGB565", Binding::intToValue(GL_RGB565) });
	properties.insert({ L"DEPTH_COMPONENT16", Binding::intToValue(GL_DEPTH_COMPONENT16) });

	// Not sure if it makes sense to alias STENCIL_INDEX or if it should be
	// removed completely.
	properties.insert({ L"STENCIL_INDEX", Binding::intToValue(GL_DEPTH_STENCIL_OES) });
	properties.insert({ L"STENCIL_INDEX8", Binding::intToValue(GL_DEPTH_STENCIL_OES) });
	properties.insert({ L"DEPTH_STENCIL", Binding::intToValue(GL_DEPTH_STENCIL_OES) });

	properties.insert({ L"RENDERBUFFER_WIDTH", Binding::intToValue(GL_RENDERBUFFER_WIDTH) });
	properties.insert({ L"RENDERBUFFER_HEIGHT", Binding::intToValue(GL_RENDERBUFFER_HEIGHT) });
	properties.insert({ L"RENDERBUFFER_INTERNAL_FORMAT", Binding::intToValue(GL_RENDERBUFFER_INTERNAL_FORMAT) });
	properties.insert({ L"RENDERBUFFER_RED_SIZE", Binding::intToValue(GL_RENDERBUFFER_RED_SIZE) });
	properties.insert({ L"RENDERBUFFER_GREEN_SIZE", Binding::intToValue(GL_RENDERBUFFER_GREEN_SIZE) });
	properties.insert({ L"RENDERBUFFER_BLUE_SIZE", Binding::intToValue(GL_RENDERBUFFER_BLUE_SIZE) });
	properties.insert({ L"RENDERBUFFER_ALPHA_SIZE", Binding::intToValue(GL_RENDERBUFFER_ALPHA_SIZE) });
	properties.insert({ L"RENDERBUFFER_DEPTH_SIZE", Binding::intToValue(GL_RENDERBUFFER_DEPTH_SIZE) });
	properties.insert({ L"RENDERBUFFER_STENCIL_SIZE", Binding::intToValue(GL_RENDERBUFFER_STENCIL_SIZE) });

	properties.insert({ L"FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", Binding::intToValue(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE) });
	properties.insert({ L"FRAMEBUFFER_ATTACHMENT_OBJECT_NAME", Binding::intToValue(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME) });
	properties.insert({ L"FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", Binding::intToValue(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL) });
	properties.insert({ L"FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE", Binding::intToValue(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE) });

	properties.insert({ L"COLOR_ATTACHMENT0", Binding::intToValue(GL_COLOR_ATTACHMENT0) });
	properties.insert({ L"DEPTH_ATTACHMENT", Binding::intToValue(GL_DEPTH_ATTACHMENT) });
	properties.insert({ L"STENCIL_ATTACHMENT", Binding::intToValue(GL_STENCIL_ATTACHMENT) });
	properties.insert({ L"DEPTH_STENCIL_ATTACHMENT", Binding::intToValue(GL_DEPTH_STENCIL_ATTACHMENT) });


	properties.insert({ L"NONE", Binding::intToValue(GL_NONE) });

	properties.insert({ L"FRAMEBUFFER_COMPLETE", Binding::intToValue(GL_FRAMEBUFFER_COMPLETE) });
	properties.insert({ L"FRAMEBUFFER_INCOMPLETE_ATTACHMENT", Binding::intToValue(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT) });
	properties.insert({ L"FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT", Binding::intToValue(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT) });
	properties.insert({ L"FRAMEBUFFER_INCOMPLETE_DIMENSIONS", Binding::intToValue(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS) });
	properties.insert({ L"FRAMEBUFFER_UNSUPPORTED", Binding::intToValue(GL_FRAMEBUFFER_UNSUPPORTED) });

	properties.insert({ L"FRAMEBUFFER_BINDING", Binding::intToValue(GL_FRAMEBUFFER_BINDING) });
	properties.insert({ L"RENDERBUFFER_BINDING", Binding::intToValue(GL_RENDERBUFFER_BINDING) });
	properties.insert({ L"MAX_RENDERBUFFER_SIZE", Binding::intToValue(GL_MAX_RENDERBUFFER_SIZE) });

	properties.insert({ L"INVALID_FRAMEBUFFER_OPERATION", Binding::intToValue(GL_INVALID_FRAMEBUFFER_OPERATION) });

	// WebGL-specific enums
	properties.insert({ L"UNPACK_FLIP_Y_WEBGL", Binding::intToValue(GL_UNPACK_FLIP_Y_WEBGL) });
	properties.insert({ L"UNPACK_PREMULTIPLY_ALPHA_WEBGL", Binding::intToValue(GL_UNPACK_PREMULTIPLY_ALPHA_WEBGL) });
	properties.insert({ L"CONTEXT_LOST_WEBGL", Binding::intToValue(GL_CONTEXT_LOST_WEBGL) });
	properties.insert({ L"UNPACK_COLORSPACE_CONVERSION_WEBGL", Binding::intToValue(GL_UNPACK_COLORSPACE_CONVERSION_WEBGL) });
	properties.insert({ L"BROWSER_DEFAULT_WEBGL", Binding::intToValue(GL_BROWSER_DEFAULT_WEBGL) });

	return properties;
}

CanvasRenderingContextHolographic::CanvasRenderingContextHolographic(IMapView<String^, Boolean>^ contextAttributes, HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame)
{
	this->contextAttributes = contextAttributes;
	this->holographicSpace = holographicSpace;
	this->stationaryReferenceFrame = stationaryReferenceFrame;
	CreateContext();

	EGLint panelWidth = 0;
	EGLint panelHeight = 0;
	eglQuerySurface(display, surface, EGL_WIDTH, &panelWidth);
	eglQuerySurface(display, surface, EGL_HEIGHT, &panelHeight);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::createContext(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

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

JsValueRef CALLBACK CanvasRenderingContextHolographic::render(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	eglSwapBuffers(display, surface);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::activeTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	int texture = Binding::valueToInt(arguments[1]);
	glActiveTexture(texture);
	return JS_INVALID_REFERENCE;
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::attachShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	GLuint shader = Binding::valueToInt(arguments[2]);
	glAttachShader(program, shader);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::bindAttribLocation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	GLuint index = Binding::valueToInt(arguments[2]);
	const wchar_t * name = Binding::valueToString(arguments[3]);

	const char* nameChars = AscIICharsFromString(name);
	glBindAttribLocation(program, index, nameChars);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::bindBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLuint buffer = Binding::valueToInt(arguments[2]);
	glBindBuffer(target, buffer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::bindFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLuint framebuffer = Binding::valueToInt(arguments[2]);
	glBindFramebuffer(target, framebuffer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::bindRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLuint renderbuffer = Binding::valueToInt(arguments[2]);
	glBindRenderbuffer(target, renderbuffer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::bindTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLuint texture = Binding::valueToInt(arguments[2]);
	glBindTexture(target, texture);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::blendColor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLclampf red = (float)Binding::valueToDouble(arguments[1]);
	GLclampf green = (float)Binding::valueToDouble(arguments[2]);
	GLclampf blue = (float)Binding::valueToDouble(arguments[3]);
	GLclampf alpha = (float)Binding::valueToDouble(arguments[4]);
	glBlendColor(red, green, blue, alpha);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::blendEquation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum mode = Binding::valueToInt(arguments[1]);
	glBlendEquation(mode);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::blendEquationSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum modeRGB = Binding::valueToInt(arguments[1]);
	GLenum modeAlpha = Binding::valueToInt(arguments[2]);
	glBlendEquationSeparate(modeRGB, modeAlpha);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::blendFunc(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum sfactor = Binding::valueToInt(arguments[1]);
	GLenum dfactor = Binding::valueToInt(arguments[2]);
	glBlendFunc(sfactor, dfactor);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::blendFuncSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum srcRGB = Binding::valueToInt(arguments[1]);
	GLenum dstRGB = Binding::valueToInt(arguments[2]);
	GLenum srcAlpha = Binding::valueToInt(arguments[3]);
	GLenum dstAlpha = Binding::valueToInt(arguments[4]);
	glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::bufferData(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLint size = Binding::valueToInt(arguments[2]);
	// TODO: int size or array<float> data
	GLenum usage = Binding::valueToInt(arguments[3]);
	glBufferData(target, size, NULL, usage);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::bufferSubData(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLint offset = Binding::valueToInt(arguments[2]);
	std::vector<int> data = Binding::valueToIntVector(arguments[3]);
	glBufferSubData(target, offset, data.size(), &data[0]);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::checkFramebufferStatus(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	return Binding::intToValue(glCheckFramebufferStatus(target));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::clear(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLbitfield mask = Binding::valueToInt(arguments[1]);
	glClear(mask);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::clearColor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLclampf red = (float)Binding::valueToDouble(arguments[1]);
	GLclampf green = (float)Binding::valueToDouble(arguments[2]);
	GLclampf blue = (float)Binding::valueToDouble(arguments[3]);
	GLclampf alpha = (float)Binding::valueToDouble(arguments[4]);
	glClearColor(red, green, blue, alpha);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::clearDepth(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLfloat depth = Binding::valueToDouble(arguments[1]);
	glClearDepthf(depth);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::clearStencil(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLint s = Binding::valueToInt(arguments[1]);
	glClearStencil(s);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::colorMask(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLboolean red = Binding::valueToBool(arguments[1]);
	GLboolean green = Binding::valueToBool(arguments[2]);
	GLboolean blue = Binding::valueToBool(arguments[3]);
	GLboolean alpha = Binding::valueToBool(arguments[4]);
	glColorMask(red, green, blue, alpha);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::compileShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint shader = Binding::valueToInt(arguments[1]);
	glCompileShader(shader);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::createBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index;
	glGenBuffers(1, &index);
	return Binding::intToValue(index);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::createFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index;
	glGenFramebuffers(1, &index);
	return Binding::intToValue(index);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::createProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	return Binding::intToValue(glCreateProgram());
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::createRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index;
	glGenRenderbuffers(1, &index);
	return Binding::intToValue(index);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::createShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint type = Binding::valueToInt(arguments[1]);
	return Binding::intToValue(glCreateShader(type));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::createTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index;
	glGenTextures(1, &index);
	return Binding::intToValue(index);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::cullFace(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum mode = Binding::valueToInt(arguments[1]);
	glCullFace(mode);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::deleteBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint buffer = Binding::valueToInt(arguments[1]);
	glDeleteBuffers(1, &buffer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::deleteFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint framebuffer = Binding::valueToInt(arguments[1]);
	glDeleteFramebuffers(1, &framebuffer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::deleteProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	glDeleteProgram(program);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::deleteRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint renderbuffer = Binding::valueToInt(arguments[1]);
	glDeleteRenderbuffers(1, &renderbuffer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::deleteShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint shader = Binding::valueToInt(arguments[1]);
	glDeleteShader(shader);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::deleteTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint texture = Binding::valueToInt(arguments[1]);
	glDeleteTextures(1, &texture);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::depthFunc(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum func = Binding::valueToInt(arguments[1]);
	glDepthFunc(func);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::depthMask(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLboolean flag = Binding::valueToBool(arguments[1]);
	glDepthMask(flag);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::depthRange(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLfloat zNear = (float)Binding::valueToDouble(arguments[1]);
	GLfloat zFar = (float)Binding::valueToDouble(arguments[2]);
	glDepthRangef(zNear, zFar);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::detachShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	GLuint shader = Binding::valueToInt(arguments[2]);
	glDetachShader(program, shader);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::disable(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum cap = Binding::valueToInt(arguments[1]);
	glDisable(cap);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::disableVertexAttribArray(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index = Binding::valueToInt(arguments[1]);
	glDisableVertexAttribArray(index);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::drawArrays(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum mode = Binding::valueToInt(arguments[1]);
	GLint first = Binding::valueToInt(arguments[2]);
	GLsizei count = Binding::valueToInt(arguments[3]);
	glDrawArrays(mode, first, count);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::drawElements(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum mode = Binding::valueToInt(arguments[1]);
	GLsizei count = Binding::valueToInt(arguments[2]);
	GLenum type = Binding::valueToInt(arguments[3]);
	GLint offset = Binding::valueToInt(arguments[4]);
	glDrawElements(mode, count, type, BUFFER_OFFSET(offset));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::drawElementsInstancedANGLE(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum mode = Binding::valueToInt(arguments[1]);
	GLsizei count = Binding::valueToInt(arguments[2]);
	GLenum type = Binding::valueToInt(arguments[3]);
	GLint offset = Binding::valueToInt(arguments[4]);
	GLsizei primcount = Binding::valueToInt(arguments[5]);
	glDrawElementsInstancedANGLE(mode, count, type, BUFFER_OFFSET(offset), primcount);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::enable(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum cap = Binding::valueToInt(arguments[1]);
	glEnable(cap);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::enableVertexAttribArray(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index = Binding::valueToInt(arguments[1]);
	glEnableVertexAttribArray(index);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::finish(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	glFinish();
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::flush(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	glFlush();
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::framebufferRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLenum attachment = Binding::valueToInt(arguments[2]);
	GLenum renderbuffertarget = Binding::valueToInt(arguments[3]);
	GLuint renderbuffer = Binding::valueToInt(arguments[4]);
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::framebufferTexture2D(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLenum attachment = Binding::valueToInt(arguments[2]);
	GLenum textarget = Binding::valueToInt(arguments[3]);
	GLuint texture = Binding::valueToInt(arguments[4]);
	GLint level = Binding::valueToInt(arguments[5]);
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::frontFace(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum mode = Binding::valueToInt(arguments[1]);
	glFrontFace(mode);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::generateMipmap(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	glGenerateMipmap(target);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getActiveAttrib(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	GLuint index = Binding::valueToInt(arguments[2]);
	
	GLint buffsize;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &buffsize);

	GLchar *namebuffer = (GLchar *)malloc(buffsize);
	GLsizei length;
	GLint size;
	GLenum type;
	glGetActiveAttrib(program, index, buffsize, &length, &size, &type, namebuffer);

	const wchar_t * name = StringFromAscIIChars(namebuffer);

	free(namebuffer);

	return nullptr;
	// TODO fix me
	//return new WebGLActiveInfo(type, name, size);
}


JsValueRef CALLBACK CanvasRenderingContextHolographic::getActiveUniform(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	GLuint index = Binding::valueToInt(arguments[2]);
	
	GLint buffsize;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &buffsize);

	GLchar *namebuffer = (GLchar *)malloc(buffsize);
	GLsizei length;
	GLint size;
	GLenum type;
	glGetActiveUniform(program, index, buffsize, &length, &size, &type, namebuffer);

	const wchar_t * name = StringFromAscIIChars(namebuffer);

	free(namebuffer);

	return nullptr;
	// TODO fix me
	//return new WebGLActiveInfo(type, name, size);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getAttribLocation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	const wchar_t * name = Binding::valueToString(arguments[2]);
	
	return Binding::intToValue(glGetAttribLocation(program, AscIICharsFromString(name)));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getAttachedShaders(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);

	GLint count;
	glGetProgramiv(program, GL_ATTACHED_SHADERS, &count);

	GLuint *list = (GLuint *)malloc(count * sizeof(GLuint));
	glGetAttachedShaders(program, count, NULL, list);

	std::vector<int> shaders;

	for (int i = 0; i < count; i++) {
		shaders.push_back(list[i]);
	}

	free(list);

	return Binding::intVectorToValue(shaders);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getBufferParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLenum pname = Binding::valueToInt(arguments[2]);

	GLint param;
	glGetBufferParameteriv(target, pname, &param);
	return Binding::intToValue(param);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getContextAttributes(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	// TODO fix me
	//return contextAttributes;
	return nullptr;
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getError(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	return Binding::intToValue(glGetError());
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getExtension(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	return nullptr;
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum pname = Binding::valueToInt(arguments[1]);
	
	int intbuffer[4];
	switch (pname) {
	case GL_COMPRESSED_TEXTURE_FORMATS:
		std::vector<float> floatData;
		return Binding::floatVectorToValue(floatData);
	case GL_ALIASED_LINE_WIDTH_RANGE:
	case GL_ALIASED_POINT_SIZE_RANGE:
	case GL_DEPTH_RANGE:
		std::vector<float> floatData;
		glGetFloatv(pname, floatData.data);
		return Binding::floatVectorToValue(floatData);
	case GL_BLEND_COLOR:
	case GL_COLOR_CLEAR_VALUE:
		std::vector<float> floatData;
		glGetFloatv(pname, floatData.data);
		return Binding::floatVectorToValue(floatData);
	case GL_MAX_VIEWPORT_DIMS:
		std::vector<int> intData;
		glGetIntegerv(pname, intData.data);
		return Binding::intVectorToValue(intData);
	case GL_SCISSOR_BOX:
	case GL_VIEWPORT:
		std::vector<int> intData;
		glGetIntegerv(pname, intData.data);
		return Binding::intVectorToValue(intData);
	case GL_COLOR_WRITEMASK:
		std::vector<bool> mask;
		glGetIntegerv(pname, intbuffer);
		for (int i = 0; i < 4; i++) {
			mask.push_back(intbuffer[i]);
		}
		return Binding::boolVectorToValue(mask);
	case GL_ARRAY_BUFFER_BINDING:
	case GL_ELEMENT_ARRAY_BUFFER_BINDING:
		glGetIntegerv(pname, intbuffer);
		return Binding::intToValue(intbuffer[0]);
	case GL_CURRENT_PROGRAM:
		glGetIntegerv(pname, intbuffer);
		return Binding::intToValue(intbuffer[0]);
	case GL_FRAMEBUFFER_BINDING:
		glGetIntegerv(pname, intbuffer);
		return Binding::intToValue(intbuffer[0]);
	case GL_RENDERBUFFER_BINDING:
		glGetIntegerv(pname, intbuffer);
		return Binding::intToValue(intbuffer[0]);
	case GL_TEXTURE_BINDING_2D:
	case GL_TEXTURE_BINDING_CUBE_MAP:
		glGetIntegerv(pname, intbuffer);
		return Binding::intToValue(intbuffer[0]);
	case GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS:
		return Binding::intToValue(CANVAS_MAX_TEXTURE_UNITS);
		// TODO: fix these!
	//case GL_UNPACK_FLIP_Y_WEBGL:
	//	return Binding::boolToValue(unpackFlipY);
	//case GL_UNPACK_PREMULTIPLY_ALPHA_WEBGL:
	//	return Binding::boolToValue(premultiplyAlpha);
	case GL_UNPACK_COLORSPACE_CONVERSION_WEBGL:
		return false;
	case GL_RENDERER:
	case GL_SHADING_LANGUAGE_VERSION:
	case GL_VENDOR:
	case GL_VERSION:
		const wchar_t * str = StringFromAscIIChars((char *)glGetString(pname));
		return Binding::stringToValue(str, wcslen(str));
	}
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getProgramInfoLog(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	
	GLint size;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &size);

	GLchar *message = (GLchar *)malloc(size);

	glGetProgramInfoLog(program, size, &size, message);

	const wchar_t * str = StringFromAscIIChars(message);

	free(message);

	return Binding::stringToValue(str, wcslen(str));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getProgramParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	GLenum pname = Binding::valueToInt(arguments[2]);
	GLint value;
	glGetProgramiv(program, pname, &value);
	return Binding::intToValue(value);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getShaderInfoLog(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint shader = Binding::valueToInt(arguments[1]);
	
	GLint size;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);

	GLchar *message = (GLchar *)malloc(size);

	glGetShaderInfoLog(shader, size, &size, message);

	const wchar_t * str = StringFromAscIIChars(message);

	free(message);

	return Binding::stringToValue(str, wcslen(str));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getShaderParameter(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint shader = Binding::valueToInt(arguments[1]);
	GLenum pname = Binding::valueToInt(arguments[2]);

	GLint value;
	glGetShaderiv(shader, pname, &value);

	if (pname == GL_DELETE_STATUS || pname == GL_COMPILE_STATUS) {
		return Binding::intToValue(value);
	}
	else { // GL_SHADER_TYPE || GL_INFO_LOG_LENGTH || GL_SHADER_SOURCE_LENGTH
		return Binding::intToValue(value);
	}
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getShaderSource(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint shader = Binding::valueToInt(arguments[1]);
	
	GLint size;
	glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &size);

	GLchar *source = (GLchar *)malloc(size);
	glGetShaderSource(shader, size, &size, source);

	const wchar_t * str = StringFromAscIIChars(source);

	free(source);

	return Binding::stringToValue(str, wcslen(str));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getSupportedExtensions(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	std::vector<string> supportedExtensions;
	return Binding::stringVectorToValue(supportedExtensions);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getUniformLocation(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	const wchar_t * name = Binding::valueToString(arguments[2]);
	return Binding::intToValue(glGetUniformLocation(program, AscIICharsFromString(name)));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getVertexAttrib(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index = Binding::valueToInt(arguments[1]);
	GLenum pname = Binding::valueToInt(arguments[2]);

	if (pname == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING) {
		GLint buffer;
		glGetVertexAttribiv(index, pname, &buffer);
		return Binding::intToValue(buffer);
	}
	else if (pname == GL_CURRENT_VERTEX_ATTRIB) {
		vector<int> vec;
		glGetVertexAttribiv(index, pname, vec.data);
		return Binding::intVectorToValue(vec);
	}
	else {
		GLint value;
		glGetVertexAttribiv(index, pname, &value);
		return Binding::intToValue(value);
	}
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::getVertexAttribOffset(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint index = Binding::valueToInt(arguments[1]);
	GLenum pname = Binding::valueToInt(arguments[2]);

	GLvoid *pointer;
	glGetVertexAttribPointerv(index, pname, &pointer);
	return Binding::intToValue((GLint)pointer);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::hint(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum target = Binding::valueToInt(arguments[1]);
	GLenum mode = Binding::valueToInt(arguments[2]);
	glHint(target, mode);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isBuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint buffer = Binding::valueToInt(arguments[1]);
	return Binding::boolToValue(glIsBuffer(buffer));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isContextLost(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	return Binding::boolToValue(false);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isEnabled(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum cap = Binding::valueToInt(arguments[1]);
	return Binding::boolToValue(glIsEnabled(cap));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isFramebuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint framebuffer = Binding::valueToInt(arguments[1]);
	return Binding::boolToValue(glIsFramebuffer(framebuffer));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	return Binding::boolToValue(glIsProgram(program));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isRenderbuffer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint renderbuffer = Binding::valueToInt(arguments[1]);
	return Binding::boolToValue(glIsRenderbuffer(renderbuffer));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isShader(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint shader = Binding::valueToInt(arguments[1]);
	return Binding::boolToValue(glIsShader(shader));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::isTexture(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint texture = Binding::valueToInt(arguments[1]);
	return Binding::boolToValue(glIsTexture(texture));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::lineWidth(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLfloat width = Binding::valueToFloat(arguments[1]);
	glLineWidth(width);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::linkProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLuint program = Binding::valueToInt(arguments[1]);
	glLinkProgram(program);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::pixelStorei(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {
	GLenum pname = Binding::valueToInt(arguments[1]);
	GLint param = Binding::valueToInt(arguments[2]);
	glPixelStorei(pname, param);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::polygonOffset(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glPolygonOffset(factor, units);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::renderbufferStorage(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glRenderbufferStorage(target, internalformat, width, height);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::sampleCoverage(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glSampleCoverage(value, invert);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::scissor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glScissor(x, y, width, height);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::shaderSource(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	std::wstring sourceW(source->Begin());
	std::string sourceA(sourceW.begin(), sourceW.end());
	const char* sourceChars = sourceA.c_str();
	glShaderSource(shader, 1, &sourceChars, nullptr);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::stencilFunc(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glStencilFunc(func, ref, mask);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::stencilFuncSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glStencilFuncSeparate(face, func, ref, mask);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::stencilMask(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glStencilMask(mask);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::stencilMaskSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glStencilMaskSeparate(face, mask);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::stencilOp(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glStencilOp(fail, zfail, zpass);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::stencilOpSeparate(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glStencilOpSeparate(face, fail, zfail, zpass);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::texParameterf(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glTexParameterf(target, pname, param);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::texParameteri(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glTexParameteri(target, pname, param);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::useProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glUseProgram(program);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::uniformMatrix4fv(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glUniformMatrix4fv(location, value->Length, transpose, value->Data);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::validateProgram(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glValidateProgram(program);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::vertexAttrib1f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glVertexAttrib1f(indx, x);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::vertexAttrib2f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glVertexAttrib2f(indx, x, y);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::vertexAttrib3f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glVertexAttrib3f(indx, x, y, z);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::vertexAttrib4f(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glVertexAttrib4f(indx, x, y, z, w);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::vertexAttribDivisorANGLE(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glVertexAttribDivisorANGLE(index, divisor);
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::vertexAttribPointer(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glVertexAttribPointer(indx, size, type, normalized, stride, BUFFER_OFFSET(offset));
}

JsValueRef CALLBACK CanvasRenderingContextHolographic::viewport(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState) {

	glViewport(x, y, width, height);
}

const char* CanvasRenderingContextHolographic::AscIICharsFromString(const wchar_t * str) {
	std::wstring strW(str);
	std::string strA(strW.begin(), strW.end());
	return strA.c_str();
}

const wchar_t * CanvasRenderingContextHolographic::StringFromAscIIChars(char* chars) {
	size_t newsize = strlen(chars) + 1;
	wchar_t * wcstring = new wchar_t[newsize];
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wcstring, newsize, chars, _TRUNCATE);
	return wcstring;
}
