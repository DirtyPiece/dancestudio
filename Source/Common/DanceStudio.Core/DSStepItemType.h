// =======================================================================
// <copyright file="DSStepItemType.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPITEMTYPE_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPITEMTYPE_H_

#pragma pack(push, 1)

/// <summary>
/// Represents various game types that are supported by
/// the Dance Studio Editor.  Today, the only supported
/// type is In the Groove.
/// </summary>
enum DSStepItemType {
    /// <summary>
    /// The starting marker for the range of values in this enum.
    /// </summary>
    DS_STEP_ITEM_TYPE_START,

    /// <summary>
    /// Represents nothing is there on the beat.
    /// </summary>
    DS_STEP_ITEM_TYPE_NONE = DS_STEP_ITEM_TYPE_START,

    /// <summary>
    /// Represents an arrow on the beat.
    /// </summary>
    DS_STEP_ITEM_TYPE_ARROW,

    /// <summary>
    /// Represents the start of a freeze arrow on the beat.
    /// </summary>
    DS_STEP_ITEM_TYPE_FREEZE_START,

    /// <summary>
    /// Represents the end of a freeze or roll arrow on the beat.
    /// </summary>
    DS_STEP_ITEM_TYPE_FREEZE_END,

    /// <summary>
    /// Represents the start of a roll arrow on the beat.
    /// </summary>
    DS_STEP_ITEM_TYPE_ROLL_START,

    /// <summary>
    /// Represents a mine on the beat.
    /// </summary>
    DS_STEP_ITEM_TYPE_MINE,

    /// <summary>
    /// The ending marker for the range of values in this enum.
    /// </summary>
    DS_STEP_ITEM_TYPE_END
};

#pragma pack(pop)

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPITEMTYPE_H_