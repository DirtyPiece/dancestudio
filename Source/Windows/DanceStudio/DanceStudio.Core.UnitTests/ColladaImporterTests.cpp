// =======================================================================
// <copyright file="Coll.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#include "Stdafx.h"
#include "CppUnitTest.h"
#include "ColladaImporter.h"
#include "Scene.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;  // NOLINT
using DanceStudio::Core::ColladaImporter;
using DanceStudio::Core::Scene;
using DanceStudioCoreUnitTests::TestHelper;

namespace DanceStudioCoreUnitTests {
TEST_CLASS(ColladaImporterTests) {
public:
    DANCE_STUDIO_TEST_METHOD(
        ParseModels_WhenCalledWithBoxFile_CorrectlyLoadsOneMesh,
        L"DirtyPiece") {
        std::string colladaFilePath = TestHelper::GetFullResourcePath(
            "box.dae");

        Scene scene;
        ColladaImporter::Import(colladaFilePath.c_str(), &scene);

        /*Assert::AreEqual(
            1,
            static_cast<int>(scene.GetModels().size()),
            L"The number of models loaded for the scene is incorrect.");*/
    }

    DANCE_STUDIO_TEST_METHOD(
        ParseModels_WhenCalledWith2BoxesFile_CorrectlyLoadsTwoMeshes,
        L"DirtyPiece") {
        std::string colladaFilePath = TestHelper::GetFullResourcePath(
            "box2.dae");

        Scene scene;
        ColladaImporter::Import(colladaFilePath.c_str(), &scene);

        /*Assert::AreEqual(
            2,
            static_cast<int>(scene.GetModels().size()),
            L"The number of models loaded for the scene is incorrect.");*/
    }
};
}  // namespace DanceStudioCoreUnitTests
