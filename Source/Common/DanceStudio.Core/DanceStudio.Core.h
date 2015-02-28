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
// of DanceStudio.Core to Mac (Swift) and C++/Cli.
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
    /// Sets a logger to use for logging from the Core library.  If
    /// set to <c>nullptr</c>, will not log.
    /// </summary>
    /// <param name="logger">
    /// The logger to set.  Can be <c>nullptr</c> to turn off core logging.
    /// </param>
    void DSLoggerSetCoreLogger(DS_LOGGER* logger);

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
    /// AudioStream functions.
    /// ----------------------------------------------------------------------

    /// <summary>
    /// Allocates an audio stream from the passed in audio file.  The returned
    /// stream can be used to play back the audio file to standard audio
    /// output.  The supported audio file formats are MP3, WAV, and OGG.
    /// </summary>
    /// <param name="audioFilePath">
    /// The file path of the audio file to load.
    /// </param>
    /// <returns>The audio stream which can be used for playback.</returns>
    DS_AUDIOSTREAM* DSAudioStreamAllocate(const CHAR* audioFilePath);

    /// <summary>
    /// Frees the passed in audio stream.
    /// </summary>
    /// <param name="stream">
    /// The stream to free.
    /// </param>
    void DSAudioStreamFree(DS_AUDIOSTREAM* stream);

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
    /// <param name="editor">
    /// The editor to free.
    /// </param>
    void DSStepChartEditorFree(DS_STEPCHARTEDITOR* editor);

    /// <summary>
    /// Updates and renders the step chart editor.
    /// </summary>
    /// <param name="editor">
    /// The editor to update.
    /// </param>
    void DSStepChartEditorUpdate(DS_STEPCHARTEDITOR* editor);

    /// <summary>
    /// Sets the audio stream that the Step Chart Editor will use
    /// to play a song when the user is editing.  The stream should
    /// already be created with a call to DSAudioStreamAllocate().
    /// </summary>
    /// <param name="editor">
    /// The editor to set the stream for.
    /// </param>
    /// <param name="stream">
    /// The stream to associate with the step chart editor.
    /// </param>
    void DSStepChartEditorSetAudioStream(
        DS_STEPCHARTEDITOR* editor,
        DS_AUDIOSTREAM* stream);
#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DANCESTUDIO_CORE_H_
