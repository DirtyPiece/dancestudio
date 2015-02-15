// =======================================================================
// <copyright file="SEHException.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-08-2015</date>
// =======================================================================

#ifndef SOURCE_COMMON_DANCESTUDIO_CORE_SEHEXCEPTION_H_
#define SOURCE_COMMON_DANCESTUDIO_CORE_SEHEXCEPTION_H_

#include "Typedefs.h"
#include "Constants.h"

namespace DanceStudio {
namespace Core {

#pragma pack(1)
/// <summary>
/// Represents the custom structured exception handling (SEH) exception
/// that is thrown in order to marshal exception details between C++ and C#.
/// </summary>
struct SEHException {
    /// <summary>
    /// The title of the exception message (ArgumentNullException, etc.)
    /// </summary>
    CHAR* Title;

    /// <summary>
    /// The message to display in the exception.
    /// </summary>
    CHAR Message[DANCE_STUDIO_MAX_EXCEPTION_MESSAGE_LENGTH];

    /// <summary>
    /// The call stack of where the message was thrown from.
    /// </summary>
    CHAR CallStack[DANCE_STUDIO_MAX_CALLSTACK_LENGTH];
};
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_COMMON_DANCESTUDIO_CORE_SEHEXCEPTION_H_
