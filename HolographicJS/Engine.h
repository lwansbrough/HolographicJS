#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>
#include <string>
#include "Console.h"
#include "Window.h"

class Engine
{
public:
	HolographicSpace^ holographicSpace;
	SpatialStationaryFrameOfReference^ stationaryReferenceFrame;

	Engine(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
	String^ runScript(const wchar_t * script);
private:
	unsigned currentSourceContext;
	JsContextRef context;
	JsRuntimeHandle runtime;

	void CreateContext();
	void ThrowException(wstring errorString);

	JsValueRef CALLBACK JSRequestAnimationFrame(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState);
};