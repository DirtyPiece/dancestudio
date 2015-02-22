// =======================================================================
// <copyright file="OpenGLVertexType.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLVERTEXTYPE_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLVERTEXTYPE_H_

#include "Typedefs.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a loaded 3D model with vertices, normals, etc.
/// </summary>
struct OpenGLVertexType {
    /// <summary>
    /// The x coordinate of the vertex.
    /// </summary>
    SINGLE X;

    /// <summary>
    /// The y coordinate of the vertex.
    /// </summary>
    SINGLE Y;

    /// <summary>
    /// The z coordinate of the vertex.
    /// </summary>
    SINGLE Z;

    /// <summary>
    /// The red color component of the vertex.
    /// </summary>
    SINGLE R;

    /// <summary>
    /// The green color component of the vertex.
    /// </summary>
    SINGLE G;

    /// <summary>
    /// The blue color component of the vertex.
    /// </summary>
    SINGLE B;
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLVERTEXTYPE_H_