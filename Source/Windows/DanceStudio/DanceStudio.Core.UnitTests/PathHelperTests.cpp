// =======================================================================
// <copyright file="PathHelperTests.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#include "Stdafx.h"
#include "CppUnitTest.h"
#include "PathHelper.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;  // NOLINT
using DanceStudio::Core::PathHelper;

namespace DanceStudioCoreUnitTests {
TEST_CLASS(PathHelperTests) {
 public:
    DANCE_STUDIO_TEST_METHOD(
        Combine_WhenCalledOnWindows_CorrectlyInsertsBackslash,
        L"DirtyPiece") {
        std::string path1 = "C:\\SomeTestPath";
        std::string path2 = "sometestfile.log";

        std::string result = PathHelper::Combine(path1, path2);
        Assert::AreEqual(
            "C:\\SomeTestPath\\sometestfile.log",
            result.c_str(),
            "The Windows path separator was not properly inserted.");
    }
};
}  // namespace DanceStudioCoreUnitTests
