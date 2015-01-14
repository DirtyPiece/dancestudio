// =======================================================================
// <copyright file="OpenGLExtensions.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-12-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLEXTENSIONS_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLEXTENSIONS_H_

#include "OpenGL.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents extension methods for OpenGL 4.
/// </summary>
class OpenGLExtensions {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="OpenGLExtensions"/> class.
    /// </summary>
    OpenGLExtensions();

    /// <summary>
    /// Loads the extension functions for OpenGL 4.0.
    /// Note that an OpenGL context must be active with a
    /// call to wglMakeCurrent before this funtion is called.
    /// </summary>
    void LoadExtensionFunctions();

    PFNGLATTACHSHADERPROC glAttachShader;
    PFNGLBINDBUFFERPROC glBindBuffer;
    PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
    PFNGLBUFFERDATAPROC glBufferData;
    PFNGLCOMPILESHADERPROC glCompileShader;
    PFNGLCREATEPROGRAMPROC glCreateProgram;
    PFNGLCREATESHADERPROC glCreateShader;
    PFNGLDELETEBUFFERSPROC glDeleteBuffers;
    PFNGLDELETEPROGRAMPROC glDeleteProgram;
    PFNGLDELETESHADERPROC glDeleteShader;
    PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
    PFNGLDETACHSHADERPROC glDetachShader;
    PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
    PFNGLGENBUFFERSPROC glGenBuffers;
    PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
    PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
    PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
    PFNGLGETPROGRAMIVPROC glGetProgramiv;
    PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
    PFNGLGETSHADERIVPROC glGetShaderiv;
    PFNGLLINKPROGRAMPROC glLinkProgram;
    PFNGLSHADERSOURCEPROC glShaderSource;
    PFNGLUSEPROGRAMPROC glUseProgram;
    PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
    PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
    PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
    PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
    PFNGLACTIVETEXTUREPROC glActiveTexture;
    PFNGLUNIFORM1IPROC glUniform1i;
    PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
    PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
    PFNGLUNIFORM3FVPROC glUniform3fv;
    PFNGLUNIFORM4FVPROC glUniform4fv;
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLEXTENSIONS_H_
