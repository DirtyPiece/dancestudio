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
    outMatrix[3] = 0;

    outMatrix[4] = (-rollSin * yawCos) + (rollCos * pitchSin * yawSin);
    outMatrix[5] = (rollCos * pitchCos);
    outMatrix[6] = (rollSin * yawSin) + (rollCos * pitchSin * yawCos);
    outMatrix[7] = 0;

    outMatrix[8] = (pitchCos * yawSin);
    outMatrix[9] = -pitchSin;
    outMatrix[10] = (pitchCos * yawCos);
    outMatrix[11] = 0;

    // Translation.
    outMatrix[12] = 0;
    outMatrix[13] = 0;
    outMatrix[14] = 0;
    outMatrix[15] = 1;

    return outMatrix;
}
