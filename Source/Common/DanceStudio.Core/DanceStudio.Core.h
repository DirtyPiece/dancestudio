// =======================================================================
// <copyright file="DanceStudio.Core.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-04-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIO_CORE_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIO_CORE_H_

#include "Typedefs.h"

// The following functions are all wrappers to expose the functionality
// of DanceStudio.Core to Mac (Swift).
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
    /// <summary>
    /// Allocates memory for an application logger and returns a pointer to it.
    /// </summary>
    /// <param name="outputDirectory">
    /// The path to the output directory to store the log file in.
    /// </param>
    /// <returns>The pointer to the logger that was created.</returns>
    void* DSLogAllocateLogger(const CHAR* outputDirectory);

    /// <summary>
    /// Frees memory for an application logger.
    /// </summary>
    /// <param name="logger">The logger to free.</param>
    void DSLogFreeLogger(void* logger);

    /// <summary>
    /// Logs a verbose message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLogVerbose(void* logger, const WCHAR* message);

    /// <summary>
    /// Logs an informational message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLogInfo(void* logger, const WCHAR* message);

    /// <summary>
    /// Logs a warning message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLogWarning(void* logger, const WCHAR* message);

    /// <summary>
    /// Logs an error message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLogError(void* logger, const WCHAR* message);
#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIO_CORE_H_
