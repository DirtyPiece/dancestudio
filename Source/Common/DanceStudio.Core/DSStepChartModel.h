// =======================================================================
// <copyright file="DSStepChartModel.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPCHARTMODEL_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPCHARTMODEL_H_

#include "DSStepItemModel.h"

#pragma pack(push, 1)

/// <summary>
/// Represents a stepchart which contains steps for a particular
/// difficulty, mode (singles vs. doubles), etc.
/// </summary>
struct DSStepChartModel {
    /// <summary>
    /// The list of step items in the step chart (arrows, mines, etc.).
    /// The items are sorted by time offset.
    /// </summary>
    DSStepItemModel* StepItems;

    /// <summary>
    /// The number of items in the StepItems field.
    /// </summary>
    UINT32 StepItemsLength;
};

#pragma pack(pop)

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPCHARTMODEL_H_