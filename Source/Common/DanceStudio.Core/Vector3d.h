// =======================================================================
// <copyright file="Constants.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-16-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_VECTOR3D_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_VECTOR3D_H_

#include "Typedefs.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a 3D vector.
/// </summary>
struct Vector3d {
    /// <summary>
    /// The x coordinate of the vector.
    /// </summary>
    SINGLE X;

    /// <summary>
    /// The y coordinate of the vector.
    /// </summary>
    SINGLE Y;

    /// <summary>
    /// The z coordinate of the vector.
    /// </summary>
    SINGLE Z;
};
}  // namespace DanceStudio
}  // namespace Core

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_VECTOR3D_H_