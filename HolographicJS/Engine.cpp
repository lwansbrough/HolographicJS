#include "pch.h"
#include "Engine.h"
#include "CanvasRenderingContextHolographic.h"
#include "Console.h"
#include "Binding.h"
#include <string>
#include <iostream>
#include <sstream>

Engine::Engine(CoreWindow^ coreWindow) {
	this->coreWindow = coreWindow;

	// Create a holographic space for the core window for the current view.
	this->holographicSpace = HolographicSpace::CreateForCoreWindow(coreWindow);

	// Get the default SpatialLocator.
	SpatialLocator^ locator = SpatialLocator::GetDefault();

	// Create a stationary frame of reference.
	this->stationaryReferenceFrame = locator->CreateStationaryFrameOfReferenceAtCurrentLocation();

	createEGLContext();
	createContext();
}

void Engine::createContext() {

	currentSourceContext = 0;

	if (JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &runtime) != JsNoError)
		throw ref new Exception(-1, L"Failed to create runtime.");

	if (JsCreateContext(runtime, &context) != JsNoError)
		throw ref new Exception(-1, L"Failed to create execution context.");

	if (JsSetCurrentContext(context) != JsNoError)
		throw ref new Exception(-1, L"Failed to set execution context.");

	if (JsSetPromiseContinuationCallback(promiseContinuationCallback, &taskQueue) != JsNoError)
		throw ref new Exception(-1, L"Failed to set up promise continuations.");

	CanvasRenderingContextHolographic::engine = this;
	CanvasRenderingContextHolographic::eglContext = eglContext;
	CanvasRenderingContextHolographic::eglDisplay = eglDisplay;
	CanvasRenderingContextHolographic::eglSurface = eglSurface;

	Binding::engine = this;
	Binding::bind();

	Binding::projectNativeClassToGlobal(
		L"Console",
		Console::constructor,
		Console::prototype,
		Console::getMembers(),
		Console::getProperties()
	);

	Binding::projectNativeClassToGlobal(
		L"CanvasRenderingContextHolographic",
		CanvasRenderingContextHolographic::constructor,
		CanvasRenderingContextHolographic::prototype,
		CanvasRenderingContextHolographic::getMembers(),
		CanvasRenderingContextHolographic::getProperties()
	);

	JsSetCurrentContext(JS_INVALID_REFERENCE);
}


void Engine::createEGLContext() {
	const EGLint configAttributes[] =
	{
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_ALPHA_SIZE, 8,
		EGL_DEPTH_SIZE, 8,
		EGL_STENCIL_SIZE, 8,
		EGL_NONE
	};

	const EGLint contextAttributes[] =
	{
		EGL_CONTEXT_CLIENT_VERSION, 2,
		EGL_NONE
	};

	const EGLint surfaceAttributes[] =
	{
		// EGL_ANGLE_SURFACE_RENDER_TO_BACK_BUFFER is part of the same optimization as EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER (see above).
		// If you have compilation issues with it then please update your Visual Studio templates.
		EGL_ANGLE_SURFACE_RENDER_TO_BACK_BUFFER, EGL_TRUE,
		EGL_NONE
	};

	const EGLint defaultDisplayAttributes[] =
	{
		// These are the default display attributes, used to request ANGLE's D3D11 renderer.
		// eglInitialize will only succeed with these attributes if the hardware supports D3D11 Feature Level 10_0+.
		EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,

		// EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER is an optimization that can have large performance benefits on mobile devices.
		// Its syntax is subject to change, though. Please update your Visual Studio templates if you experience compilation issues with it.
		EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,

		// EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE is an option that enables ANGLE to automatically call 
		// the IDXGIDevice3::Trim method on behalf of the application when it gets suspended. 
		// Calling IDXGIDevice3::Trim when an application is suspended is a Windows Store application certification requirement.
		EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
		EGL_NONE,
	};

	const EGLint fl9_3DisplayAttributes[] =
	{
		// These can be used to request ANGLE's D3D11 renderer, with D3D11 Feature Level 9_3.
		// These attributes are used if the call to eglInitialize fails with the default display attributes.
		EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
		EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE, 9,
		EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE, 3,
		EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,
		EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
		EGL_NONE,
	};

	const EGLint warpDisplayAttributes[] =
	{
		// These attributes can be used to request D3D11 WARP.
		// They are used if eglInitialize fails with both the default display attributes and the 9_3 display attributes.
		EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
		EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_DEVICE_TYPE_WARP_ANGLE,
		EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,
		EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
		EGL_NONE,
	};

	EGLConfig config = NULL;

	// eglGetPlatformDisplayEXT is an alternative to eglGetDisplay. It allows us to pass in display attributes, used to configure D3D11.
	PFNEGLGETPLATFORMDISPLAYEXTPROC eglGetPlatformDisplayEXT = reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(eglGetProcAddress("eglGetPlatformDisplayEXT"));
	if (!eglGetPlatformDisplayEXT)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to get function eglGetPlatformDisplayEXT");
	}

	//
	// To initialize the display, we make three sets of calls to eglGetPlatformDisplayEXT and eglInitialize, with varying 
	// parameters passed to eglGetPlatformDisplayEXT:
	// 1) The first calls uses "defaultDisplayAttributes" as a parameter. This corresponds to D3D11 Feature Level 10_0+.
	// 2) If eglInitialize fails for step 1 (e.g. because 10_0+ isn't supported by the default GPU), then we try again 
	//    using "fl9_3DisplayAttributes". This corresponds to D3D11 Feature Level 9_3.
	// 3) If eglInitialize fails for step 2 (e.g. because 9_3+ isn't supported by the default GPU), then we try again 
	//    using "warpDisplayAttributes".  This corresponds to D3D11 Feature Level 11_0 on WARP, a D3D11 software rasterizer.
	//

	// This tries to initialize EGL to D3D11 Feature Level 10_0+. See above comment for details.
	eglDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, defaultDisplayAttributes);
	if (eglDisplay == EGL_NO_DISPLAY)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to get EGL display");
	}

	if (eglInitialize(eglDisplay, NULL, NULL) == EGL_FALSE)
	{
		// This tries to initialize EGL to D3D11 Feature Level 9_3, if 10_0+ is unavailable (e.g. on some mobile devices).
		eglDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, fl9_3DisplayAttributes);
		if (eglDisplay == EGL_NO_DISPLAY)
		{
			throw Exception::CreateException(E_FAIL, L"Failed to get EGL display");
		}

		if (eglInitialize(eglDisplay, NULL, NULL) == EGL_FALSE)
		{
			// This initializes EGL to D3D11 Feature Level 11_0 on WARP, if 9_3+ is unavailable on the default GPU.
			eglDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, warpDisplayAttributes);
			if (eglDisplay == EGL_NO_DISPLAY)
			{
				throw Exception::CreateException(E_FAIL, L"Failed to get EGL display");
			}

			if (eglInitialize(eglDisplay, NULL, NULL) == EGL_FALSE)
			{
				// If all of the calls to eglInitialize returned EGL_FALSE then an error has occurred.
				throw Exception::CreateException(E_FAIL, L"Failed to initialize EGL");
			}
		}
	}

	EGLint numConfigs = 0;
	if ((eglChooseConfig(eglDisplay, configAttributes, &config, 1, &numConfigs) == EGL_FALSE) || (numConfigs == 0))
	{
		throw Exception::CreateException(E_FAIL, L"Failed to choose first EGLConfig");
	}

	// Create a PropertySet and initialize with the EGLNativeWindowType.
	PropertySet^ surfaceCreationProperties = ref new PropertySet();
	surfaceCreationProperties->Insert(ref new String(EGLNativeWindowTypeProperty), holographicSpace);
	if (stationaryReferenceFrame != nullptr)
	{
		surfaceCreationProperties->Insert(ref new String(EGLBaseCoordinateSystemProperty), stationaryReferenceFrame);
	}

	// You can configure the surface to render at a lower resolution and be scaled up to
	// the full window size. This scaling is often free on mobile hardware.
	//
	// One way to configure the SwapChainPanel is to specify precisely which resolution it should render at.
	// Size customRenderSurfaceSize = Size(800, 600);
	// surfaceCreationProperties->Insert(ref new String(EGLRenderSurfaceSizeProperty), PropertyValue::CreateSize(customRenderSurfaceSize));
	//
	// Another way is to tell the SwapChainPanel to render at a certain scale factor compared to its size.
	// e.g. if the SwapChainPanel is 1920x1280 then setting a factor of 0.5f will make the app render at 960x640
	// float customResolutionScale = 0.5f;
	// surfaceCreationProperties->Insert(ref new String(EGLRenderResolutionScaleProperty), PropertyValue::CreateSingle(customResolutionScale));

	eglSurface = eglCreateWindowSurface(eglDisplay, config, reinterpret_cast<IInspectable*>(surfaceCreationProperties), surfaceAttributes);
	if (eglSurface == EGL_NO_SURFACE)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to create EGL fullscreen surface");
	}

	eglContext = eglCreateContext(eglDisplay, config, EGL_NO_CONTEXT, contextAttributes);
	if (eglContext == EGL_NO_CONTEXT)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to create EGL context");
	}

	if (eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext) == EGL_FALSE)
	{
		throw Exception::CreateException(E_FAIL, L"Failed to make fullscreen EGLSurface current");
	}
}

void Engine::runScript(const wchar_t * script) {
	JsValueRef result;

	if (wcslen(script) == 0) {
		throw ref new Exception(-1, L"Unable to load script or script was empty");
	}

	JsSetCurrentContext(context);

	JsErrorCode errorCode = JsRunScript(script, currentSourceContext++, L"", &result);

	if (errorCode != JsNoError) {
		JsValueRef exception;
		if (JsGetAndClearException(&exception) != JsNoError)
			throw ref new Exception(-1, L"failed to get and clear exception");

		JsPropertyIdRef messageName;
		if (JsGetPropertyIdFromName(L"message", &messageName) != JsNoError)
			throw ref new Exception(-1, L"failed to get error message id");

		JsValueRef messageValue;
		if (JsGetProperty(exception, messageName, &messageValue))
			throw ref new Exception(-1, L"failed to get error message");

		const wchar_t *message;
		size_t length;
		if (JsStringToPointer(messageValue, &message, &length) != JsNoError)
			throw ref new Exception(-1, L"failed to convert error message");

		OutputDebugString(message);
	}
}

void Engine::processNextTask() {
	if (!taskQueue.empty()) {
		Task* task = taskQueue.front();
		taskQueue.pop();
		int currentTime = clock() / (double)(CLOCKS_PER_SEC / 1000);
		if (currentTime - task->_time > task->_delay) {
			task->invoke();
			if (task->_repeat) {
				task->_time = currentTime;
				taskQueue.push(task);
			}
			else {
				delete task;
			}
		}
		else {
			taskQueue.push(task);
		}
	}
}

// Save promises in task queue
void CALLBACK Engine::promiseContinuationCallback(JsValueRef task, void *callbackState)
{
	JsValueRef global;
	JsGetGlobalObject(&global);
	queue<Task*> * q = (queue<Task*> *)callbackState;
	q->push(new Task(task, 0, global, JS_INVALID_REFERENCE));
}


void Engine::OnCameraAdded(Windows::Graphics::Holographic::HolographicSpace ^sender, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs ^args)
{
	throw ref new Platform::NotImplementedException();
}
