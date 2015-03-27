// =======================================================================
// <copyright file="OpenGLRenderer.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-12-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLRENDERER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLRENDERER_H_

#include "Typedefs.h"
#include "OpenGL.h"
#include "OpenGLExtensions.h"
#include "Camera.h"
#include "Scene.h"

using DanceStudio::Core::Camera;
using DanceStudio::Core::Scene;

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents main Open GL renderer for rending all graphics from the core
/// library components to the screen.
/// </summary>
class OpenGLRenderer {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="OpenGLRenderer" /> class.
    /// </summary>
    /// <param name="windowHandle">
    /// The handle of the window to render to.
    /// </param>
    explicit OpenGLRenderer(DS_HANDLE* windowHandle);

    /// <summary>
    /// Finalizes an instance of the <see cref="OpenGLRenderer"/> class.
    /// </summary>
    ~OpenGLRenderer();

    /// <summary>
    /// Begins rendering of the OpenGL scene.
    /// </summary>
    void BeginScene();

    /// <summary>
    /// Ends rendering of the OpenGL scene.
    /// </summary>
    void EndScene();

 private:
    /// <summary>
    /// The object that loads all of the OpenGL 4.0 extension functions.
    /// </summary>
    OpenGLExtensions extensions;

    /// <summary>
    /// The device context for the window being rendered to.
    /// </summary>
    HDC deviceContext;

    /// <summary>
    /// The rendering context for the window being rendered to.
    /// </summary>
    HGLRC renderingContext;

    /// <summary>
    /// The handle of the window being rendered to.
    /// </summary>
    DS_HANDLE* windowHandle;

    /// <summary>
    /// The main world camera.
    /// </summary>
    Camera camera;

    /// <summary>
    /// The matrix used to transform all geometry into world space.
    /// </summary>
    SINGLE worldMatrix[4 * 4];

    /// <summary>
    /// The matrix used to transform all geometry into the view space.
    /// </summary>
    SINGLE viewMatrix[4 * 4];

    /// <summary>
    /// The matrix used to project geometry into projection space.
    /// </summary>
    SINGLE projectionMatrix[4 * 4];

    /// <summary>
    /// The compiled vertex shader.
    /// </summary>
    UINT32 vertexShader;

    /// <summary>
    /// The compiled pixel shader.
    /// </summary>
    UINT32 pixelShader;

    /// <summary>
    /// The compiled shader program.
    /// </summary>
    UINT32 shaderProgram;

    /*/// <summary>
    /// The number of vertices in the model geometry.
    /// </summary>
    INT32 vertexCount;

    /// <summary>
    /// The number of indices in the model index buffer.
    /// </summary>
    INT32 indexCount;*/

    /*/// <summary>
    /// The vertex array identifier.
    /// </summary>
    UINT32 vertexArrayId;

    /// <summary>
    /// The vertex buffer identifier.
    /// </summary>
    UINT32 vertexBufferId;

    /// <summary>
    /// The index buffer identifier.
    /// </summary>
    UINT32 indexBufferId;*/

    /// <summary>
    /// The main scene being rendered.
    /// </summary>
    Scene scene;

    /// <summary>
    /// Initializes OpenGL with the passed in window.
    /// </summary>
    void Initialize();

    /// <summary>
    /// Loads the Open GL function extension list (modern functions).
    /// </summary>
    void LoadExtensionList();

    /// <summary>
    /// Initializes the OpenGL context for rendering.
    /// </summary>
    void InitializeOpenGL();

    /// <summary>
    /// Logs the last error using GetLastError().
    /// </summary>
    void LogLastError();

    /// <summary>
    /// Logs a shader compile error message to the log file.
    /// </summary>
    /// <param name="shaderId">
    /// The ID of the shader that was attempted to be compiled.
    /// </param>
    void LogShaderCompileErrorMessage(INT32 shaderId);

    /// <summary>
    /// Logs a shader link error message to the log file.
    /// </summary>
    void LogShaderLinkErrorMessage();

    /// <summary>
    /// Loads the vertex and pixel shaders.
    /// </summary>
    void LoadShaders();

    /// <summary>
    /// Loads the Collada models from disk for rendering.
    /// </summary>
    void LoadModels();

    /// <summary>
    /// Renders the scene to the 3D window.
    /// </summary>
    void RenderScene();
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLRENDERER_H_
