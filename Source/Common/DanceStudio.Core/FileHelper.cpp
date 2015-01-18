// =======================================================================
// <copyright file="FileHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-17-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "FileHelper.h"
#include <stdio.h>

using DanceStudio::Core::FileHelper;

std::string FileHelper::LoadAllFileText(const std::string& filePath) {
    FILE* file = fopen(filePath.c_str(), "r");
    Validator::IsFileOpened(file, filePath);

    fseek(file, 0, SEEK_END);
    INT32 fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    CHAR* buffer = new CHAR[fileSize + 1];
    fread(buffer, sizeof(CHAR), fileSize, file);

    // Terminate the string.
    buffer[fileSize] = 0;
    std::string contents = buffer;
    delete[] buffer;

    return contents;
}