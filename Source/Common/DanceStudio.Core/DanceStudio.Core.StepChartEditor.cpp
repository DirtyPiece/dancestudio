// =======================================================================
// <copyright
//      file="DanceStudio.Core.StepChartEditor.cpp"
//      company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "DanceStudio.Core.h"
#include "StepChartEditor.h"

using DanceStudio::Core::StepChartEditor;

DS_STEPCHARTEDITOR* DSStepChartEditorAllocate(DS_HANDLE* windowHandle) {
    StepChartEditor* editor = new StepChartEditor(windowHandle);
    return editor;
}

void DSStepChartEditorFree(DS_STEPCHARTEDITOR* editor) {
    delete editor;
}

void DSStepChartEditorInitialize(
    DS_STEPCHARTEDITOR* stepChartEditor,
    DS_HANDLE* windowHandle) {
    (void)stepChartEditor;
    (void)windowHandle;
}
