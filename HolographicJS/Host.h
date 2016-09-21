#pragma once
#include "Engine.h"

using namespace std;
using namespace Platform;

namespace HolographicJS {
	public ref class Host sealed
	{
	public:
		Host(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);

		String^ RunScript(String^ fileName);
	private:
		Engine* engine;
		String^ LoadScript(String^ fileName);
	};
}
