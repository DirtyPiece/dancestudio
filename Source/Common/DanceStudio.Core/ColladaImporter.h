// =======================================================================
// <copyright file="ColladaImporter.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_

#include "Scene.h"
#include "Model3d.h"
#include "Node3d.h"
#include "Matrix4x4.h"

// Forward declarations.
typedef struct aiScene;
typedef struct aiMesh;
typedef struct aiNode;

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents an importer that can open Collada 3D scene files.
/// </summary>
class ColladaImporter {
 public:
     /// <summary>
     /// Imports the specified collada file into a scene object.
     /// </summary>
     /// <param name="colladaFilePath">
     /// The path to the collada file to import (*.dae).
     /// </param>
     /// <param name="outScene">The imported scene.</param>
     static void Import(const CHAR* colladaFilePath, Scene* outScene);

 private:
     /// <summary>
     /// Parses the 3D models, materials, textures, cameras, etc.
     /// out of the Assimp scene.
     /// </summary>
     /// <param name="assetImportScene">
     /// The Assimp scene to load the models from.
     /// </param>
     /// <param name="scene">
     /// The parsed scene.
     /// </param>
     static void ParseScene(const aiScene* assetImportScene, Scene* scene);

     /// <summary>
     /// Parses the node heirarchy out of the passed in Assimp node.
     /// </summary>
     /// <param name="assetImporterScene">The asset importer scene.</param>
     /// <param name="assetImportNode">The asset import node.</param>
     /// <param name="parentMatrix">The parent matrix to apply to this node's matrix.</param>
     /// <returns>
     /// The node that was parsed, or <c>nullptr</c> if it could not be parsed.
     /// </returns>
     static Node3d* ParseNode(
         const aiScene* assetImporterScene,
         const aiNode* assetImportNode,
         const Matrix4x4& parentMatrix);

     /// <summary>
     /// Parses the model out of the passed in Assimp mesh.
     /// </summary>
     /// <param name="assetImportMesh">The Assimp mesh to parse from.</param>
     /// <returns>The model that was parsed, or <c>nullptr</c> if it could not be parsed.</returns>
     static Model3d* ParseMesh(const aiMesh* assetImportMesh);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_