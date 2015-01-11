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
    /// ----------------------------------------------------------------------
    /// Logger functions.
    /// ----------------------------------------------------------------------

    /// <summary>
    /// Allocates memory for an application logger and returns a pointer to it.
    /// </summary>
    /// <param name="outputDirectory">
    /// The path to the output directory to store the log file in.
    /// </param>
    /// <returns>The pointer to the logger that was created.</returns>
    DS_LOGGER* DSLoggerAllocate(const CHAR* outputDirectory);

    /// <summary>
    /// Frees memory for an application logger.
    /// </summary>
    /// <param name="logger">The logger to free.</param>
    void DSLoggerFree(DS_LOGGER* logger);

    /// <summary>
    /// Logs a verbose message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLoggerLogVerbose(DS_LOGGER* logger, const WCHAR* message);

    /// <summary>
    /// Logs an informational message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLoggerLogInfo(DS_LOGGER* logger, const WCHAR* message);

    /// <summary>
    /// Logs a warning message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLoggerLogWarning(DS_LOGGER* logger, const WCHAR* message);

    /// <summary>
    /// Logs an error message to the log.
    /// </summary>
    /// <param name="logger">The logger to log the message with.</param>
    /// <param name="message">The message to log.</param>
    void DSLoggerLogError(DS_LOGGER* logger, const WCHAR* message);

    /// ----------------------------------------------------------------------
    /// Stepchart Editor functions.
    /// ----------------------------------------------------------------------

    /// <summary>
    /// Allocates the step chart editor.
    /// </summary>
    /// <param name="windowHandle">
    /// The handle to the window that the stepchart will be rendered into.
    /// </param>
    /// <returns>The allocated step chart editor.</returns>
    DS_STEPCHARTEDITOR* DSStepChartEditorAllocate(DS_HANDLE* windowHandle);

    /// <summary>
    /// Frees the step chart editor.
    /// </summary>
    /// <param name="windowHandle">
    /// The handle to the window that the stepchart will be rendered into.
    /// </param>
    void DSStepChartEditorFree(DS_STEPCHARTEDITOR* editor);

    /// <summary>
    /// Initializes the step chart editor.
    /// </summary>
    /// <param name="stepChartEditor">The step chart editor.</param>
    /// <param name="windowHandle">
    /// The handle to the window that the stepchart will be rendered into.
    /// </param>
    void DSStepChartEditorInitialize(
        DS_STEPCHARTEDITOR* stepChartEditor,
        DS_HANDLE* windowHandle);
#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIO_CORE_H_
