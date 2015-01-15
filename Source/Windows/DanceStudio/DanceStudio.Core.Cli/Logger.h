// =======================================================================
// <copyright file="Logger.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_LOGGER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_LOGGER_H_

#include "..\..\..\Common\DanceStudio.Core\DanceStudio.Core.h"

using System::Object;
using System::String;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a logger that can log statements to a file for the application.
/// </summary>
public ref class Logger {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="Logger"/> class.
    /// </summary>
    /// <param name="outputDirectory">
    /// The output directory to log files to.
    /// </param>
    Logger(String^ outputDirectory);

    /// <summary>
    /// Finalizes an instance of the <see cref="Logger"/> class.
    /// </summary>
    ~Logger();

    /// <summary>
    /// Logs a verbose message to the log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    /// <param name="args">The arguments to format into the message.</param>
    void LogVerbose(String^ message, ... array<Object^>^ args);

    /// <summary>
    /// Logs an information message to the log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    /// <param name="args">The arguments to format into the message.</param>
    void LogInfo(String^ message, ... array<Object^>^ args);

    /// <summary>
    /// Logs a warning message to the log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    /// <param name="args">The arguments to format into the message.</param>
    void LogWarning(String^ message, ... array<Object^>^ args);

    /// <summary>
    /// Logs an error message to the log file.
    /// </summary>
    /// <param name="message">The message to log.</param>
    /// <param name="args">The arguments to format into the message.</param>
    void LogError(String^ message, ... array<Object^>^ args);

    /// <summary>
    /// Gets the singleton instance pf the logger.
    /// </summary>
    static property Logger^ Instance {
        Logger^ get() {
            if (instance == nullptr) {
                String^ logFolder = CreateLogFolder();
                instance = gcnew Logger(logFolder);
            }

            return instance;
        }
    }

 private:
     /// <summary>
     /// The native logger that is wrapped by this class.
     /// </summary>
     DS_LOGGER* logger;

     /// <summary>
     /// The singleton instance of the logger.
     /// </summary>
     static Logger^ instance = nullptr;

     /// <summary>
     /// Creates the folder where log files will be created and returns
     /// the folder path.
     /// </summary>
     /// <returns>
     /// The path to the folder where log files will be created.
     /// </returns>
     static String^ CreateLogFolder();
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_LOGGER_H_
