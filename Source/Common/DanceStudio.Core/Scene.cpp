// =======================================================================
// <copyright file="Scene.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Scene.h"
#include "Model3d.h"
#include "Node3d.h"
#include <vector>

using DanceStudio::Core::Scene;
using DanceStudio::Core::Model3d;
using DanceStudio::Core::Node3d;

Scene::Scene() :
    rootNode(nullptr) {
}

Scene::~Scene() {
    assert(this->rootNode != nullptr);
    delete this->rootNode;
    this->rootNode = nullptr;
}

void Scene::SetRootNode(Node3d* rootNode) {
    Validator::IsNotNull(rootNode, "rootNode");

    this->rootNode = rootNode;
}

const Node3d* Scene::GetRootNode() const {
    return this->rootNode;
}
