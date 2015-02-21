// =======================================================================
// <copyright file="Matrix3x3.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-18-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Matrix3x3.h"
#include "Validator.h"

using DanceStudio::Core::Matrix3x3;

SINGLE* Matrix3x3::RotationYawPitchRoll(
    SINGLE* outMatrix,
    SINGLE yaw,
    SINGLE pitch,
    SINGLE roll) {
    Validator::IsNotNull(outMatrix, "outMatrix");

    // Get the cosine and sine values for the rotation.
    SINGLE yawCos = cosf(yaw);
    SINGLE pitchCos = cosf(pitch);
    SINGLE rollCos = cosf(roll);

    SINGLE yawSin = sinf(yaw);
    SINGLE pitchSin = sinf(pitch);
    SINGLE rollSin = sinf(roll);

    // Calculate the matrix.
    outMatrix[0] = (rollCos * yawCos) + (rollSin * pitchSin * yawSin);
    outMatrix[1] = (rollSin * pitchCos);
    outMatrix[2] = (rollCos * -yawSin) + (rollSin* pitchSin * yawCos);

    outMatrix[3] = (-rollSin * yawCos) + (rollCos * pitchSin * yawSin);
    outMatrix[4] = (rollCos * pitchCos);
    outMatrix[5] = (rollSin * yawSin) + (rollCos * pitchSin * yawCos);

    outMatrix[6] = (pitchCos * yawSin);
    outMatrix[7] = -pitchSin;
    outMatrix[8] = (pitchCos * yawCos);

    return outMatrix;
}
