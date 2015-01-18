// =======================================================================
// <copyright file="Validator.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_VALIDATOR_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_VALIDATOR_H_

#include <sstream>
#include <string>
#include "Throw.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a class that contains static methods for validating
/// parameters and functionality.
/// </summary>
class Validator {
 public:
    /// <summary>
    /// Determines whether the passed in parameter is null and,
    /// if so, throws an invalid argument exception.
    /// </summary>
    /// <param name="parameter">The parameter to validate.</param>
    /// <param name="parameterName">The name of the parameter.</param>
    static inline void IsNotNull(
        const void* parameter,
        const std::string& parameterName) {
        if (parameter == nullptr) {
            Throw::ArgumentNullException(parameterName);
        }
    }

    /// <summary>
    /// Determines whether the passed in file that
    /// was successfully created.  If not, it throws an
    /// out of range exception.
    /// </summary>
    /// <param name="file">The pointer to the file handle to verify.</param>
    /// <param name="filePath">
    /// The path to the file that was attempted to be opened.
    /// </param>
    static inline void IsFileCreated(
        const FILE* file,
        const std::string& filePath) {
        if (file == nullptr) {
            std::stringstream stream;
            stream << "The file could not be created at '"
                   << filePath
                   << "'.";

            Throw::InvalidOperationException(stream.str());
        }
    }

    /// <summary>
    /// Determines whether the passed in file that
    /// was successfully opened.  If not, it throws an
    /// out of range exception.
    /// </summary>
    /// <param name="file">The pointer to the file handle to verify.</param>
    /// <param name="filePath">
    /// The path to the file that was attempted to be opened.
    /// </param>
    static inline void IsFileOpened(
        const FILE* file,
        const std::string& filePath) {
        if (file == nullptr) {
            std::stringstream stream;
            stream << "The file could not be opened at '"
                << filePath
                << "'.";

            Throw::InvalidOperationException(stream.str());
        }
    }

    /// <summary>
    /// Determines whether the passed in time pointer determines that
    /// a time value was successfully created.  If not, it throws an
    /// out of range exception.
    /// </summary>
    /// <param name="time">
    /// The time value to validate for not being <c>null</c>.
    /// </param>
    static inline void IsValidTime(const tm* time) {
        if (time == nullptr) {
            Throw::InvalidOperationException("The time could not be created.");
        }
    }

    /// <summary>
    /// Determines whether the passed in OpenGL extension function
    /// loaded properly or not.
    /// </summary>
    /// <param name="function">
    /// The function value to validate for not being <c>null</c>.
    /// </param>
    /// <param name="functionName">
    /// The name of the function being checked.
    /// </param>
    static inline void IsOpenGLExtensionFunctionLoaded(
        void* function,
        const std::string& functionName) {
        if (function == nullptr) {
            std::stringstream stream;
            stream << "The OpenGL extension function '"
                   << functionName
                   << "' was not loaded.";

            Throw::InvalidOperationException(stream.str());
        }
    }

    /// <summary>
    /// Determines whether the passed in parameter is out of range and,
    /// if so, throws an invalid argument exception.
    /// </summary>
    /// <param name="condition">
    /// The condition to test (if <c>true</c>, throws).
    /// </param>
    /// <param name="parameterName">The name of the parameter.</param>
    static inline void IsArgumentOutOfRange(
        bool condition,
        const std::string& parameterName) {
        if (condition) {
            Throw::ArgumentOutOfRangeException(parameterName);
        }
    }
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_VALIDATOR_H_
