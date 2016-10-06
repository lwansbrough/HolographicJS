#pragma once
#include "Engine.h"

using namespace std;
using namespace Platform;
using namespace Windows::UI::Core;

namespace HolographicJS {
	public ref class Host sealed
	{
	public:
		Host(CoreWindow^ coreWindow);

		void RunScript(String^ fileName);
		void ProcessNextTask();
	private:
		Engine* engine;
		String^ LoadScript(String^ fileName);
	};
}
