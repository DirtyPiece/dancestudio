// =======================================================================
// <copyright file="Throw.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-12-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIOEXCEPTIONTYPE_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIOEXCEPTIONTYPE_H_

/// <summary>
/// Represents the different exception types that can be thrown
/// by core.
/// </summary>
enum DanceStudioExceptionTypes {
    /// <summary>
    /// The starting marker for the range of vales in this enum.
    /// </summary>
    DANCE_STUDIO_EXCEPTION_TYPE_START,

    /// <summary>
    /// Exception type for an argument null exception.
    /// </summary>
    DANCE_STUDIO_EXCEPTION_TYPE_ARGUMENT_NULL =
        DANCE_STUDIO_EXCEPTION_TYPE_START,

    /// <summary>
    /// Exception type for an argument out of range exception.
    /// </summary>
    DANCE_STUDIO_EXCEPTION_TYPE_ARGUMENT_OUT_OF_RANGE,

    /// <summary>
    /// Exception type for an invalid operation exception.
    /// </summary>
    DANCE_STUDIO_EXCEPTION_TYPE_INVALID_OPERATION,

    /// <summary>
    /// Exception type for an out of memory exception.
    /// </summary>
    DANCE_STUDIO_EXCEPTION_TYPE_OUT_OF_MEMORY,

    /// <summary>
    /// The ending marker for the range of vales in this enum.
    /// </summary>
    DANCE_STUDIO_EXCEPTION_TYPE_END,
};

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIOEXCEPTIONTYPE_H_