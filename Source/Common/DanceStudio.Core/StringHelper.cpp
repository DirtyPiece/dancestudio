// =======================================================================
// <copyright file="StringHelper.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>02-22-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "StringHelper.h"
#include <string>

using DanceStudio::Core::StringHelper;

std::vector<std::string> StringHelper::Split(
    const std::string& str,
    CHAR delimiter) {
    std::stringstream stream(str);
    std::string element;
    std::vector<std::string> elements;
    while (std::getline(stream, element, delimiter)) {
        elements.push_back(element);
    }

    return elements;
}
