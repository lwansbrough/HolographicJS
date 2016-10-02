//
// This file demonstrates how to initialize EGL in a Windows Store app, using ICoreWindow.
//

#include "pch.h"
#include "app.h"

using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::Graphics::Holographic;
using namespace Windows::Perception::Spatial;
using namespace Microsoft::WRL;
using namespace Platform;
using namespace HolographicJS;

using namespace HolographicJSTest;

// Implementation of the IFrameworkViewSource interface, necessary to run our app.
ref class SimpleApplicationSource sealed : Windows::ApplicationModel::Core::IFrameworkViewSource
{
public:
    virtual Windows::ApplicationModel::Core::IFrameworkView^ CreateView()
    {
        return ref new App();
    }
};

// The main function creates an IFrameworkViewSource for our app, and runs the app.
[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
    auto simpleApplicationSource = ref new SimpleApplicationSource();
    CoreApplication::Run(simpleApplicationSource);
    return 0;
}

App::App() :
    mWindowClosed(false),
    mWindowVisible(true)
{
}

// The first method called when the IFrameworkView is being created.
void App::Initialize(CoreApplicationView^ applicationView)
{
    // Register event handlers for app lifecycle. This example includes Activated, so that we
    // can make the CoreWindow active and start rendering on the window.
    applicationView->Activated += 
        ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &App::OnActivated);

    // Logic for other event handlers could go here.
    // Information about the Suspending and Resuming event handlers can be found here:
    // http://msdn.microsoft.com/en-us/library/windows/apps/xaml/hh994930.aspx
}

// Called when the CoreWindow object is created (or re-created).
void App::SetWindow(CoreWindow^ window)
{
    window->VisibilityChanged +=
        ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &App::OnVisibilityChanged);

    window->Closed += 
        ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &App::OnWindowClosed);

    try
    {
        // Create a holographic space for the core window for the current view.
        mHolographicSpace = HolographicSpace::CreateForCoreWindow(window);

        // Get the default SpatialLocator.
        SpatialLocator^ locator = SpatialLocator::GetDefault();

        // Create a stationary frame of reference.
        mStationaryReferenceFrame = locator->CreateStationaryFrameOfReferenceAtCurrentLocation();
    }
    catch (Platform::Exception^ ex)
    {
        if (ex->HResult == HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED))
        {
            // Device does not support holographic spaces. Initialize EGL to use the CoreWindow instead.
        }
    }
}

// Initializes scene resources
void App::Load(Platform::String^ entryPoint)
{
	try {
		holographicJS = ref new Host(mHolographicSpace, mStationaryReferenceFrame);
	}
	catch (Exception^ e) {
		OutputDebugString(e->Message->Data());
	}
}


// This method is called after the window becomes active.
void App::Run()
{
	bool hasRun = false;
    while (!mWindowClosed)
    {
        if (mWindowVisible)
        {
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
		
			if (!hasRun) {
				holographicJS->RunScript("app.js");
				hasRun = true;
			}
		}
        else
        {
            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
        }
    }

    // TODO: Clean up HolographicJS here
}

// Terminate events do not cause Uninitialize to be called. It will be called if your IFrameworkView
// class is torn down while the app is in the foreground.
void App::Uninitialize()
{
}

// Application lifecycle event handler.
void App::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
    // Run() won't start until the CoreWindow is activated.
    CoreWindow::GetForCurrentThread()->Activate();
}

// Window event handlers.
void App::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
    mWindowVisible = args->Visible;
}

void App::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
    mWindowClosed = true;
}
