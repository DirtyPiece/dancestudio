// =======================================================================
// <copyright file="OpenGLRenderer.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>10-12-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "OpenGLRenderer.h"

using DanceStudio::Core::OpenGLRenderer;

OpenGLRenderer::OpenGLRenderer(DS_HANDLE* window) {
    Validator::IsNotNull(window, "window");

    this->Initialize(window);
}

void OpenGLRenderer::Initialize(DS_HANDLE* window) {
    assert(window != nullptr);

    Logger::LogCoreVerbose(L"Initializing the OpenGL renderer.");

    PIXELFORMATDESCRIPTOR pixelFormat;
    BOOL error;
    HDC deviceContext = nullptr;
    HGLRC renderContext = nullptr;
    HWND hwnd = reinterpret_cast<HWND>(window);

    // Get the device context for the window.
    deviceContext = GetDC(hwnd);
    if (deviceContext == nullptr) {
        Throw::InvalidOperationException(
            "Unable to retrieve the device context from the window"
            " when initializing OpenGL extensions.");
    }

    // Set a temporary default pixel format.
    error = SetPixelFormat(deviceContext, 1, &pixelFormat);
    if (error != TRUE) {
        Throw::InvalidOperationException(
            "Unable to retrieve the temporary pixel format"
            " when initializing OpenGL extensions.");
    }

    // Create a temporary rendering context.
    renderContext = wglCreateContext(deviceContext);
    if (renderContext == nullptr) {
        Throw::InvalidOperationException(
            "Unable to create a temporary render context"
            " when initializing OpenGL extensions.");
    }

    // Set the temporary rendering context as the current context
    // for the window.
    error = wglMakeCurrent(deviceContext, renderContext);
    if (error != TRUE) {
        Throw::InvalidOperationException(
            "Unable to set the rendering context as current on the window"
            " when initializing OpenGL extensions.");
    }

    // Load the extension functions for OpenGL 4.0.
    extensions.LoadExtensionFunctions();

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
