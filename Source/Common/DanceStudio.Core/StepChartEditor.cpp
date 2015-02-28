// =======================================================================
// <copyright file="StepChartEditor.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StepChartEditor.h"
#include "AudioHelper.h"
#include "AudioStream.h"

using DanceStudio::Core::StepChartEditor;
using DanceStudio::Core::AudioHelper;
using DanceStudio::Core::AudioStream;

StepChartEditor::StepChartEditor(DS_HANDLE* window) :
    renderer(nullptr),
    stream(nullptr) {
    Logger::LogCoreVerbose(L"Initializing the step chart editor control.");
    Validator::IsNotNull(window, "window");

    renderer = new OpenGLRenderer(window);
    Validator::IsMemoryAllocated(
        renderer,
        "the step chart editor's internal renderer.");

    // TODO(dirtypiece): Need to move this to a singleton class in the future
    // since the StepChartEditor may not always be a singleton control.
    AudioHelper::InitializeFmod();
}

StepChartEditor::~StepChartEditor() {
    Logger::LogCoreVerbose(L"Shutting down the step chart editor control.");
    if (renderer != nullptr) {
        delete renderer;
        renderer = nullptr;
    }

    AudioHelper::ShutdownFmod();
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

    if (this->stream != nullptr) {
        // Stop the current stream.
        this->stream->Stop();
    }

    // Set the stream and begin playback.
    this->stream = stream;
    this->stream->Play();
}
