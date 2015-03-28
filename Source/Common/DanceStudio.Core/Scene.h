// =======================================================================
// <copyright file="Scene.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_SCENE_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_SCENE_H_

#include "Model3d.h"
#include "Node3d.h"
#include <vector>

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
     /// Sets the root node of the scene.
     /// </summary>
     /// <param name="rootNode">The root node to set.</param>
     void SetRootNode(Node3d* rootNode);

     /// <summary>
     /// Gets the root node of the scene.
     /// </summary>
     /// <returns>The root node of the scene.</returns>
     const Node3d* GetRootNode() const;

 private:
     /// <summary>
     /// The root node of the scene.
     /// </summary>
     Node3d* rootNode;
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_SCENE_H_