// =======================================================================
// <copyright file="Matrix4x4.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>03-29-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Matrix4x4.h"

using DanceStudio::Core::Matrix4x4;

Matrix4x4::Matrix4x4() {
    // Set the matrix to be the identity.
    memset(this->components, 0, sizeof(this->components));
    this->components[0] = 1.0f;
    this->components[5] = 1.0f;
    this->components[10] = 1.0f;
    this->components[15] = 1.0f;
}

Matrix4x4::Matrix4x4(const SINGLE* matrix) {
    Validator::IsNotNull(matrix, "matrix");
    memcpy(this->components, matrix, sizeof(this->components));
}

Matrix4x4 DanceStudio::Core::operator*(const Matrix4x4& matrix1, const Matrix4x4& matrix2) {
    Matrix4x4 result;

    // Perform 4x4 matrix multiplication.
    // m m m m  m m m m
    // m m m m  m m m m
    // m m m m  m m m m
    // m m m m  m m m m
    for (UINT32 c = 0; c < 4; ++c) {
        for (UINT32 r = 0; r < 4; ++r) {
            result[c][r] =
                matrix1[c][0] * matrix2[0][r] +
                matrix1[c][1] * matrix2[1][r] +
                matrix1[c][2] * matrix2[2][r] +
                matrix1[c][3] * matrix2[3][r];
        }
    }

    return result;
}

const SINGLE* Matrix4x4::operator[](const UINT32 column) const {
    Validator::IsArgumentOutOfRange(column > 4, "column");
    return &this->components[column * 4];
}

SINGLE* Matrix4x4::operator[](const UINT32 column) {
    Validator::IsArgumentOutOfRange(column > 4, "column");
    return &this->components[column * 4];
}

Matrix4x4 Matrix4x4::PerspectiveLeftHanded(
    SINGLE fieldOfView,
    SINGLE screenAspect,
    SINGLE screenNear,
    SINGLE screenFar) {
    Validator::IsArgumentOutOfRange(fieldOfView < 0.0f, "fieldOfView");
    Validator::IsArgumentOutOfRange(screenAspect < 0.0f, "screenAspect");
    Validator::IsArgumentOutOfRange(screenNear < 0.0f, "screenNear");
    Validator::IsArgumentOutOfRange(screenFar < 0.0f, "screenFar");

    Matrix4x4 result;
    result.components[0] = 1.0f / (screenAspect * tan(fieldOfView * 0.5f));
    result.components[1] = 0.0f;
    result.components[2] = 0.0f;
    result.components[3] = 0.0f;

    result.components[4] = 0.0f;
    result.components[5] = 1.0f / tan(fieldOfView * 0.5f);
    result.components[6] = 0.0f;
    result.components[7] = 0.0f;

    result.components[8] = 0.0f;
    result.components[9] = 0.0f;
    result.components[10] = screenFar / (screenFar - screenNear);
    result.components[11] = 1.0f;

    result.components[12] = 0.0f;
    result.components[13] = 0.0f;
    result.components[14] = (-screenNear * screenFar) / (screenFar - screenNear);
    result.components[15] = 0.0f;

    return result;
}

Matrix4x4 Matrix4x4::OrthogonalLeftHanded(
    SINGLE width,
    SINGLE height,
    SINGLE znearDistance,
    SINGLE zfarDistance) {
    Matrix4x4 result;
    result.components[0] = 2.0f / width;
    result.components[1] = 0.0f;
    result.components[2] = 0.0f;
    result.components[3] = 0.0f;

    result.components[4] = 0.0f;
    result.components[5] = 2.0f / height;
    result.components[6] = 0.0f;
    result.components[7] = 0.0f;

    result.components[8] = 0.0f;
    result.components[9] = 0.0f;
    result.components[10] = 1.0f / (zfarDistance - znearDistance);
    result.components[11] = 0.0f;

    result.components[12] = 0.0f;
    result.components[13] = 0.0f;
    result.components[14] = znearDistance / (znearDistance - zfarDistance);
    result.components[15] = 1.0f;

    return result;
}

Matrix4x4 Matrix4x4::Translation(
    SINGLE x,
    SINGLE y,
    SINGLE z) {
    Matrix4x4 result;
    result.components[0] = 1.0f;
    result.components[1] = 0.0f;
    result.components[2] = 0.0f;
    result.components[3] = 0.0f;

    result.components[4] = 0.0f;
    result.components[5] = 1.0f;
    result.components[6] = 0.0f;
    result.components[7] = 0.0f;

    result.components[8] = 0.0f;
    result.components[9] = 0.0f;
    result.components[10] = 1.0f;
    result.components[11] = 0.0f;

    result.components[12] = x;
    result.components[13] = y;
    result.components[14] = z;
    result.components[15] = 1.0f;

    return result;
}

Matrix4x4 Matrix4x4::RotationYawPitchRoll(
    SINGLE yaw,
    SINGLE pitch,
    SINGLE roll) {
    Matrix4x4 result;

    // Get the cosine and sine values for the rotation.
    SINGLE yawCos = cosf(yaw);
    SINGLE pitchCos = cosf(pitch);
    SINGLE rollCos = cosf(roll);

    SINGLE yawSin = sinf(yaw);
    SINGLE pitchSin = sinf(pitch);
    SINGLE rollSin = sinf(roll);

    // Calculate the matrix.
    result.components[0] = (rollCos * yawCos) + (rollSin * pitchSin * yawSin);
    result.components[1] = (rollSin * pitchCos);
    result.components[2] = (rollCos * -yawSin) + (rollSin* pitchSin * yawCos);
    result.components[3] = 0;

    result.components[4] = (-rollSin * yawCos) + (rollCos * pitchSin * yawSin);
    result.components[5] = (rollCos * pitchCos);
    result.components[6] = (rollSin * yawSin) + (rollCos * pitchSin * yawCos);
    result.components[7] = 0;

    result.components[8] = (pitchCos * yawSin);
    result.components[9] = -pitchSin;
    result.components[10] = (pitchCos * yawCos);
    result.components[11] = 0;

    // Translation.
    result.components[12] = 0;
    result.components[13] = 0;
    result.components[14] = 0;
    result.components[15] = 1;

    return result;
}

Matrix4x4 Transpose(const Matrix4x4& matrix) {
    Matrix4x4 result;
    for (UINT32 c = 0; c < 4; ++c) {
        for (UINT32 r = 0; r < 4; ++r) {
            result[c][r] = matrix[r][c];
        }
    }

    return result;
}

Matrix4x4 Matrix4x4::Invert(const Matrix4x4& matrix) {
    Matrix4x4 result;
    result.components[0] =
        matrix.components[5] * matrix.components[10] * matrix.components[15] -
        matrix.components[5] * matrix.components[11] * matrix.components[14] -
        matrix.components[9] * matrix.components[6] * matrix.components[15] +
        matrix.components[9] * matrix.components[7] * matrix.components[14] +
        matrix.components[13] * matrix.components[6] * matrix.components[11] -
        matrix.components[13] * matrix.components[7] * matrix.components[10];

    result.components[4] =
        -matrix.components[4] * matrix.components[10] * matrix.components[15] +
        matrix.components[4] * matrix.components[11] * matrix.components[14] +
        matrix.components[8] * matrix.components[6] * matrix.components[15] -
        matrix.components[8] * matrix.components[7] * matrix.components[14] -
        matrix.components[12] * matrix.components[6] * matrix.components[11] +
        matrix.components[12] * matrix.components[7] * matrix.components[10];

    result.components[8] =
        matrix.components[4] * matrix.components[9] * matrix.components[15] -
        matrix.components[4] * matrix.components[11] * matrix.components[13] -
        matrix.components[8] * matrix.components[5] * matrix.components[15] +
        matrix.components[8] * matrix.components[7] * matrix.components[13] +
        matrix.components[12] * matrix.components[5] * matrix.components[11] -
        matrix.components[12] * matrix.components[7] * matrix.components[9];

    result.components[12] =
        -matrix.components[4] * matrix.components[9] * matrix.components[14] +
        matrix.components[4] * matrix.components[10] * matrix.components[13] +
        matrix.components[8] * matrix.components[5] * matrix.components[14] -
        matrix.components[8] * matrix.components[6] * matrix.components[13] -
        matrix.components[12] * matrix.components[5] * matrix.components[10] +
        matrix.components[12] * matrix.components[6] * matrix.components[9];

    result.components[1] =
        -matrix.components[1] * matrix.components[10] * matrix.components[15] +
        matrix.components[1] * matrix.components[11] * matrix.components[14] +
        matrix.components[9] * matrix.components[2] * matrix.components[15] -
        matrix.components[9] * matrix.components[3] * matrix.components[14] -
        matrix.components[13] * matrix.components[2] * matrix.components[11] +
        matrix.components[13] * matrix.components[3] * matrix.components[10];

    result.components[5] =
        matrix.components[0] * matrix.components[10] * matrix.components[15] -
        matrix.components[0] * matrix.components[11] * matrix.components[14] -
        matrix.components[8] * matrix.components[2] * matrix.components[15] +
        matrix.components[8] * matrix.components[3] * matrix.components[14] +
        matrix.components[12] * matrix.components[2] * matrix.components[11] -
        matrix.components[12] * matrix.components[3] * matrix.components[10];

    result.components[9] =
        -matrix.components[0] * matrix.components[9] * matrix.components[15] +
        matrix.components[0] * matrix.components[11] * matrix.components[13] +
        matrix.components[8] * matrix.components[1] * matrix.components[15] -
        matrix.components[8] * matrix.components[3] * matrix.components[13] -
        matrix.components[12] * matrix.components[1] * matrix.components[11] +
        matrix.components[12] * matrix.components[3] * matrix.components[9];

    result.components[13] =
        matrix.components[0] * matrix.components[9] * matrix.components[14] -
        matrix.components[0] * matrix.components[10] * matrix.components[13] -
        matrix.components[8] * matrix.components[1] * matrix.components[14] +
        matrix.components[8] * matrix.components[2] * matrix.components[13] +
        matrix.components[12] * matrix.components[1] * matrix.components[10] -
        matrix.components[12] * matrix.components[2] * matrix.components[9];

    result.components[2] =
        matrix.components[1] * matrix.components[6] * matrix.components[15] -
        matrix.components[1] * matrix.components[7] * matrix.components[14] -
        matrix.components[5] * matrix.components[2] * matrix.components[15] +
        matrix.components[5] * matrix.components[3] * matrix.components[14] +
        matrix.components[13] * matrix.components[2] * matrix.components[7] -
        matrix.components[13] * matrix.components[3] * matrix.components[6];

    result.components[6] =
        -matrix.components[0] * matrix.components[6] * matrix.components[15] +
        matrix.components[0] * matrix.components[7] * matrix.components[14] +
        matrix.components[4] * matrix.components[2] * matrix.components[15] -
        matrix.components[4] * matrix.components[3] * matrix.components[14] -
        matrix.components[12] * matrix.components[2] * matrix.components[7] +
        matrix.components[12] * matrix.components[3] * matrix.components[6];

    result.components[10] =
        matrix.components[0] * matrix.components[5] * matrix.components[15] -
        matrix.components[0] * matrix.components[7] * matrix.components[13] -
        matrix.components[4] * matrix.components[1] * matrix.components[15] +
        matrix.components[4] * matrix.components[3] * matrix.components[13] +
        matrix.components[12] * matrix.components[1] * matrix.components[7] -
        matrix.components[12] * matrix.components[3] * matrix.components[5];

    result.components[14] =
        -matrix.components[0] * matrix.components[5] * matrix.components[14] +
        matrix.components[0] * matrix.components[6] * matrix.components[13] +
        matrix.components[4] * matrix.components[1] * matrix.components[14] -
        matrix.components[4] * matrix.components[2] * matrix.components[13] -
        matrix.components[12] * matrix.components[1] * matrix.components[6] +
        matrix.components[12] * matrix.components[2] * matrix.components[5];

    result.components[3] =
        -matrix.components[1] * matrix.components[6] * matrix.components[11] +
        matrix.components[1] * matrix.components[7] * matrix.components[10] +
        matrix.components[5] * matrix.components[2] * matrix.components[11] -
        matrix.components[5] * matrix.components[3] * matrix.components[10] -
        matrix.components[9] * matrix.components[2] * matrix.components[7] +
        matrix.components[9] * matrix.components[3] * matrix.components[6];

    result.components[7] =
        matrix.components[0] * matrix.components[6] * matrix.components[11] -
        matrix.components[0] * matrix.components[7] * matrix.components[10] -
        matrix.components[4] * matrix.components[2] * matrix.components[11] +
        matrix.components[4] * matrix.components[3] * matrix.components[10] +
        matrix.components[8] * matrix.components[2] * matrix.components[7] -
        matrix.components[8] * matrix.components[3] * matrix.components[6];

    result.components[11] =
        -matrix.components[0] * matrix.components[5] * matrix.components[11] +
        matrix.components[0] * matrix.components[7] * matrix.components[9] +
        matrix.components[4] * matrix.components[1] * matrix.components[11] -
        matrix.components[4] * matrix.components[3] * matrix.components[9] -
        matrix.components[8] * matrix.components[1] * matrix.components[7] +
        matrix.components[8] * matrix.components[3] * matrix.components[5];

    result.components[15] =
        matrix.components[0] * matrix.components[5] * matrix.components[10] -
        matrix.components[0] * matrix.components[6] * matrix.components[9] -
        matrix.components[4] * matrix.components[1] * matrix.components[10] +
        matrix.components[4] * matrix.components[2] * matrix.components[9] +
        matrix.components[8] * matrix.components[1] * matrix.components[6] -
        matrix.components[8] * matrix.components[2] * matrix.components[5];

    SINGLE determinant;
    determinant =
        matrix.components[0] * result.components[0]
        + matrix.components[1] * result.components[4]
        + matrix.components[2] * result.components[8]
        + matrix.components[3] * result.components[12];

    if (determinant == 0.0f) {
        Throw::InvalidOperationException(
            "The passed in matrix is not invertible.");
    }

    determinant = 1.0f / determinant;

    for (INT32 i = 0; i < 16; i++) {
        result.components[i] *= determinant;
    }

    return result;
}
