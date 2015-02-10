// =======================================================================
// <copyright file="EXCEPTION_RECORD.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-08-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTION_RECORD_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTION_RECORD_H_

using System::IntPtr;
using System::Int32;
using System::UInt32;
using System::Runtime::InteropServices::StructLayoutAttribute;
using System::Runtime::InteropServices::MarshalAsAttribute;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a marshaled EXCEPTION_RECORD structure.
/// </summary>
[StructLayout(LayoutKind.Sequential, Pack = 1)]
public ref struct EXCEPTION_RECORD
{
    /// <summary>
    /// The reason the exception occurred. This is the code generated by a
    /// hardware exception, or the code specified in the RaiseException
    /// function for a software-generated exception. The following tables
    /// describes the exception codes that are likely to occur due to common
    /// programming errors. 
    /// </summary>
    UInt32 ExceptionCode;

    /// <summary>
    /// The exception flags. This member can be either zero, indicating a
    /// continuable exception, or EXCEPTION_NONCONTINUABLE indicating a
    /// noncontinuable exception. Any attempt to continue execution after a
    /// noncontinuable exception causes the EXCEPTION_NONCONTINUABLE_EXCEPTION
    /// exception.
    /// </summary>
    UInt32 ExceptionFlags;
    /// <summary>
    /// A pointer to an associated EXCEPTION_RECORD structure. Exception
    /// records can be chained together to provide additional information
    /// when nested exceptions occur.
    /// </summary>
    IntPtr ExceptionRecord;

    /// <summary>
    /// The address where the exception occurred.
    /// </summary>
    IntPtr ExceptionAddress;

    /// <summary>
    /// The number of parameters associated with the exception. This is the
    /// number of defined elements in the ExceptionInformation array.
    /// </summary>
    UInt32 NumberParameters;

    /// <summary>
    /// An array of additional arguments that describe the exception. The
    /// RaiseException function can specify this array of arguments. For
    /// most exception codes, the array elements are undefined. The following
    /// table describes the exception codes whose array elements are defined.
    /// </summary>
    [MarshalAs(UnmanagedType.ByValArray, SizeConst = EXCEPTION_MAXIMUM_PARAMETERS)]
    array<UInt32>^ ExceptionInformation;
};
};  // namespace Cli
};  // namespace Core
};  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTION_RECORD_H_