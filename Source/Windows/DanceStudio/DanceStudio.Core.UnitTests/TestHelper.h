// =======================================================================
// <copyright file="TestHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_TESTHELPER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_TESTHELPER_H_

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
};
} // namespace DanceStudioCoreUnitTests {

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_TESTHELPER_H_