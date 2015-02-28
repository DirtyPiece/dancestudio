// =======================================================================
// <copyright file="Validator.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_VALIDATOR_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_VALIDATOR_H_

#include "Throw.h"

using System::Object;
using System::String;
using DanceStudio::Core::Cli::Throw;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents the validator for verifying input parameters and
/// program functionality.
/// </summary>
public ref class Validator {
public:
    static void IsNotNull(
        const Object^ object,
        String^ parameterName) {
        if (object == nullptr) {
            Throw::ArgumentNullException(parameterName);
        }
    }
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_VALIDATOR_H_