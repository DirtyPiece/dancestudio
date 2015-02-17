// =======================================================================
// <copyright file="Constants.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-16-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_CAMERA_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_CAMERA_H_

#include "Typedefs.h"

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
     /// Gets the view matrix as an array.
     /// </summary>
     /// <returns>The array of view matrix components.</returns>
     SINGLE* GetViewMatrix();

 private:
     /// <summary>
     /// The x position of the camera.
     /// </summary>
     SINGLE xPosition;

     /// <summary>
     /// The y position of the camera.
     /// </summary>
     SINGLE yPosition;

     /// <summary>
     /// The z position of the camera.
     /// </summary>
     SINGLE zPosition;

     /// <summary>
     /// The x rotation of the camera.
     /// </summary>
     SINGLE xRotationInRadians;

     /// <summary>
     /// The y rotation of the camera.
     /// </summary>
     SINGLE yRotationInRadians;

     /// <summary>
     /// The z rotation of the camera.
     /// </summary>
     SINGLE zRotationInRadians;

     /// <summary>
     /// The view matrix components.
     /// </summary>
     SINGLE viewMatrix[16];
};
}  // namespace DanceStudio
}  // namespace Core

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_CAMERA_H_