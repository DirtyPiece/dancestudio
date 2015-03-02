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

/// <summary>
/// Macro for marking function parameters as unused (to avoid warnings).
/// </summary>
#define DANCE_STUDIO_UNUSED(x) ((void)x)

/// <summary>
/// The maximum length of exception message details.
/// </summary>
#define DANCE_STUDIO_MAX_EXCEPTION_MESSAGE_LENGTH 1024

/// <summary>
/// The maximum length of exception callstack details.
/// </summary>
#define DANCE_STUDIO_MAX_CALLSTACK_LENGTH 1024

/// <summary>
/// The minimum speed that songs can be played back at.
/// </summary>
#define DANCE_STUDIO_MIN_SONG_PLAYBACK_SPEED 0.01f

/// <summary>
/// The maximum speed that songs can be played back at.
/// </summary>
#define DANCE_STUDIO_MAX_SONG_PLAYBACK_SPEED 100.0f

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_CONSTANTS_H_
