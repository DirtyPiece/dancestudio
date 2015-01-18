// =======================================================================
// <copyright file="Throw.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>10-12-2015</date>
// =======================================================================

#include "Stdafx.h"
#include <string>
#include "Throw.h"

using DanceStudio::Core::Throw;

void Throw::ArgumentNullException(const std::string& paramName) {
    throw std::invalid_argument("'" + paramName + "' cannot be null.");
}

void Throw::ArgumentOutOfRangeException(const std::string& paramName) {
    throw std::invalid_argument(
        "The argument '" + paramName + "' is out of range.");
}

void Throw::InvalidOperationException(const std::string& message) {
    throw std::runtime_error(message);
}
