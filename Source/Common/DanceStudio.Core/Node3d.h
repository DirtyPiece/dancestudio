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
#include "Matrix4x4.h"
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

     /// <summary>
     /// Gets the model at the specified index.
     /// </summary>
     /// <param name="index">The index to retrieve the model for.</param>
     /// <returns>The model at the specified index.</returns>
     const Model3d* GetModel(UINT32 index) const;

     /// <summary>
     /// Adds the child node to this node.
     /// </summary>
     /// <param name="childNode">The child node to add.</param>
     void AddChild(Node3d* childNode);

     /// <summary>
     /// Gets the number of children in this node.
     /// </summary>
     /// <returns>The number of children in this node.</returns>
     UINT32 GetChildrenCount() const;

     /// <summary>
     /// Gets the child at the specified index.
     /// </summary>
     /// <param name="index">The index of the child element to retrieve.</param>
     /// <returns>The child at the specified index.</returns>
     const Node3d* GetChild(UINT32 index) const;

     /// <summary>
     /// Gets the transformation matrix for this node.
     /// </summary>
     /// <returns>The transformation for this node.</returns>
     const Matrix4x4& GetTransformationMatrix() const;

     /// <summary>
     /// Sets the transformation matrix values.
     /// </summary>
     /// <param name="matrix">The matrix to set the values from.</param>
     void SetTransformationMatrix(const Matrix4x4& matrix);

 private:
    /// <summary>
    /// The transformation matrix that is applied to this node.
    /// </summary>
    Matrix4x4 transformationMatrix;

    /// <summary>
    /// The children of this node.
    /// </summary>
    std::vector<Node3d*> children;

    /// <summary>
    /// The models that are associated with this node's transformation.
    /// </summary>
    std::vector<Model3d*> models;

    /// <summary>
    /// Frees the memory for the child nodes of the passed in node.
    /// </summary>
    /// <param name="node">
    /// The node to free memory for.
    /// </param>
    void FreeChildNodes(Node3d* node);
};
}  // Core
}  // DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_NODE3D_H_