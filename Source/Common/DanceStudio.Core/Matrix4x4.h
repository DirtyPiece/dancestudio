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

 private:
     /// <summary>
     /// The matrix component in column 1, row 1.
     /// </summary>
     SINGLE c1r1;

     /// <summary>
     /// The matrix component in column 1, row 2.
     /// </summary>
     SINGLE c1r2;

     /// <summary>
     /// The matrix component in column 1, row 3.
     /// </summary>
     SINGLE c1r3;

     /// <summary>
     /// The matrix component in column 1, row 4.
     /// </summary>
     SINGLE c1r4;

     /// <summary>
     /// The matrix component in column 2, row 1.
     /// </summary>
     SINGLE c2r1;

     /// <summary>
     /// The matrix component in column 2, row 2.
     /// </summary>
     SINGLE c2r2;

     /// <summary>
     /// The matrix component in column 2, row 3.
     /// </summary>
     SINGLE c2r3;

     /// <summary>
     /// The matrix component in column 2, row 4.
     /// </summary>
     SINGLE c2r4;

     /// <summary>
     /// The matrix component in column 3, row 1.
     /// </summary>
     SINGLE c3r1;

     /// <summary>
     /// The matrix component in column 3, row 2.
     /// </summary>
     SINGLE c3r2;

     /// <summary>
     /// The matrix component in column 3, row 3.
     /// </summary>
     SINGLE c3r3;

     /// <summary>
     /// The matrix component in column 3, row 4.
     /// </summary>
     SINGLE c3r4;

     /// <summary>
     /// The matrix component in column 4, row 1.
     /// </summary>
     SINGLE c4r1;

     /// <summary>
     /// The matrix component in column 4, row 2.
     /// </summary>
     SINGLE c4r2;

     /// <summary>
     /// The matrix component in column 4, row 3.
     /// </summary>
     SINGLE c4r3;

     /// <summary>
     /// The matrix component in column 4, row 4.
     /// </summary>
     SINGLE c4r4;
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
/// <param name="matrix">The matrix to multiply the vector by.</param>
/// <param name="vector">The vector to multiply.</param>
/// <returns>The result of the multiplication.</returns>
Vector3d operator*(const Matrix4x4& matrix, const Vector3d& vector);

}  // Core
}  // DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_MATRIX4X4_H_