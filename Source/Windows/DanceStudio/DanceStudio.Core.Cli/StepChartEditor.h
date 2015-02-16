// =======================================================================
// <copyright file="StepChartEditor.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-13-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_STEPCHARTEDITOR_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_STEPCHARTEDITOR_H_

#include "..\..\..\Common\DanceStudio.Core\DanceStudio.Core.h"

using System::Windows::Forms::UserControl;
using System::Object;
using System::EventArgs;
using System::Windows::Forms::PaintEventArgs;
using System::Threading::ThreadExceptionEventArgs;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a control that edits stepcharts for StepMania and
/// In The Groove arcade machines.
/// </summary>
public ref class StepChartEditor : public UserControl {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="StepChartEditor"/> class.
    /// </summary>
    StepChartEditor();

    /// <summary>
    /// Finalizes an instance of the <see cref="StepChartEditor"/> class.
    /// </summary>
    ~StepChartEditor();

    /// <summary>
    /// Updates the rendering of the control.
    /// </summary>
    void Tick();

 protected:
    /// <summary>
    /// Called when the background is about to paint.  Overriding it
    /// so that we can do a no-op to avoid flickering since the rendering
    /// will all be done manually with OpenGL.
    /// </summary>
    /// <param name="e">The paint event arguments.</param>
    void OnPaintBackground(PaintEventArgs^ e) override;

    /// <summary>
    /// Called when the foreground is about to paint.  Overriding it
    /// so that we can render with OpenGL to draw the scene.
    /// </summary>
    /// <param name="e">The paint event arguments.</param>
    void OnPaint(PaintEventArgs^ e) override;

 private:
    /// <summary>
    /// The native step chart editor that is wrapped by this class.
    /// </summary>
    DS_STEPCHARTEDITOR* editor;

    /// <summary>
    /// Called when the the step chart editor first loads in order to
    /// do initialization logic.
    /// </summary>
    /// <param name="sender">
    /// The sender (<see cref="StepChartEditor" />).
    /// </param>
    /// <param name="e">The event arguments (empty).</param>
    void StepChartEditor_Loaded(Object^ sender, EventArgs^ e);

    /// <summary>
    /// Called when the step chart editor is resized so we can
    /// reset the OpenGL matrices to properly render the scene.
    /// </summary>
    /// <param name="sender">
    /// The sender (<see cref="StepChartEditor" />).
    /// </param>
    /// <param name="e">The event arguments (empty).</param>
    void StepChartEditor_SizeChanged(Object^ sender, EventArgs^ e);
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_STEPCHARTEDITOR_H_
