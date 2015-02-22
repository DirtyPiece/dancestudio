// =======================================================================
// <copyright file="Coll.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#include "Stdafx.h"
#include "CppUnitTest.h"
#include "ColladaImporter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;  // NOLINT
using DanceStudio::Core::ColladaImporter;
using DanceStudioCoreUnitTests::TestHelper;

namespace DanceStudioCoreUnitTests {
TEST_CLASS(ColladaImporterTests) {
public:
    DANCE_STUDIO_TEST_METHOD(
        ParseModels_WhenCalledWithBoxFile_CorrectlyLoadsOneMesh,
        L"DirtyPiece") {
        std::string colladaFilePath = "Resources\\box.dae";
        std::string contents = TestHelper::LoadAllFileText(colladaFilePath);
    }
};
}  // namespace DanceStudioCoreUnitTests
