#pragma once

#include "CanvasRenderingContextHolographic.h"
#include "Window.h"

namespace HolographicJS
{
	public ref class Document sealed
	{
	public:
		property Window^ window;

		Document();
		
	};
}
