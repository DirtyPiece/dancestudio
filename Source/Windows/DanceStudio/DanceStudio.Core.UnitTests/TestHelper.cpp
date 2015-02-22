// =======================================================================
// <copyright file="TestHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-21-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "TestHelper.h"

using DanceStudioCoreUnitTests::TestHelper;

std::string TestHelper::LoadAllFileText(const std::string& filePath) {
    FILE* file = fopen(filePath.c_str(), "r");

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = new char[fileSize + 1];
    size_t readSize = fread(buffer, sizeof(char), fileSize, file);

    // Terminate the string.
    buffer[readSize] = 0;
    std::string contents = buffer;
    delete[] buffer;

    fclose(file);
    file = nullptr;

    return contents;
}