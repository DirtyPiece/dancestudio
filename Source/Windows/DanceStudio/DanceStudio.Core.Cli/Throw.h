// =======================================================================
// <copyright file="StepChartEditor.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-13-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_THROW_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_THROW_H_

using System::String;
using System::ArgumentNullException;
using System::ArgumentOutOfRangeException;
using System::InvalidOperationException;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a control that edits stepcharts for StepMania and
/// In The Groove arcade machines.
/// </summary>
public ref class Throw {
public:
    /// <summary>
    /// Throws an ArgumentNullException.
    /// </summary>
    /// <param name="parameterName">
    /// The name of the parameter that was null.
    /// </param>
    static void ArgumentNullException(String^ parameterName) {
        // We don't need to log here as it will be caught by the C#
        // exception handler.
        throw gcnew System::ArgumentNullException(parameterName);
    }

    /// <summary>
    /// Throws an ArgumentOutOfRangeException.
    /// </summary>
    /// <param name="parameterName">
    /// The name of the parameter that was out of range.
    /// </param>
    static void ArgumentOutOfRangeException(String^ parameterName) {
        // We don't need to log here as it will be caught by the C#
        // exception handler.
        throw gcnew System::ArgumentOutOfRangeException(parameterName);
    }

    /// <summary>
    /// Throws an InvalidOperationException.
    /// </summary>
    /// <param name="message">
    /// The message for the exception.
    /// </param>
    static void InvalidOperationException(String^ message) {
        // We don't need to log here as it will be caught by the C#
        // exception handler.
        throw gcnew System::InvalidOperationException(message);
    }
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_THROW_H_
