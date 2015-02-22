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
#include "..\..\External\RapidXML\rapidxml.hpp"
#include <sstream>

using DanceStudio::Core::ColladaImporter;
using DanceStudio::Core::Scene;

void ColladaImporter::Import(const CHAR* colladaFilePath, Scene* outScene) {
    Validator::IsNotNull(colladaFilePath, "colladaFilePath");
    Validator::IsNotNull(outScene, "outScene");

    Logger::LogCoreInfo(
        "Importing the Collada file at '"
      + std::string(colladaFilePath)
      + "'.");

    std::string fileContents = FileHelper::LoadAllFileText(colladaFilePath);
    ParseModels(fileContents.c_str(), outScene);
}

void ColladaImporter::ParseModels(const CHAR* fileContents, Scene* scene) {
    assert(fileContents != nullptr);
    assert(scene != nullptr);

    UINT32 loadedModelCount = 0;

    // Use RapidXML to load the Collada XML document.
    rapidxml::xml_document<> doc;
    doc.parse<0>(const_cast<CHAR*>(fileContents));

    doc.first_node("mesh");

    std::stringstream stream;
    stream
        << "Loaded '"
        << loadedModelCount
        << "' models from the Collada file.";

    Logger::LogCoreInfo(stream.str());
}

//bool ColladaImporter::ScanUntilXmlElement(
//    const CHAR* elementName,
//    const CHAR** currentCharacter) {
//    assert(elementName != nullptr);
//    assert(currentCharacter != nullptr);
//    assert(*currentCharacter != nullptr);
//
//    const CHAR* c = *currentCharacter;
//    while (stricmp(elementName, c) != 0) {
//        // Scan until we reach an element.
//        bool result = ScanUntilCharacter('<', &c);
//        if (!result) {
//            Logger::LogCoreVerbose(
//                "Reached the end of the Collada file (no more elements).");
//            return false;
//        }
//    }
//
//    *currentCharacter = c;
//    return true;
//}
//
//bool ColladaImporter::ReadXmlElementAttribute(
//    const CHAR* attributeName,
//    const CHAR** currentCharacter) {
//    assert(attributeName != nullptr);
//    assert(currentCharacter != nullptr);
//    assert(*currentCharacter != nullptr);
//
//    std::string attributeMatch = attributeName + std::string("=");
//    const CHAR* c = *currentCharacter;
//    while (*c != '>' && stricmp(attributeName, c) != 0) {
//        ++c;
//    }
//
//    if (*c == '>') {
//        // The attribute was not found.
//        return false;
//    }
//
//    return true;
//}
//
//bool ColladaImporter::ScanUntilCharacter(
//    CHAR character,
//    const CHAR** currentCharacter) {
//    assert(currentCharacter != nullptr);
//    assert(*currentCharacter != nullptr);
//
//    const CHAR* c = *currentCharacter;
//    while (*c != character && *c != '\0') {
//        ++c;
//    }
//
//    if (*c == character) {
//        *currentCharacter = c;
//        return true;
//    }
//
//    return false;
//}
