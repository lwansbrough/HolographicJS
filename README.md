# HolographicJS

A C++ Windows Runtime Component for hosting Windows Holographic apps built with Javascript and WebGL.

## Purpose

To provide a familiar environment for web developers who are interested in holographic development for Microsoft HoloLens and Windows Holographic.

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

## Notes

- This library is completely devoid of memory management. I'm not a C++ developer so I've left memory management as an excercise for later
- `libEGL.dll` and `libGLES.dll` were compiled using [Microsoft's fork of ANGLE with support for Windows Holographic](https://github.com/microsoft/angle/tree/ms-holographic-experimental)
- At the moment, shaders for specific libraries have to be updated to support holographics

## Roadmap

- [ ] Implement entire WebGL 1.x spec
- [ ] Provide high level interfaces for spatial mapping, shared experiences