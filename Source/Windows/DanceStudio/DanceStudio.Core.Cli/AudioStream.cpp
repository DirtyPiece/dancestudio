// =======================================================================
// <copyright file="AudioStream.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "AudioStream.h"
#include "MarshalHelper.h"
#include <string>

using DanceStudio::Core::Cli::AudioStream;
using DanceStudio::Core::Cli::MarshalHelper;

AudioStream::AudioStream(String^ audioFilePath) :
    stream(nullptr) {
    Validator::IsNotNull(audioFilePath, "audioFilePath");

    std::string str = MarshalHelper::ConvertStringToStlString(
        audioFilePath);

    this->stream = DSAudioStreamAllocate(str.c_str());
}

AudioStream::~AudioStream() {
    if (this->stream != nullptr) {
        DSAudioStreamFree(this->stream);
        this->stream = nullptr;
    }
}
