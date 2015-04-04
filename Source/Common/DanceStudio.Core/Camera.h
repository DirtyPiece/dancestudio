// =======================================================================
// <copyright file="Constants.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-16-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_CAMERA_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_CAMERA_H_

#include "Typedefs.h"
#include "Vector3d.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a camera in 3D space.
/// </summary>
class Camera {
 public:
     /// <summary>
     /// Initializes a new instance of the <see cref="Camera"/> class.
     /// </summary>
     Camera();

     /// <summary>
     /// Finalizes an instance of the <see cref="Camera"/> class.
     /// </summary>
     ~Camera();

     /// <summary>
     /// Sets the position of the camera.
     /// </summary>
     /// <param name="x">The x position.</param>
     /// <param name="y">The y position.</param>
     /// <param name="z">The z position.</param>
     void SetPosition(SINGLE x, SINGLE y, SINGLE z);

     /// <summary>
     /// Sets the look at position of the camera.
     /// </summary>
     /// <param name="x">The x position to look at.</param>
     /// <param name="y">The y position to look at.</param>
     /// <param name="z">The z position to look at.</param>
     void SetLookAtPosition(SINGLE x, SINGLE y, SINGLE z);

     /// <summary>
     /// Sets the rotation of the camera.
     /// </summary>
     /// <param name="xRadians">The x amount in radians.</param>
     /// <param name="yRadians">The y amount in radians.</param>
     /// <param name="zRadians">The z amount in radians.</param>
     void SetRotation(SINGLE xRadians, SINGLE yRadians, SINGLE zRadians);

     /// <summary>
     /// Updates the transformation of the camera.
     /// </summary>
     void Update();

     /// <summary>
     /// Gets the view matrix.
     /// </summary>
     /// <param name="outMatrix">The output view matrix.</param>
     void GetViewMatrix(SINGLE* outMatrix);

     /// <summary>
     /// Zooms the camera by the specified distance along the look at vector.
     /// </summary>
     /// <param name="distance">The distance to zoom the camera.</param>
     void Zoom(SINGLE distance);

     /// <summary>
     /// Rotates the camera along the x and y world axes.
     /// </summary>
     /// <param name="xRadians">The x radians to rotate.</param>
     /// <param name="yRadians">The y radians to rotate.</param>
     void RotateWorld(SINGLE xRadians, SINGLE yRadians);

 private:
     /// <summary>
     /// The position of the camera.
     /// </summary>
     Vector3d position;

     /// <summary>
     /// The position that the camera is looking at.
     /// </summary>
     Vector3d lookAtPosition;

     /// <summary>
     /// The rotation vector for the rotation along yaw, pitch, and roll
     /// for the camera (local coordinate system).
     /// </summary>
     Vector3d rotationInRadians;

     /// <summary>
     /// The up vector of the camera.
     /// </summary>
     Vector3d upVector;

     /// <summary>
     /// The look-at vector of the camera.
     /// </summary>
     Vector3d lookAtVector;

     /// <summary>
     /// The view matrix components.
     /// </summary>
     SINGLE viewMatrix[16];
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_CAMERA_H_
