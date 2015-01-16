// =======================================================================
// <copyright file="App.xaml.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-24-2014</date>
// =======================================================================

namespace DanceStudio
{
    using System.Windows;
    using DanceStudio.Core.Cli;

    /// <summary>
    /// Represents the main application class.
    /// </summary>
    public partial class App : Application
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="App"/> class.
        /// </summary>
        public App()
        {
            // Log a statement to ensure that the logger is present for all future
            // operations.
            Logger.Instance.LogInfo("The Dance Studio application was launched.");
        }
    }
}
