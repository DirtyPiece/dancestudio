// =======================================================================
// <copyright file="StepChartEditor.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StepChartEditor.h"

using DanceStudio::Core::StepChartEditor;

StepChartEditor::StepChartEditor(DS_HANDLE* window) {
    Validator::IsNotNull(window, "window");
}
