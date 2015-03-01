// =======================================================================
// <copyright file="DSSongPackModel.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DSSONGPACKMODEL_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DSSONGPACKMODEL_H_

#include "Typedefs.h"
#include "DSSongModel.h"

#pragma pack(push, 1)

/// <summary>
/// Represents a song pack which is a list of songs, stepcharts,
/// images, etc. that are released as a bundle.
/// </summary>
struct DSSongPackModel {
    /// <summary>
    /// The list of songs that belong to the pack.
    /// </summary>
    DSSongModel* Songs;

    /// <summary>
    /// The length of the Songs field.
    /// </summary>
    UINT32 SongsLength;
};

#pragma pack(pop)

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DSSONGPACKMODEL_H_