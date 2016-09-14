#include "pch.h"
#include "Window.h"

using namespace HolographicJS;

Window::Window(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame)
{
	this->holographicSpace = holographicSpace;
	this->stationaryReferenceFrame = stationaryReferenceFrame;
}

CanvasRenderingContextHolographic^ Window::CreateCanvasRenderingContextHolographic() {
	return ref new CanvasRenderingContextHolographic(nullptr, this->holographicSpace, this->stationaryReferenceFrame);
}

CanvasRenderingContextHolographic^ Window::CreateCanvasRenderingContextHolographic(IMapView<String^, Boolean>^ contextAttributes) {
	return ref new CanvasRenderingContextHolographic(contextAttributes, this->holographicSpace, this->stationaryReferenceFrame);
}
