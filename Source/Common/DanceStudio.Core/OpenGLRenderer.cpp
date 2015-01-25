// =======================================================================
// <copyright file="OpenGLRenderer.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>10-12-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "OpenGLRenderer.h"
#include "MathHelper.h"
#include "FileHelper.h"
#include "PathHelper.h"

using DanceStudio::Core::OpenGLRenderer;
using DanceStudio::Core::FileHelper;

OpenGLRenderer::OpenGLRenderer(DS_HANDLE* windowHandle) :
    deviceContext(nullptr),
    renderingContext(nullptr),
    windowHandle(nullptr),
    vertexShader(0),
    pixelShader(0),
    shaderProgram(0),
    vertexCount(0),
    indexCount(0),
    vertexArrayId(0),
    vertexBufferId(0),
    indexBufferId(0) {
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

    if (this->shaderProgram != 0) {
        if (this->vertexShader != 0) {
            extensions.glDetachShader(
                this->shaderProgram,
                this->vertexShader);
            extensions.glDeleteShader(
                this->vertexShader);

            this->vertexShader = 0;
        }

        if (this->pixelShader != 0) {
            extensions.glDetachShader(
                this->shaderProgram,
                this->pixelShader);
            extensions.glDeleteShader(
                this->pixelShader);

            this->pixelShader = 0;
        }

        extensions.glDeleteProgram(this->shaderProgram);
        this->shaderProgram = 0;
    }
}

void OpenGLRenderer::BeginScene() {
    // Clear the scene to black.
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Clear the back buffer and depth buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    INT32 location = -1;
    location = extensions.glGetUniformLocation(
        this->shaderProgram,
        "worldMatrix");
    if (location == -1) {
        Throw::InvalidOperationException(
            "The 'worldMatrix' uniform parameter is missing from the shader.");
    }

    extensions.glUniformMatrix4fv(
        location,
        1 /*count*/,
        false /*transpose*/,
        worldMatrix);

    // TODO: Put the view matrix uniform store here.

    location = extensions.glGetUniformLocation(
        this->shaderProgram,
        "projectionMatrix");
    if (location == -1) {
        Throw::InvalidOperationException(
            "The 'projectionMatrix' uniform parameter is missing from the shader.");
    }

    extensions.glUniformMatrix4fv(
        location,
        1 /*count*/,
        false /*transpose*/,
        projectionMatrix);
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

    // The shaders are copied to the output folder in the post build scripts.
    const std::string exeDirectory = FileHelper::GetExecutingExeDirectory();
    const std::string shaderDirectory = PathHelper::Combine(
        exeDirectory,
        "Shaders");

    const std::string vertexShaderFilePath = PathHelper::Combine(
        shaderDirectory,
        "VertexShader.vs");
    const std::string pixelShaderFilePath = PathHelper::Combine(
        shaderDirectory,
        "PixelShader.ps");

    const std::string vertexShaderStringContents =
        FileHelper::LoadAllFileText(vertexShaderFilePath);
    const CHAR* vertexShaderContents = vertexShaderStringContents.c_str();

    const std::string pixelShaderStringContents =
        FileHelper::LoadAllFileText(pixelShaderFilePath);
    const CHAR* pixelShaderContents = pixelShaderStringContents.c_str();

    // Create the vertex and pixel shader.
    this->vertexShader = extensions.glCreateShader(
        GL_VERTEX_SHADER);
    this->pixelShader = extensions.glCreateShader(
        GL_FRAGMENT_SHADER);

    // Copy the file contents into the shader objects.
    extensions.glShaderSource(
        this->vertexShader,
        1 /*count*/,
        &vertexShaderContents,
        nullptr);

    extensions.glShaderSource(
        this->pixelShader,
        1 /*count*/,
        &pixelShaderContents,
        nullptr);

    // Compile the shaders.
    BOOL status = FALSE;
    extensions.glCompileShader(this->vertexShader);
    extensions.glGetShaderiv(
        this->vertexShader,
        GL_COMPILE_STATUS,
        &status);
    if (status != TRUE) {
        LogShaderCompileErrorMessage(this->vertexShader);
        Throw::InvalidOperationException(
            "The vertex shader at '"
            + vertexShaderFilePath
            + "' failed to compile.");
    }

    extensions.glCompileShader(this->pixelShader);
    extensions.glGetShaderiv(
        this->pixelShader,
        GL_COMPILE_STATUS,
        &status);
    if (status != TRUE) {
        LogShaderCompileErrorMessage(this->pixelShader);
        Throw::InvalidOperationException(
            "The pixel shader at '"
            + pixelShaderFilePath
            + "' failed to compile.");
    }

    // Create the shader program object.
    this->shaderProgram = extensions.glCreateProgram();

    // Attach the vertex and pixel shaders to the program object.
    extensions.glAttachShader(
        this->shaderProgram,
        this->vertexShader);

    extensions.glAttachShader(
        this->shaderProgram,
        this->pixelShader);

    // Bind the input variables for the shader.
    extensions.glBindAttribLocation(
        this->shaderProgram,
        0 /*index*/,
        "inputPosition");

    extensions.glBindAttribLocation(
        this->shaderProgram,
        1 /*index*/,
        "inputColor");

    // Link the shader program.
    extensions.glLinkProgram(this->shaderProgram);
    extensions.glGetProgramiv(
        this->shaderProgram,
        GL_LINK_STATUS,
        &status);

    if (status != TRUE) {
        LogShaderLinkErrorMessage();
        Throw::InvalidOperationException("The shader program failed to link.");
    }

    // Load the vertex data.
    VertexType* vertices = nullptr;
    UINT32* indices = nullptr;

    this->vertexCount = 3;
    this->indexCount = 3;

    vertices = new VertexType[this->vertexCount];
    Validator::IsMemoryAllocated(vertices, "the vertices of the model");

    indices = new UINT32[this->indexCount];
    Validator::IsMemoryAllocated(vertices, "the indices of the model");

    // Load the vertex array with data.

    // Bottom left.
    vertices[0].x = -1.0f;  // Position.
    vertices[0].y = -1.0f;
    vertices[0].z = 0.0f;

    vertices[0].r = 0.0f;  // Color.
    vertices[0].g = 1.0f;
    vertices[0].b = 0.0f;

    // Top middle.
    vertices[1].x = 0.0f;  // Position.
    vertices[1].y = 1.0f;
    vertices[1].z = 0.0f;

    vertices[1].r = 0.0f;  // Color.
    vertices[1].g = 1.0f;
    vertices[1].b = 0.0f;

    // Bottom right.
    vertices[2].x = 1.0f;  // Position.
    vertices[2].y = -1.0f;
    vertices[2].z = 0.0f;

    vertices[2].r = 0.0f;  // Color.
    vertices[2].g = 1.0f;
    vertices[2].b = 0.0f;

    // Load the index array with data.
    indices[0] = 0;  // Bottom left.
    indices[1] = 1;  // Top middle.
    indices[2] = 2;  // Bottom right.

    // Allocate the vertex array object for OpenGL.
    extensions.glGenVertexArrays(1, &this->vertexArrayId);

    // Bind the vertex array object.
    extensions.glBindVertexArray(this->vertexArrayId);

    // Generate an ID for the vertex buffer.
    extensions.glGenBuffers(1, &this->vertexBufferId);

    // Bind the vertex buffer.
    extensions.glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);

    // Load the vertex data into the buffer.
    extensions.glBufferData(
        GL_ARRAY_BUFFER,
        this->vertexCount * sizeof(VertexType),
        vertices,
        GL_STATIC_DRAW);

    // Enable the vertex position attribute.
    extensions.glEnableVertexAttribArray(0);

    // Enable the vertex color attribute.
    extensions.glEnableVertexAttribArray(1);

    // Bind the vertex buffer again.
    extensions.glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);

    // Describe the format of the position data.
    extensions.glVertexAttribPointer(
        0 /*index*/,
        3 /*size*/,
        GL_FLOAT,
        false /*normalized*/,
        sizeof(VertexType),
        nullptr);

    // Bind the vertex buffer again.
    extensions.glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);

    // Describe the format of the color data.
    extensions.glVertexAttribPointer(
        1 /*index*/,
        3 /*size*/,
        GL_FLOAT,
        false /*normalized*/,
        sizeof(VertexType),
        reinterpret_cast<BYTE*>(0) + (3 * sizeof(SINGLE)));

    // Generate an ID for the index buffer.
    extensions.glGenBuffers(1, &this->indexBufferId);

    // Bind the index buffer.
    extensions.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferId);

    // Load the index data into the buffer.
    extensions.glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        this->indexCount * sizeof(UINT32),
        indices,
        GL_STATIC_DRAW);

    // Clean up the buffers.
    delete[] vertices;
    vertices = nullptr;

    delete[] indices;
    indices = nullptr;
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
    result = extensions.wglChoosePixelFormatARB(
        this->deviceContext,
        attributeListInt,
        nullptr,
        1,
        pixelFormat,
        &formatCount);

    if (result != TRUE) {
        Throw::InvalidOperationException(
            "The pixel format desired for rendering is not compatible.");
    }

    // Set the 4.0 version of OpenGL in the attribute list.
    attributeList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
    attributeList[1] = 4;
    attributeList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
    attributeList[3] = 0;

    // Null terminate the attribute list.
    attributeList[4] = 0;

    // Create a OpenGL 4.0 rendering context.
    assert(this->renderingContext == nullptr);
    this->renderingContext = extensions.wglCreateContextAttribsARB(
        this->deviceContext,
        0,
        attributeList);

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
    MathHelper::BuildIdentityMatrix(this->worldMatrix);

    // Set the field of view and screen aspect ratio.
    fieldOfView = 3.14159265358979323846f / 4.0f;

    SINGLE screenWidth = 100;
    SINGLE screenHeight = 100;
    screenAspect = screenWidth / screenHeight;

    SINGLE screenNear = 0.1f;
    SINGLE screenFar = 1000.0f;

    // Build the perspective projection matrix.
    MathHelper::BuildPerspectiveFovLHMatrix(
        this->projectionMatrix,
        fieldOfView,
        screenAspect,
        screenNear,
        screenFar);

    // Get the details of the video card.
    const CHAR* vendorString = reinterpret_cast<const CHAR*>(
        glGetString(GL_VENDOR));
    const CHAR* rendererString = reinterpret_cast<const CHAR*>(
        glGetString(GL_RENDERER));
    const CHAR* versionString = reinterpret_cast<const CHAR*>(
        glGetString(GL_VERSION));

    Logger::LogCoreVerbose(
        (std::string("Video card vendor: ")
      + vendorString).c_str());

    Logger::LogCoreVerbose(
        (std::string("Video card renderer: ")
        + rendererString).c_str());

    Logger::LogCoreVerbose(
        (std::string("Video card version: ")
        + versionString).c_str());

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

void OpenGLRenderer::LogShaderCompileErrorMessage(INT32 shaderId) {
    assert(shaderId >= 0);

    INT32 logSize = 0;
    extensions.glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logSize);

    // Account for the null terminator;
    ++logSize;

    CHAR* logMessage = new CHAR[logSize];
    Validator::IsMemoryAllocated(
        logMessage,
        "the shader compiler error message.");

    extensions.glGetShaderInfoLog(shaderId, logSize, nullptr, logMessage);

    // TODO: log the message to the logger.
}

void OpenGLRenderer::LogShaderLinkErrorMessage() {
    INT32 logSize = 0;
    extensions.glGetProgramiv(
        this->shaderProgram,
        GL_INFO_LOG_LENGTH,
        &logSize);

    // Account for the null terminator;
    ++logSize;

    CHAR* logMessage = new CHAR[logSize];
    Validator::IsMemoryAllocated(logMessage, "the shader linker error message.");

    extensions.glGetProgramInfoLog(
        this->shaderProgram,
        logSize,
        nullptr,
        logMessage);

    // TODO: log the message to the logger.
}
