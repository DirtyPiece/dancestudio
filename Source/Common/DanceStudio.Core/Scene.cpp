// =======================================================================
// <copyright file="Scene.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Scene.h"
#include "Model3d.h"
#include <vector>

using DanceStudio::Core::Scene;
using DanceStudio::Core::Model3d;

Scene::Scene() {
}

Scene::~Scene() {
    FreeModels();
}

void Scene::AddModel(Model3d* model) {
    this->models.push_back(model);
}

const std::vector<Model3d*>& Scene::GetModels() {
    return this->models;
}

UINT32 Scene::GetModelCount() const {
    return this->models.size();
}

void Scene::FreeModels() {
    for (UINT32 i = 0; i < this->models.size(); ++i) {
        delete this->models[i];
    }

    this->models.clear();
}
