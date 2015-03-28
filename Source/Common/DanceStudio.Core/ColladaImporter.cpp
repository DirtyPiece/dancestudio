// =======================================================================
// <copyright file="ColladaImporter.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "ColladaImporter.h"
#include "FileHelper.h"
#include "Scene.h"
#include "StringHelper.h"
#include "Node3d.h"
#include "..\..\External\RapidXML\rapidxml.hpp"
#include "..\..\External\Assimp\include\assimp\Importer.hpp"
#include "..\..\External\Assimp\include\assimp\scene.h"
#include <sstream>

using DanceStudio::Core::ColladaImporter;
using DanceStudio::Core::Model3d;
using DanceStudio::Core::Scene;
using DanceStudio::Core::OpenGLVertexType;
using DanceStudio::Core::Node3d;
using Assimp::Importer;

void ColladaImporter::Import(const CHAR* colladaFilePath, Scene* outScene) {
    Validator::IsNotNull(colladaFilePath, "colladaFilePath");
    Validator::IsNotNull(outScene, "outScene");

    Logger::LogCoreInfo(
        "Importing the Collada file at '"
      + std::string(colladaFilePath)
      + "'.");

    // Use Assimp to load the Collada XML document.
    Importer assimpImporter;
    const struct aiScene* assetImporterScene = assimpImporter.ReadFile(
        colladaFilePath,
        0);

    if (assetImporterScene == nullptr) {
        std::string assimpError = assimpImporter.GetErrorString();
        Throw::InvalidOperationException(
            "Failed to import the Collada file at '"
            + std::string(colladaFilePath)
            + "' due to error:\n"
            + assimpError);
    }

    ParseScene(assetImporterScene, outScene);
}

void ColladaImporter::ParseScene(
    const aiScene* assetImporterScene,
    Scene* scene) {
    assert(assetImporterScene != nullptr);
    assert(scene != nullptr);

    if (!assetImporterScene->HasMeshes()) {
        Throw::InvalidOperationException(
            "The Collada file doesn't contain any meshes.");
    }

    // Load all the meshes in the scene.
    for (INT32 i = 0; i < assetImporterScene->mNumMeshes; ++i) {
        aiMesh* assetImportMesh = assetImporterScene->mMeshes[i];
        Model3d* model = ParseMesh(assetImportMesh);

        if (model != nullptr) {
            scene->AddModel(model);
        }
    }
}

Node3d* ColladaImporter::ParseNode(const aiScene* assetImporterScene, const aiNode* assetImportNode) {
    assert(assetImporterScene != nullptr);
    assert(assetImportNode != nullptr);

    // Parse all the meshes in this node.
    for (UINT32 i = 0; i < assetImportNode->mNumMeshes; ++i) {
        const aiMesh* mesh = assetImporterScene->mMeshes[assetImportNode->mMeshes[i]];

        Model3d* model = ParseMesh(mesh);

    }

    return nullptr;
}

Model3d* ColladaImporter::ParseMesh(const aiMesh* assetImportMesh) {
    assert(assetImportMesh != nullptr);

    if (assetImportMesh->mPrimitiveTypes != aiPrimitiveType_TRIANGLE) {
        Logger::LogCoreWarning(
            "Unable to load mesh '"
            + std::string(assetImportMesh->mName.C_Str())
            + "' as only triangles are supported.");

        return nullptr;
    }

    Model3d* model = new Model3d();
    Validator::IsMemoryAllocated(model, "a 3D model.");

    model->SetName(assetImportMesh->mName.C_Str());

    OpenGLVertexType* vertices = new OpenGLVertexType[assetImportMesh->mNumVertices];
    for (UINT32 i = 0; i < assetImportMesh->mNumVertices; ++i) {
        const aiVector3D* assetImportVertex = &assetImportMesh->mVertices[i];
        OpenGLVertexType* vertex = &vertices[i];

        vertex->X = assetImportVertex->x;
        vertex->Y = assetImportVertex->y;
        vertex->Z = assetImportVertex->z;

        vertex->R = 1;
        vertex->G = 1;
        vertex->B = 1;
    }

    model->SetVertices(vertices, assetImportMesh->mNumVertices);

    // All faces must be triangles.
    const UINT32 indexCount = assetImportMesh->mNumFaces * 3;
    UINT32* indices = new UINT32[indexCount];
    for (UINT32 i = 0; i < indexCount; i += 3) {
        const aiFace* assetImportFace = &assetImportMesh->mFaces[i / 3];
        indices[i + 0] = assetImportFace->mIndices[0];
        indices[i + 1] = assetImportFace->mIndices[1];
        indices[i + 2] = assetImportFace->mIndices[2];
    }

    model->SetIndices(indices, indexCount);

    return model;
}
