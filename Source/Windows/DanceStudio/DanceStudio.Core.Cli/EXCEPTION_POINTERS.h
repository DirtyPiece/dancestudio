// =======================================================================
// <copyright file="EXCEPTION_POINTERS.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-08-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTION_POINTERS_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTION_POINTERS_H_

using System::IntPtr;
using System::Runtime::InteropServices::StructLayoutAttribute;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a marshaled EXCEPTION_POINTERS structure.
/// </summary>
[StructLayout(LayoutKind.Sequential, Pack = 1)]
public ref struct EXCEPTION_POINTERS
{
    /// <summary>
    /// A pointer to an EXCEPTION_RECORD structure that contains a
    /// machine-independent description of the exception.
    /// </summary>
    IntPtr^ ExceptionRecord;

    /// <summary>
    /// A pointer to a CONTEXT structure that contains a processor-specific
    /// description of the state of the processor at the time of the exception.
    /// </summary>
    IntPtr^ Context;
};
};  // namespace Cli
};  // namespace Core
};  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTION_POINTERS_H_