// =======================================================================
// <copyright file="Throw.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-12-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_THROW_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_THROW_H_

#include <string>

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents the main exception thrower for the Core library.
/// All exceptions thrown by the library should be done via this
/// class to ensure the exception is properly logged.
/// </summary>
class Throw {
 public:
    /// <summary>
    /// Throws a std::invalid_argument exception identifying the specified
    /// parameter name in the message.
    /// </summary>
    /// <param name="paramName">
    /// The name of the parameter that is <c>null</c>.
    /// </param>
    static void ArgumentNullException(const std::string& paramName);

    /// <summary>
    /// Throws a std::invalid_argument exception identifying the specified
    /// parameter name in the message.
    /// </summary>
    /// <param name="paramName">
    /// The name of the parameter that is out of range.
    /// </param>
    static void ArgumentOutOfRangeException(const std::string& paramName);

    /// <summary>
    /// Throws a std::runtime_error exception identifying that an invalid
    /// operation was performed.
    /// </summary>
    /// <param name="message">The exception message body.</param>
    static void InvalidOperationException(const std::string& message);

    /// <summary>
    /// Throws a std::runtime_error exception identifying that the program
    /// ran out of memory when attempting the allocation.
    /// </summary>
    /// <param name="memoryRegionName">
    /// The name of the memory location attempting to be allocated.
    /// </param>
    static void OutOfMemoryException(const std::string& memoryRegionName);

private:
    /// <summary>
    /// Throws a platform specific instruction (Windows versus Mac).
    /// </summary>
    /// <param name="title">
    /// The title to place in the exception.
    /// </param>
    /// <param name="message">
    /// The message body which includes things like the exception details.
    /// </param>
    /// <param name="exceptionCode">
    /// The exception code used to identify the type of exception on the
    /// managed side.
    /// </param>
    static void PlatformSpecificException(
        const std::string& title,
        const std::string& message,
        UINT32 exceptionCode);

    /// <summary>
    /// Gets the current callstack from the call point.
    /// </summary>
    /// <returns>The callstack string.</returns>
    static std::string GetCurrentCallstack();

#ifdef _WIN32
    /// <summary>
    /// Throws a Structured Exception Handling exception that will be marshaled
    /// through to C#.
    /// </summary>
    /// <param name="title">
    /// The title to place in the exception.
    /// </param>
    /// <param name="message">
    /// The message body which includes things like the exception details.
    /// </param>
    /// <param name="exceptionCode">
    /// The exception code used to identify the type of exception on the
    /// managed side.
    /// </param>
    static void SEHException(
        const std::string& title,
        const std::string& message,
        UINT32 exceptionCode);
#endif  // _WIN32
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_THROW_H_
