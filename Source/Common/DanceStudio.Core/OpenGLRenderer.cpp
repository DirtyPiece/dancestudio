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
#include "OpenGLVertexType.h"
#include "ColladaImporter.h"
#include "Scene.h"
#include "Node3d.h"
#include "Model3d.h"
#include <string>

using DanceStudio::Core::OpenGLRenderer;
using DanceStudio::Core::FileHelper;
using DanceStudio::Core::OpenGLVertexType;
using DanceStudio::Core::ColladaImporter;
using DanceStudio::Core::Scene;
using DanceStudio::Core::Node3d;
using DanceStudio::Core::Model3d;

#define DS_LOAD_COLLADA
#define SCENE_RENDERING

OpenGLRenderer::OpenGLRenderer(DS_HANDLE* windowHandle, Camera* camera) :
    deviceContext(nullptr),
    renderingContext(nullptr),
    windowHandle(nullptr),
    vertexShader(0),
    pixelShader(0),
    shaderProgram(0) {
    Validator::IsNotNull(windowHandle, "windowHandle");

    this->windowHandle = windowHandle;
    this->camera = camera;

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
    // Clear the scene to gray.
    glClearColor(.5, .5, .5, 1);

    // Clear the back buffer and depth buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set the vertex and pixel shaders to render with.
    extensions.glUseProgram(this->shaderProgram);

    INT32 location = -1;

    //camera->SetPosition(0, -10, 0);
    //camera->SetLookAtPosition(0, 0, 0);
    //camera->SetPosition(-5, 0, -10);
    //camera->SetLookAtPosition(0, 0, 0);
    camera->Update();
    camera->GetViewMatrix(this->viewMatrix);

    location = extensions.glGetUniformLocation(
        this->shaderProgram,
        "viewMatrix");
    if (location == -1) {
        Throw::InvalidOperationException(
            "The 'viewMatrix' uniform parameter is"
            " missing from the shader.");
    }

    extensions.glUniformMatrix4fv(
        location,
        1 /*count*/,
        false /*transpose*/,
        this->viewMatrix);

    location = extensions.glGetUniformLocation(
        this->shaderProgram,
        "projectionMatrix");
    if (location == -1) {
        Throw::InvalidOperationException(
            "The 'projectionMatrix' uniform parameter is"
            " missing from the shader.");
    }

    extensions.glUniformMatrix4fv(
        location,
        1 /*count*/,
        false /*transpose*/,
        this->projectionMatrix);

    // Render the geometry.
    /*extensions.glBindVertexArray(this->vertexArrayId);
    glDrawElements(GL_TRIANGLES, this->indexCount, GL_UNSIGNED_INT, 0);*/

    RenderScene();
}

void OpenGLRenderer::EndScene() {
    assert(this->deviceContext != nullptr);
    if (SwapBuffers(this->deviceContext) == FALSE) {
        this->LogLastError();
        Throw::InvalidOperationException(
            "Unable to swap the front and back buffers for rendering.");
    }
}

void OpenGLRenderer::Initialize() {
    assert(this->windowHandle != nullptr);

    Logger::LogCoreVerbose(L"Initializing the OpenGL renderer.");
    this->LoadExtensionList();

    this->InitializeOpenGL();

    // TODO(dirtypiece): Remove after loading is fixed (wireframe mode).
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

#ifdef SCENE_RENDERING
    this->LoadShaders();
    this->LoadModels();
#else SCENE_RENDERING
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

    Logger::LogCoreVerbose(
        "Loading the vertex shader file at '"
      + vertexShaderFilePath
      + "'.");

    const std::string vertexShaderStringContents =
        FileHelper::LoadAllFileText(vertexShaderFilePath);
    const CHAR* vertexShaderContents = vertexShaderStringContents.c_str();

    Logger::LogCoreVerbose(
        "Loading the pixel shader file at '"
        + pixelShaderFilePath
        + "'.");

    const std::string pixelShaderStringContents =
        FileHelper::LoadAllFileText(pixelShaderFilePath);
    const CHAR* pixelShaderContents = pixelShaderStringContents.c_str();

    // Create the vertex and pixel shader.
    Logger::LogCoreVerbose("Creating the vertex shader.");
    this->vertexShader = extensions.glCreateShader(
        GL_VERTEX_SHADER);

    Logger::LogCoreVerbose("Creating the pixel shader.");
    this->pixelShader = extensions.glCreateShader(
        GL_FRAGMENT_SHADER);

    // Copy the file contents into the shader objects.
    Logger::LogCoreVerbose("Loading the vertex shader contents.");
    extensions.glShaderSource(
        this->vertexShader,
        1 /*count*/,
        &vertexShaderContents,
        nullptr);

    Logger::LogCoreVerbose("Loading the pixel shader contents.");
    extensions.glShaderSource(
        this->pixelShader,
        1 /*count*/,
        &pixelShaderContents,
        nullptr);

    // Compile the shaders.
    BOOL status = FALSE;
    Logger::LogCoreVerbose("Compiling the vertex shader.");
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

    Logger::LogCoreVerbose("Compiling the pixel shader.");
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
    Logger::LogCoreVerbose("Creating the shader program.");
    this->shaderProgram = extensions.glCreateProgram();

    // Attach the vertex and pixel shaders to the program object.
    Logger::LogCoreVerbose("Attaching the vertex shader to the program.");
    extensions.glAttachShader(
        this->shaderProgram,
        this->vertexShader);

    Logger::LogCoreVerbose("Attaching the pixel shader to the program.");
    extensions.glAttachShader(
        this->shaderProgram,
        this->pixelShader);

    // Bind the input variables for the shader.
    Logger::LogCoreVerbose(
        "Binding the 'inputPosition' attribute to the shader program.");
    extensions.glBindAttribLocation(
        this->shaderProgram,
        0 /*index*/,
        "inputPosition");

    Logger::LogCoreVerbose(
        "Binding the 'inputColor' attribute to the shader program.");
    extensions.glBindAttribLocation(
        this->shaderProgram,
        1 /*index*/,
        "inputColor");

    // Link the shader program.
    Logger::LogCoreVerbose("Linking the shader program.");
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
    Logger::LogCoreVerbose("Loading the vertex data.");
    OpenGLVertexType* vertices = nullptr;
    UINT32* indices = nullptr;

    this->vertexCount = 3;
    this->indexCount = 3;

    vertices = new OpenGLVertexType[this->vertexCount];
    Validator::IsMemoryAllocated(vertices, "the vertices of the model");

    indices = new UINT32[this->indexCount];
    Validator::IsMemoryAllocated(vertices, "the indices of the model");

#ifdef DS_LOAD_COLLADA
    // Load the vertex array with data.
    Scene scene;
    /*ColladaImporter::Import(
        "C:\\Code\\DanceStudio\\Source\\Windows\\DanceStudio"
        "\\DanceStudio.Core.UnitTests\\Resources\\box.dae",
        &scene);*/

    ColladaImporter::Import(
        "C:\\Code\\DanceStudio\\Content\\"
        "Blender\\ITGMachine\\itgmachine.dae",
        &scene);

    const Model3d* model = scene.GetModels()[0];
    this->vertexCount = model->GetVertexCount();
    this->indexCount = model->GetIndexCount();
#else
    this->vertexCount = 3;
    this->indexCount = 3;

    // Bottom left.
    vertices[0].X = -1.0f;  // Position.
    vertices[0].Y = -1.0f;
    vertices[0].Z = 0.0f;

    vertices[0].R = 0.0f;  // Color.
    vertices[0].G = 1.0f;
    vertices[0].B = 0.0f;

    // Top middle.
    vertices[1].X = 0.0f;  // Position.
    vertices[1].Y = 1.0f;
    vertices[1].Z = 0.0f;

    vertices[1].R = 0.0f;  // Color.
    vertices[1].G = 1.0f;
    vertices[1].B = 0.0f;

    // Bottom right.
    vertices[2].X = 1.0f;  // Position.
    vertices[2].Y = -1.0f;
    vertices[2].Z = 0.0f;

    vertices[2].R = 0.0f;  // Color.
    vertices[2].G = 1.0f;
    vertices[2].B = 0.0f;

    // Load the index array with data.
    indices[0] = 0;  // Bottom left.
    indices[1] = 1;  // Top middle.
    indices[2] = 2;  // Bottom right.
#endif

    // Allocate the vertex array object for OpenGL.
    Logger::LogCoreVerbose("Allocating the vertex array.");
    extensions.glGenVertexArrays(1, &this->vertexArrayId);

    // Bind the vertex array object.
    Logger::LogCoreVerbose("Binding the vertex array object.");
    extensions.glBindVertexArray(this->vertexArrayId);

    // Generate an ID for the vertex buffer.
    Logger::LogCoreVerbose("Generating a vertex buffer ID.");
    extensions.glGenBuffers(1, &this->vertexBufferId);

    // Bind the vertex buffer.
    Logger::LogCoreVerbose("Binding the vertex buffer.");
    extensions.glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);

    // Load the vertex data into the buffer.
    Logger::LogCoreVerbose("Loading the vertex data into the buffer.");
#ifdef DS_LOAD_COLLADA
    vertices = model->GetVertices();
#endif
    extensions.glBufferData(
        GL_ARRAY_BUFFER,
        this->vertexCount * sizeof(OpenGLVertexType),
        vertices,
        GL_STATIC_DRAW);

    // Enable the vertex position attribute.
    Logger::LogCoreVerbose("Enabling the vertex position attribute.");
    extensions.glEnableVertexAttribArray(0);

    // Enable the vertex color attribute.
    Logger::LogCoreVerbose("Enabling the vertex color attribute.");
    extensions.glEnableVertexAttribArray(1);

    // Bind the vertex buffer again.
    Logger::LogCoreVerbose("Rebinding the vertex buffer.");
    extensions.glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);

    // Describe the format of the position data.
    Logger::LogCoreVerbose("Setting the position data format.");
    extensions.glVertexAttribPointer(
        0 /*index*/,
        3,//this->vertexCount /*size*/,
        GL_FLOAT,
        false /*normalized*/,
        sizeof(OpenGLVertexType),
        nullptr);

    // Bind the vertex buffer again.
    Logger::LogCoreVerbose("Rebinding the vertex buffer.");
    extensions.glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);

    // Describe the format of the color data.
    Logger::LogCoreVerbose("Setting the color data format.");
    extensions.glVertexAttribPointer(
        1 /*index*/,
        3, //this->indexCount /*size*/,
        GL_FLOAT,
        false /*normalized*/,
        sizeof(OpenGLVertexType),
        reinterpret_cast<BYTE*>(0) + (3 * sizeof(SINGLE)));

    // Generate an ID for the index buffer.
    Logger::LogCoreVerbose("Generating an ID for the index buffer.");
    extensions.glGenBuffers(1, &this->indexBufferId);

    // Bind the index buffer.
    Logger::LogCoreVerbose("Binding the index buffer.");
    extensions.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferId);

    // Load the index data into the buffer.
#ifdef DS_LOAD_COLLADA
    indices = model->GetIndices();
#endif
    Logger::LogCoreVerbose("Loading the index data into the buffer.");
    extensions.glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        this->indexCount * sizeof(UINT32),
        indices,
        GL_STATIC_DRAW);

    // Clean up the buffers.
    /*delete[] vertices;
    vertices = nullptr;

    delete[] indices;
    indices = nullptr;*/
#endif // SCENE_RENDERING
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

    // Support for 24 bit color.
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

    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 
        1,                                // version number 
        PFD_DRAW_TO_WINDOW |              // support window 
        PFD_SUPPORT_OPENGL |              // support OpenGL 
        PFD_DOUBLEBUFFER,                 // double buffered 
        PFD_TYPE_RGBA,                    // RGBA type 
        24,                               // 24-bit color depth 
        0, 0, 0, 0, 0, 0,                 // color bits ignored 
        0,                                // no alpha buffer 
        0,                                // shift bit ignored 
        0,                                // no accumulation buffer 
        0, 0, 0, 0,                       // accum bits ignored 
        32,                               // 32-bit z-buffer     
        0,                                // no stencil buffer 
        0,                                // no auxiliary buffer 
        PFD_MAIN_PLANE,                   // main layer 
        0,                                // reserved 
        0, 0, 0                           // layer masks ignored 
    };

    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);

    pfd.nVersion = 1;

    pfd.dwFlags = PFD_DRAW_TO_WINDOW |

    PFD_SUPPORT_OPENGL /*| PFD_DOUBLEBUFFER*/;

    pfd.iPixelType = PFD_TYPE_RGBA;

    pfd.cColorBits = 24;

    pfd.cDepthBits = 16;

    pfd.iLayerType = PFD_MAIN_PLANE;

    pixelFormat[0] = ChoosePixelFormat(this->deviceContext, &pfd);
    if (pixelFormat[0] == 0) {
        this->LogLastError();
        Throw::InvalidOperationException(
            "The pixel format desired for rendering is not compatible.");
    }

    // Query for a pixel format that fits the attributes we want.
#if 0
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
#endif

    /*result = SetPixelFormat(
        this->deviceContext,
        pixelFormat[0],
        &pfd);

    if (result != TRUE)
    {
        this->LogLastError();
        Throw::InvalidOperationException(
            "The pixel format could not be set for the context.");
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

    SINGLE screenWidth = 1000;
    SINGLE screenHeight = 1000;
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

    // Account for the null terminator.
    ++logSize;

    CHAR* logMessage = new CHAR[logSize];
    Validator::IsMemoryAllocated(
        logMessage,
        "the shader compiler error message.");

    extensions.glGetShaderInfoLog(shaderId, logSize, nullptr, logMessage);

    Logger::LogCoreError(logMessage);
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
    Validator::IsMemoryAllocated(
        logMessage,
        "the shader linker error message.");

    extensions.glGetProgramInfoLog(
        this->shaderProgram,
        logSize,
        nullptr,
        logMessage);

    Logger::LogCoreError(logMessage);
}

void OpenGLRenderer::LoadShaders() {
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

    Logger::LogCoreVerbose(
        "Loading the vertex shader file at '"
        + vertexShaderFilePath
        + "'.");

    const std::string vertexShaderStringContents =
        FileHelper::LoadAllFileText(vertexShaderFilePath);
    const CHAR* vertexShaderContents = vertexShaderStringContents.c_str();

    Logger::LogCoreVerbose(
        "Loading the pixel shader file at '"
        + pixelShaderFilePath
        + "'.");

    const std::string pixelShaderStringContents =
        FileHelper::LoadAllFileText(pixelShaderFilePath);
    const CHAR* pixelShaderContents = pixelShaderStringContents.c_str();

    // Create the vertex and pixel shader.
    Logger::LogCoreVerbose("Creating the vertex shader.");
    this->vertexShader = extensions.glCreateShader(
        GL_VERTEX_SHADER);

    Logger::LogCoreVerbose("Creating the pixel shader.");
    this->pixelShader = extensions.glCreateShader(
        GL_FRAGMENT_SHADER);

    // Copy the file contents into the shader objects.
    Logger::LogCoreVerbose("Loading the vertex shader contents.");
    extensions.glShaderSource(
        this->vertexShader,
        1 /*count*/,
        &vertexShaderContents,
        nullptr);

    Logger::LogCoreVerbose("Loading the pixel shader contents.");
    extensions.glShaderSource(
        this->pixelShader,
        1 /*count*/,
        &pixelShaderContents,
        nullptr);

    // Compile the shaders.
    BOOL status = FALSE;
    Logger::LogCoreVerbose("Compiling the vertex shader.");
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

    Logger::LogCoreVerbose("Compiling the pixel shader.");
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
    Logger::LogCoreVerbose("Creating the shader program.");
    this->shaderProgram = extensions.glCreateProgram();

    // Attach the vertex and pixel shaders to the program object.
    Logger::LogCoreVerbose("Attaching the vertex shader to the program.");
    extensions.glAttachShader(
        this->shaderProgram,
        this->vertexShader);

    Logger::LogCoreVerbose("Attaching the pixel shader to the program.");
    extensions.glAttachShader(
        this->shaderProgram,
        this->pixelShader);

    // Bind the input variables for the shader.
    Logger::LogCoreVerbose(
        "Binding the 'inputPosition' attribute to the shader program.");
    extensions.glBindAttribLocation(
        this->shaderProgram,
        0 /*index*/,
        "inputPosition");

    Logger::LogCoreVerbose(
        "Binding the 'inputColor' attribute to the shader program.");
    extensions.glBindAttribLocation(
        this->shaderProgram,
        1 /*index*/,
        "inputColor");

    // Link the shader program.
    Logger::LogCoreVerbose("Linking the shader program.");
    extensions.glLinkProgram(this->shaderProgram);
    extensions.glGetProgramiv(
        this->shaderProgram,
        GL_LINK_STATUS,
        &status);

    if (status != TRUE) {
        LogShaderLinkErrorMessage();
        Throw::InvalidOperationException("The shader program failed to link.");
    }
}

void OpenGLRenderer::LoadModels() {
    ColladaImporter::Import(
        "C:\\Code\\DanceStudio\\Content\\"
        "Blender\\ITGMachine\\itgmachine.dae",
        &this->scene);

    /*ColladaImporter::Import(
        "C:\\Code\\DanceStudio\\Content\\Blender\\ITGMachine\\box2.dae",
        &this->scene);*/

    /*ColladaImporter::Import(
        "D:\\Code\\DanceStudio\\Content\\Blender\\ITGMachine\\itgmachine.dae",
        &this->scene);*/
}

void OpenGLRenderer::RenderScene() {
    const Node3d* rootNode = this->scene.GetRootNode();
    this->RenderNode(rootNode, this->worldMatrix);
}

void OpenGLRenderer::RenderNode(
    const Node3d* node,
    const SINGLE* parentMatrix) {
    assert(node != nullptr);
    assert(parentMatrix != nullptr);

    // Create the transformation matrix of the parent applied with this
    // node's local transformation.
    SINGLE shaderMatrix[4 * 4];
    const SINGLE* nodeMatrix = node->GetTransformationMatrix();
    this->SetWorldMatrix(nodeMatrix);

    // Render the models for this node.
    for (UINT32 i = 0; i < node->GetModelCount(); ++i) {
        const Model3d* model = node->GetModel(i);
        this->RenderModel(model);
    }

    // Render the children of this node.
    for (UINT32 i = 0; i < node->GetChildrenCount(); ++i) {
        const Node3d* childNode = node->GetChild(i);
        this->RenderNode(childNode, shaderMatrix);
    }
}

void OpenGLRenderer::RenderModel(const Model3d* model) {
    assert(model != nullptr);

    UINT32 vertexArrayId = 0;
    UINT32 vertexBufferId = 0;
    UINT32 indexBufferId = 0;

    UINT32 vertexCount = model->GetVertexCount();
    UINT32 indexCount = model->GetIndexCount();

    // Allocate the vertex array object for OpenGL.
    Logger::LogCoreVerbose("Allocating the vertex array.");
    extensions.glGenVertexArrays(1, &vertexArrayId);

    // Bind the vertex array object.
    Logger::LogCoreVerbose("Binding the vertex array object.");
    extensions.glBindVertexArray(vertexArrayId);

    // Generate an ID for the vertex buffer.
    Logger::LogCoreVerbose("Generating a vertex buffer ID.");
    extensions.glGenBuffers(1, &vertexBufferId);

    // Bind the vertex buffer.
    Logger::LogCoreVerbose("Binding the vertex buffer.");
    extensions.glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);

    // Load the vertex data into the buffer.
    Logger::LogCoreVerbose("Loading the vertex data into the buffer.");

    OpenGLVertexType* vertices = model->GetVertices();

    extensions.glBufferData(
        GL_ARRAY_BUFFER,
        vertexCount * sizeof(OpenGLVertexType),
        vertices,
        GL_STATIC_DRAW);

    // Enable the vertex position attribute.
    Logger::LogCoreVerbose("Enabling the vertex position attribute.");
    extensions.glEnableVertexAttribArray(0);

    // Enable the vertex color attribute.
    Logger::LogCoreVerbose("Enabling the vertex color attribute.");
    extensions.glEnableVertexAttribArray(1);

    // Bind the vertex buffer again.
    Logger::LogCoreVerbose("Rebinding the vertex buffer.");
    extensions.glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);

    // Describe the format of the position data.
    Logger::LogCoreVerbose("Setting the position data format.");
    extensions.glVertexAttribPointer(
        0 /*index*/,
        3,//this->vertexCount /*size*/,
        GL_FLOAT,
        false /*normalized*/,
        sizeof(OpenGLVertexType),
        nullptr);

    // Bind the vertex buffer again.
    Logger::LogCoreVerbose("Rebinding the vertex buffer.");
    extensions.glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);

    // Describe the format of the color data.
    Logger::LogCoreVerbose("Setting the color data format.");
    extensions.glVertexAttribPointer(
        1 /*index*/,
        3, //this->indexCount /*size*/,
        GL_FLOAT,
        false /*normalized*/,
        sizeof(OpenGLVertexType),
        reinterpret_cast<BYTE*>(0) + (3 * sizeof(SINGLE)));

    // Generate an ID for the index buffer.
    Logger::LogCoreVerbose("Generating an ID for the index buffer.");
    extensions.glGenBuffers(1, &indexBufferId);

    // Bind the index buffer.
    Logger::LogCoreVerbose("Binding the index buffer.");
    extensions.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

    // Load the index data into the buffer.
    UINT32* indices = model->GetIndices();

    Logger::LogCoreVerbose("Loading the index data into the buffer.");
    extensions.glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indexCount * sizeof(UINT32),
        indices,
        GL_STATIC_DRAW);

    // Render the mesh.
    extensions.glBindVertexArray(vertexArrayId);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

void OpenGLRenderer::SetWorldMatrix(const SINGLE* matrix) {
    assert(matrix != nullptr);

    INT32 location = extensions.glGetUniformLocation(
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
        matrix);
}
