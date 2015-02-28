// =======================================================================
// <copyright file="AudioHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-27-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOHELPER_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOHELPER_H_

#include "..\..\External\FMOD\inc\fmod.hpp"

namespace DanceStudio {
namespace Core {
/// <summary>
/// Represents an audio helper that deals with initializing the audio
/// subsystem and performing global audio operations.
/// </summary>
class AudioHelper {
 public:
     /// <summary>
     /// Initializes the FMOD audio system.
     /// </summary>
     static void InitializeFmod();

     /// <summary>
     /// Shuts down the FMOD audio system.
     /// </summary>
     static void ShutdownFmod();

     /// <summary>
     /// Loads an audio file as a stream for playback.  Streams are useful
     /// for songs that are of a longer length.
     /// </summary>
     /// <param name="audioFilePath">
     /// The audio file path to load as a stream.
     /// </param>
     /// <returns>
     /// The pointer to the loaded stream.  Ownership of the
     /// allocated stream is passed to the caller.
     /// </returns>
     static FMOD::Sound* LoadStream(const std::string& audioFilePath);

     /// <summary>
     /// Starts playback of a stream.
     /// </summary>
     /// <param name="stream">The stream to play.</param>
     /// <returns>The channel that the stream is playing on.</returns>
     static FMOD::Channel* PlayStream(FMOD::Sound* stream);

     /// <summary>
     /// Logs the FMOD error to the log file.
     /// </summary>
     /// <param name="result">The error result to log.</param>
     static void LogFmodError(FMOD_RESULT result);
 private:
     /// <summary>
     /// Represents the core system object for FMOD.
     /// </summary>
     static FMOD::System* system;
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_AUDIOHELPER_H_
