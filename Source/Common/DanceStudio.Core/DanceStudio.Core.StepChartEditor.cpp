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
#include "AudioStream.h"

using DanceStudio::Core::StepChartEditor;
using DanceStudio::Core::AudioStream;
using DanceStudio::Core::Validator;

DS_STEPCHARTEDITOR* DSStepChartEditorAllocate(DS_HANDLE* windowHandle) {
    StepChartEditor* editor = new StepChartEditor(windowHandle);
    Validator::IsMemoryAllocated(editor, "the native step chart editor.");
    return editor;
}

void DSStepChartEditorFree(DS_STEPCHARTEDITOR* editor) {
    delete editor;
}

void DSStepChartEditorUpdate(DS_STEPCHARTEDITOR* editor) {
    Validator::IsNotNull(editor, "editor");
    StepChartEditor* typedEditor = static_cast<StepChartEditor*>(editor);
    typedEditor->Update();
}

void DSStepChartEditorSetAudioStream(
    DS_STEPCHARTEDITOR* editor,
    DS_AUDIOSTREAM* stream) {
    Validator::IsNotNull(editor, "editor");

    StepChartEditor* typedEditor = static_cast<StepChartEditor*>(editor);
    AudioStream* typedStream = static_cast<AudioStream*>(stream);
    typedEditor->SetAudioStream(typedStream);
}
