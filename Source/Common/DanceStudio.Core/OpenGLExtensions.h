// =======================================================================
// <copyright file="OpenGLExtensions.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-12-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLEXTENSIONS_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLEXTENSIONS_H_

#include "OpenGL.h"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents extension methods for OpenGL 4.
/// </summary>
class OpenGLExtensions {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="OpenGLExtensions"/> class.
    /// </summary>
    OpenGLExtensions();

    /// <summary>
    /// Loads the extension functions for OpenGL 4.0.
    /// Note that an OpenGL context must be active with a
    /// call to wglMakeCurrent before this funtion is called.
    /// </summary>
    void LoadExtensionFunctions();

    /// <summary>
    /// Attaches a shader object to a program object.
    /// </summary>
    /// <param name="program">
    /// Specifies the program object to which a shader object will be attached.
    /// </param>
    /// <param name="shader">
    /// Specifies the shader object that is to be attached.
    /// </param>
    PFNGLATTACHSHADERPROC glAttachShader;

    /// <summary>
    /// Binds a named buffer object.
    /// </summary>
    /// <param name="target">
    /// Specifies the target to which the buffer object is bound.
    /// </param>
    /// <param name="buffer">Specifies the name of a buffer object.</param>
    PFNGLBINDBUFFERPROC glBindBuffer;

    /// <summary>
    /// Binds a vertex array object.
    /// </summary>
    /// <param name="array">
    /// Specifies the name of the vertex array to bind.
    /// </param>
    PFNGLBINDVERTEXARRAYPROC glBindVertexArray;

    /// <summary>
    /// Creates and initializes a buffer object's data store.
    /// </summary>
    /// <param name="target">
    /// Specifies the target to which the buffer object is bound
    /// for glBufferData.
    /// </param>
    /// <param name="size">
    /// Specifies the size in bytes of the buffer object's new data store.
    /// </param>
    /// <param name="data">
    /// Specifies a pointer to data that will be copied into the data store
    /// for initialization, or <c>nullptr</c> if no data is to be copied.
    /// </param>
    /// <param name="usage">
    /// Specifies the expected usage pattern of the data store. The
    /// symbolic constant must be GL_STREAM_DRAW, GL_STREAM_READ,
    /// GL_STREAM_COPY, GL_STATIC_DRAW, GL_STATIC_READ, GL_STATIC_COPY,
    /// GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, or GL_DYNAMIC_COPY.
    /// </param>
    PFNGLBUFFERDATAPROC glBufferData;

    /// <summary>
    /// Compiles a shader object.
    /// </summary>
    /// <param name="shader">
    /// Specifies the shader object to be compiled.
    /// </param>
    PFNGLCOMPILESHADERPROC glCompileShader;

    /// <summary>
    /// Creates a program object.
    /// </summary>
    /// <returns>
    /// A non-zero value by which the program object can be referenced.
    /// </returns>
    PFNGLCREATEPROGRAMPROC glCreateProgram;

    /// <summary>
    /// Creates a shader object.
    /// </summary>
    /// <param name="shaderType">
    /// Specifies the type of shader to be created. Must be one of
    /// GL_COMPUTE_SHADER, GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
    /// GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER, or GL_FRAGMENT_SHADER.
    /// </param>
    /// <returns>
    /// A non-zero value by which the shader object can be referenced.
    /// </returns>
    PFNGLCREATESHADERPROC glCreateShader;

    /// <summary>
    /// Delete named buffer objects.
    /// </summary>
    /// <param name="n">
    /// Specifies the number of buffer objects to be deleted.
    /// </param>
    /// <param name="buffers">
    /// Specifies an array of buffer objects to be deleted.
    /// </param>
    /// <returns>
    /// A non-zero value by which the shader object can be referenced.
    /// </returns>
    PFNGLDELETEBUFFERSPROC glDeleteBuffers;

    /// <summary>
    /// Deletes a program object.
    /// </summary>
    /// <param name="program">
    /// Specifies the program object to be deleted.
    /// </param>
    PFNGLDELETEPROGRAMPROC glDeleteProgram;

    /// <summary>
    /// Deletes a shader object.
    /// </summary>
    /// <param name="shader">
    /// Specifies the shader object to be deleted.
    /// </param>
    PFNGLDELETESHADERPROC glDeleteShader;

    /// <summary>
    /// Deletes vertex array objects.
    /// </summary>
    /// <param name="n">
    /// Specifies the number of vertex array objects to be deleted.
    /// </param>
    /// <param name="arrays">
    /// Specifies the address of an array containing the n names of the
    /// objects to be deleted.
    /// </param>
    PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;

    /// <summary>
    /// Detaches a shader object from a program object to which it is attached.
    /// </summary>
    /// <param name="program">
    /// Specifies the program object from which to detach the shader object.
    /// </param>
    /// <param name="shader">
    /// Specifies the shader object to be detached.
    /// </param>
    PFNGLDETACHSHADERPROC glDetachShader;

    /// <summary>
    /// Enable or disable a generic vertex attribute array.
    /// </summary>
    /// <param name="index">
    /// Specifies the index of the generic vertex attribute
    /// to be enabled or disabled.
    /// </param>
    PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;

    /// <summary>
    /// Generates buffer object names.
    /// </summary>
    /// <param name="n">
    /// Specifies the number of buffer object names to be generated.
    /// </param>
    /// <param name="buffers">
    /// Specifies an array in which the generated buffer object
    /// names are stored.
    /// </param>
    PFNGLGENBUFFERSPROC glGenBuffers;

    /// <summary>
    /// Generates vertex array object names.
    /// </summary>
    /// <param name="n">
    /// Specifies the number of vertex array object names to generate.
    /// </param>
    /// <param name="arrays">
    /// Specifies an array in which the generated vertex array object
    /// names are stored.
    /// </param>
    PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;

    /// <summary>
    /// Returns the location of an attribute variable.
    /// </summary>
    /// <param name="program">
    /// Specifies the program object to be queried.
    /// </param>
    /// <param name="name">
    /// Points to a null terminated string containing
    /// the name of the attribute variable whose location
    /// is to be queried.
    /// </param>
    PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;

    /// <summary>
    /// Returns the information log for a program object.
    /// </summary>
    /// <param name="program">
    /// Specifies the program object whose information log is to be queried.
    /// </param>
    /// <param name="maxLength">
    /// Specifies the size of the character buffer for storing the returned
    /// information log.
    /// </param>
    /// <param name="length">
    /// Returns the length of the string returned in infoLog
    /// (excluding the null terminator).
    /// </param>
    /// <param name="infoLog">
    /// Specifies an array of characters that is used to return the
    /// information log.
    /// </param>
    PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;

    /// <summary>
    /// Returns a parameter from a program object.
    /// </summary>
    /// <param name="program">
    /// Specifies the program object to be queried.
    /// </param>
    /// <param name="pname">
    /// Specifies the object parameter. Accepted symbolic names are
    /// GL_DELETE_STATUS, GL_LINK_STATUS, GL_VALIDATE_STATUS,
    /// GL_INFO_LOG_LENGTH, GL_ATTACHED_SHADERS,
    /// GL_ACTIVE_ATOMIC_COUNTER_BUFFERS, GL_ACTIVE_ATTRIBUTES,
    /// GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, GL_ACTIVE_UNIFORMS,
    /// GL_ACTIVE_UNIFORM_BLOCKS, GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH,
    /// GL_ACTIVE_UNIFORM_MAX_LENGTH, GL_COMPUTE_WORK_GROUP_SIZE,
    /// GL_PROGRAM_BINARY_LENGTH, GL_TRANSFORM_FEEDBACK_BUFFER_MODE,
    /// GL_TRANSFORM_FEEDBACK_VARYINGS,
    /// GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH, GL_GEOMETRY_VERTICES_OUT,
    /// GL_GEOMETRY_INPUT_TYPE, and GL_GEOMETRY_OUTPUT_TYPE.
    /// </param>
    /// <param name="params">
    /// Returns the requested object parameter.
    /// </param>
    PFNGLGETPROGRAMIVPROC glGetProgramiv;

    /// <summary>
    /// Returns the information log for a shader object.
    /// </summary>
    /// <param name="shader">
    /// Specifies the shader object whose information log is to be queried.
    /// </param>
    /// <param name="maxLength">
    /// Specifies the size of the character buffer for storing the returned
    /// information log.
    /// </param>
    /// <param name="length">
    /// Returns the length of the string returned in infoLog
    /// (excluding the null terminator).
    /// </param>
    /// <param name="infoLog">
    /// Specifies an array of characters that is used to return the
    /// information log.
    /// </param>
    PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;

    /// <summary>
    /// Returns a parameter from a shader object.
    /// </summary>
    /// <param name="shader">
    /// Specifies the shader object to be queried.
    /// </param>
    /// <param name="pname">
    /// Specifies the object parameter. Accepted symbolic names are
    /// GL_SHADER_TYPE, GL_DELETE_STATUS, GL_COMPILE_STATUS,
    /// GL_INFO_LOG_LENGTH, GL_SHADER_SOURCE_LENGTH.
    /// </param>
    /// <param name="params">
    /// Returns the requested object parameter.
    /// </param>
    PFNGLGETSHADERIVPROC glGetShaderiv;

    /// <summary>
    /// Links a program object.
    /// </summary>
    /// <param name="program">
    /// Specifies the handle of the program object to be linked.
    /// </param>
    PFNGLLINKPROGRAMPROC glLinkProgram;

    /// <summary>
    /// Links a program object.
    /// </summary>
    /// <param name="shader">
    /// Specifies the handle of the shader object whose source code
    /// is to be replaced.
    /// </param>
    /// <param name="count">
    /// Specifies the number of elements in the string and length arrays.
    /// </param>
    /// <param name="str">
    /// Specifies an array of pointers to strings containing the source code
    /// to be loaded into the shader.
    /// </param>
    /// <param name="length">
    /// Specifies an array of string lengths.
    /// </param>
    PFNGLSHADERSOURCEPROC glShaderSource;

    /// <summary>
    /// Installs a program object as part of current rendering state.
    /// </summary>
    /// <param name="program">
    /// Specifies the handle of the program object whose executables
    /// are to be used as part of current rendering state.
    /// </param>
    PFNGLUSEPROGRAMPROC glUseProgram;

    /// <summary>
    /// Defines an array of generic vertex attribute data.
    /// </summary>
    /// <param name="index">
    /// Specifies the index of the generic vertex attribute to be modified.
    /// </param>
    /// <param name="size">
    /// Specifies the number of components per generic vertex attribute.
    /// Must be 1, 2, 3, 4. Additionally, the symbolic constant GL_BGRA
    /// is accepted by glVertexAttribPointer. The initial value is 4.
    /// </param>
    /// <param name="type">
    /// Specifies the data type of each component in the array. The
    /// symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT,
    /// GL_UNSIGNED_SHORT, GL_INT, and GL_UNSIGNED_INT are accepted by
    /// glVertexAttribPointer and glVertexAttribIPointer. Additionally
    /// GL_HALF_FLOAT, GL_FLOAT, GL_DOUBLE, GL_FIXED, GL_INT_2_10_10_10_REV,
    /// GL_UNSIGNED_INT_2_10_10_10_REV and GL_UNSIGNED_INT_10F_11F_11F_REV are
    /// accepted by glVertexAttribPointer. GL_DOUBLE is also accepted by
    /// glVertexAttribLPointer and is the only token accepted by the type
    /// parameter for that function. The initial value is GL_FLOAT.
    /// </param>
    /// <param name="normalized">
    /// For glVertexAttribPointer, specifies whether fixed-point data values
    /// should be normalized (GL_TRUE) or converted directly as fixed-point
    /// values (GL_FALSE) when they are accessed.
    /// </param>
    /// <param name="stride">
    /// Specifies the byte offset between consecutive generic vertex attributes.
    /// If stride is 0, the generic vertex attributes are understood to be
    /// tightly packed in the array. The initial value is 0.
    /// </param>
    /// <param name="pointer">
    /// Specifies a offset of the first component of the first generic vertex
    /// attribute in the array in the data store of the buffer currently bound
    /// to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// </param>
    PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

    /// <summary>
    /// Associates a generic vertex attribute index with a
    /// named attribute variable.
    /// </summary>
    /// <param name="program">
    /// Specifies the handle of the program object in which
    /// the association is to be made.
    /// </param>
    /// <param name="index">
    /// Specifies the index of the generic vertex attribute to be bound.
    /// </param>
    /// <param name="name">
    /// Specifies a null terminated string containing the name of the
    /// vertex shader attribute variable to which index is to be bound.
    /// </param>
    PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;

    /// <summary>
    /// Returns the location of a uniform variable.
    /// </summary>
    /// <param name="program">
    /// Specifies the program object to be queried.
    /// </param>
    /// <param name="name">
    /// Points to a null terminated string containing the name of the
    /// uniform variable whose location is to be queried.
    /// </param>
    PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;

    /// <summary>
    /// Returns the location of a uniform variable.
    /// </summary>
    /// <param name="location">
    /// Specifies the location of the uniform value to be modified.
    /// </param>
    /// <param name="count">
    /// Specifies the number of matrices that are to be modified.
    /// This should be 1 if the targeted uniform variable is not an array of
    /// matrices, and 1 or more if it is an array of matrices.
    /// </param>
    /// <param name="transpose">
    /// Specifies whether to transpose the matrix as the values are loaded
    /// into the uniform variable. Must be GL_FALSE.
    /// </param>
    /// <param name="value">
    /// Specifies a pointer to an array of count values that will be used
    /// to update the specified uniform variable.
    /// </param>
    PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;

    /// <summary>
    /// Selects the active texture unit.
    /// </summary>
    /// <param name="texture">
    /// Specifies which texture unit to make active. The number of texture
    /// units is implementation dependent, but must be at least 80. texture
    /// must be one of GL_TEXTUREi, where i ranges from zero to the value of
    /// GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS minus one. The initial value is
    /// GL_TEXTURE0.
    /// </param>
    PFNGLACTIVETEXTUREPROC glActiveTexture;

    /// <summary>
    /// Selects the active texture unit.
    /// </summary>
    /// <param name="location">
    /// Specifies the location of the uniform variable to be modified.
    /// </param>
    /// <param name="v0">
    /// For the scalar commands, specifies the new value to be used
    /// for the specified uniform variable.
    /// </param>
    PFNGLUNIFORM1IPROC glUniform1i;

    /// <summary>
    /// Generates mipmaps for a specified texture target.
    /// </summary>
    /// <param name="target">
    /// Specifies the target to which the texture whose mimaps to generate
    /// is bound. target must be GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
    /// GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY or GL_TEXTURE_CUBE_MAP.
    /// </param>
    PFNGLGENERATEMIPMAPPROC glGenerateMipmap;

    /// <summary>
    /// Disables a generic vertex attribute array.
    /// </summary>
    /// <param name="index">
    /// Specifies the index of the generic vertex attribute
    /// to be enabled or disabled.
    /// </param>
    PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;

    /// <summary>
    /// Specify the value of a uniform variable for the current program object.
    /// </summary>
    /// <param name="location">
    /// Specifies the location of the uniform variable to be modified.
    /// </param>
    /// <param name="count">
    /// For the vector (glUniform*v) commands, specifies the number of elements
    /// that are to be modified. This should be 1 if the targeted uniform
    /// variable is not an array, and 1 or more if it is an array. For the
    /// matrix(glUniformMatrix*) commands, specifies the number of matrices
    /// that are to be modified.This should be 1 if the targeted uniform
    /// variable is not an array of matrices, and 1 or more if it is an array
    /// of matrices.
    /// </param>
    /// <param name="value">
    /// For the scalar commands, specifies the new value to be used for the
    /// specified uniform variable.
    /// </param>
    PFNGLUNIFORM3FVPROC glUniform3fv;

    /// <summary>
    /// Specify the value of a uniform variable for the current program object.
    /// </summary>
    /// <param name="location">
    /// Specifies the location of the uniform variable to be modified.
    /// </param>
    /// <param name="count">
    /// For the vector (glUniform*v) commands, specifies the number of elements
    /// that are to be modified. This should be 1 if the targeted uniform
    /// variable is not an array, and 1 or more if it is an array. For the
    /// matrix(glUniformMatrix*) commands, specifies the number of matrices
    /// that are to be modified.This should be 1 if the targeted uniform
    /// variable is not an array of matrices, and 1 or more if it is an array
    /// of matrices.
    /// </param>
    /// <param name="value">
    /// For the scalar commands, specifies the new value to be used for the
    /// specified uniform variable.
    /// </param>
    PFNGLUNIFORM4FVPROC glUniform4fv;

#ifdef _WIN32
    /// <summary>
    /// Windows specific OpenGL extension for choosing the
    /// device context pixel format.
    /// </summary>
    /// <param name="hdc">
    /// The device context of the window being rendered to.
    /// </param>
    /// <param name="piAttribIList">
    /// The attribute list used when setting the format.
    /// </param>
    /// <param name="pfAttribFList">
    /// The attribute list used when setting the format.
    /// </param>
    /// <param name="nMaxFormats">
    /// The max number of formats in the formats array.
    /// </param>
    /// <param name="piFormats">
    /// The array of formats to apply.
    /// </param>
    /// <param name="nNumFormats">
    /// The number of formats in the array.
    /// </param>
    PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

    /// <summary>
    /// Windows specific OpenGL extension for creating
    /// a device context.
    /// </summary>
    /// <param name="hDC">
    /// The device context of the window being rendered to.
    /// </param>
    /// <param name="hShareContext">
    /// The rendering context to share with this one.
    /// </param>
    /// <param name="attribList">
    /// The attribute list to reference when creating the context.
    /// </param>
    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;

    /// <summary>
    /// Windows specific OpenGL extension for setting whether
    /// or not v-sync is enabled when presenting.
    /// </summary>
    /// <param name="interval">
    /// The VSync swap interval to use.
    /// </param>
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
#endif  // _WIN32
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_OPENGLEXTENSIONS_H_
