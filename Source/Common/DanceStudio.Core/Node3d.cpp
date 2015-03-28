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

using DanceStudio::Core::Node3d;
using DanceStudio::Core::MathHelper;
using DanceStudio::Core::Model3d;

Node3d::Node3d() :
    childrenCount(0),
    children(nullptr) {
    MathHelper::BuildIdentityMatrix(this->transformationMatrix);
}

Node3d::~Node3d() {
}

void Node3d::AddModel(Model3d* model) {
    this->models.push_back(model);
}