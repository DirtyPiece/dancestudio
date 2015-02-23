// =======================================================================
// <copyright file="StringHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-22-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_STRINGHELPER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_STRINGHELPER_H_

#include "Typedefs.h"
#include <string>
#include <vector>

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a helper for dealing with string operations.
/// </summary>
class StringHelper {
public:
    /// <summary>
    /// Splits the specified string into a list of strings
    /// using the specified delimiter character.
    /// </summary>
    /// <param name="str">The string to split.</param>
    /// <param name="delimiter">The delimiter to split on.</param>
    /// <returns>The split string (can contain empty entries).</returns>
    static std::vector<std::string> Split(const std::string& str, CHAR delimiter);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_STRINGHELPER_H_
