// =======================================================================
// <copyright file="Node3d.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>03-27-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Node3d.h"
#include "Model3d.h"
#include "MathHelper.h"
#include "Matrix4x4.h"

using DanceStudio::Core::Node3d;
using DanceStudio::Core::MathHelper;
using DanceStudio::Core::Model3d;
using DanceStudio::Core::Matrix4x4;

Node3d::Node3d() {
}

Node3d::~Node3d() {
    this->FreeChildNodes(this);
}

void Node3d::AddModel(Model3d* model) {
    Validator::IsNotNull(model, "model");
    this->models.push_back(model);
}

UINT32 Node3d::GetModelCount() const {
    return this->models.size();
}

const Model3d* Node3d::GetModel(UINT32 index) const {
    Validator::IsArgumentOutOfRange(
        index >= this->GetModelCount(),
        "index");

    return this->models[index];
}

void Node3d::AddChild(Node3d* childNode) {
    Validator::IsNotNull(childNode, "childNode");
    this->children.push_back(childNode);
}

UINT32 Node3d::GetChildrenCount() const {
    return this->children.size();
}

const Node3d* Node3d::GetChild(UINT32 index) const {
    Validator::IsArgumentOutOfRange(
        index >= this->GetChildrenCount(),
        "index");

    return this->children[index];
}

const Matrix4x4& Node3d::GetTransformationMatrix() const {
    return this->transformationMatrix;
}

void Node3d::SetTransformationMatrix(const Matrix4x4& matrix) {
    this->transformationMatrix = matrix;
}

void Node3d::FreeChildNodes(Node3d* node) {
    assert(node != nullptr);

    // Delete all the children nodes.
    for (UINT32 i = 0; i < node->GetChildrenCount(); ++i) {
        Node3d* childNode = node->children[i];

        // Free the child's children first.
        this->FreeChildNodes(childNode);

        // Then free the child.
        delete childNode;
    }

    node->children.clear();
}
