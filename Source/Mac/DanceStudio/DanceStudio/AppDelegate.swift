// =======================================================================
// <copyright file="AppDelegate.swift" company="Bean &amp; Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>01-03-2015</date>
// =======================================================================

import Cocoa

/// <summary>
/// Represents the main application delegate for Dance Studio.
/// </summary>
@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {
    /// <summary>
    /// Event that is raised when the user clicks the
    /// Help->DanceStudio Help menu item.
    /// </summary>
    @IBAction func danceStudioHelpClicked(sender: NSMenuItem) {
        let helpDocumentationUrl = "https://onedrive.live.com/redir?resid=DFA2592B559E3EE7!113&authkey=!AGur6S7aqPKWOVE&ithint=onenote%2c"
        
        if let checkURL = NSURL(string: helpDocumentationUrl) {
            NSWorkspace.sharedWorkspace().openURL(checkURL)
        }
    }
    
    /// <summary>
    /// Called when the application finished launching (used as a point to initialize the app).
    /// </summary>
    /// <param name="aNotification">The notification object.</param>
    func applicationDidFinishLaunching(aNotification: NSNotification) {
        // Insert code here to initialize your application
    }
    
    /// <summary>
    /// Called when the application terminates (to perform cleanup).
    /// </summary>
    /// <param name="aNotification">The notification object.</param>
    func applicationWillTerminate(aNotification: NSNotification) {
        // Insert code here to tear down your application
    }
}
