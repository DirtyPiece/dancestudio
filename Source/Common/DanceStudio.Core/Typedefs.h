// =======================================================================
// <copyright file="Typedefs.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_TYPEDEFS_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_TYPEDEFS_H_

// Integer types.
typedef char SBYTE;
typedef unsigned char BYTE;
typedef short INT16;  // NOLINT
typedef unsigned short UINT16;  // NOLINT
typedef int INT32;
typedef unsigned int UINT32;
typedef long long INT64;  // NOLINT
typedef unsigned long long UINT64;  // NOLINT

// Real types.
typedef float SINGLE;
typedef double DOUBLE;

// String types.
typedef char CHAR;
typedef wchar_t WCHAR;

// Dance Studio types.
typedef void DS_LOGGER;
typedef void DS_HANDLE;
typedef void DS_STEPCHARTEDITOR;
typedef void DS_AUDIOSTREAM;

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_TYPEDEFS_H_
