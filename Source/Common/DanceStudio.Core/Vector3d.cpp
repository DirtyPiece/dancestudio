// =======================================================================
// <copyright file="Vector3d.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-18-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Vector3d.h"

using DanceStudio::Core::Vector3d;

Vector3d::Vector3d() :
    X(0.0f),
    Y(0.0f),
    Z(0.0f) {
}

Vector3d::Vector3d(SINGLE x, SINGLE y, SINGLE z) :
    X(x),
    Y(y),
    Z(z) {
}

Vector3d Vector3d::TransformCoordinate(
    const Vector3d& vector,
    const SINGLE* const matrix) {
    SINGLE x;
    SINGLE y;
    SINGLE z;

    x =
        (vector.X * matrix[0])
      + (vector.Y * matrix[3])
      + (vector.Z * matrix[6]);

    y =
        (vector.X * matrix[1])
      + (vector.Y * matrix[4])
      + (vector.Z * matrix[7]);

    z =
        (vector.X * matrix[2])
      + (vector.Y * matrix[5])
      + (vector.Z * matrix[8]);

    return vector;
}

SINGLE Vector3d::GetLength() const {
    return sqrt(
        (this->X * this->X)
      + (this->Y * this->Y)
      + (this->Z * this->Z));
}

Vector3d& Vector3d::Normalize() {
    SINGLE length = this->GetLength();
    this->X /= length;
    this->Y /= length;
    this->Z /= length;

    return *this;
}

Vector3d DanceStudio::Core::operator-(const Vector3d& v1, const Vector3d& v2) {
    return Vector3d(
        v1.X - v2.X,
        v1.Y - v2.Y,
        v1.Z - v2.Z);
}

Vector3d DanceStudio::Core::operator%(const Vector3d& v1, const Vector3d& v2) {
    return Vector3d(
        v1.Y * v2.Z - v1.Z * v2.Y,
        v1.Z * v2.X - v1.X * v2.Z,
        v1.X * v2.Y - v1.Y * v2.X);
}

SINGLE DanceStudio::Core::operator*(const Vector3d& v1, const Vector3d& v2) {
    return (v1.X * v2.X) + (v1.Y * v2.Y) + (v1.Z * v2.Z);
}
