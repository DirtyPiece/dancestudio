// =======================================================================
// <copyright file="DSProjectModel.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DSPROJECTMODEL_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DSPROJECTMODEL_H_

#include "Typedefs.h"
#include "DSSongPackModel.h"
#include "DSGameType.h"

#pragma pack(push, 1)

/// <summary>
/// Represents the root model structure for a Dance Studio project.
/// </summary>
struct DSProjectModel {
    /// <summary>
    /// The name of the project.
    /// </summary>
    WCHAR* Name;

    /// <summary>
    /// The length of the Name field in characters.
    /// </summary>
    UINT32 NameLength;

    /// <summary>
    /// All of the song packs the user has created in the project.
    /// </summary>
    DSSongPackModel* SongPacks;

    /// <summary>
    /// The number of packs in the SongPacks field.
    /// </summary>
    UINT32 SongPacksLength;

    /// <summary>
    /// The type of game being edited in this project.
    /// </summary>
    DSGameType GameType;
};

#pragma pack(pop)

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DSPROJECTMODEL_H_