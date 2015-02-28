# =======================================================================
# <copyright file="FixWpfDesigner.ps1" company="Bean and Cheese Studios">
# Copyright 2015 Bean and Cheese Studios
# </copyright>
# <date>02-28-2015</date>
# =======================================================================

# Adds an unmanaged dll path to the PATH environment variable if it's not
# already there.
function AddDLLToPathIfNotPresent([string] $unmanagedDllPath)
{
    $pathValue = [Environment]::GetEnvironmentVariable("PATH", [EnvironmentVariableTarget]::Machine);
    if (-not $pathValue.Contains($unmanagedDllPath))
    {
        Write-Output "Adding unmanaged DLL path '$unmanagedDllPath' to the PATH environment variable."
        $pathValue = $pathValue + ";$unmanagedDllPath"
        [Environment]::SetEnvironmentVariable("PATH", $pathValue, [EnvironmentVariableTarget]::Machine);
    }
}

# The WPF designer won't load if it can't find unmanaged DLL dependencies
# so we add them to the path variable here.
Write-Output "Fixing the WPF designer search paths for unamanged DLLs."

# FMOD DLLs.
$scriptPath = Split-Path -parent $PSCommandPath
$externalRoot = "$scriptPath\..\..\Source\External"
AddDLLToPathIfNotPresent "$externalRoot\FMOD\dll\x64"
AddDLLToPathIfNotPresent "$externalRoot\FMOD\dll\x64\log"
AddDLLToPathIfNotPresent "$externalRoot\FMOD\dll\x86"
AddDLLToPathIfNotPresent "$externalRoot\FMOD\dll\x86\log"