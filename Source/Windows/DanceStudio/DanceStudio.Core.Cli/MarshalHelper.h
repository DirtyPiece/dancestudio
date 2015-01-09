// =======================================================================
// <copyright file="MarshalHelper.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_MARSHALHELPER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_MARSHALHELPER_H_

#include <string>
#include "..\..\..\Common\DanceStudio.Core\Typedefs.h"

using System::String;
using System::Text::Encoding;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a logger that can log statements to a file for the application.
/// </summary>
public ref class MarshalHelper abstract sealed {
 public:
    /// <summary>
    /// Converts the string to an STL string.
    /// </summary>
    /// <param name="string">The string to convert to an STL string.</param>
    /// <returns>The STL string representation of the managed string.</returns>
    inline static std::string ConvertStringToStlString(String^ string) {
        array<BYTE>^ bytes = Encoding::ASCII->GetBytes(string);
        pin_ptr<BYTE> ptr = &bytes[0];
        return std::string(reinterpret_cast<CHAR*>(ptr));
    }

    /// <summary>
    /// Converts the string to an STL wstring.
    /// </summary>
    /// <param name="string">The string to convert to an STL wstring.</param>
    /// <returns>The STL wstring representation of the managed string.</returns>
    inline static std::wstring ConvertStringToStlWString(String^ string) {
        array<BYTE>^ bytes = Encoding::Unicode->GetBytes(string);
        pin_ptr<BYTE> ptr = &bytes[0];
        return std::wstring(reinterpret_cast<WCHAR*>(ptr));
    }
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_MARSHALHELPER_H_
