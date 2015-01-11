// =======================================================================
// <copyright file="StepChartEditor.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StepChartEditor.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <gl\GL.h>
#endif  // _WIN32

using DanceStudio::Core::StepChartEditor;

StepChartEditor::StepChartEditor(DS_HANDLE* window) {
    Validator::IsNotNull(window, "window");

    InitializeGLExtensions(window);
}

void StepChartEditor::InitializeGLExtensions(DS_HANDLE* window) {
    assert(window != nullptr);

    PIXELFORMATDESCRIPTOR pixelFormat;
    BOOL error;
    HDC deviceContext = nullptr;
    HGLRC renderContext = nullptr;
    HWND hwnd = reinterpret_cast<HWND>(window);

    __try {
        // Get the device context for the window.
        deviceContext = GetDC(hwnd);
        if (deviceContext == nullptr) {
            throw std::runtime_error(
                "Unable to retrieve the device context from the window"
                " when initializing OpenGL extensions.");
        }

        // Set a temporary default pixel format.
        error = SetPixelFormat(deviceContext, 1, &pixelFormat);
        if (error != TRUE) {
            throw std::runtime_error(
                "Unable to retrieve the temporary pixel format"
                " when initializing OpenGL extensions.");
        }

        // Create a temporary rendering context.
        renderContext = wglCreateContext(deviceContext);
        if (renderContext == nullptr) {
            throw std::runtime_error(
                "Unable to create a temporary render context"
                " when initializing OpenGL extensions.");
        }

        // Set the temporary rendering context as the current context
        // for the window.
        error = wglMakeCurrent(deviceContext, renderContext);
        if (error != TRUE) {
            throw std::runtime_error(
                "Unable to set the rendering context as current on the window"
                " when initializing OpenGL extensions.");
        }

        // Load the extension list here...
    }
    __finally {
        // Set the current context back to the default.
        wglMakeCurrent(nullptr, nullptr);

        // Clean up the temporary rendering context.
        // It's no longer needed once we load the GL extension functions.
        if (renderContext != nullptr) {
            wglDeleteContext(renderContext);
            renderContext = nullptr;
        }

        // Clean up the device context.
        if (deviceContext != nullptr) {
            ReleaseDC(hwnd, deviceContext);
            deviceContext = nullptr;
        }
    }
}
