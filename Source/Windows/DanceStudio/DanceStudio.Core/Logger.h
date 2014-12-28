// =======================================================================
// <copyright file="Logger.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_LOGGER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_LOGGER_H_

#include <stdio.h>

namespace DanceStudio {
namespace Core {

/// <summary>
/// Represents the logger for Dance Studio.  Will output log files to the
/// user's computer for analysis if there is an error or issue.
/// </summary>
class Logger {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="Logger"/> class.
    /// </summary>
    /// <param name="outputDirectory">
    /// The output directory to store the log file at.
    /// </param>
    explicit Logger(const WCHAR* outputDirectory);

    /// <summary>
    /// Finalizes an instance of the <see cref="Logger"/> class.
    /// </summary>
    ~Logger();

    /// <summary>
    /// Logs a verbose message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogVerbose(const WCHAR* message);

    /// <summary>
    /// Logs an informational message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogInfo(const WCHAR* message);

    /// <summary>
    /// Logs a warning message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogWarning(const WCHAR* message);

    /// <summary>
    /// Logs an error message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogError(const WCHAR* message);

 private:
    /// <summary>
    /// The file pointer used to write to the log file.
    /// </summary>
    FILE* file;

    /// <summary>
    /// Logs the specified message with the format parameters supplied.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void Log(const WCHAR* message);
};

}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_LOGGER_H_
