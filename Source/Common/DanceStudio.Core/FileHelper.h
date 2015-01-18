// =======================================================================
// <copyright file="FileHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-17-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_FILEHELPER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_FILEHELPER_H_

#include <string>

namespace DanceStudio {
namespace Core {
class FileHelper {
public:
    /// <summary>
    /// Loads all the text from a file.
    /// </summary>
    /// <param name="filePath">The file path to load.</param>
    /// <returns>The text contents of the file.</returns>
    static std::string LoadAllFileText(const std::string& filePath);

    /// <summary>
    /// Gets the executing executable directory.
    /// </summary>
    /// <returns>The path to the current exe.</returns>
    static std::string GetExecutingExeDirectory();
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_FILEHELPER_H_