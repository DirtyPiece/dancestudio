// =======================================================================
// <copyright
//      file="DanceStudio.Core.AudioStream.cpp"
//      company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "DanceStudio.Core.h"
#include "AudioStream.h"

using DanceStudio::Core::AudioStream;
using DanceStudio::Core::Validator;

DS_AUDIOSTREAM* DSAudioStreamAllocate(const CHAR* audioFilePath) {
    Validator::IsNotNull(audioFilePath, "audioFilePath");
    AudioStream* stream = new AudioStream(audioFilePath);
    Validator::IsMemoryAllocated(
        stream,
        "an audio stream for file '"
        + std::string(audioFilePath)
        + "'.");

    return stream;
}

void DSAudioStreamFree(DS_AUDIOSTREAM* stream) {
    Validator::IsNotNull(stream, "stream");
    delete[] stream;
}
