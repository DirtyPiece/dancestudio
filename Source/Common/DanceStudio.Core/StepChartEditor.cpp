// =======================================================================
// <copyright file="StepChartEditor.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StepChartEditor.h"
#include "AudioStream.h"

using DanceStudio::Core::StepChartEditor;
using DanceStudio::Core::AudioStream;

StepChartEditor::StepChartEditor(DS_HANDLE* window) :
    renderer(nullptr) {
    Logger::LogCoreVerbose(L"Initializing the step chart editor control.");
    Validator::IsNotNull(window, "window");

    renderer = new OpenGLRenderer(window);
    Validator::IsMemoryAllocated(
        renderer,
        "the step chart editor's internal renderer.");
}

StepChartEditor::~StepChartEditor() {
    Logger::LogCoreVerbose(L"Shutting down the step chart editor control.");
    if (renderer != nullptr) {
        delete renderer;
        renderer = nullptr;
    }
}

/// <summary>
/// Updates this instance.
/// </summary>
void StepChartEditor::Update() {
    assert(this->renderer != nullptr);
    this->renderer->BeginScene();
    this->renderer->EndScene();
}

void StepChartEditor::SetAudioStream(AudioStream* stream) {
    Validator::IsNotNull(stream, "stream");

    this->stream = stream;
}
