// =======================================================================
// <copyright file="Constants.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CONSTANTS_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CONSTANTS_H_

/// <summary>
/// The path separator to use for the current operating system
/// that the user is using.
/// </summary>
const WCHAR DANCE_STUDIO_PATH_SEPARATOR =
#ifdef _WIN32
'\\';  // Windows
#else
'/';  // Mac
#endif  // _WIN32

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CONSTANTS_H_
