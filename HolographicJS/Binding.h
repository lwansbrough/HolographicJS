#pragma once

#include <Engine.h>

class Binding
{
public:
	static Engine* engine;
	static void bind();
	static void setCallback(JsValueRef object, const wchar_t *propertyName, JsNativeFunction callback, void *callbackState);
	static void setProperty(JsValueRef object, const wchar_t *propertyName, JsValueRef property);
	static JsValueRef getProperty(JsValueRef object, const wchar_t *propertyName);
	static void Binding::projectNativeClassToGlobal(const wchar_t *className, JsNativeFunction constructor, JsValueRef &prototype, map<const wchar_t *, JsNativeFunction> members, map<const wchar_t *, JsValueRef> properties);
	static void Binding::projectNativeClassToObject(JsValueRef object, const wchar_t *className, JsNativeFunction constructor, JsValueRef &prototype, map<const wchar_t *, JsNativeFunction> members, map<const wchar_t *, JsValueRef> properties);

	static bool Binding::valueToBool(JsValueRef value);
	static double Binding::valueToDouble(JsValueRef value);
	static float Binding::valueToFloat(JsValueRef value);
	static int Binding::valueToInt(JsValueRef value);
	static std::vector<int> Binding::valueToIntVector(JsValueRef value);
	static const wchar_t * valueToString(JsValueRef value);
	static JsValueRef Binding::boolToValue(bool val);
	static JsValueRef Binding::boolVectorToValue(std::vector<bool> vec);
	static JsValueRef Binding::doubleVectorToValue(std::vector<double> vec);
	static JsValueRef Binding::floatVectorToValue(std::vector<float> vec);
	static JsValueRef Binding::intToValue(int val);
	static JsValueRef Binding::intVectorToValue(std::vector<int> vec);
	static JsValueRef Binding::stringToValue(const wchar_t * str, size_t strLen);
	static JsValueRef Binding::stringVectorToValue(std::vector<string> vec);
private:
	static JsValueRef CALLBACK JSSetTimeout(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
	static JsValueRef CALLBACK JSSetInterval(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
};


