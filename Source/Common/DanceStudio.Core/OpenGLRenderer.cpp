// =======================================================================
// <copyright file="OpenGLRenderer.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>10-12-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "OpenGLRenderer.h"

using DanceStudio::Core::OpenGLRenderer;

OpenGLRenderer::OpenGLRenderer(DS_HANDLE* windowHandle) :
    deviceContext(nullptr),
    renderingContext(nullptr),
    windowHandle(nullptr) {
    Validator::IsNotNull(windowHandle, "windowHandle");

    this->windowHandle = windowHandle;

    this->Initialize();
}

OpenGLRenderer::~OpenGLRenderer() {
    Logger::LogCoreVerbose(L"Shutting down the OpenGL renderer.");

    if (this->renderingContext != nullptr) {
        wglMakeCurrent(nullptr, nullptr);
        wglDeleteContext(this->renderingContext);
        this->renderingContext = nullptr;
    }

    if (this->deviceContext != nullptr && this->windowHandle != nullptr) {
        ReleaseDC(static_cast<HWND>(this->windowHandle), this->deviceContext);
        this->deviceContext = nullptr;
        this->windowHandle = nullptr;
    }
}

void OpenGLRenderer::BeginScene() {
    // Clear the scene to black.
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Clear the back buffer and depth buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderer::EndScene() {
    assert(this->deviceContext != nullptr);
    SwapBuffers(this->deviceContext);
}

void OpenGLRenderer::Initialize() {
    assert(this->windowHandle != nullptr);

    Logger::LogCoreVerbose(L"Initializing the OpenGL renderer.");
    this->LoadExtensionList();

    this->InitializeOpenGL();
}

void OpenGLRenderer::LoadExtensionList() {
    assert(this->windowHandle != nullptr);

    Logger::LogCoreVerbose(L"Loading the OpenGL 4.0 extension methods.");

    PIXELFORMATDESCRIPTOR pixelFormat;
    BOOL error;
    HDC deviceContext = nullptr;
    HGLRC renderContext = nullptr;

    // Get the device context for the window.
    deviceContext = GetDC(static_cast<HWND>(this->windowHandle));
    if (deviceContext == nullptr) {
        Throw::InvalidOperationException(
            "Unable to retrieve the device context from the window"
            " when initializing OpenGL extensions.");
    }

    // Set a temporary default pixel format.
    error = SetPixelFormat(deviceContext, 1, &pixelFormat);
    if (error != TRUE) {
        this->LogLastError();
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
        ReleaseDC(static_cast<HWND>(this->windowHandle), deviceContext);
        deviceContext = nullptr;
    }
}

void OpenGLRenderer::InitializeOpenGL() {
    INT32 attributeListInt[19];
    INT32 pixelFormat[1];
    UINT32 formatCount;
    BOOL result;
    INT32 attributeList[5];
    SINGLE fieldOfView, screenAspect;
    PIXELFORMATDESCRIPTOR pixelFormatDescriptor;

    // Get the device context for this window.
    assert(this->deviceContext == nullptr);
    this->deviceContext = GetDC(static_cast<HWND>(this->windowHandle));
    if (this->deviceContext == nullptr) {
        Throw::InvalidOperationException(
            "The device context could not be retrieved"
            " for the window handle.");
    }

    // Support for OpenGL rendering.
    attributeListInt[0] = WGL_SUPPORT_OPENGL_ARB;
    attributeListInt[1] = TRUE;

    // Support for rendering to a window.
    attributeListInt[2] = WGL_DRAW_TO_WINDOW_ARB;
    attributeListInt[3] = TRUE;

    // Support for hardware acceleration.
    attributeListInt[4] = WGL_ACCELERATION_ARB;
    attributeListInt[5] = WGL_FULL_ACCELERATION_ARB;

    // Support for 24bit color.
    attributeListInt[6] = WGL_COLOR_BITS_ARB;
    attributeListInt[7] = 24;

    // Support for 24 bit depth buffer.
    attributeListInt[8] = WGL_DEPTH_BITS_ARB;
    attributeListInt[9] = 24;

    // Support for double buffer.
    attributeListInt[10] = WGL_DOUBLE_BUFFER_ARB;
    attributeListInt[11] = TRUE;

    // Support for swapping front and back buffer.
    attributeListInt[12] = WGL_SWAP_METHOD_ARB;
    attributeListInt[13] = WGL_SWAP_EXCHANGE_ARB;

    // Support for the RGBA pixel type.
    attributeListInt[14] = WGL_PIXEL_TYPE_ARB;
    attributeListInt[15] = WGL_TYPE_RGBA_ARB;

    // Support for a 8 bit stencil buffer.
    attributeListInt[16] = WGL_STENCIL_BITS_ARB;
    attributeListInt[17] = 8;

    // Null terminate the attribute list.
    attributeListInt[18] = 0;

    // Query for a pixel format that fits the attributes we want.
    result = extensions.wglChoosePixelFormatARB(this->deviceContext, attributeListInt, nullptr, 1, pixelFormat, &formatCount);
    if (result != TRUE) {
        Throw::InvalidOperationException(
            "The pixel format desired for rendering is not compatible.");
    }

    // If the video card/display can handle our desired pixel format then we set it as the current one.
    /*result = SetPixelFormat(this->deviceContext, pixelFormat[0], &pixelFormatDescriptor);
    if (result != 1) {
        LogLastError();
        Throw::InvalidOperationException(
            "Unable to set the desired pixel format for the device context.");
    }*/

    // Set the 4.0 version of OpenGL in the attribute list.
    attributeList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
    attributeList[1] = 4;
    attributeList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
    attributeList[3] = 0;

    // Null terminate the attribute list.
    attributeList[4] = 0;

    // Create a OpenGL 4.0 rendering context.
    assert(this->renderingContext == nullptr);
    this->renderingContext = extensions.wglCreateContextAttribsARB(this->deviceContext, 0, attributeList);
    if (this->renderingContext == nullptr) {
        Throw::InvalidOperationException(
            "Unable to create the OpenGL rendering context.");
    }

    // Set the rendering context to active.
    result = wglMakeCurrent(this->deviceContext, this->renderingContext);
    if (result != TRUE) {
        Throw::InvalidOperationException(
            "Unable to set the OpenGL rendering context to active.");
    }

    // Set the depth buffer to be entirely cleared to 1.0 values.
    glClearDepth(1.0f);

    // Enable depth testing.
    glEnable(GL_DEPTH_TEST);

    // Set the polygon winding to front facing for the left handed system.
    glFrontFace(GL_CW);

    // Enable back face culling.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Initialize the world/model matrix to the identity matrix.
    // BuildIdentityMatrix(m_worldMatrix);

    // Set the field of view and screen aspect ratio.
    fieldOfView = 3.14159265358979323846f / 4.0f;
    // screenAspect = (float)screenWidth / (float)screenHeight;

    // Build the perspective projection matrix.
    // BuildPerspectiveFovLHMatrix(m_projectionMatrix, fieldOfView, screenAspect, screenNear, screenDepth);

    // Get the name of the video card.
    const CHAR* vendorString = reinterpret_cast<const CHAR*>(glGetString(GL_VENDOR));
    const CHAR* rendererString = reinterpret_cast<const CHAR*>(glGetString(GL_RENDERER));

    // Store the video card name in a class member variable so it can be retrieved later.
    /*strcpy_s(m_videoCardDescription, vendorString);
    strcat_s(m_videoCardDescription, " - ");
    strcat_s(m_videoCardDescription, rendererString);*/

    // Turn on or off the vertical sync depending on the input bool value.
    /*if (true)
    {
        result = wglSwapIntervalEXT(1);
    }
    else
    {
        result = wglSwapIntervalEXT(0);
    }*/

    // Check if vsync was set correctly.
    if (result != TRUE) {
        Throw::InvalidOperationException(
            "Unable to set the vsync mode to true.");
    }
}

void OpenGLRenderer::LogLastError() {
#ifdef _WIN32
    LPVOID lpMsgBuf;
    DWORD error = GetLastError();

    FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr,
        error,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<LPWSTR>(&lpMsgBuf),
        0,
        nullptr);

    std::wstringstream stream;
    stream 
        << L"GetLastError() returned error code '"
        << error
        << L"' which resolves to message '"
        << reinterpret_cast<LPWSTR>(lpMsgBuf)
        << L"'.";

    Logger::LogCoreError(stream.str().c_str());

    LocalFree(lpMsgBuf);
#endif  // _WIN32
}
