// =======================================================================
// <copyright file="PathHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_PATHHELPER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_PATHHELPER_H_

#include <string>
#include "Constants.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a class that contains static helper methods for dealing with
/// path and file based operations in a platform independent way.
/// </summary>
class PathHelper {
 public:
     /// <summary>
     /// Combines the passed in two paths using the path separator
     /// appropriate for the current platform ('/' or '\\').
     /// </summary>
     /// <param name="path1">
     /// The first path to combine (should be something like "C:\path1").
     /// </param>
     /// <param name="path2">
     /// The second part of the path to combine
     /// (should be something without a root like "file1.bin").
     /// </param>
     /// <returns>
     /// The combined path with the proper path separator applied.
     /// </returns>
     static inline std::string Combine(
         const std::string& path1,
         const std::string& path2) {
         return path1 + DANCE_STUDIO_PATH_SEPARATOR + path2;
     }

     /// <summary>
     /// Gets a filename with the current date formatted as the name
     /// (with no extension).
     /// Example: "2014.12.26_10.27.00".
     /// </summary>
     /// <returns>The file name formatted with the current date.</returns>
     static std::string GetCurrentDateFileName();
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_PATHHELPER_H_
