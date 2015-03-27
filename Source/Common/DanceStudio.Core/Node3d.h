// =======================================================================
// <copyright file="Node3d.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>03-27-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_NODE3D_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_NODE3D_H_

#include "Typedefs.h"

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

 private:
    /// <summary>
    /// The transformation matrix that is applied to this node.
    /// </summary>
    SINGLE* transformationMatrix;

    /// <summary>
    /// The number of child nodes that this node contains.
    /// </summary>
    UINT32 childrenCount;

    /// <summary>
    /// The children of this node.
    /// </summary>
    Node3d* children;
};
}  // Core
}  // DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_NODE3D_H_