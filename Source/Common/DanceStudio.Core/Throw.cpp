// =======================================================================
// <copyright file="Throw.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>10-12-2015</date>
// =======================================================================

#include "Stdafx.h"
#include <string>

#ifdef _WIN32
#include <ObjBase.h>
#endif  // _WIN32

#include "Throw.h"
#include "SEHException.h"

using DanceStudio::Core::Throw;
using DanceStudio::Core::SEHException;

void Throw::ArgumentNullException(const std::string& paramName) {
    Throw::PlatformSpecificException(
        "ArgumentNullException",
        "'" + paramName + "' cannot be null.");
}

void Throw::ArgumentOutOfRangeException(const std::string& paramName) {
    Throw::PlatformSpecificException(
        "ArgumentOutOfRangeException",
        "The argument '" + paramName + "' is out of range.");
}

void Throw::InvalidOperationException(const std::string& message) {
    Throw::PlatformSpecificException(
        "InvalidOperationException",
        message);
}

void Throw::OutOfMemoryException(const std::string& memoryRegionName) {
    Throw::PlatformSpecificException(
        "OutOfMemoryException",
        "Ran out of memory while attempting to allocate for '"
        + memoryRegionName
        + "'.");
}

void Throw::PlatformSpecificException(
    const std::string& title,
    const std::string& message) {
#ifdef _WIN32
    Throw::SEHException(title, message);
#endif  // _WIN32
}

#ifdef _WIN32
void Throw::SEHException(
    const std::string& title,
    const std::string& message) {

    DanceStudio::Core::SEHException* exception = reinterpret_cast<DanceStudio::Core::SEHException*>(
        CoTaskMemAlloc(sizeof(DanceStudio::Core::SEHException)));

    Validator::IsMemoryAllocated(exception, "an SEH exception object.");

    // Zero out all the bytes.
    memset(exception, 0, sizeof(DanceStudio::Core::SEHException));

    // Reserve one space for the newline.
    size_t allocLength = sizeof(CHAR) * title.length() + 1;
    exception->Title = reinterpret_cast<CHAR*>(CoTaskMemAlloc(allocLength));
    strncpy(exception->Title, title.c_str(), allocLength);
    strncpy(
        exception->Message,
        message.c_str(),
        DANCE_STUDIO_MAX_EXCEPTION_MESSAGE_LENGTH);

    // Raise the exception message.  Freeing of the exception memory will
    // happen on the C# side after recieving it.
    RaiseException(
        100     /* Error code */,
        0       /* Exception flags */,
        1       /* Number of exceptions */,
        reinterpret_cast<const ULONG_PTR*>(&exception));
}
#endif  // _WIN32
