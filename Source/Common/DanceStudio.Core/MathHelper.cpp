// =======================================================================
// <copyright file="MathHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-17-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "MathHelper.h"

using DanceStudio::Core::MathHelper;

void MathHelper::BuildPerspectiveFovLHMatrix(
    SINGLE* returnedMatrix,
    SINGLE fieldOfView,
    SINGLE screenAspect,
    SINGLE screenNear,
    SINGLE screenFar) {
    Validator::IsNotNull(returnedMatrix, "returnedMatrix");
    Validator::IsArgumentOutOfRange(fieldOfView < 0.0f, "fieldOfView");
    Validator::IsArgumentOutOfRange(screenAspect < 0.0f, "screenAspect");
    Validator::IsArgumentOutOfRange(screenNear < 0.0f, "screenNear");
    Validator::IsArgumentOutOfRange(screenFar < 0.0f, "screenFar");

    returnedMatrix[0] = 1.0f / (screenAspect * tan(fieldOfView * 0.5f));
    returnedMatrix[1] = 0.0f;
    returnedMatrix[2] = 0.0f;
    returnedMatrix[3] = 0.0f;

    returnedMatrix[4] = 0.0f;
    returnedMatrix[5] = 1.0f / tan(fieldOfView * 0.5f);
    returnedMatrix[6] = 0.0f;
    returnedMatrix[7] = 0.0f;

    returnedMatrix[8] = 0.0f;
    returnedMatrix[9] = 0.0f;
    returnedMatrix[10] = screenFar / (screenFar - screenNear);
    returnedMatrix[11] = 1.0f;

    returnedMatrix[12] = 0.0f;
    returnedMatrix[13] = 0.0f;
    returnedMatrix[14] = (-screenNear * screenFar) / (screenFar - screenNear);
    returnedMatrix[15] = 0.0f;
}

void MathHelper::BuildOrthogonalLHMatrix(
    SINGLE* returnedMatrix,
    SINGLE width,
    SINGLE height,
    SINGLE znearDistance,
    SINGLE zfarDistance) {
    Validator::IsNotNull(returnedMatrix, "returnedMatrix");

    returnedMatrix[0] = 2.0f / width;
    returnedMatrix[1] = 0.0f;
    returnedMatrix[2] = 0.0f;
    returnedMatrix[3] = 0.0f;

    returnedMatrix[4] = 0.0f;
    returnedMatrix[5] = 2.0f / height;
    returnedMatrix[6] = 0.0f;
    returnedMatrix[7] = 0.0f;

    returnedMatrix[8] = 0.0f;
    returnedMatrix[9] = 0.0f;
    returnedMatrix[10] = 1.0f / (zfarDistance - znearDistance);
    returnedMatrix[11] = 0.0f;

    returnedMatrix[12] = 0.0f;
    returnedMatrix[13] = 0.0f;
    returnedMatrix[14] = znearDistance / (znearDistance - zfarDistance);
    returnedMatrix[15] = 1.0f;
}

void MathHelper::BuildIdentityMatrix(SINGLE* returnedMatrix) {
    Validator::IsNotNull(returnedMatrix, "returnedMatrix");

    returnedMatrix[0] = 1.0f;
    returnedMatrix[1] = 0.0f;
    returnedMatrix[2] = 0.0f;
    returnedMatrix[3] = 0.0f;

    returnedMatrix[4] = 0.0f;
    returnedMatrix[5] = 1.0f;
    returnedMatrix[6] = 0.0f;
    returnedMatrix[7] = 0.0f;

    returnedMatrix[8] = 0.0f;
    returnedMatrix[9] = 0.0f;
    returnedMatrix[10] = 1.0f;
    returnedMatrix[11] = 0.0f;

    returnedMatrix[12] = 0.0f;
    returnedMatrix[13] = 0.0f;
    returnedMatrix[14] = 0.0f;
    returnedMatrix[15] = 1.0f;
}

void MathHelper::BuildTranslationMatrix(
    SINGLE* returnedMatrix,
    SINGLE x,
    SINGLE y,
    SINGLE z) {
    Validator::IsNotNull(returnedMatrix, "returnedMatrix");

    returnedMatrix[0] = 1.0f;
    returnedMatrix[1] = 0.0f;
    returnedMatrix[2] = 0.0f;
    returnedMatrix[3] = 0.0f;

    returnedMatrix[4] = 0.0f;
    returnedMatrix[5] = 1.0f;
    returnedMatrix[6] = 0.0f;
    returnedMatrix[7] = 0.0f;

    returnedMatrix[8] = 0.0f;
    returnedMatrix[9] = 0.0f;
    returnedMatrix[10] = 1.0f;
    returnedMatrix[11] = 0.0f;

    returnedMatrix[12] = x;
    returnedMatrix[13] = y;
    returnedMatrix[14] = z;
    returnedMatrix[15] = 1.0f;
}

void MathHelper::MultiplyMatrices(
    SINGLE* returnedMatrix,
    const SINGLE* const matrix1,
    const SINGLE* const matrix2) {
    Validator::IsNotNull(returnedMatrix, "returnedMatrix");
    Validator::IsNotNull(matrix1, "matrix1");
    Validator::IsNotNull(matrix2, "matrix2");

    returnedMatrix[0] =
        (matrix1[0] * matrix2[0])
      + (matrix1[1] * matrix2[4])
      + (matrix1[2] * matrix2[8])
      + (matrix1[3] * matrix2[12]);

    returnedMatrix[1] =
        (matrix1[0] * matrix2[1])
      + (matrix1[1] * matrix2[5])
      + (matrix1[2] * matrix2[9])
      + (matrix1[3] * matrix2[13]);

    returnedMatrix[2] =
        (matrix1[0] * matrix2[2])
      + (matrix1[1] * matrix2[6])
      + (matrix1[2] * matrix2[10])
      + (matrix1[3] * matrix2[14]);

    returnedMatrix[3] =
        (matrix1[0] * matrix2[3])
      + (matrix1[1] * matrix2[7])
      + (matrix1[2] * matrix2[11])
      + (matrix1[3] * matrix2[15]);

    returnedMatrix[4] =
        (matrix1[4] * matrix2[0])
      + (matrix1[5] * matrix2[4])
      + (matrix1[6] * matrix2[8])
      + (matrix1[7] * matrix2[12]);

    returnedMatrix[5] =
        (matrix1[4] * matrix2[1])
      + (matrix1[5] * matrix2[5])
      + (matrix1[6] * matrix2[9])
      + (matrix1[7] * matrix2[13]);

    returnedMatrix[6] =
        (matrix1[4] * matrix2[2])
      + (matrix1[5] * matrix2[6])
      + (matrix1[6] * matrix2[10])
      + (matrix1[7] * matrix2[14]);

    returnedMatrix[7] =
        (matrix1[4] * matrix2[3])
      + (matrix1[5] * matrix2[7])
      + (matrix1[6] * matrix2[11])
      + (matrix1[7] * matrix2[15]);

    returnedMatrix[8] =
        (matrix1[8] * matrix2[0])
      + (matrix1[9] * matrix2[4])
      + (matrix1[10] * matrix2[8])
      + (matrix1[11] * matrix2[12]);

    returnedMatrix[9] =
        (matrix1[8] * matrix2[1])
      + (matrix1[9] * matrix2[5])
      + (matrix1[10] * matrix2[9])
      + (matrix1[11] * matrix2[13]);

    returnedMatrix[10] =
        (matrix1[8] * matrix2[2])
      + (matrix1[9] * matrix2[6])
      + (matrix1[10] * matrix2[10])
      + (matrix1[11] * matrix2[14]);

    returnedMatrix[11] =
        (matrix1[8] * matrix2[3])
      + (matrix1[9] * matrix2[7])
      + (matrix1[10] * matrix2[11])
      + (matrix1[11] * matrix2[15]);

    returnedMatrix[12] =
        (matrix1[12] * matrix2[0])
      + (matrix1[13] * matrix2[4])
      + (matrix1[14] * matrix2[8])
      + (matrix1[15] * matrix2[12]);

    returnedMatrix[13] =
        (matrix1[12] * matrix2[1])
      + (matrix1[13] * matrix2[5])
      + (matrix1[14] * matrix2[9])
      + (matrix1[15] * matrix2[13]);

    returnedMatrix[14] =
        (matrix1[12] * matrix2[2])
      + (matrix1[13] * matrix2[6])
      + (matrix1[14] * matrix2[10])
      + (matrix1[15] * matrix2[14]);

    returnedMatrix[15] =
        (matrix1[12] * matrix2[3])
      + (matrix1[13] * matrix2[7])
      + (matrix1[14] * matrix2[11])
      + (matrix1[15] * matrix2[15]);
}
