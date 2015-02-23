// =======================================================================
// <copyright file="Model3d.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Model3d.h"
#include "OpenGLVertexType.h"

using DanceStudio::Core::Model3d;
using DanceStudio::Core::OpenGLVertexType;

Model3d::Model3d() :
    vertices(nullptr),
    indices(nullptr),
    name("<NoName>"),
    vertexArraySize(0),
    indexArraySize(0) {
}

Model3d::~Model3d() {
    FreeVertices();
    FreeIndices();
}

void Model3d::SetVertices(
    const OpenGLVertexType* vertexArray,
    UINT32 arraySize) {
    Validator::IsNotNull(vertexArray, "vertexArray");

    // Free any vertices we already have allocated.
    FreeVertices();

    // Copy the vertices in.
    this->vertices = new OpenGLVertexType[arraySize];
    Validator::IsMemoryAllocated(this->vertices, "a model vertex buffer.");
    memcpy(this->vertices, vertexArray, sizeof(OpenGLVertexType) * arraySize);
    this->vertexArraySize = arraySize;
}

void Model3d::SetIndices(
    const UINT32* indexArray,
    UINT32 arraySize) {
    Validator::IsNotNull(indexArray, "indexArray");

    // Free any indices we already have allocated.
    FreeIndices();

    // Copy the vertices in.
    this->indices = new UINT32[arraySize];
    Validator::IsMemoryAllocated(this->indices, "a model index buffer.");
    memcpy(this->indices, indexArray, sizeof(UINT32) * arraySize);
    this->indexArraySize = arraySize;
}

void Model3d::SetName(const CHAR* name) {
    Validator::IsNotNull(name, "name");

    this->name = name;
}

OpenGLVertexType* Model3d::GetVertices() const {
    return this->vertices;
}

UINT32 Model3d::GetVertexCount() const {
    return this->vertexArraySize;
}

UINT32* Model3d::GetIndices() const {
    return this->indices;
}

UINT32 Model3d::GetIndexCount() const {
    return this->indexArraySize;
}

void Model3d::FreeVertices() {
    if (this->vertices != nullptr) {
        delete[] this->vertices;
        this->vertices = nullptr;
        this->vertexArraySize = 0;
    }
}

void Model3d::FreeIndices() {
    if (this->indices != nullptr) {
        delete[] this->indices;
        this->indices = nullptr;
        this->indexArraySize = 0;
    }
}
