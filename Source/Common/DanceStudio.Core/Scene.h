// =======================================================================
// <copyright file="Scene.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_SCENE_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_SCENE_H_

#include "Model3d.h"
#include <list>

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a 3D scene that contains objects such as
/// models, materials, lights, and animations.
/// </summary>
class Scene {
 public:
     /// <summary>
     /// Initializes a new instance of the <see cref="Scene"/> class.
     /// </summary>
     Scene();

     /// <summary>
     /// Finalizes an instance of the <see cref="Scene"/> class.
     /// </summary>
     ~Scene();

     /// <summary>
     /// Adds a model to the scene.
     /// </summary>
     /// <param name="model">The model to add to the scene.</param>
     void AddModel(Model3d* model);

 private:
     /// <summary>
     /// The list of models that have been placed in the scene.
     /// </summary>
     std::list<Model3d*> models;
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_SCENE_H_