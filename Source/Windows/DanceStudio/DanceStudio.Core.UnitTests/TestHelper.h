// =======================================================================
// <copyright file="TestHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_TESTHELPER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_TESTHELPER_H_

#include "Typedefs.h"
#include <string>

namespace DanceStudioCoreUnitTests {
/// <summary>
/// Represents a class that contains static helper methods for dealing
/// with unit testing.
/// </summary>
class TestHelper {
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
    static std::string GetCurrentWorkingDirectory();

    /// <summary>
    /// Gets the test resources directory root path.
    /// </summary>
    /// <returns>The path to the resource directory root.</returns>
    static std::string GetResourceDirectory();

    /// <summary>
    /// Gets the full path to a test resource.
    /// </summary>
    /// <param name="localPath">
    /// The local path to the file (under the Resources folder).
    /// </param>
    /// <returns>The path to the resource directory root.</returns>
    static std::string GetFullResourcePath(
        const std::string& localPath);

    /// <summary>
    /// Loads the resource file as text.
    /// </summary>
    /// <param name="localPath">
    /// The local path to the file (under the Resources folder).
    /// </param>
    /// <returns>The contents of the file.</returns>
    static std::string LoadResourceFileAsText(
        const std::string& localPath);

    /// <summary>
    /// Performs a fuzzy equals operation against the passed
    /// in float values.
    /// </summary>
    /// <param name="first">The first value to compare.</param>
    /// <param name="second">The second value to compare.</param>
    /// <returns>
    /// <c>true</c> if the values are close to equal
    /// (within 0.001 margin of difference), <c>false</c>
    /// otherwise.
    /// </returns>
    static bool FuzzyEquals(SINGLE first, SINGLE second);
};
} // namespace DanceStudioCoreUnitTests {

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_TESTHELPER_H_