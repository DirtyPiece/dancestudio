// =======================================================================
// <copyright file="DSStepItemModel.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPITEMMODEL_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPITEMMODEL_H_

#include "DSStepItemType.h"

#pragma pack(push, 1)

/// <summary>
/// Represents a step item such as an arrow, mine, freeze arrow,
/// etc.
/// </summary>
struct DSStepItemModel {
    /// <summary>
    /// The type of item this step item is (arrow, mine, etc.).
    /// </summary>
    DSStepItemType Type;


};

#pragma pack(pop)

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_DSSTEPITEMMODEL_H_