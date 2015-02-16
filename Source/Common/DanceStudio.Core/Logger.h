// =======================================================================
// <copyright file="Logger.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_LOGGER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_LOGGER_H_

#include <stdio.h>
#include <string>

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
    explicit Logger(const CHAR* outputDirectory);

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
    /// Logs a verbose message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogVerbose(const CHAR* message);

    /// <summary>
    /// Logs an informational message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogInfo(const WCHAR* message);

    /// <summary>
    /// Logs an informational message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogInfo(const CHAR* message);

    /// <summary>
    /// Logs a warning message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogWarning(const WCHAR* message);

    /// <summary>
    /// Logs a warning message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogWarning(const CHAR* message);

    /// <summary>
    /// Logs an error message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogError(const WCHAR* message);

    /// <summary>
    /// Logs an error message to the Dance Studio log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void LogError(const CHAR* message);

    /// <summary>
    /// Sets the global core logger.
    /// </summary>
    /// <param name="logger">The logger to set as the global logger.</param>
    static void SetCoreLogger(Logger* logger);

    /// <summary>
    /// Logs a verbose message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreVerbose(const WCHAR* message);

    /// <summary>
    /// Logs a verbose message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreVerbose(const CHAR* message);

    /// <summary>
    /// Logs a verbose message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreVerbose(const std::string& message);

    /// <summary>
    /// Logs an informational message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreInfo(const WCHAR* message);

    /// <summary>
    /// Logs an informational message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreInfo(const CHAR* message);

    /// <summary>
    /// Logs an informational message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreInfo(const std::string& message);

    /// <summary>
    /// Logs a warning message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreWarning(const WCHAR* message);

    /// <summary>
    /// Logs a warning message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreWarning(const CHAR* message);

    /// <summary>
    /// Logs a warning message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreWarning(const std::string& message);

    /// <summary>
    /// Logs an error message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreError(const WCHAR* message);

    /// <summary>
    /// Logs an error message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreError(const CHAR* message);

    /// <summary>
    /// Logs an error message for the core library.
    /// </summary>
    /// <param name="message">The message to log.</param>
    static void LogCoreError(const std::string& message);

 private:
    /// <summary>
    /// The file pointer used to write to the log file.
    /// </summary>
    FILE* file;

    /// <summary>
    /// The global core logger used to log information from this library.
    /// </summary>
    static Logger* globalLogger;

    /// <summary>
    /// Logs the specified message with the format parameters supplied.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void Log(const WCHAR* message);

    /// <summary>
    /// Logs the specified message with the format parameters supplied.
    /// </summary>
    /// <param name="message">The message to log.</param>
    void Log(const CHAR* message);
};

}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_LOGGER_H_
