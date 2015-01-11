// =======================================================================
// <copyright
//      file="DanceStudio.Core.Logger.cpp"
//      company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-10-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "DanceStudio.Core.h"
#include "Logger.h"

using DanceStudio::Core::Logger;

DS_LOGGER* DSLoggerAllocate(const CHAR* outputDirectory) {
    Logger* logger = new Logger(outputDirectory);
    return logger;
}

void DSLoggerFree(DS_LOGGER* logger) {
    delete logger;
}

void DSLoggerSetCoreLogger(DS_LOGGER* logger) {
    Logger* typedLogger = static_cast<Logger*>(logger);
    Logger::SetCoreLogger(typedLogger);
}

void DSLoggerLogVerbose(DS_LOGGER* logger, const WCHAR* message) {
    Logger* typedLogger = static_cast<Logger*>(logger);
    typedLogger->LogVerbose(message);
}

void DSLoggerLogInfo(DS_LOGGER* logger, const WCHAR* message) {
    Logger* typedLogger = static_cast<Logger*>(logger);
    typedLogger->LogInfo(message);
}

void DSLoggerLogWarning(DS_LOGGER* logger, const WCHAR* message) {
    Logger* typedLogger = static_cast<Logger*>(logger);
    typedLogger->LogWarning(message);
}

void DSLoggerLogError(DS_LOGGER* logger, const WCHAR* message) {
    Logger* typedLogger = static_cast<Logger*>(logger);
    typedLogger->LogError(message);
}
