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
using System::Environment;
using System::IO::Directory;
using DanceStudio::Core::Cli::Logger;

Logger::Logger(String^ outputDirectory) {
    std::string outputDir = MarshalHelper::ConvertStringToStlString(
        outputDirectory);

    Logger::logger = DSLoggerAllocate(outputDir.c_str());

    // Set the core logger so the Core library
    // messages log as well.
    DSLoggerSetCoreLogger(Logger::logger);
}

Logger::~Logger() {
    if (Logger::logger != nullptr) {
        DSLoggerFree(this->logger);
        Logger::logger = nullptr;
    }
}

void Logger::LogVerbose(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlWString(
        formattedMessage);

    DSLoggerLogVerbose(Logger::logger, str.c_str());
}

void Logger::LogInfo(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlWString(
        formattedMessage);

    DSLoggerLogInfo(Logger::logger, str.c_str());
}

void Logger::LogWarning(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlWString(
        formattedMessage);

    DSLoggerLogWarning(Logger::logger, str.c_str());
}

void Logger::LogError(String^ message, ... array<Object^>^ args) {
    String^ formattedMessage = String::Format(message, args);
    std::wstring str = MarshalHelper::ConvertStringToStlWString(
        formattedMessage);

    DSLoggerLogError(Logger::logger, str.c_str());
}

String^ Logger::CreateLogFolder() {
    String^ logFolder = Environment::GetFolderPath(
        Environment::SpecialFolder::LocalApplicationData)
      + "\\DanceStudio\\logs";

    if (!Directory::Exists(logFolder)) {
        Directory::CreateDirectory(logFolder);
    }

    return logFolder;
}
