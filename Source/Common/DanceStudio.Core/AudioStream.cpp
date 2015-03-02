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
    channel(nullptr),
    defaultFrequency(0.0f),
    playbackSpeed(1.0f) {
    this->stream = AudioHelper::LoadStream(filePath);
}

AudioStream::~AudioStream() {
    if (this->channel != nullptr) {
        FMOD_RESULT result = this->channel->stop();
        Validator::FmodOperationSucceeded(
            result,
            "Could not stop the channel when cleaning up.");

        this->channel = nullptr;
    }

    if (this->stream != nullptr) {
        FMOD_RESULT result = this->stream->release();
        Validator::FmodOperationSucceeded(
            result,
            "Could not release the stream when cleaning up.");

        this->stream = nullptr;
    }
}

void AudioStream::Play() {
    assert(this->stream != nullptr);

    if (this->channel == nullptr) {
        this->channel = AudioHelper::PlayStream(this->stream);

        // Get the default frequency of the song so we can change it later.

    }
    else {
        FMOD_RESULT result = this->channel->setPaused(false);
        Validator::FmodOperationSucceeded(
            result,
            "Failed to unpause the channel.");
    }
}

void AudioStream::Pause() {
    assert(this->channel != nullptr);

    FMOD_RESULT result = this->channel->setPaused(true);
    Validator::FmodOperationSucceeded(
        result,
        "Failed to pause the channel.");
}

void AudioStream::Stop() {
    assert(this->channel != nullptr);

    Logger::LogCoreVerbose("Stoping audio playback of the channel.");
    if (this->IsPlaying()) {
        this->Pause();
        this->SetCurrentPlaybackPositionInMilliseconds(0u);
    }
}

UINT32 AudioStream::GetLengthInMilliseconds() const {
    assert(this->stream != nullptr);

    UINT32 length = 0;
    FMOD_RESULT result = this->stream->getLength(
        &length,
        FMOD_TIMEUNIT_MS);

    Validator::FmodOperationSucceeded(
        result,
        "Failed to get the FMOD stream length in milliseconds.");

    return length;
}

UINT32 AudioStream::GetCurrentPlaybackPositionInMilliseconds() const {
    assert(this->channel != nullptr);

    UINT32 position = 0;
    FMOD_RESULT result = this->channel->getPosition(
        &position,
        FMOD_TIMEUNIT_MS);

    Validator::FmodOperationSucceeded(
        result,
        "Failed to get the FMOD playback position in milliseconds.");

    return position;
}

void AudioStream::SetCurrentPlaybackPositionInMilliseconds(UINT32 position) {
    assert(this->channel != nullptr);

    FMOD_RESULT result = this->channel->setPosition(
        position,
        FMOD_TIMEUNIT_MS);

    Validator::FmodOperationSucceeded(
        result,
        "Failed to set the FMOD playback position in milliseconds.");
}

bool AudioStream::IsPlaying() const {
    assert(this->channel != nullptr);

    bool isPlaying = false;
    FMOD_RESULT result = this->channel->isPlaying(&isPlaying);
    Validator::FmodOperationSucceeded(
        result,
        "Unable to get the playing status of the channel.");

    return isPlaying;
}

void AudioStream::SetPlaybackSpeed(SINGLE speed) {
    assert(this->stream != nullptr);
    Validator::IsArgumentOutOfRange(
        speed < DANCE_STUDIO_MIN_SONG_PLAYBACK_SPEED
     || speed > DANCE_STUDIO_MAX_SONG_PLAYBACK_SPEED,
        "speed");

    FMOD_RESULT result = this->stream->setMusicSpeed(speed);
    Validator::FmodOperationSucceeded(
        result,
        "Failed to set the playback speed of the audio stream.");
}

void AudioStream::InitializeDefaultFrequency() {
    assert(this->channel != nullptr);
}
