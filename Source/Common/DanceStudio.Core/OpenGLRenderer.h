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
    /// <param name="window">The window to render to.</param>
    explicit OpenGLRenderer(DS_HANDLE* window);

 private:
    /// <summary>
    /// The object that loads all of the OpenGL 4.0 extension functions.
    /// </summary>
    OpenGLExtensions extensions;

    /// <summary>
    /// Initializes OpenGL with the passed in window.
    /// </summary>
    /// <param name="window">The window to render to.</param>
    void Initialize(DS_HANDLE* window);

    /// <summary>
    /// Loads the Open GL function extension list (modern functions).
    /// </summary>
    void LoadExtensionList();
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLRENDERER_H_
