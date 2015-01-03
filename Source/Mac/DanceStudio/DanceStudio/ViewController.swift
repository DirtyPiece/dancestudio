// =======================================================================
// <copyright file="ViewController.swift" company="Bean &amp; Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-03-2015</date>
// =======================================================================

import Cocoa

/// <summary>
/// Represents the main view controller for the Dance Studio window.
/// </summary>
class ViewController: NSViewController {
    /// <summary>
    /// Called when the view has finished loading.
    /// </summary>
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    /// <summary>
    /// Property hook for determining when the represented object was set.
    /// </summary>
    override var representedObject: AnyObject? {
        didSet {
        // Update the view, if already loaded.
        }
    }
}

