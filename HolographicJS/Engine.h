#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>
#include <queue>
#include <string>
#include "Console.h"
#include "Task.h"
#include "Window.h"

class Engine
{
public:
	HolographicSpace^ holographicSpace;
	SpatialStationaryFrameOfReference^ stationaryReferenceFrame;

	Engine(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
	String^ runScript(const wchar_t * script);
	queue<Task*> taskQueue;
private:
	unsigned currentSourceContext;
	JsContextRef context;
	JsRuntimeHandle runtime;

	void CreateContext();
	void ThrowException(wstring errorString);
};