#pragma once
#include "CanvasRenderingContextHolographic.h"

using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

namespace HolographicJS
{
	public ref class Window sealed
	{
	public:
		Window(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
		CanvasRenderingContextHolographic^ CreateCanvasRenderingContextHolographic();
	private:
		HolographicSpace^ holographicSpace;
		SpatialStationaryFrameOfReference^ stationaryReferenceFrame;
	};
}
