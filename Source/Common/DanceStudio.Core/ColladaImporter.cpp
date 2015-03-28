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
#include "MathHelper.h"
#include "..\..\External\RapidXML\rapidxml.hpp"
#include "..\..\External\Assimp\include\assimp\Importer.hpp"
#include "..\..\External\Assimp\include\assimp\scene.h"
#include <sstream>

using DanceStudio::Core::ColladaImporter;
using DanceStudio::Core::Model3d;
using DanceStudio::Core::Scene;
using DanceStudio::Core::OpenGLVertexType;
using DanceStudio::Core::Node3d;
using DanceStudio::Core::MathHelper;
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

    SINGLE identityMatrix[4 * 4];
    MathHelper::BuildIdentityMatrix(identityMatrix);

    // Parse all nodes in the scene heirarchy (recursively) starting with the root.
    Node3d* rootNode = ParseNode(
        assetImporterScene,
        assetImporterScene->mRootNode,
        identityMatrix);

    scene->SetRootNode(rootNode);
}

Node3d* ColladaImporter::ParseNode(
    const aiScene* assetImporterScene,
    const aiNode* assetImportNode,
    const SINGLE* parentMatrix) {
    assert(assetImporterScene != nullptr);
    assert(assetImportNode != nullptr);
    assert(parentMatrix != nullptr);

    // Create the public node to represent this internal node.
    Node3d* node = new Node3d();

    // Parse all the meshes in this node.
    for (UINT32 i = 0; i < assetImportNode->mNumMeshes; ++i) {
        const aiMesh* mesh = assetImporterScene->mMeshes[assetImportNode->mMeshes[i]];

        Model3d* model = ParseMesh(mesh);
        if (model != nullptr) {
            node->AddModel(model);
        }
    }

    // Assign the matrix transformation for this node.
    SINGLE matrix[4 * 4];
    matrix[0] = assetImportNode->mTransformation.a1;
    matrix[1] = assetImportNode->mTransformation.a2;
    matrix[2] = assetImportNode->mTransformation.a3;
    matrix[3] = assetImportNode->mTransformation.a4;
    matrix[4] = assetImportNode->mTransformation.b1;
    matrix[5] = assetImportNode->mTransformation.b2;
    matrix[6] = assetImportNode->mTransformation.b3;
    matrix[7] = assetImportNode->mTransformation.b4;
    matrix[8] = assetImportNode->mTransformation.c1;
    matrix[9] = assetImportNode->mTransformation.c2;
    matrix[10] = assetImportNode->mTransformation.c3;
    matrix[11] = assetImportNode->mTransformation.c4;
    matrix[12] = assetImportNode->mTransformation.d1;
    matrix[13] = assetImportNode->mTransformation.d2;
    matrix[14] = assetImportNode->mTransformation.d3;
    matrix[15] = assetImportNode->mTransformation.d4;

    SINGLE worldMatrix[4 * 4];
    MathHelper::MultiplyMatrices(
        worldMatrix,
        parentMatrix,
        matrix);

    node->SetTransformationMatrix(worldMatrix);

    // Load all the child nodes and meshes.
    for (UINT32 i = 0; i < assetImportNode->mNumChildren; ++i) {
        const aiNode* childAssetImportNode = assetImportNode->mChildren[i];

        Node3d* childNode = ParseNode(
            assetImporterScene,
            childAssetImportNode,
            worldMatrix);

        node->AddChild(childNode);
    }

    return node;
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
