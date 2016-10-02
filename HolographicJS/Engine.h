#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>
#include <queue>
#include <string>
#include "Console.h"
#include "Task.h"

using namespace std;
using namespace Platform;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

class Engine
{
public:
	HolographicSpace^ holographicSpace;
	SpatialStationaryFrameOfReference^ stationaryReferenceFrame;

	Engine(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
	String^ runScript(const wchar_t * script);
	std::queue<Task*> taskQueue;
private:
	unsigned currentSourceContext;
	JsContextRef context;
	JsRuntimeHandle runtime;

	void CreateContext();
	static void CALLBACK Engine::PromiseContinuationCallback(JsValueRef task, void *callbackState);
};