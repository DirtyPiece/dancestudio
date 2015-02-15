// =======================================================================
// <copyright file="StepChartEditor.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-08-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_SEHEXCEPTION_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_SEHEXCEPTION_H_

#include "..\..\..\Common\DanceStudio.Core\Constants.h"

using System::String;
using System::Runtime::InteropServices::StructLayoutAttribute;
using System::Runtime::InteropServices::MarshalAsAttribute;
using System::Runtime::InteropServices::LayoutKind;
using System::Runtime::InteropServices::CharSet;
using System::Runtime::InteropServices::UnmanagedType;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a marshaled SEH exception from C++.
/// </summary>
[StructLayout(LayoutKind::Sequential, Pack = 1, CharSet = CharSet::Ansi)]
public ref struct SEHException {
    /// <summary>
    /// The title of the exception.
    /// </summary>
    [MarshalAs(UnmanagedType::LPStr)]
    String^ Title;

    /// <summary>
    /// The detailed message for the exception (stack trace, etc.).
    /// </summary>
    [MarshalAs(
        UnmanagedType::ByValTStr,
        SizeConst = DANCE_STUDIO_MAX_EXCEPTION_MESSAGE_LENGTH)]
    String^ Message;

    /// <summary>
    /// The detailed message for the exception (stack trace, etc.).
    /// </summary>
    [MarshalAs(
        UnmanagedType::ByValTStr,
        SizeConst = DANCE_STUDIO_MAX_CALLSTACK_LENGTH)]
    String^ StackTrace;
};
};  // namespace Cli
};  // namespace Core
};  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_SEHEXCEPTION_H_
