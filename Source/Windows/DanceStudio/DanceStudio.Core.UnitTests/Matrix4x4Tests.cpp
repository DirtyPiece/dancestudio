// =======================================================================
// <copyright file="Matrix4x4.cpp" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>04-04-2015</date>
// =======================================================================

#include "Stdafx.h"
#include "CppUnitTest.h"
#include "Matrix4x4.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;  // NOLINT
using DanceStudio::Core::Matrix4x4;

namespace DanceStudioCoreUnitTests {
    TEST_CLASS(PathHelperTests) {
public:
    DANCE_STUDIO_TEST_METHOD(
        ArrayOperator_WhenCalled_CorrectlySetsTheMatrixValues,
        L"DirtyPiece") {
        Matrix4x4 matrix;

        SINGLE value = 0.0f;
        for (UINT32 c = 0; c < 4; ++c) {
            for (UINT32 r = 0; r < 4; ++r) {
                matrix[c][r] = value++;
            }
        }

        WCHAR tempBuffer[3];
        for (UINT32 i = 0; i < 16; ++i) {
            Assert::AreEqual(
                static_cast<SINGLE>(i),
                matrix.Get()[i],
                (L"The matrix value at index '" +
                std::wstring(_itow(i, tempBuffer, 10)) +
                L"'is invalid.").c_str());
        }
    }

    DANCE_STUDIO_TEST_METHOD(
        Constructor_WhenCalled_CorrectlySetsTheIdentityMatrix,
        L"DirtyPiece") {
        Matrix4x4 matrix;

        this->AssertIsIdentity(matrix);
    }

    DANCE_STUDIO_TEST_METHOD(
        Translation_WhenCalled_CorrectlySetsTranslationValues,
        L"DirtyPiece") {
        SINGLE x = 1.0f;
        SINGLE y = 2.0f;
        SINGLE z = 3.0f;

        Matrix4x4 matrix = Matrix4x4::Translation(x, y, z);

        WCHAR tempBuffer[3];
        for (UINT32 c = 0; c < 3; ++c) {
            for (UINT32 r = 0; r < 4; ++r) {
                if (c == r) {
                    Assert::AreEqual(
                        1.0f,
                        matrix[c][r],
                        (L"The diagonal value at column '" +
                        std::wstring(_itow(c, tempBuffer, 10)) +
                        L"' and row '" +
                        std::wstring(_itow(r, tempBuffer, 10)) +
                        L"'is invalid.").c_str());
                }
                else {
                    Assert::AreEqual(
                        0.0f,
                        matrix[c][r],
                        (L"The non-diagonal value at column '" +
                        std::wstring(_itow(c, tempBuffer, 10)) +
                        L"' and row '" +
                        std::wstring(_itow(r, tempBuffer, 10)) +
                        L"'is invalid.").c_str());
                }
            }
        }

        Assert::AreEqual(matrix[3][0], x, L"The x-component of translation is not correct.");
        Assert::AreEqual(matrix[3][1], y, L"The y-component of translation is not correct.");
        Assert::AreEqual(matrix[3][2], z, L"The z-component of translation is not correct.");
        Assert::AreEqual(matrix[3][3], 1.0f, L"The w-component of translation is not correct.");
    }

    DANCE_STUDIO_TEST_METHOD(
        RotationX_WhenCalledWith90Degrees_CorrectlySetsRotationValues,
        L"DirtyPiece") {
        Matrix4x4 result = Matrix4x4::RotationX(90.0f);

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[1][1], 0.0f),
            L"The matrix component at 1, 1 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[2][1], -1.0f),
            L"The matrix component at 2, 1 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[1][2], 1.0f),
            L"The matrix component at 1, 2 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[2][2], 0.0f),
            L"The matrix component at 2, 2 is not correct.");
    }

    DANCE_STUDIO_TEST_METHOD(
        RotationY_WhenCalledWith90Degrees_CorrectlySetsRotationValues,
        L"DirtyPiece") {
        Matrix4x4 result = Matrix4x4::RotationY(90.0f);

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[0][0], 0.0f),
            L"The matrix component at 0, 0 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[2][0], 1.0f),
            L"The matrix component at 2, 0 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[0][2], -1.0f),
            L"The matrix component at 0, 2 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[2][2], 0.0f),
            L"The matrix component at 2, 2 is not correct.");
    }

    DANCE_STUDIO_TEST_METHOD(
        RotationZ_WhenCalledWith90Degrees_CorrectlySetsRotationValues,
        L"DirtyPiece") {
        Matrix4x4 result = Matrix4x4::RotationZ(90.0f);

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[0][0], 0.0f),
            L"The matrix component at 0, 0 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[0][1], 1.0f),
            L"The matrix component at 0, 1 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[1][0], -1.0f),
            L"The matrix component at 1, 0 is not correct.");

        Assert::IsTrue(
            TestHelper::FuzzyEquals(result[1][1], 0.0f),
            L"The matrix component at 1, 1 is not correct.");
    }

    DANCE_STUDIO_TEST_METHOD(
        Transpose_WhenCalled_CorrectlySetsMatrixValues,
        L"DirtyPiece") {
        Matrix4x4 matrix;

        for (UINT32 i = 0; i < 16; ++i) {
            matrix.Get()[i] = i;
        }

        WCHAR tempBuffer[3];
        Matrix4x4 result = Matrix4x4::Transpose(matrix);
        for (UINT32 c = 0; c < 4; ++c) {
            for (UINT32 r = 0; r < 4; ++r) {
                Assert::AreEqual(
                    matrix[r][c],
                    result[c][r],
                    (L"The matrix value at '" +
                    std::wstring(_itow(c, tempBuffer, 10)) +
                    L"' and row '" +
                    std::wstring(_itow(r, tempBuffer, 10)) +
                    L"'is invalid.").c_str());
            }
        }
    }

    DANCE_STUDIO_TEST_METHOD(
        Invert_WhenCalled_CorrectlySetsMatrixValues,
        L"DirtyPiece") {
        Matrix4x4 matrix =
            Matrix4x4::RotationX(45.0f) *
            Matrix4x4::RotationY(45.0f) *
            Matrix4x4::RotationZ(45.0f) *
            Matrix4x4::Translation(1.0f, 2.0f, 3.0f);

        Matrix4x4 inverse = Matrix4x4::Invert(matrix);

        Matrix4x4 result = matrix * inverse;
        this->AssertIsIdentity(result);
    }

    DANCE_STUDIO_TEST_METHOD(
        Multiply_WhenCalled_CorrectlySetsMatrixValues,
        L"DirtyPiece") {
        Matrix4x4 result =
            Matrix4x4::RotationX(90.0f) *
            Matrix4x4::RotationX(90.0f) *
            Matrix4x4::RotationX(90.0f) *
            Matrix4x4::RotationX(90.0f);

        this->AssertIsIdentity(result);
    }

 private:
    void AssertIsIdentity(const Matrix4x4& matrix) {
        WCHAR tempBuffer[3];
        for (UINT32 c = 0; c < 4; ++c) {
            for (UINT32 r = 0; r < 4; ++r) {
                if (c == r) {
                    Assert::IsTrue(
                        TestHelper::FuzzyEquals(1.0f, matrix[c][r]),
                        (L"The diagonal value at column '" +
                        std::wstring(_itow(c, tempBuffer, 10)) +
                        L"' and row '" +
                        std::wstring(_itow(r, tempBuffer, 10)) +
                        L"'is invalid.").c_str());
                }
                else {
                    Assert::IsTrue(
                        TestHelper::FuzzyEquals(0.0f, matrix[c][r]),
                        (L"The non-diagonal value at column '" +
                        std::wstring(_itow(c, tempBuffer, 10)) +
                        L"' and row '" +
                        std::wstring(_itow(r, tempBuffer, 10)) +
                        L"'is invalid.").c_str());
                }
            }
        }
    }
    };
}  // namespace DanceStudioCoreUnitTests