// =======================================================================
// <copyright file="ExceptionHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-09-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "ExceptionHelper.h"
#include "EXCEPTION_POINTERS.h"
#include "EXCEPTION_RECORD.h"
#include "SEHException.h"
#include "Throw.h"
#include "..\..\..\Common\DanceStudio.Core\DanceStudioExceptionType.h"

using DanceStudio::Core::Cli::ExceptionHelper;
using DanceStudio::Core::Cli::EXCEPTION_POINTERS;
using DanceStudio::Core::Cli::EXCEPTION_RECORD;
using DanceStudio::Core::Cli::SEHException;
using System::IntPtr;
using System::ArgumentNullException;
using System::ArgumentOutOfRangeException;
using System::InvalidOperationException;
using System::OutOfMemoryException;
using System::Runtime::InteropServices::Marshal;

Exception^ ExceptionHelper::UnpackSEHException(
    System::Runtime::InteropServices::SEHException^ exception) {
    assert(exception != nullptr);

    // Grab the exception code from the call to RaiseException in the Core
    // library.
    INT32 exceptionCode = Marshal::GetExceptionCode();

    // Get a pointer to the unmanaged EXCEPTION_POINTERS structure.
    IntPtr exceptionPointers = Marshal::GetExceptionPointers();

    // Convert the EXCEPTION_POINTERS structure into the managed version.
    EXCEPTION_POINTERS^ managedExceptionPointers =
        dynamic_cast<EXCEPTION_POINTERS^>(
        Marshal::PtrToStructure(
            exceptionPointers,
            EXCEPTION_POINTERS::typeid));

    if (managedExceptionPointers == nullptr) {
        Throw::InvalidOperationException(
            "The EXCEPTION_POINTERS structure"
            " could not be marshaled properly.");
    }

    // Convert the EXCEPTION_RECORD structure into the managed version.
    EXCEPTION_RECORD^ record =
        dynamic_cast<EXCEPTION_RECORD^>(
        Marshal::PtrToStructure(
            managedExceptionPointers->ExceptionRecord,
            EXCEPTION_RECORD::typeid));

    if (record == nullptr) {
        Throw::InvalidOperationException(
            "The EXCEPTION_RECORD structure"
            " could not be marshaled properly.");
    }

    // Verify that this is an exception code we recognize.
    if (exceptionCode >= DANCE_STUDIO_EXCEPTION_TYPE_START
     && exceptionCode < DANCE_STUDIO_EXCEPTION_TYPE_END) {
        if (record->NumberParameters <= 0) {
            Throw::InvalidOperationException(
                "The number of parameters for the exception"
                " record should be greater than 0.");
        }

        IntPtr exceptionInfoPointer(
            safe_cast<INT32>(record->ExceptionInformation[0]));

        // Grab out the SEH exception structure.
        SEHException^ sehException = dynamic_cast<SEHException^>(
            Marshal::PtrToStructure(
                exceptionInfoPointer,
                SEHException::typeid));

        // The responsibility of freeing the memory for the exception lies here.
        Marshal::DestroyStructure(exceptionInfoPointer, SEHException::typeid);
        Marshal::FreeCoTaskMem(exceptionInfoPointer);

        // Throw the managed exception.
        Exception^ ex = ExceptionHelper::CreateManagedExceptionFromSEHException(
            exceptionCode,
            sehException->Message,
            sehException->StackTrace,
            exception);

        return ex;
    }
    else {
        Logger::Instance->LogVerbose(
            "The SEH Exception was not a Dance Studio SEH exception.");
    }
    
    return nullptr;
}

Exception^ ExceptionHelper::CreateManagedExceptionFromSEHException(
    INT32 exceptionCode,
    String^ message,
    String^ callstack,
    System::Runtime::InteropServices::SEHException^ sehException) {
    assert(exceptionCode >= 0);
    assert(message != nullptr);
    assert(callstack != nullptr);
    assert(sehException != nullptr);

    switch (exceptionCode) {
        case DANCE_STUDIO_EXCEPTION_TYPE_ARGUMENT_NULL:
            return gcnew ArgumentNullException(
                message,
                sehException);
        case DANCE_STUDIO_EXCEPTION_TYPE_ARGUMENT_OUT_OF_RANGE:
            return gcnew ArgumentOutOfRangeException(
                message,
                sehException);
        case DANCE_STUDIO_EXCEPTION_TYPE_INVALID_OPERATION:
            return gcnew InvalidOperationException(
                message,
                sehException);
        case DANCE_STUDIO_EXCEPTION_TYPE_OUT_OF_MEMORY:
            return gcnew OutOfMemoryException(
                message,
                sehException);
        default:
            String^ errorMessage = String::Format(
                "Dance Studio exception type value of '{0}' is not supported.",
                exceptionCode);

            throw gcnew InvalidOperationException(errorMessage);
    }
}
