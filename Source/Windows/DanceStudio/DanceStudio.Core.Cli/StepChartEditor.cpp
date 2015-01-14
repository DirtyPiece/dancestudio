// =======================================================================
// <copyright file="StepChartEditor.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-13-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StepChartEditor.h"
#include "..\..\..\Common\DanceStudio.Core\Constants.h"

using DanceStudio::Core::Cli::StepChartEditor;
using System::EventHandler;

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

void StepChartEditor::StepChartEditor_Loaded(Object^ sender, EventArgs^ e) {
    DANCE_STUDIO_UNUSED(sender);
    DANCE_STUDIO_UNUSED(e);

    // Grab the HWND for the UserControl and pass it along to the C++
    // step chart editor for rendering.
    DS_HANDLE* windowHandle = this->Handle.ToPointer();
    this->editor = DSStepChartEditorAllocate(windowHandle);
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
    // Render with OpenGL here...
}
