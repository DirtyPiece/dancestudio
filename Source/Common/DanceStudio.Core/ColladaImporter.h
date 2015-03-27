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

// Forward declarations.
typedef struct aiScene;
typedef struct aiMesh;

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
     /// Parses the model out of the passed in Assimp mesh.
     /// </summary>
     /// <param name="assetImportMesh">The Assimp mesh to parse from.</param>
     /// <returns>The model that was parsed.</returns>
     static Model3d* ParseMesh(const aiMesh* assetImportMesh);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_