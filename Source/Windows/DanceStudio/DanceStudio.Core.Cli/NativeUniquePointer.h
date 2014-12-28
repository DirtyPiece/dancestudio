// =======================================================================
// <copyright file="NativeUniquePointer.h" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-27-2014</date>
// =======================================================================

#ifndef SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_NATIVEUNIQUEPOINTER_H_
#define SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_NATIVEUNIQUEPOINTER_H_

#include <memory>
#include <cassert>

namespace DanceStudio {
namespace Core {
namespace Cli {
/// <summary>
/// Represents a native pointer that is auto-released when scope ends.
/// </summary>
template<typename T>
public ref class NativeUniquePointer {
 public:
    /// <summary>
    /// Initializes a new instance of the <see cref="NativeUniquePointer{T}"/>
    /// class.
    /// </summary>
    NativeUniquePointer()
        : _pointer(nullptr) {
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="NativeUniquePointer{T}"/>
    /// class.
    /// </summary>
    /// <param name="pointer">The pointer to track and release.</param>
    NativeUniquePointer(T* pointer)
        : _pointer(pointer) {
    }

    /// <summary>
    /// Finalizes an instance of the <see cref="NativeUniquePointer{T}"/> class.
    /// </summary>
    ~NativeUniquePointer() {
        delete _pointer;
    }

    /// <summary>
    /// Operator overload for the -> operator that returns the pointer.
    /// </summary>
    /// <returns>The pointer to the inner native reference.</returns>
    T* operator->() {
        assert(_pointer != nullptr);
        return _pointer;
    }

    /// <summary>
    /// Operator overload for the = operator that assigns the pointer.
    /// </summary>
    /// <param name="pointer">The pointer to assign for tracking.</param>
    /// <returns>A reference to this object.</returns>
    NativeUniquePointer<T>% operator=(T* pointer) {
        if (_pointer != nullptr) {
            throw gcnew System::ArgumentException(
                "The pointer being assigned to has already been assigned to.");
        }

        _pointer = pointer;
        return *this;
    }


private:
    /// <summary>
    /// The native pointer being wrapped.
    /// </summary>
    T* _pointer;
};
}  // namespace Cli
}  // namespace Core
}  // namespace DanceStudio

#endif  // SOURCE_WINDOWS_DANCESTUDIO_DANCESTUDIO_CORE_CLI_NATIVEUNIQUEPOINTER_H_
