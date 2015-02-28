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
#include "AudioHelper.h"
#include "..\..\External\FMOD\inc\fmod.hpp"

using DanceStudio::Core::AudioHelper;

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

    /// <summary>
    /// Determines whether or not the passed in memory location was
    /// able to be allocated.
    /// </summary>
    /// <param name="memory">The memory.</param>
    /// <param name="memoryRegionName">
    /// The name of the memory region to validate.  If the memory is null,
    /// will use the parameter in the exception message as:
    /// [Ran out of memory while attempting to allocate for
    /// {memoryRegionName}.].
    /// </param>
    static inline void IsMemoryAllocated(
        const void* memory,
        const std::string& memoryRegionName) {
        if (memory == nullptr) {
            Throw::OutOfMemoryException(memoryRegionName);
        }
    }

    /// <summary>
    /// Determines whether the passed in XML node was found
    /// or not (null check).
    /// </summary>
    /// <param name="node">The node to check.</param>
    /// <param name="nodeName">The name of the node to check.</param>
    static inline void IsXmlNodeFound(
        void* node,
        const CHAR* nodeName) {
        assert(nodeName != nullptr);

        if (node == nullptr) {
            std::string message = 
                "The XML node with name '"
              + std::string(nodeName)
              + "' was not found.";

            Throw::InvalidOperationException(message);
        }
    }

    /// <summary>
    /// Determines whether the passed in XML attribute was found
    /// or not (null check).
    /// </summary>
    /// <param name="attribute">The attribute to check.</param>
    /// <param name="attributeName">The name of the attribute to check.</param>
    static inline void IsXmlAttributeFound(
        void* attribute,
        const CHAR* attributeName) {
        assert(attributeName != nullptr);

        if (attribute == nullptr) {
            std::string message =
                "The XML attribute with name '"
                + std::string(attributeName)
                + "' was not found.";

            Throw::InvalidOperationException(message);
        }
    }

    /// <summary>
    /// Determines whether the FMOD operation succeeded or not.
    /// </summary>
    /// <param name="result">The FMOD result value to check.</param>
    /// <param name="errorMessage">
    /// The error message to throw if the result check fails.
    /// </param>
    static inline void FmodOperationSucceeded(
        FMOD_RESULT result,
        const std::string& errorMessage) {
        if (result != FMOD_OK) {
            AudioHelper::LogFmodError(result);
            Throw::InvalidOperationException(errorMessage);
        }
    }
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_VALIDATOR_H_
