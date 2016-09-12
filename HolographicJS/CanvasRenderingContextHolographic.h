#pragma once

using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;

namespace HolographicJS
{
	public ref class CanvasRenderingContextHolographic sealed
	{
	public:
		CanvasRenderingContextHolographic(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);
	private:
		EGLContext context;
		EGLDisplay display;
		EGLSurface surface;
		HolographicSpace^ holographicSpace;
		SpatialStationaryFrameOfReference^ stationaryReferenceFrame;

		void CreateContext();
	};
}

