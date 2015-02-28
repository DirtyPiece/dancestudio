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
            AudioHelper::LogFmodError(result);
            Throw::InvalidOperationException(
                "Could not stop the channel when cleaning up.");
        }

        this->channel = nullptr;
    }

    if (this->stream != nullptr) {
        FMOD_RESULT result = this->stream->release();
        if (result != FMOD_OK) {
            AudioHelper::LogFmodError(result);
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
        AudioHelper::LogFmodError(result);
        Throw::InvalidOperationException(
            "Failed to unpause the channel.");
    }
}

void AudioStream::Pause() {
    assert(this->channel != nullptr);

    FMOD_RESULT result = this->channel->setPaused(true);
    if (result != FMOD_OK) {
        AudioHelper::LogFmodError(result);
        Throw::InvalidOperationException(
            "Failed to pause the channel.");
    }
}

void AudioStream::Stop() {
    assert(this->channel != nullptr);

    Logger::LogCoreVerbose("Stoping audio playback of the channel.");
    if (this->IsPlaying()) {
        this->Pause();
        this->SetCurrentPlaybackPositionInMilliseconds(0u);
    }
}

UINT32 AudioStream::GetCurrentPlaybackPositionInMilliseconds() const {
    assert(this->channel != nullptr);

    UINT32 position = 0;
    FMOD_RESULT result = this->channel->getPosition(
        &position,
        FMOD_TIMEUNIT_MS);

    if (result != FMOD_OK) {
        AudioHelper::LogFmodError(result);
        Throw::InvalidOperationException(
            "Failed to get the FMOD playback position in milliseconds.");
    }

    return position;
}

void AudioStream::SetCurrentPlaybackPositionInMilliseconds(UINT32 position) {
    assert(this->channel != nullptr);

    FMOD_RESULT result = this->channel->setPosition(
        position,
        FMOD_TIMEUNIT_MS);

    if (result != FMOD_OK) {
        AudioHelper::LogFmodError(result);
        Throw::InvalidOperationException(
            "Failed to set the FMOD playback position in milliseconds.");
    }
}

bool AudioStream::IsPlaying() const {
    assert(this->channel != nullptr);

    bool isPlaying = false;
    FMOD_RESULT result = this->channel->isPlaying(&isPlaying);
    if (result != FMOD_OK) {
        AudioHelper::LogFmodError(result);
        Throw::InvalidOperationException(
            "Unable to get the playing status of the channel.");
    }

    return isPlaying;
}
