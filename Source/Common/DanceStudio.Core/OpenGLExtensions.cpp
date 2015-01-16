// =======================================================================
// <copyright file="OpenGLExtensions.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>10-12-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "OpenGLExtensions.h"

using DanceStudio::Core::OpenGLExtensions;

OpenGLExtensions::OpenGLExtensions() :
    glAttachShader(nullptr),
    glBindBuffer(nullptr),
    glBindVertexArray(nullptr),
    glBufferData(nullptr),
    glCompileShader(nullptr),
    glCreateProgram(nullptr),
    glCreateShader(nullptr),
    glDeleteBuffers(nullptr),
    glDeleteProgram(nullptr),
    glDeleteShader(nullptr),
    glDeleteVertexArrays(nullptr),
    glDetachShader(nullptr),
    glEnableVertexAttribArray(nullptr),
    glGenBuffers(nullptr),
    glGenVertexArrays(nullptr),
    glGetAttribLocation(nullptr),
    glGetProgramInfoLog(nullptr),
    glGetProgramiv(nullptr),
    glGetShaderInfoLog(nullptr),
    glGetShaderiv(nullptr),
    glLinkProgram(nullptr),
    glShaderSource(nullptr),
    glUseProgram(nullptr),
    glVertexAttribPointer(nullptr),
    glGetUniformLocation(nullptr),
    glUniformMatrix4fv(nullptr),
    glActiveTexture(nullptr),
    glUniform1i(nullptr),
    glGenerateMipmap(nullptr),
    glDisableVertexAttribArray(nullptr),
    glUniform3fv(nullptr),
    glUniform4fv(nullptr),
#ifdef _WIN32
    wglChoosePixelFormatARB(nullptr),
    wglCreateContextAttribsARB(nullptr),
    wglSwapIntervalEXT(nullptr) {
#endif  // _WIN32
}

void OpenGLExtensions::LoadExtensionFunctions() {
    glAttachShader = reinterpret_cast<PFNGLATTACHSHADERPROC>(
        wglGetProcAddress("glAttachShader"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glAttachShader,
        "glAttachShader");

    glBindBuffer = reinterpret_cast<PFNGLBINDBUFFERPROC>(
        wglGetProcAddress("glBindBuffer"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glBindBuffer,
        "glBindBuffer");

    glBindVertexArray = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(
        wglGetProcAddress("glBindVertexArray"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glBindVertexArray,
        "glBindVertexArray");

    glBufferData = reinterpret_cast<PFNGLBUFFERDATAPROC>(
        wglGetProcAddress("glBufferData"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glBufferData,
        "glBufferData");

    glBindBuffer = reinterpret_cast<PFNGLBINDBUFFERPROC>(
        wglGetProcAddress("glBindBuffer"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glBindBuffer,
        "glBindBuffer");

    glCompileShader = reinterpret_cast<PFNGLCOMPILESHADERPROC>(
        wglGetProcAddress("glCompileShader"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glCompileShader,
        "glCompileShader");

    glCreateProgram = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(
        wglGetProcAddress("glCreateProgram"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glCreateProgram,
        "glCreateProgram");

    glCreateShader = reinterpret_cast<PFNGLCREATESHADERPROC>(
        wglGetProcAddress("glCreateShader"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glCreateShader,
        "glCreateShader");

    glDeleteBuffers = reinterpret_cast<PFNGLDELETEBUFFERSPROC>(
        wglGetProcAddress("glDeleteBuffers"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glDeleteBuffers,
        "glDeleteBuffers");

    glDeleteProgram = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(
        wglGetProcAddress("glDeleteProgram"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glDeleteProgram,
        "glDeleteProgram");

    glDeleteShader = reinterpret_cast<PFNGLDELETESHADERPROC>(
        wglGetProcAddress("glDeleteShader"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glDeleteShader,
        "glDeleteShader");

    glDeleteVertexArrays = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(
        wglGetProcAddress("glDeleteVertexArrays"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glDeleteVertexArrays,
        "glDeleteVertexArrays");

    glDetachShader = reinterpret_cast<PFNGLDETACHSHADERPROC>(
        wglGetProcAddress("glDetachShader"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glDetachShader,
        "glDetachShader");

    glEnableVertexAttribArray =
        reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(
        wglGetProcAddress("glEnableVertexAttribArray"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glEnableVertexAttribArray,
        "glEnableVertexAttribArray");

    glGenBuffers = reinterpret_cast<PFNGLGENBUFFERSPROC>(
        wglGetProcAddress("glGenBuffers"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGenBuffers,
        "glGenBuffers");

    glGenVertexArrays = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(
        wglGetProcAddress("glGenVertexArrays"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGenVertexArrays,
        "glGenVertexArrays");

    glGetAttribLocation = reinterpret_cast<PFNGLGETATTRIBLOCATIONPROC>(
        wglGetProcAddress("glGetAttribLocation"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGetAttribLocation,
        "glGetAttribLocation");

    glGetProgramInfoLog = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>(
        wglGetProcAddress("glGetProgramInfoLog"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGetProgramInfoLog,
        "glGetProgramInfoLog");

    glBindBuffer = reinterpret_cast<PFNGLBINDBUFFERPROC>(
        wglGetProcAddress("glBindBuffer"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glBindBuffer,
        "glBindBuffer");

    glGetProgramiv = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(
        wglGetProcAddress("glGetProgramiv"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGetProgramiv,
        "glGetProgramiv");

    glGetShaderInfoLog = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(
        wglGetProcAddress("glGetShaderInfoLog"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGetShaderInfoLog,
        "glGetShaderInfoLog");

    glGetShaderiv = reinterpret_cast<PFNGLGETSHADERIVPROC>(
        wglGetProcAddress("glGetShaderiv"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGetShaderiv,
        "glGetShaderiv");

    glLinkProgram = reinterpret_cast<PFNGLLINKPROGRAMPROC>(
        wglGetProcAddress("glLinkProgram"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glLinkProgram,
        "glLinkProgram");

    glShaderSource = reinterpret_cast<PFNGLSHADERSOURCEPROC>(
        wglGetProcAddress("glShaderSource"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glShaderSource,
        "glShaderSource");

    glUseProgram = reinterpret_cast<PFNGLUSEPROGRAMPROC>(
        wglGetProcAddress("glUseProgram"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glUseProgram,
        "glUseProgram");

    glVertexAttribPointer = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(
        wglGetProcAddress("glVertexAttribPointer"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glVertexAttribPointer,
        "glVertexAttribPointer");

    glBindAttribLocation = reinterpret_cast<PFNGLBINDATTRIBLOCATIONPROC>(
        wglGetProcAddress("glBindAttribLocation"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glBindAttribLocation,
        "glBindAttribLocation");

    glGetUniformLocation = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(
        wglGetProcAddress("glGetUniformLocation"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGetUniformLocation,
        "glGetUniformLocation");

    glUniformMatrix4fv = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(
        wglGetProcAddress("glUniformMatrix4fv"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glUniformMatrix4fv,
        "glUniformMatrix4fv");

    glActiveTexture = reinterpret_cast<PFNGLACTIVETEXTUREPROC>(
        wglGetProcAddress("glActiveTexture"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glActiveTexture,
        "glActiveTexture");

    glUniform1i = reinterpret_cast<PFNGLUNIFORM1IPROC>(
        wglGetProcAddress("glUniform1i"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glUniform1i,
        "glUniform1i");

    glGenerateMipmap = reinterpret_cast<PFNGLGENERATEMIPMAPPROC>(
        wglGetProcAddress("glGenerateMipmap"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glGenerateMipmap,
        "glGenerateMipmap");

    glDisableVertexAttribArray =
        reinterpret_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(
        wglGetProcAddress("glDisableVertexAttribArray"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glDisableVertexAttribArray,
        "glDisableVertexAttribArray");

    glUniform3fv = reinterpret_cast<PFNGLUNIFORM3FVPROC>(
        wglGetProcAddress("glUniform3fv"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glUniform3fv,
        "glUniform3fv");

    glUniform4fv = reinterpret_cast<PFNGLUNIFORM4FVPROC>(
        wglGetProcAddress("glUniform4fv"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        glUniform4fv,
        "glUniform4fv");

#ifdef _WIN32
    wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(
        wglGetProcAddress("wglChoosePixelFormatARB"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        wglChoosePixelFormatARB,
        "wglChoosePixelFormatARB");

    wglCreateContextAttribsARB = reinterpret_cast<
        PFNWGLCREATECONTEXTATTRIBSARBPROC>(
        wglGetProcAddress("wglCreateContextAttribsARB"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        wglCreateContextAttribsARB,
        "wglCreateContextAttribsARB");

    wglSwapIntervalEXT = reinterpret_cast<PFNWGLSWAPINTERVALEXTPROC>(
        wglGetProcAddress("wglSwapIntervalEXT"));
    Validator::IsOpenGLExtensionFunctionLoaded(
        wglSwapIntervalEXT,
        "wglSwapIntervalEXT");
#endif  // _WIN32
}
