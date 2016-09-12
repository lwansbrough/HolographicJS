#include "pch.h"
#include "Window.h"

using namespace HolographicJS;

Window::Window(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame)
{
	this->holographicSpace = holographicSpace;
	this->stationaryReferenceFrame = stationaryReferenceFrame;
}

CanvasRenderingContextHolographic^ Window::CreateCanvasRenderingContextHolographic() {
	return ref new CanvasRenderingContextHolographic(this->holographicSpace, this->stationaryReferenceFrame);
}
