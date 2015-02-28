// =======================================================================
// <copyright file="AudioStream.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-27-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOSTREAM_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOSTREAM_H_

#include <string>
#include "..\..\External\FMOD\inc\fmod.hpp"

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

 private:
     /// <summary>
     /// The loaded audio stream.
     /// </summary>
     FMOD::Sound* stream;

     /// <summary>
     /// The channel that the stream is playing on.
     /// </summary>
     FMOD::Channel* channel;
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOSTREAM_H_
