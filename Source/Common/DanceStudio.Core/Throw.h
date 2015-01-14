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
    /// Throws a std::runtime_error exception identifying that an invalid
    /// operation was performed.
    /// </summary>
    /// <param name="message">The exception message body.</param>
    static void InvalidOperationException(const std::string& message);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_THROW_H_
