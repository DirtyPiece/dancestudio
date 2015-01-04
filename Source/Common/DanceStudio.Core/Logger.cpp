// =======================================================================
// <copyright file="Logger.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

#include "Stdafx.h"
#include "Logger.h"
#include <stdarg.h>
#include <string>
#include "PathHelper.h"

using DanceStudio::Core::Logger;

Logger::Logger(const CHAR* outputDirectory)
    : file(nullptr) {
    assert(this->file == nullptr);
    Validator::IsNotNull(outputDirectory, "outputDirectory");

    // Get a new filename with the current date stamped.
    std::string logFileName = PathHelper::GetCurrentDateFileName() + ".log";

    // Open the new file to start writing the log to.
    std::string outputFilePath = PathHelper::Combine(
        outputDirectory,
        logFileName);

    this->file = fopen(outputFilePath.c_str(), "w");
    Validator::IsFileCreated(this->file, outputFilePath);
}

Logger::~Logger() {
    if (this->file != nullptr) {
        fclose(this->file);
        this->file = nullptr;
    }
}

void Logger::LogVerbose(const WCHAR* message) {
    Validator::IsNotNull(message, "message");

    const std::wstring& adjustedMessage =
        L"V: "
      + std::wstring(message)
      + DANCE_STUDIO_NEWLINE;

    this->Log(adjustedMessage.c_str());
}

void Logger::LogInfo(const WCHAR* message) {
    Validator::IsNotNull(message, "message");

    const std::wstring& adjustedMessage =
        L"I: "
        + std::wstring(message)
        + DANCE_STUDIO_NEWLINE;

    this->Log(adjustedMessage.c_str());
}

void Logger::LogWarning(const WCHAR* message) {
    Validator::IsNotNull(message, "message");

    const std::wstring& adjustedMessage =
        L"W: "
        + std::wstring(message)
        + DANCE_STUDIO_NEWLINE;

    this->Log(adjustedMessage.c_str());
}

void Logger::LogError(const WCHAR* message) {
    Validator::IsNotNull(message, "message");

    const std::wstring& adjustedMessage =
        L"E: "
        + std::wstring(message)
        + DANCE_STUDIO_NEWLINE;

    this->Log(adjustedMessage.c_str());
}

void Logger::Log(const WCHAR* message) {
    assert(this->file != nullptr);
    Validator::IsNotNull(message, "message");

    fwprintf(this->file, message);
    fflush(this->file);
}
