#pragma once
#define USE_EDGEMODE_JSRT
#include <jsrt.h>
#include <queue>
#include "CanvasRenderingContextHolographic.h"

using namespace std;
using namespace Platform;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

namespace HolographicJS
{
	public ref class Window sealed
	{
	public:
		Window(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
		CanvasRenderingContextHolographic^ CreateCanvasRenderingContextHolographic();
		CanvasRenderingContextHolographic^ CreateCanvasRenderingContextHolographic(IMapView<String^, Boolean>^ contextAttributes);
	private:
		HolographicSpace^ holographicSpace;
		SpatialStationaryFrameOfReference^ stationaryReferenceFrame;
	};
}
