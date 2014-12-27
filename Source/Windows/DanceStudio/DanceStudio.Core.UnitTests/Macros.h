// =======================================================================
// <copyright file="Macros.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_MACROS_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_MACROS_H_

#ifndef DANCE_STUDIO_TEST_METHOD
#define DANCE_STUDIO_TEST_METHOD(methodName, owner) \
    BEGIN_TEST_METHOD_ATTRIBUTE(methodName) \
    TEST_OWNER(owner) \
    END_TEST_METHOD_ATTRIBUTE() \
    TEST_METHOD(methodName)
#endif  // DANCE_STUDIO_TEST_METHOD

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_UNITTESTS_MACROS_H_
