// =======================================================================
// <copyright file="HelpController.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

namespace DanceStudio.Controller
{
    using System;
    using System.Collections.Generic;
    using System.Diagnostics;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    /// <summary>
    /// Represents the controller that performs operations to help the user
    /// learn about Dance Studio.
    /// </summary>
    public static class HelpController
    {
        /// <summary>
        /// The URL to the help documentation for users of Dance Studio.  All user
        /// documentation is stored in a shared OneNote notebook on OneDrive.
        /// </summary>
        private const string HelpDocumentationUrl = "https://onedrive.live.com/redir?resid=DFA2592B559E3EE7!113&authkey=!AGur6S7aqPKWOVE&ithint=onenote%2c";

        /// <summary>
        /// Launches the help documentation in the user's default browser.
        /// </summary>
        /// <remarks>
        /// Will open the URL at <see cref="HelpDocumentationUrl"/>.
        /// </remarks>
        public static void LaunchHelpDocumentationInDefaultBrowser()
        {
            try
            {
                Process.Start(HelpDocumentationUrl);
            }
            catch
            {
            }
        }
    }
}
