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
    /// The matrix used to transform all geometry into world space.
    /// </summary>
    SINGLE worldMatrix[4 * 4];

    /// <summary>
    /// The matrix used to project geometry into projection space.
    /// </summary>
    SINGLE projectionMatrix[4 * 4];

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
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLRENDERER_H_
