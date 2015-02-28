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
    using System.IO;
    using System.Linq;
    using System.Reflection;
    using System.Text;
    using System.Threading.Tasks;
    using DanceStudio.Core.Cli;

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
        /// The relative path to the local help file for user documentation.
        /// </summary>
        private const string HelpFileRelativePath = @"Documentation\Dance Studio Help.pdf";

        /// <summary>
        /// Launches the help documentation in the user's default browser.
        /// </summary>
        /// <remarks>
        /// Will open the URL at <see cref="HelpDocumentationUrl"/>.
        /// </remarks>
        public static void LaunchHelpDocumentationInDefaultBrowser()
        {
            Logger.Instance.LogVerbose("Launching the help documentation link at '{0}'.", HelpDocumentationUrl);
            try
            {
                Process.Start(HelpDocumentationUrl);
            }
            catch (Exception ex)
            {
                Logger.Instance.LogError("Failed to launch the help documentation due to an exception:\n{0}", ex.ToString());
            }
        }

        /// <summary>
        /// Launches the help documentation.
        /// </summary>
        public static void LaunchHelpDocumentation()
        {
            Logger.Instance.LogVerbose("Launching the help documentation at '{0}'.", HelpDocumentationUrl);
            try
            {
                string exeDirectory = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
                string documentationPath = Path.Combine(exeDirectory, HelpFileRelativePath);
                Process.Start(documentationPath);
            }
            catch (Exception ex)
            {
                Logger.Instance.LogError("Failed to launch the help documentation due to an exception:\n{0}", ex.ToString());
            }
        }
    }
}
