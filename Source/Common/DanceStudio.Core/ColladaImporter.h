// =======================================================================
// <copyright file="ColladaImporter.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_

#include "Scene.h"

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
     /// Parses the 3D models out of the collada file contents.
     /// </summary>
     /// <param name="fileContents">
     /// The file contents to parse.
     /// </param>
     /// <param name="scene">
     /// The scene to add the parsed models to.
     /// </param>
     static void ParseModels(const CHAR* fileContents, Scene* scene);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_