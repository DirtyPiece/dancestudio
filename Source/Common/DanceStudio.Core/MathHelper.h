// =======================================================================
// <copyright file="MathHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-17-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_MATHHELPER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_MATHHELPER_H_

#include "Typedefs.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents helper methods for performing mathematical operations.
/// </summary>
class MathHelper {
 public:
    /// <summary>
    /// Builds a perspective field of view, left-handed
    /// perspective projection matrix.
    /// </summary>
    /// <param name="returnedMatrix">The returned projection matrix.</param>
    /// <param name="fieldOfView">
    /// The field of view of the eyepoint (in radians).
    /// </param>
    /// <param name="screenAspect">
    /// The screen aspect ratio (width / height).
    /// </param>
    /// <param name="screenNear">
    /// The screen near clipping plane distance from the eyepoint.
    /// </param>
    /// <param name="screenFar">
    /// The screen far clipping plane distance from the eyepoint.
    /// </param>
    static void BuildPerspectiveFovLHMatrix(
        SINGLE* returnedMatrix,
        SINGLE fieldOfView,
        SINGLE screenAspect,
        SINGLE screenNear,
        SINGLE screenFar);

    /// <summary>
    /// Builds a left-handed orthogonal projection matrix.
    /// </summary>
    /// <param name="returnedMatrix">The returned projection matrix.</param>
    /// <param name="width">The width of the view.</param>
    /// <param name="height">The height of the view.</param>
    /// <param name="znearDistance">
    /// The distance to the near clipping plane along the z-axis.
    /// </param>
    /// <param name="zfarDistance">
    /// The distance to the far clipping plan along the z-axis.
    /// </param>
    static void BuildOrthogonalLHMatrix(
        SINGLE* returnedMatrix,
        SINGLE width,
        SINGLE height,
        SINGLE znearDistance,
        SINGLE zfarDistance);

    /// <summary>
    /// Builds an identity matrix.
    /// </summary>
    /// <param name="returnedMatrix">The returned matrix.</param>
    static void BuildIdentityMatrix(SINGLE* returnedMatrix);

    /// <summary>
    /// Builds a translation matrix.
    /// </summary>
    /// <param name="returnedMatrix">The returned matrix.</param>
    /// <param name="x">The x translation factor.</param>
    /// <param name="y">The y translation factor.</param>
    /// <param name="z">The z translation factor.</param>
    static void BuildTranslationMatrix(
        SINGLE* returnedMatrix,
        SINGLE x,
        SINGLE y,
        SINGLE z);

    /// <summary>
    /// Multiplies two matrices together and returns the result.
    /// </summary>
    /// <param name="returnedMatrix">The returned matrix.</param>
    /// <param name="matrix1">The matrix1.</param>
    /// <param name="matrix2">The matrix2.</param>
    static void MultiplyMatrices(
        SINGLE* returnedMatrix,
        const SINGLE* const matrix1,
        const SINGLE* const matrix2);

    /// <summary>
    /// Returns the transpose of a matrix.
    /// </summary>
    /// <param name="returnedMatrix">The transposed matrix.</param>
    /// <param name="matrix">The matrix to return the transpose of.</param>
    static void TransposeMatrix(SINGLE* returnedMatrix, const SINGLE* matrix);

    /// <summary>
    /// Returns the inverse of the passed in matrix.
    /// </summary>
    /// <param name="returnedMatrix">The inverted matrix.</param>
    /// <param name="matrix">The matrix to return the inverse of.</param>
    /// <returns>
    /// <c>true</c> if the matrix was invertable,
    /// otherwise <c>false</c>.
    /// </returns>
    static bool InvertMatrix(SINGLE* returnedMatrix, const SINGLE* matrix);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_MATHHELPER_H_
