// =======================================================================
// <copyright file="Matrix4x4.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>03-29-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_MATRIX4X4_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_MATRIX4X4_H_

#include "Typedefs.h"
#include "Vector3d.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a 4x4 matrix.
/// </summary>
struct Matrix4x4 {
 public:
     /// <summary>
     /// Initializes a new instance of the <see cref="Matrix4x4"/> struct.
     /// </summary>
     Matrix4x4();

     /// <summary>
     /// Initializes a new instance of the <see cref="Matrix4x4"/> struct.
     /// </summary>
     /// <param name="matrix">
     /// The matrix to initialize the matrix with (16 elements, column major).
     /// </param>
     Matrix4x4(const SINGLE* matrix);

     /// <summary>
     /// Operator overload that returns a pointer to a column.
     /// </summary>
     /// <param name="column">The index of the column to retrieve.</param>
     /// <returns>
     /// A pointer to the column, which can be indexed by row.
     /// </returns>
     const SINGLE* operator[](const UINT32 column) const;

     /// <summary>
     /// Operator overload that returns a pointer to a column.
     /// </summary>
     /// <param name="column">The index of the column to retrieve.</param>
     /// <returns>
     /// A pointer to the column, which can be indexed by row.
     /// </returns>
     SINGLE* operator[](const UINT32 column);

     /// <summary>
     /// Gets the internal matrix representation.
     /// </summary>
     /// <returns>The matrix array (column major).</returns>
     SINGLE* Get();

     /// <summary>
     /// Gets the internal matrix representation.
     /// </summary>
     /// <returns>The matrix array (column major).</returns>
     const SINGLE* Get() const;

     /// <summary>
     /// Builds a perspective field of view, left-handed
     /// perspective projection matrix.
     /// </summary>
     /// <param name="fieldOfView">The field of view of the eyepoint (in radians).</param>
     /// <param name="screenAspect">The screen aspect ratio (width / height).</param>
     /// <param name="screenNear">The screen near clipping plane distance from the eyepoint.</param>
     /// <param name="screenFar">The screen far clipping plane distance from the eyepoint.</param>
     /// <returns>The perspective projection matrix.</returns>
     static Matrix4x4 PerspectiveLeftHanded(
         SINGLE fieldOfView,
         SINGLE screenAspect,
         SINGLE screenNear,
         SINGLE screenFar);

     /// <summary>
     /// Builds a left-handed orthogonal projection matrix.
     /// </summary>
     /// <param name="width">The width of the view.</param>
     /// <param name="height">The height of the view.</param>
     /// <param name="znearDistance">
     /// The distance to the near clipping plane along the z-axis.
     /// </param>
     /// <param name="zfarDistance">
     /// The distance to the far clipping plan along the z-axis.
     /// </param>
     /// <returns>The orthogonal projection matrix.</returns>
     static Matrix4x4 OrthogonalLeftHanded(
         SINGLE width,
         SINGLE height,
         SINGLE znearDistance,
         SINGLE zfarDistance);

     /// <summary>
     /// Builds a translation matrix.
     /// </summary>
     /// <param name="x">The x translation factor.</param>
     /// <param name="y">The y translation factor.</param>
     /// <param name="z">The z translation factor.</param>
     /// <returns>The translation matrix.</returns>
     static Matrix4x4 Translation(
         SINGLE x,
         SINGLE y,
         SINGLE z);

     /// <summary>
     /// Builds a rotation matrix along the x-axis by
     /// the specified number of degrees.
     /// </summary>
     /// <param name="degrees">The degrees to rotate by.</param>
     /// <returns>The rotation matrix around the x-axis.</returns>
     static Matrix4x4 RotationX(SINGLE degrees);

     /// <summary>
     /// Builds a rotation matrix along the y-axis by
     /// the specified number of degrees.
     /// </summary>
     /// <param name="degrees">The degrees to rotate by.</param>
     /// <returns>The rotation matrix around the y-axis.</returns>
     static Matrix4x4 RotationY(SINGLE degrees);

     /// <summary>
     /// Builds a rotation matrix along the z-axis by
     /// the specified number of degrees.
     /// </summary>
     /// <param name="degrees">The degrees to rotate by.</param>
     /// <returns>The rotation matrix around the z-axis.</returns>
     static Matrix4x4 RotationZ(SINGLE degrees);

     /// <summary>
     /// Returns a rotation matrix based on yaw,
     /// pitch, and roll.
     /// </summary>
     /// <param name="outMatrix">
     /// The returned rotation matrix (9 elements - 3x3).
     /// </param>
     /// <param name="yaw">The yaw rotation factor.</param>
     /// <param name="pitch">The pitch rotation factor.</param>
     /// <param name="roll">The roll rotation factor.</param>
     /// <returns>The rotation matrix.</returns>
     static Matrix4x4 RotationYawPitchRoll(
         SINGLE yaw,
         SINGLE pitch,
         SINGLE roll);

     /// <summary>
     /// Returns the transpose of a matrix.
     /// </summary>
     /// <param name="matrix">The matrix to return the transpose of.</param>
     /// <returns>The transposed matrix.</returns>
     static Matrix4x4 Transpose(const Matrix4x4& matrix);

     /// <summary>
     /// Builds the inverse of the passed in matrix.  If the
     /// inverse cannot be calculated, an exception will be
     /// thrown.
     /// </summary>
     /// <param name="matrix">The matrix to invert.</param>
     /// <returns>The inverted matrix.</returns>
     static Matrix4x4 Invert(const Matrix4x4& matrix);

 private:
     /// <summary>
     /// The components of the matrix.  (0-3) represents the first column,
     /// (4-7) represents column 2, etc.
     /// </summary>
     SINGLE components[4 * 4];
};

/// <summary>
/// Operator overload for multiplying two matrices.
/// </summary>
/// <param name="matrix1">The left hand matrix.</param>
/// <param name="matrix2">The right hand matrix.</param>
/// <returns>The result of the multiplication.</returns>
Matrix4x4 operator*(const Matrix4x4& matrix1, const Matrix4x4& matrix2);

/// <summary>
/// Operator overload for transforming a vector by a matrix.
/// </summary>
/// <param name="vector">The vector to multiply.</param>
/// <param name="matrix">The matrix to multiply the vector by.</param>
/// <returns>The result of the multiplication.</returns>
Vector3d operator*(const Vector3d& vector, const Matrix4x4& matrix);

}  // Core
}  // DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_MATRIX4X4_H_