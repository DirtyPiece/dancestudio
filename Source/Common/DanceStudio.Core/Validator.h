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
        const CHAR* parameterName) {
        if (parameter == nullptr) {
            const std::string& message =
                "The '"
              + std::string(parameterName)
              + "' parameter cannot be null.";

            throw std::invalid_argument(message);
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

            throw std::out_of_range(stream.str());
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
            throw std::out_of_range("The time could not be created.");
        }
    }
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_VALIDATOR_H_
