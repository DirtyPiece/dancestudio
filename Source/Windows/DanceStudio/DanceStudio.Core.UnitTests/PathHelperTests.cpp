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
        std::wstring path1 = L"C:\\SomeTestPath";
        std::wstring path2 = L"sometestfile.log";

        std::wstring result = PathHelper::Combine(path1, path2);
        Assert::AreEqual(
            L"C:\\SomeTestPath\\sometestfile.log",
            result.c_str(),
            L"The Windows path separator was not properly inserted.");
    }
};
}  // namespace DanceStudioCoreUnitTests
