// =======================================================================
// <copyright file="Model3d.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_MODEL3D_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_MODEL3D_H_

#include "Typedefs.h"
#include "OpenGLVertexType.h"
#include <string>

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a loaded 3D model with vertices, normals, etc.
/// </summary>
class Model3d {
 public:
     /// <summary>
     /// Initializes a new instance of the <see cref="Model3d"/> class.
     /// </summary>
     Model3d();

     /// <summary>
     /// Finalizes an instance of the <see cref="Model3d"/> class.
     /// </summary>
     ~Model3d();

     /// <summary>
     /// Sets the vertices that represent the model.
     /// </summary>
     /// <param name="vertexArray">
     /// The vertex array to store.  It is assumed that all vertices in this
     /// array are distinct so as to save memory when accessing from
     /// the index buffer.
     /// </param>
     /// <param name="arraySize">The size of the vertex array.</param>
     void SetVertices(const OpenGLVertexType* vertexArray, UINT32 arraySize);

     /// <summary>
     /// Sets the indices that represents the index buffer for
     /// rendering vertices.
     /// </summary>
     /// <param name="indexArray">The index array to store.</param>
     /// <param name="arraySize">The size of the index array.</param>
     void SetIndices(const UINT32* indexArray, UINT32 arraySize);

     /// <summary>
     /// Sets the name of the model.
     /// </summary>
     /// <param name="name">The name of the model.</param>
     void SetName(const CHAR* name);

     /// <summary>
     /// Gets the vertices for the model.
     /// </summary>
     /// <returns>The vertices for the model.</returns>
     OpenGLVertexType* GetVertices() const;

     /// <summary>
     /// Gets the vertex count of vertices in the model.
     /// </summary>
     /// <returns>The vertex count of vertices in the model.</returns>
     UINT32 GetVertexCount() const;

     /// <summary>
     /// Gets the indices for the model.
     /// </summary>
     /// <returns>The indices for the model.</returns>
     UINT32* GetIndices() const;

     /// <summary>
     /// Gets the index count of indices in the model.
     /// </summary>
     /// <returns>The index count of indices in the model.</returns>
     UINT32 GetIndexCount() const;

 private:
     /// <summary>
     /// The array of vertices that will be copied into an OpenGL vertex buffer
     /// for rendering into the scene.  It is assumed that all vertices in this
     /// array are distinct so as to save memory when accessing from
     /// the index buffer.
     /// </summary>
     OpenGLVertexType* vertices;

     /// <summary>
     /// The size of the array of vertices.
     /// </summary>
     UINT32 vertexArraySize;

     /// <summary>
     /// The array of indices that will be copied into an OpenGL index buffer
     /// for rendering into the scene.
     /// </summary>
     UINT32* indices;

     /// <summary>
     /// The size of the array of indices.
     /// </summary>
     UINT32 indexArraySize;

     /// <summary>
     /// The name of the model.
     /// </summary>
     std::string name;

     /// <summary>
     /// Deallocates the vertices.
     /// </summary>
     void FreeVertices();

     /// <summary>
     /// Deallocates the indices.
     /// </summary>
     void FreeIndices();
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_MODEL3D_H_