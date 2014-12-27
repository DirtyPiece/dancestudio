// =======================================================================
// <copyright file="PathHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#include "Stdafx.h"
#include "PathHelper.h"
#include <ctime>
#include <sstream>

using DanceStudio::Core::PathHelper;

std::wstring PathHelper::GetCurrentDateFileName() {
    time_t t = time(0);
    tm now;
    errno_t error = localtime_s(&now, &t);
    Validator::IsValidTime(error);

    // Create the string with format like "2014.12.26_10.27.00".
    std::wstringstream stream;
    stream << (now.tm_year + 1900);
    stream << ".";
    stream << (now.tm_mon + 1);
    stream << ".";
    stream << now.tm_mday;
    stream << "_";
    stream << now.tm_hour;
    stream << ".";
    stream << now.tm_min;
    stream << ".";
    stream << now.tm_sec;

    return stream.str();
}
