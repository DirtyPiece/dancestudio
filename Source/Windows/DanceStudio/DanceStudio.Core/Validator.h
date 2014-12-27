// =======================================================================
// <copyright file="Validator.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_VALIDATOR_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_VALIDATOR_H_

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
        if (parameter == NULL) {
            const std::string& message =
                "The '"
              + std::string(parameterName)
              + "' parameter cannot be null.";

            throw std::invalid_argument(message);
        }
    }

    /// <summary>
    /// Determines whether the passed in error code determines that
    /// a file was successfully created.  If not, it throws an
    /// out of range exception.
    /// </summary>
    /// <param name="errorCode">The error code.</param>
    static inline void IsFileCreated(errno_t errorCode) {
        if (errorCode != 0) {
            std::ostringstream stream;
            stream << "The file could not be created due to error code '"
                   << errorCode
                   << "'.";

            throw std::out_of_range(stream.str());
        }
    }

    /// <summary>
    /// Determines whether the passed in error code determines that
    /// a time value was successfully created.  If not, it throws an
    /// out of range exception.
    /// </summary>
    /// <param name="errorCode">The error code.</param>
    static inline void IsValidTime(errno_t errorCode) {
        if (errorCode != 0) {
            std::ostringstream stream;
            stream << "The time could not be created due to error code '"
                << errorCode
                << "'.";

            throw std::out_of_range(stream.str());
        }
    }
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_VALIDATOR_H_
