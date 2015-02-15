// =======================================================================
// <copyright file="ExceptionHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-09-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTIONHELPER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTIONHELPER_H_

#include "SEHException.h"
#include "..\..\..\Common\DanceStudio.Core\DanceStudio.Core.h"

using System::Object;
using System::String;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a class that helps with exception operations.
/// </summary>
public ref class ExceptionHelper {
 public:
     /// <summary>
     /// Throws a managed exception that represents the contents
     /// of the SEH exception.
     /// </summary>
     /// <param name="exception">
     /// The exception to be repackaged and thrown.
     /// </param>
     static void ThrowSEHException(
         System::Runtime::InteropServices::SEHException^ exception);

 private:
     /// <summary>
     /// Throws a managed exception that corresponds with the passed
     /// in exception code.
     /// </summary>
     /// <param name="exceptionCode">
     /// The exception code that identifies the type of exception to throw.
     /// </param>
     /// <param name="message">
     /// The message to display on the managed exception.
     /// </param>
     /// <param name="sehException">
     /// The SEH exception which will be added as the inner exception.
     /// </param>
     static void ThrowManagedException(
         INT32 exceptionCode,
         String^ message,
         System::Runtime::InteropServices::SEHException^ sehException);
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_EXCEPTIONHELPER_H_