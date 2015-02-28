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

    // TODO(dirtypiece) - Need to make this constant string non constant and
    // copy the buffer.
    ParseModels(fileContents.c_str(), outScene);
}

void ColladaImporter::ParseModels(const CHAR* fileContents, Scene* scene) {
    assert(fileContents != nullptr);
    assert(scene != nullptr);

    // Use RapidXML to load the Collada XML document.
    rapidxml::xml_document<> doc;
    doc.parse<0>(const_cast<CHAR*>(fileContents));

    rapidxml::xml_node<CHAR>* colladaNode = doc.first_node("COLLADA");
    Validator::IsXmlNodeFound(colladaNode, "colladaNode");

    rapidxml::xml_node<CHAR>* libraryGeometriesNode =
        colladaNode->first_node("library_geometries");
    Validator::IsXmlNodeFound(libraryGeometriesNode, "libraryGeometriesNode");

    rapidxml::xml_node<CHAR>* geometryNode =
        libraryGeometriesNode->first_node("geometry");
    Validator::IsXmlNodeFound(geometryNode, "geometryNode");

    // Load all the models.
    UINT32 loadedModelCount = 0;
    do {
        rapidxml::xml_attribute<CHAR>* attribute =
            geometryNode->first_attribute("name");
        Validator::IsXmlAttributeFound(attribute, "geometry.name");

        Model3d* model = new Model3d();
        Logger::LogCoreVerbose(
            "Found model with name '"
            + std::string(attribute->value())
            + "' in the Collada file.");

        model->SetName(attribute->value());

        rapidxml::xml_node<CHAR>* meshNode =
            geometryNode->first_node("mesh");
        Validator::IsXmlNodeFound(meshNode, "meshNode");

        // The first source element contains the vertex positions.
        rapidxml::xml_node<CHAR>* sourceNode =
            meshNode->first_node("source");
        Validator::IsXmlNodeFound(sourceNode, "sourceNode");

        rapidxml::xml_node<CHAR>* floatArrayNode =
            sourceNode->first_node("float_array");
        Validator::IsXmlNodeFound(floatArrayNode, "floatArrayNode");

        std::vector<std::string> values = StringHelper::Split(
            floatArrayNode->value(),
            ' ');

        // Ensure that we only have triangles.
        if (values.size() % 3 != 0) {
            Throw::InvalidOperationException(
                "The Collada file contains non-3d positions (x, y, z)"
                " which are not supported.");
        }

        UINT32 vertexCount = values.size() / 3;
        OpenGLVertexType* vertices = new OpenGLVertexType[vertexCount];
        for (UINT32 i = 0; i < values.size(); i += 3) {
            INT32 vertexIndex = i / 3;
            vertices[vertexIndex].X = static_cast<SINGLE>(atof(values[i + 0].c_str()));
            vertices[vertexIndex].Y = static_cast<SINGLE>(atof(values[i + 1].c_str()));
            vertices[vertexIndex].Z = static_cast<SINGLE>(atof(values[i + 2].c_str()));
            vertices[vertexIndex].R = 0.0f;
            vertices[vertexIndex].G = 1.0f;
            vertices[vertexIndex].B = 0.0f;
        }

        model->SetVertices(vertices, vertexCount);
        delete[] vertices;
        vertices = nullptr;

        rapidxml::xml_node<CHAR>* polylistNode =
            meshNode->first_node("polylist");
        Validator::IsXmlNodeFound(polylistNode, "polylistNode");

        rapidxml::xml_node<CHAR>* pNode =
            polylistNode->first_node("p");
        Validator::IsXmlNodeFound(pNode, "pNode");

        values = StringHelper::Split(
            pNode->value(),
            ' ');

        // Ensure that we only have triangles.
        if (values.size() % 3 != 0) {
            Throw::InvalidOperationException(
                "The Collada file contains quadrangles"
                " which are not supported (only triangles).");
        }

        // Loads the indexes for rendering.
        // TODO(dirtypiece) - skip normals for now, but should load them later.
        UINT32* indices = new UINT32[values.size() / 2];
        for (UINT32 i = 0; i < values.size(); i += 2) {
            indices[i/2] = atoi(values[i/2].c_str());
        }

        model->SetIndices(indices, values.size() / 2);
        delete[] indices;
        indices = nullptr;

        scene->AddModel(model);

        ++loadedModelCount;
        geometryNode = geometryNode->next_sibling("geometry");
    } while (geometryNode != nullptr);

    std::stringstream stream;
    stream
        << "Loaded '"
        << loadedModelCount
        << "' models from the Collada file.";

    Logger::LogCoreInfo(stream.str());
}
