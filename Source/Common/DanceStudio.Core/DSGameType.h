// =======================================================================
// <copyright file="DSGameType.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DSGAMETYPE_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DSGAMETYPE_H_

#pragma pack(push, 1)

/// <summary>
/// Represents various game types that are supported by
/// the Dance Studio Editor.  Today, the only supported
/// type is In the Groove.
/// </summary>
enum DSGameType {
    /// <summary>
    /// The starting marker for the range of values in this enum.
    /// </summary>
    DS_GAME_TYPE_START,

    /// <summary>
    /// Represents that the game type being edited is In The Groove.
    /// </summary>
    DS_GAME_TYPE_IN_THE_GROOVE = DS_GAME_TYPE_START,

    /// <summary>
    /// The ending marker for the range of values in this enum.
    /// </summary>
    DS_GAME_TYPE_END
};

#pragma pack(pop)

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DSGAMETYPE_H_