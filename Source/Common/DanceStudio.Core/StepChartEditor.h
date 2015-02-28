// =======================================================================
// <copyright file="StepChartEditor.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_STEPCHARTEDITOR_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_STEPCHARTEDITOR_H_

#include "Typedefs.h"
#include "OpenGLRenderer.h"
#include "AudioStream.h"
#include <string>

namespace DanceStudio {
namespace Core {

/// <summary>
/// Represents the step chart editor for Dance Studio.
/// The step chart editor is the main editor for Dance Studio that visualizes
/// the waveform of songs being edited and allows the user to place arrows
/// that line up to the beat.
/// </summary>
class StepChartEditor {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="StepChartEditor"/> class.
    /// </summary>
    /// <param name="window">
    /// The window to render the stepchart editing experience to.
    /// </param>
    explicit StepChartEditor(DS_HANDLE* window);

    /// <summary>
    /// Finalizes an instance of the <see cref="StepChartEditor"/> class.
    /// </summary>
    ~StepChartEditor();

    /// <summary>
    /// Updates the geometry and other graphics of the scene.
    /// Should be called before Render().
    /// </summary>
    void Update();

    /// <summary>
    /// Sets the audio stream to apply as part of step chart editing.
    /// </summary>
    /// <param name="stream">The stream to apply for audio playback.</param>
    void SetAudioStream(AudioStream* stream);

 private:
    /// <summary>
    /// The internal OpenGL renderer used to render the control
    /// in its entirety.
    /// </summary>
    OpenGLRenderer* renderer;

    /// <summary>
    /// The audio stream that is playing during editing.  The stepchart being
    /// created will lay on top and be timed against this audio stream.
    /// </summary>
    AudioStream* stream;
};

}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_STEPCHARTEDITOR_H_
