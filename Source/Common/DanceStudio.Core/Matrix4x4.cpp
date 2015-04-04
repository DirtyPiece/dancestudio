// =======================================================================
// <copyright file="Matrix4x4.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>03-29-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Matrix4x4.h"

using DanceStudio::Core::Matrix4x4;

Matrix4x4::Matrix4x4() :
    c1r1(1.0f), c2r1(0.0f), c3r1(0.0f), c4r1(0.0f),
    c1r2(0.0f), c2r2(1.0f), c3r2(0.0f), c4r2(0.0f),
    c1r3(0.0f), c2r3(0.0f), c3r3(1.0f), c4r3(0.0f),
    c1r4(0.0f), c2r4(0.0f), c3r4(0.0f), c4r4(1.0f) {
}

Matrix4x4::Matrix4x4(const SINGLE* matrix) :
    c1r1(matrix[0]), c2r1(matrix[4]), c3r1(matrix[8]), c4r1(matrix[12]),
    c1r2(matrix[1]), c2r2(matrix[5]), c3r2(matrix[9]), c4r2(matrix[13]),
    c1r3(matrix[2]), c2r3(matrix[6]), c3r3(matrix[10]), c4r3(matrix[14]),
    c1r4(matrix[3]), c2r4(matrix[7]), c3r4(matrix[11]), c4r4(matrix[15]) {
}

Matrix4x4 DanceStudio::Core::operator*(const Matrix4x4& matrix1, const Matrix4x4& matrix2) {
    Matrix4x4 result;

    return result;
}
