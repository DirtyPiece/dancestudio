// =======================================================================
// <copyright file="VertexShader.vs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-17-2015</date>
// =======================================================================

// Version 4.0 GLSL.
#version 400

// The input vertex position.
in vec3 inputPosition;

// The input vertex color.
in vec3 inputColor;

// The output color passed to the pixel shader.
out vec3 outColor;

// Uniform variables calculated once.
uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
    // Calculate the position of the vertex against the world, view, and projection matrices.
    gl_Position = worldMatrix * vec4(inputPosition, 1.0f);
    gl_Position = viewMatrix * gl_Position;
    gl_Position = projectionMatrix * gl_Position;

    // Store the input color for the pixel shader to use.
    color = inputColor;
}