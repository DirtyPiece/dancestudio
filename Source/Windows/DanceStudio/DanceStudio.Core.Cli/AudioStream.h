// =======================================================================
// <copyright file="AudioStream.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-28-2015</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_AUDIOSTREAM_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_AUDIOSTREAM_H_

#include "..\..\..\Common\DanceStudio.Core\DanceStudio.Core.h"

using System::String;

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a control that edits stepcharts for StepMania and
/// In The Groove arcade machines.
/// </summary>
public ref class AudioStream {
 public:
     /// <summary>
     /// Initializes a new instance of the <see cref="AudioStream"/> class.
     /// </summary>
     /// <param name="audioFilePath">
     /// The audio file path to load as a stream.
     /// </param>
     AudioStream(String^ audioFilePath);

     /// <summary>
     /// Finalizes an instance of the <see cref="AudioStream" /> class.
     /// </summary>
     ~AudioStream();

 internal:
     /// <summary>
     /// The native audio stream that is wrapped by this class.
     DS_AUDIOSTREAM* stream;
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_AUDIOSTREAM_H_