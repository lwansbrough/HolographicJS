# Microsoft has released an official replacement for this library

Stunning work by some of the folks at MS who have put together their vision for what this library should be. The result is nearly identical, so I'm recommending their library over this one.
https://github.com/microsoft/holojs

# HolographicJS

[![Join the chat at https://gitter.im/HolographicJS](https://badges.gitter.im/HolographicJS.svg)](https://gitter.im/HolographicJS?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A C++ Windows Runtime Component for hosting Windows Holographic apps built with Javascript and WebGL.

## Purpose

To provide a familiar environment for web developers who are interested in holographic development for Microsoft HoloLens and Windows Holographic.

![Demonstration of HolographicJS](/demo.gif?raw=true)

## Notes/Warnings

- This library is completely devoid of memory management. I'm not a C++ developer so I've left memory management as an excercise for later
- `libEGL.dll` and `libGLES.dll` were compiled using [Microsoft's fork of ANGLE with support for Windows Holographic](https://github.com/microsoft/angle/tree/ms-holographic-experimental)
- At the moment, shaders for specific libraries have to be updated to support holographics

## Approach

This project is very experimental, and as such I've taken some somewhat novel approaches to some difficult problems. Nothing provided here is recommended for production environments at this point.

HolographicJS is built atop large open source efforts, including:

- [ChakraCore](https://github.com/Microsoft/ChakraCore) by Microsoft -- though a few JSRT specific calls are used
- [ANGLE](https://github.com/google/angle) by Google (and [adapted by Microsoft](https://github.com/microsoft/angle) for our purposes)
- OpenGL by Khronos Group.
- Influenced by [Ejecta](https://github.com/phoboslab/Ejecta)

The goal of this project is to achieve rendering holograms using Javascript with minimal or no adjustments to existing 3D libraries. Where required, HoloLens specific solutions should be employed.

## Getting Started

1. Clone the repo
2. Open the HolographicJS solution
3. Run the `HolographicJSTest` app on your HoloLens or HoloLens emulator
   - `app.js` is a demonstration of a plain holographic WebGL app in JS
   - `app.three.js` is a work in progress demonstration of ThreeJS support

## Example

This is an example of how HolographicJS can be used within a Universal Windows app.

```c++

// Called when the CoreWindow object is created (or re-created).
void App::SetWindow(CoreWindow^ window)
{
    window->VisibilityChanged +=
        ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &App::OnVisibilityChanged);

    window->Closed += 
        ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &App::OnWindowClosed);

	try {
		holographicJS = ref new Host(window);
	}
	catch (Exception^ e) {
		OutputDebugString(e->Message->Data());
	}
}

// Initializes scene resources
void App::Load(Platform::String^ entryPoint)
{
	holographicJS->RunScript(L"app.js");
}

// This method is called after the window becomes active.
void App::Run()
{
    while (!mWindowClosed)
    {
        if (mWindowVisible)
        {
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
			holographicJS->ProcessNextTask();
		}
        else
        {
            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
        }
    }
}
```

## Roadmap

In no particular order:

- [ ] Implement entire WebGL 1.x spec
- [ ] Port to C++/WinRT for improved performance
- [ ] Remove Edge Mode Chakra dependency
- [ ] Provide high level interfaces for spatial mapping, shared experiences
- [ ] Three.js support
