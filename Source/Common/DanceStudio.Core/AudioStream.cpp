// =======================================================================
// <copyright file="AudioStream.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "AudioStream.h"
#include "AudioHelper.h"

using DanceStudio::Core::AudioStream;

AudioStream::AudioStream(const std::string& filePath) :
    stream(nullptr),
    channel(nullptr) {
    this->stream = AudioHelper::LoadStream(filePath);
}

AudioStream::~AudioStream() {
    if (this->channel != nullptr) {
        FMOD_RESULT result = this->channel->stop();
        if (result != FMOD_OK) {
            Throw::InvalidOperationException(
                "Could not stop the channel when cleaning up.");
        }

        this->channel = nullptr;
    }

    if (this->stream != nullptr) {
        FMOD_RESULT result = this->stream->release();
        if (result != FMOD_OK) {
            Throw::InvalidOperationException(
                "Could not release the stream when cleaning up.");
        }

        this->stream = nullptr;
    }
}

void AudioStream::Play() {
    assert(this->stream != nullptr);

    if (this->channel == nullptr) {
        this->channel = AudioHelper::PlayStream(this->stream);
    }

    FMOD_RESULT result = this->channel->setPaused(false);
    if (result != FMOD_OK) {
        Throw::InvalidOperationException(
            "Failed to unpause the channel.");
    }
}
