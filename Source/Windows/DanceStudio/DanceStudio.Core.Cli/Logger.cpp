// =======================================================================
// <copyright file="Logger.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#include "Stdafx.h"
#include "Logger.h"
#include "MarshalHelper.h"
#include <string>

using System::Object;
using System::String;
using DanceStudio::Core::Cli::Logger;

Logger::Logger(String^ outputDirectory) :
    logger(nullptr) {
    std::wstring outputDir = MarshalHelper::ConvertStringToStlString(
        outputDirectory);

    this->logger = new DanceStudio::Core::Logger(outputDir.c_str());
}

void Logger::LogVerbose(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlString(
        formattedMessage);

    this->logger->LogVerbose(str.c_str());
}

void Logger::LogInfo(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlString(
        formattedMessage);

    this->logger->LogInfo(str.c_str());
}

void Logger::LogWarning(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlString(
        formattedMessage);

    this->logger->LogWarning(str.c_str());
}

void Logger::LogError(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlString(
        formattedMessage);

    this->logger->LogError(str.c_str());
}
