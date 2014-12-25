// =======================================================================
// <copyright file="BrowserHelper.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-25-2014</date>
// =======================================================================

namespace DanceStudio.Helpers
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Diagnostics;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    /// <summary>
    /// Represents a class that contains static helper methods for dealing with
    /// the browser operations on the user's machine.
    /// </summary>
    public static class BrowserHelper
    {
        /// <summary>
        /// Launches the user's default browser and navigates to the specified URL.
        /// </summary>
        /// <param name="url">The URL to navigate the browser to when it starts up.</param>
        public static void LaunchToUrl(Uri url)
        {
            try
            {
                Process.Start(url.ToString());
            }
            catch (Exception)
            {
                // Firefox can fire a Win32Exception even if it succeeds if the user has never opened a browser for the first time.
                // We can just ignore when this happens.
            }
        }
    }
}
