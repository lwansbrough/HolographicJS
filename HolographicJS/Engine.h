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
using namespace Windows::UI::Core;

class Engine
{
public:
	CoreWindow^ coreWindow;

	Engine(CoreWindow^ coreWindow);
	void runScript(const wchar_t * script);
	void processNextTask();
	std::queue<Task*> taskQueue;
	HolographicSpace^ holographicSpace;
	SpatialStationaryFrameOfReference^ stationaryReferenceFrame;
private:
	unsigned currentSourceContext;
	JsContextRef context;
	JsRuntimeHandle runtime;
	EGLDisplay eglDisplay;
	EGLSurface eglSurface;
	EGLContext eglContext;

	void createContext();
	void Engine::createEGLContext();
	static void CALLBACK Engine::promiseContinuationCallback(JsValueRef task, void *callbackState);
	static void OnCameraAdded(Windows::Graphics::Holographic::HolographicSpace ^sender, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs ^args);
};