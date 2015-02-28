// =======================================================================
// <copyright file="AudioHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-27-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "AudioHelper.h"
#include "..\..\External\FMOD\inc\fmod.hpp"

using DanceStudio::Core::AudioHelper;

FMOD::System* AudioHelper::system = nullptr;

void AudioHelper::InitializeFmod() {
    assert(AudioHelper::system == nullptr);

    FMOD_RESULT result;

    result = FMOD::System_Create(&AudioHelper::system);
    Validator::FmodOperationSucceeded(
        result,
        "Failed to create the FMOD system object.");

    result = AudioHelper::system->init(
        512, /*maxChannels*/
        FMOD_INIT_NORMAL,
        nullptr);

    Validator::FmodOperationSucceeded(
        result,
        "Failed to initialize the FMOD system object.");
}

void AudioHelper::ShutdownFmod() {
    assert(AudioHelper::system != nullptr);
    FMOD_RESULT result = AudioHelper::system->release();
    Validator::FmodOperationSucceeded(
        result,
        "The FMOD system object failed to shutdown properly.");
}

void AudioHelper::UpdateFmod() {
    assert(AudioHelper::system != nullptr);
    FMOD_RESULT result = AudioHelper::system->update();
    Validator::FmodOperationSucceeded(
        result,
        "The FMOD system object failed to update properly.");
}

FMOD::Sound* AudioHelper::LoadStream(const std::string& audioFilePath) {
    assert(AudioHelper::system != nullptr);

    FMOD::Sound* stream = nullptr;
    FMOD_RESULT result = AudioHelper::system->createStream(
        audioFilePath.c_str(),
        0,
        nullptr,
        &stream);

    Validator::FmodOperationSucceeded(
        result,
        "Failed to load the FMOD stream for file '"
        + audioFilePath
        + "'.");

    return stream;
}

FMOD::Channel* AudioHelper::PlayStream(FMOD::Sound* stream) {
    Validator::IsNotNull(stream, "stream");

    FMOD::Channel* channel = nullptr;
    AudioHelper::system->playSound(
        stream,
        nullptr,
        false,
        &channel);

    return channel;
}

void AudioHelper::LogFmodError(FMOD_RESULT result) {
    // TODO(dirtypiece): fill this in.
}
