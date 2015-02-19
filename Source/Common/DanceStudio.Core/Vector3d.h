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

    /// <summary>
    /// Initializes a new instance of the <see cref="Vector3d"/> struct.
    /// </summary>
    Vector3d();

    /// <summary>
    /// Initializes a new instance of the <see cref="Vector3d"/> struct.
    /// </summary>
    /// <param name="x">The x coordinate.</param>
    /// <param name="y">The y coordinate.</param>
    /// <param name="z">The z coordinate.</param>
    Vector3d(SINGLE x, SINGLE y, SINGLE z);

    /// <summary>
    /// Transforms a vector using the passed in matrix.
    /// </summary>
    /// <param name="vector">The vector to transform.</param>
    /// <param name="matrix">The matrix to transform with.</param>
    /// <returns>This transformed vector.</returns>
    static Vector3d TransformCoordinate(
        const Vector3d& vector,
        const SINGLE* const matrix);

    /// <summary>
    /// Gets the length of the vector.
    /// </summary>
    /// <returns>The length of the vector.</returns>
    SINGLE GetLength() const;

    /// <summary>
    /// Normalizes the vector to length 1.
    /// </summary>
    /// <returns>This vector.</returns>
    Vector3d& Normalize();

    /// <summary>
    /// Gets the view matrix for the camera.
    /// </summary>
    /// <param name="matrix">The returned view matrix.</param>
    void GetViewMatrix(SINGLE* matrix);
};

/// <summary>
/// Operator overload for subtracting two vectors.
/// </summary>
/// <param name="v1">The left hand vector.</param>
/// <param name="v2">The right hand vector.</param>
/// <returns>The result of the subtraction.</returns>
Vector3d operator-(const Vector3d& v1, const Vector3d& v2);

/// <summary>
/// Operator overload for performing the cross product.
/// </summary>
/// <param name="v1">The left hand vector.</param>
/// <param name="v2">The right hand vector.</param>
/// <returns>The result of the cross product.</returns>
Vector3d operator%(const Vector3d& v1, const Vector3d& v2);

/// <summary>
/// Operator overload for performing the dot product.
/// </summary>
/// <param name="v1">The left hand vector.</param>
/// <param name="v2">The right hand vector.</param>
/// <returns>The result of the dot product.</returns>
SINGLE operator*(const Vector3d& v1, const Vector3d& v2);

}  // namespace DanceStudio
}  // namespace Core

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_VECTOR3D_H_