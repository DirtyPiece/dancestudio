// =======================================================================
// <copyright file="AudioStream.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-27-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOSTREAM_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOSTREAM_H_

#include "Typedefs.h"
#include "..\..\External\FMOD\inc\fmod.hpp"
#include <string>

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents a loaded audio file as a stream.
/// </summary>
class AudioStream {
 public:
     /// <summary>
     /// Initializes a new instance of the <see cref="AudioStream"/> class.
     /// </summary>
     /// <param name="filePath">The path to the audio file to load.</param>
     AudioStream(const std::string& filePath);

     /// <summary>
     /// Finalizes an instance of the <see cref="AudioStream"/> class.
     /// </summary>
     ~AudioStream();

     /// <summary>
     /// Begins audio playback of the stream.
     /// </summary>
     void Play();

     /// <summary>
     /// Pauses audio playback of the stream.
     /// </summary>
     void Pause();

     /// <summary>
     /// Pauses audio playback and resets the position of the stream
     /// to the beginning of the song.
     /// </summary>
     void Stop();

     /// <summary>
     /// Determines whether the stream is currently playing.
     /// </summary>
     /// <returns>Whether or not the stream is currently playing.</returns>
     bool IsPlaying() const;

     /// <summary>
     /// Gets the length of the stream playback time in milliseconds.
     /// </summary>
     /// <returns>The length of the audio stream in milliseconds.</returns>
     UINT32 GetLengthInMilliseconds() const;

     /// <summary>
     /// Gets the current playback position in milliseconds.
     /// </summary>
     /// <returns>The current playback position in milliseconds.</returns>
     UINT32 GetCurrentPlaybackPositionInMilliseconds() const;

     /// <summary>
     /// Sets the current playback position in milliseconds.
     /// </summary>
     /// <param name="position">The milliseconds offet to jump to.</param>
     void SetCurrentPlaybackPositionInMilliseconds(UINT32 position);

     /// <summary>
     /// Sets the playback speed of the song that is playing.
     /// </summary>
     /// <param name="speed">
     /// The speed of the playback from 0.01f to 100.0f (1.0f is normal speed).
     /// </param>
     void SetPlaybackSpeed(SINGLE speed);

 private:
     /// <summary>
     /// The loaded audio stream.
     /// </summary>
     FMOD::Sound* stream;

     /// <summary>
     /// The channel that the stream is playing on.
     /// </summary>
     FMOD::Channel* channel;

     /// <summary>
     /// The default frequency of the audio stream, used to alter
     /// the playback speed of the song.  Different depending on
     /// the file that is loaded.
     /// </summary>
     SINGLE defaultFrequency;

     /// <summary>
     /// The current playback speed of the stream.
     /// </summary>
     SINGLE playbackSpeed;

     /// <summary>
     /// Initializes the default frequency value.
     /// </summary>
     void InitializeDefaultFrequency();
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOSTREAM_H_
