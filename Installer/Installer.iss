; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Dance Studio"
#define MyAppVersion "1.0"
#define MyAppPublisher "Bean and Cheese Studios"
#define MyAppURL "http://www.beanandcheesestudios.com"
#define MyAppExeName "DanceStudio.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{49C8DA1D-2F83-4EDB-AEDC-6F808F5CFFDF}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
OutputDir=C:\Code\DanceStudio\Installer
OutputBaseFilename=DanceStudioInstall
Compression=lzma
SolidCompression=yes
SourceDir=..\Source\Windows\DanceStudio\DanceStudio\bin\x64\Release

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "DanceStudio.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "DanceStudio.Controller.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "DanceStudio.exe.config"; DestDir: "{app}"; Flags: ignoreversion
Source: "en-US\DanceStudio.resources.dll"; DestDir: "{app}\en-US"; Flags: ignoreversion
Source: "Documentation\Dance Studio Help.pdf"; DestDir: "{app}\Documentation"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

