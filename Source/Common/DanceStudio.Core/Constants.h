// =======================================================================
// <copyright file="Constants.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_CONSTANTS_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_CONSTANTS_H_

#include "Typedefs.h"

/// <summary>
/// The path separator to use for the current operating system
/// that the user is using.
/// </summary>
#ifdef _WIN32  // Windows
#define DANCE_STUDIO_PATH_SEPARATOR '\\'
#else  // Mac
#define DANCE_STUDIO_PATH_SEPARATOR '/'
#endif  // _WIN32

/// <summary>
/// The newline ending for the current platform.
/// </summary>
#define DANCE_STUDIO_NEWLINE "\n"

/// <summary>
/// The newline ending for the current platform.
/// </summary>
#define DANCE_STUDIO_NEWLINE_W L"\n"

#define DANCE_STUDIO_UNUSED(x) ((void)x)

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_CONSTANTS_H_
