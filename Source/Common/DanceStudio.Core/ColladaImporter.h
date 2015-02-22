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

     /*/// <summary>
     /// Scans the current character pointer until the specified
     /// XML element is located in the buffer.
     /// </summary>
     /// <param name="elementName">
     /// The name of the XML element to scan for (don't include brackets).
     /// The name is case insensitive.
     /// </param>
     /// <param name="currentCharacter">
     /// The current character position in the buffer.  The position
     /// after scanning will be at the point of the elements opening
     /// bracket, or its passed in position if not found.
     /// </param>
     /// <returns>
     /// <c>true</c> if the element was found, <c>false</c> otherwise.
     /// </returns>
     static bool ScanUntilXmlElement(
         const CHAR* elementName,
         const CHAR** currentCharacter);

     /// <summary>
     /// Reads an XML element attribute.
     /// </summary>
     /// <param name="attributeName">
     /// The name of the attribute to read.
     /// </param>
     /// <param name="currentCharacter">
     /// The current character to read from.  This method assumes that
     /// the position of the character is at the start of the element
     /// opening tag bracket.</param>
     /// <returns>
     /// <c>true</c> if the attribute was found, <c>false</c> otherwise.
     /// </returns>
     static bool ReadXmlElementAttribute(
         const CHAR* attributeName,
         std::string& attributeValue,
         const CHAR** currentCharacter);

     /// <summary>
     /// Scans the until the specified character is found.
     /// </summary>
     /// <param name="character">The character to scan for.</param>
     /// <param name="currentCharacter">The current character position.</param>
     /// <returns>
     /// <c>true</c> if the character was found, <c>false</c> otherwise.
     /// </returns>
     static bool ScanUntilCharacter(
         CHAR character,
         const CHAR** currentCharacter);*/
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_COLLADAIMPORTER_H_