// =======================================================================
// <copyright file="Logger.swift" company="Bean &amp; Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-03-2015</date>
// =======================================================================

import Foundation

class Logger {
    /// <summary>
    /// The native C++ logger pointer.
    /// </summary>
    var logger: UnsafeMutablePointer<Void>
    
    /// <summary>
    /// Initializes a new instance of the <see cref="Logger" /> class.
    /// </summary>
    init(var outputDirectory: String) {
        logger = DSLogAllocateLogger(outputDirectory)
    }
}
