// =======================================================================
// <copyright file="Node3d.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>03-27-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_NODE3D_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_NODE3D_H_

#include "Typedefs.h"
#include "Model3d.h"
#include <vector>

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a loaded 3D node with transformation information.
/// </summary>
class Node3d {
 public:
     /// <summary>
     /// Initializes a new instance of the <see cref="Node3d"/> class.
     /// </summary>
     Node3d();

     /// <summary>
     /// Finalizes an instance of the <see cref="Node3d"/> class.
     /// </summary>
     ~Node3d();

     /// <summary>
     /// Adds the model to the node.
     /// </summary>
     /// <param name="model">The model to add to the node.</param>
     void AddModel(Model3d* model);

     /// <summary>
     /// Gets the number of models associated with the node.
     /// </summary>
     /// <returns>The number of models associated with the node.</returns>
     UINT32 GetModelCount() const;
 private:
    /// <summary>
    /// The transformation matrix that is applied to this node.
    /// </summary>
    SINGLE transformationMatrix[4 * 4];

    /// <summary>
    /// The number of child nodes that this node contains.
    /// </summary>
    UINT32 childrenCount;

    /// <summary>
    /// The children of this node.
    /// </summary>
    Node3d* children;

    /// <summary>
    /// The models that are associated with this node's transformation.
    /// </summary>
    std::vector<Model3d*> models;
};
}  // Core
}  // DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_NODE3D_H_