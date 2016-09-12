#pragma once
#include "Engine.h"

using namespace std;
using namespace Platform;

namespace HolographicJS {
	public ref class Host sealed
	{
	public:
		property Engine^ engine;

		Host(HolographicSpace^ holographicSpace, SpatialStationaryFrameOfReference^ stationaryReferenceFrame);

		String^ RunScript(String^ fileName);
	private:
		String^ LoadScript(String^ fileName);
	};
}
