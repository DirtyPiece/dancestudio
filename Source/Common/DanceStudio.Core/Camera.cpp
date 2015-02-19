// =======================================================================
// <copyright file="Camera.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-16-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "Camera.h"
#include "Vector3d.h"
#include "Matrix3x3.h"

using DanceStudio::Core::Camera;

Camera::Camera() :
    position(0, 0, -10.0f),
    lookAtPosition(0, 0, 0),
    rotationInRadians(0, 0, 0),
    upVector(0, 1, 0),
    lookAtVector(0, 0, -1.0f)
{
}

Camera::~Camera() {
}

void Camera::SetPosition(SINGLE x, SINGLE y, SINGLE z) {
    this->position.X = x;
    this->position.Y = y;
    this->position.Z = z;
}

void Camera::SetLookAtPosition(SINGLE x, SINGLE y, SINGLE z) {
    this->lookAtPosition.X = x;
    this->lookAtPosition.Y = y;
    this->lookAtPosition.Z = z;
}

void Camera::SetRotation(SINGLE xRadians, SINGLE yRadians, SINGLE zRadians) {
    this->rotationInRadians.X = xRadians;
    this->rotationInRadians.Y = yRadians;
    this->rotationInRadians.Z = zRadians;
}

void Camera::Update() {
    SINGLE rotationMatrix[9];

    // Create the rotation matrix to move the camera.
    Matrix3x3::RotationYawPitchRoll(
        rotationMatrix,
        this->rotationInRadians.Y,
        this->rotationInRadians.X,
        this->rotationInRadians.Z);

    // Transform the look at and up vectors.
    Vector3d::TransformCoordinate(this->lookAtVector, rotationMatrix);
    Vector3d::TransformCoordinate(this->upVector, rotationMatrix);

    Vector3d zAxis = (this->lookAtVector - this->position).Normalize();
    Vector3d xAxis = (this->upVector % zAxis).Normalize();
    Vector3d yAxis = zAxis % xAxis;

    SINGLE result1 = -(xAxis * this->position);
    SINGLE result2 = -(yAxis * this->position);
    SINGLE result3 = -(zAxis * this->position);

    // Set the view matrix.
    this->viewMatrix[0] = xAxis.X;
    this->viewMatrix[1] = yAxis.X;
    this->viewMatrix[2] = zAxis.X;
    this->viewMatrix[3] = 0.0f;

    this->viewMatrix[4] = xAxis.Y;
    this->viewMatrix[5] = yAxis.Y;
    this->viewMatrix[6] = zAxis.Y;
    this->viewMatrix[7] = 0.0f;

    this->viewMatrix[8] = xAxis.Z;
    this->viewMatrix[9] = yAxis.Z;
    this->viewMatrix[10] = zAxis.Z;
    this->viewMatrix[11] = 0.0f;

    this->viewMatrix[12] = result1;
    this->viewMatrix[13] = result2;
    this->viewMatrix[14] = result3;
    this->viewMatrix[15] = 1.0f;
}

void Camera::GetViewMatrix(SINGLE* outMatrix) {
    Validator::IsNotNull(outMatrix, "outMatrix");
    memcpy(outMatrix, this->viewMatrix, sizeof(this->viewMatrix));
}
