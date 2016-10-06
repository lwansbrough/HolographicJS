#include "pch.h"
#include "Host.h"

using namespace HolographicJS;

Host::Host(CoreWindow^ coreWindow)
{
	engine = new Engine(coreWindow);
	engine->runScript(
		L"const console = new Console();"
		L"console.log('   __ __     __                        __   _        ______');"
		L"console.log('  / // /__  / /__  ___ ________ ____  / /  (_)_____ / / __/');"
		L"console.log(' / _  / _ \\\\/ / _ \\\\/ _ `/ __/ _ `/ _ \\\\/ _ \\\\/ / __/ // /\\\\ \\\\  ');"
		L"console.log('/_//_/\\\\___/_/\\\\___/\\\\_, /_/  \\\\_,_/ .__/_//_/_/\\\\__/\\\\___/___/  ');"
		L"console.log('                 /___/        /_/                          ');"
		L"console.log('\\n\\n');"
	);
}

void Host::RunScript(String^ fileName)
{
	String^ script = LoadScript(fileName);
	engine->runScript(script->Data());
}

void Host::ProcessNextTask() {
	engine->processNextTask();
}

String^ Host::LoadScript(String^ fileName) {
	FILE *file;

	if (_wfopen_s(&file, fileName->Data(), L"rb")) {
		throw ref new Exception(-1, L"Unable to open script file");
	}

	unsigned int current = ftell(file);
	fseek(file, 0, SEEK_END);
	unsigned int end = ftell(file);
	fseek(file, current, SEEK_SET);
	unsigned int lengthBytes = end - current;
	char *rawBytes = (char *)calloc(lengthBytes + 1, sizeof(char));

	if (rawBytes == nullptr) {
		throw ref new Exception(-1, L"Fatal error reading script file.");
	}

	fread((void *)rawBytes, sizeof(char), lengthBytes, file);

	wchar_t *contents = (wchar_t *)calloc(lengthBytes + 1, sizeof(wchar_t));

	if (contents == nullptr) {
		free(rawBytes);
		throw ref new Exception(-1, L"Fatal error reading script file.");
	}

	if (MultiByteToWideChar(CP_UTF8, 0, rawBytes, lengthBytes + 1, contents, lengthBytes + 1) == 0) {
		free(rawBytes);
		free(contents);
		throw ref new Exception(-1, L"Fatal error reading script file.");
	}

	String^ result = ref new String(contents);
	free(rawBytes);
	free(contents);

	return result;
}