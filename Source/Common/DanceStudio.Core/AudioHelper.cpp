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
    if (result != FMOD_OK) {
        Throw::InvalidOperationException(
            "Failed to create the FMOD system object.");
    }

    result = AudioHelper::system->init(
        512, /*maxChannels*/
        FMOD_INIT_NORMAL,
        nullptr);
    if (result != FMOD_OK) {
        Throw::InvalidOperationException(
            "Failed to initialize the FMOD system object.");
    }
}

void AudioHelper::ShutdownFmod() {
    assert(AudioHelper::system != nullptr);
    FMOD_RESULT result = AudioHelper::system->release();
    if (result != FMOD_OK) {
        Throw::InvalidOperationException(
            "The FMOD system object failed to shutdown properly.");
    }
}

FMOD::Sound* AudioHelper::LoadStream(const std::string& audioFilePath) {
    assert(AudioHelper::system != nullptr);

    FMOD::Sound* stream = nullptr;
    FMOD_RESULT result = AudioHelper::system->createStream(
        audioFilePath.c_str(),
        0,
        nullptr,
        &stream);

    return stream;
}

FMOD::Channel* AudioHelper::PlayStream(FMOD::Sound* stream) {
    Validator::IsNotNull(stream, "stream");

    FMOD::Channel* channel = nullptr;
    AudioHelper::system->playSound(
        stream,
        nullptr,
        true,
        &channel);

    return channel;
}
