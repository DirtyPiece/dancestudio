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
#include "DanceStudioExceptionType.h"

using DanceStudio::Core::Throw;
using DanceStudio::Core::SEHException;

void Throw::ArgumentNullException(const std::string& paramName) {
    Throw::PlatformSpecificException(
        "ArgumentNullException",
        "'" + paramName + "' cannot be null.",
        DANCE_STUDIO_EXCEPTION_TYPE_ARGUMENT_NULL);
}

void Throw::ArgumentOutOfRangeException(const std::string& paramName) {
    Throw::PlatformSpecificException(
        "ArgumentOutOfRangeException",
        "The argument '" + paramName + "' is out of range.",
        DANCE_STUDIO_EXCEPTION_TYPE_ARGUMENT_OUT_OF_RANGE);
}

void Throw::InvalidOperationException(const std::string& message) {
    Throw::PlatformSpecificException(
        "InvalidOperationException",
        message,
        DANCE_STUDIO_EXCEPTION_TYPE_INVALID_OPERATION);
}

void Throw::OutOfMemoryException(const std::string& memoryRegionName) {
    Throw::PlatformSpecificException(
        "OutOfMemoryException",
        "Ran out of memory while attempting to allocate for '"
        + memoryRegionName
        + "'.",
        DANCE_STUDIO_EXCEPTION_TYPE_OUT_OF_MEMORY);
}

void Throw::PlatformSpecificException(
    const std::string& title,
    const std::string& message,
    UINT32 exceptionCode) {
#ifdef _WIN32
    Throw::SEHException(title, message, exceptionCode);
#endif  // _WIN32
}

std::string Throw::GetCurrentCallstack() {
    try {
        throw std::exception();
    }
    catch (const std::exception& ex) {
        return ex.what();
    }
}

#ifdef _WIN32
void Throw::SEHException(
    const std::string& title,
    const std::string& message,
    UINT32 exceptionCode) {

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
    // happen on the C# side after receiving it.
    RaiseException(
        exceptionCode,
        0               /* Exception flags */,
        1               /* Number of exceptions */,
        reinterpret_cast<const ULONG_PTR*>(&exception));
}
#endif  // _WIN32
