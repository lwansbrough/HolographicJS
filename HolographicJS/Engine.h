#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>
#include <string>
#include "Console.h"
#include "Window.h"

using namespace std;
using namespace Platform;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

namespace HolographicJS
{
    public ref class Engine sealed
    {
    public:
		property HolographicSpace^ holographicSpace;
		property SpatialStationaryFrameOfReference^ stationaryReferenceFrame;
		property Window^ window;

        Engine(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
		String^ RunScript(String^ script);
	private:
		unsigned currentSourceContext;
		JsContextRef context;
		JsRuntimeHandle runtime;

		void CreateContext();
		void ProjectToGlobal(String^ name, Object^ object);
		void ThrowException(wstring errorString);
    };
}
