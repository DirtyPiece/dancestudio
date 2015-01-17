// =======================================================================
// <copyright file="StepChartEditor.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StepChartEditor.h"

using DanceStudio::Core::StepChartEditor;

StepChartEditor::StepChartEditor(DS_HANDLE* window) :
    renderer(nullptr) {
    Logger::LogCoreVerbose(L"Initializing the step chart editor control.");
    Validator::IsNotNull(window, "window");

    renderer = new OpenGLRenderer(window);
}

StepChartEditor::~StepChartEditor() {
    Logger::LogCoreVerbose(L"Shutting down the step chart editor control.");
    if (renderer != nullptr) {
        delete renderer;
        renderer = nullptr;
    }
}

void StepChartEditor::Update() {
    assert(this->renderer != nullptr);
    this->renderer->BeginScene();
    this->renderer->EndScene();
}
