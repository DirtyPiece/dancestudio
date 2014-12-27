// =======================================================================
// <copyright file="Logger.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_LOGGER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_LOGGER_H_

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents the logger for Dance Studio.  Will output log files to the
/// user's computer for analysis if there is an error or issue.
/// </summary>
class Logger {
 public:
    /// <summary>
    /// Logs an informational message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    /// <param name="...">Arguments to format into the message.</param>
    void LogInfo(WCHAR* message, ...);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_LOGGER_H_
