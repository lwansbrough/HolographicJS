#include "pch.h"
#include "Console.h"

using namespace HolographicJS;

Console::Console()
{
}

void Console::Log(String^ data) {
	OutputDebugString(L"\r\n");
	OutputDebugString(data->Data());
}
