// =======================================================================
// <copyright file="StepChartEditor.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-13-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StepChartEditor.h"
#include "SEHException.h"
#include "ExceptionHelper.h"
#include "..\..\..\Common\DanceStudio.Core\Constants.h"

using DanceStudio::Core::Cli::StepChartEditor;
using DanceStudio::Core::Cli::ExceptionHelper;
using System::EventHandler;
using System::AppDomain;
using System::Object;
using System::UnhandledExceptionEventArgs;
using System::UnhandledExceptionEventHandler;
using System::Threading::ThreadExceptionEventHandler;
using System::Windows::Forms::Application;
using System::Windows::Forms::UnhandledExceptionMode;

StepChartEditor::StepChartEditor() :
    editor(nullptr) {
    // Register for the load event so we can initialize the
    // underlying native control there.
    this->Load += gcnew EventHandler(
        this,
        &StepChartEditor::StepChartEditor_Loaded);

    // Register for resize events so that we can reset the OpenGL
    // matrices to fit the window.
    this->SizeChanged += gcnew EventHandler(
        this,
        &StepChartEditor::StepChartEditor_SizeChanged);
}

StepChartEditor::~StepChartEditor() {
    if (this->editor != nullptr) {
        DSStepChartEditorFree(this->editor);
        this->editor = nullptr;
    }
}

void StepChartEditor::Tick() {
    if (this->editor != nullptr) {
        DSStepChartEditorUpdate(this->editor);
    }
}

void StepChartEditor::SetAudioStream(AudioStream^ stream) {
    assert(this->editor != nullptr);
    DSStepChartEditorSetAudioStream(this->editor, stream->stream);
}

void StepChartEditor::ZoomCamera(float zoomDistance) {
    DSStepChartEditorZoomCamera(this->editor, zoomDistance);
}

void StepChartEditor::StepChartEditor_Loaded(Object^ sender, EventArgs^ e) {
    DANCE_STUDIO_UNUSED(sender);
    DANCE_STUDIO_UNUSED(e);

    assert(this->editor == nullptr);

    // Grab the HWND for the UserControl and pass it along to the C++
    // step chart editor for rendering.
    DS_HANDLE* windowHandle = this->Handle.ToPointer();
    this->editor = DSStepChartEditorAllocate(windowHandle);
    DSStepChartEditorUpdate(this->editor);
}

void StepChartEditor::StepChartEditor_SizeChanged(
    Object^ sender,
    EventArgs^ e) {
    DANCE_STUDIO_UNUSED(sender);
    DANCE_STUDIO_UNUSED(e);
}

void StepChartEditor::OnPaintBackground(PaintEventArgs^ e) {
    DANCE_STUDIO_UNUSED(e);
    // Purposely do nothing here to avoid flicker.
}

void StepChartEditor::OnPaint(PaintEventArgs^ e) {
    DANCE_STUDIO_UNUSED(e);

    if (this->editor != nullptr) {
        DSStepChartEditorUpdate(this->editor);
    }
}
