// =======================================================================
// <copyright file="FileHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-17-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "FileHelper.h"
#include <stdio.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif  // _WIN32

using DanceStudio::Core::FileHelper;

std::string FileHelper::LoadAllFileText(const std::string& filePath) {
    FILE* file = fopen(filePath.c_str(), "r");
    Validator::IsFileOpened(file, filePath);

    fseek(file, 0, SEEK_END);
    INT32 fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    CHAR* buffer = new CHAR[fileSize + 1];
    INT32 readSize = fread(buffer, sizeof(CHAR), fileSize, file);

    // Terminate the string.
    buffer[readSize] = 0;
    std::string contents = buffer;
    delete[] buffer;

    return contents;
}

std::string FileHelper::GetExecutingExeDirectory() {
    const INT32 bufferSize = MAX_PATH + 1;
    CHAR* filePath = new CHAR[bufferSize];
    DWORD result = GetModuleFileName(
        nullptr,
        filePath,
        bufferSize);

    if (result >= bufferSize) {
        Throw::InvalidOperationException(
            "Unable to get the exe directory due"
            " to the buffer being too small.");
    }

    // Search backwards from the end until we find the end of the exe
    // filename.  We'll insert a null terminator there to cut the
    // filename portion off and just get the directory.
    INT32 i = result - 1;
    for (; i > 0; --i) {
        if (filePath[i] == DANCE_STUDIO_PATH_SEPARATOR) {
            filePath[i] = 0;
            break;
        }
    }

    if (i == 0) {
        Throw::InvalidOperationException(
            "An error occured while trying to"
            " find the exe folder location.");
    }

    std::string returnedPath = filePath;

    delete[] filePath;

    return returnedPath;
}

