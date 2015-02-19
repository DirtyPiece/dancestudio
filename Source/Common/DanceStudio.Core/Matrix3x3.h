// =======================================================================
// <copyright file="Matrix3x3.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-18-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_MATRIX3X3_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_MATRIX3X3_H_

#include "Typedefs.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a 3x3 matrix.
/// </summary>
struct Matrix3x3 {
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
    /// <returns>The output matrix.</returns>
    static SINGLE* RotationYawPitchRoll(
        SINGLE* outMatrix,
        SINGLE yaw,
        SINGLE pitch,
        SINGLE roll);
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_MATRIX3X3_H_
