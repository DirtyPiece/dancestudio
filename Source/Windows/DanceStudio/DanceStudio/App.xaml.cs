// =======================================================================
// <copyright file="App.xaml.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-24-2014</date>
// =======================================================================

namespace DanceStudio
{
    using System;
using System.Threading;
using System.Windows;
using System.Windows.Threading;
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

            // Set up listeners to handle unhandled exceptions (WPF swallows by default).
            // We want to be able to catch and log exceptions from the native layer.
            App.Current.DispatcherUnhandledException += this.App_DispatcherUnhandledException;
            System.Windows.Forms.Application.ThreadException += this.Application_ThreadException;
        }

        /// <summary>
        /// Handles the ThreadException event of the Application control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="ex">The <see cref="ThreadExceptionEventArgs"/> instance containing the event data.</param>
        private void Application_ThreadException(object sender, ThreadExceptionEventArgs ex)
        {
            ShowExceptionDialog(ex.Exception);
        }

        /// <summary>
        /// Handles the DispatcherUnhandledException event of the App control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="ex">The <see cref="DispatcherUnhandledExceptionEventArgs"/> instance containing the event data.</param>
        private void App_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs ex)
        {
            ShowExceptionDialog(ex.Exception);
        }

        /// <summary>
        /// Shows an exception message dialog.
        /// </summary>
        /// <param name="ex">The exception to show.</param>
        private void ShowExceptionDialog(Exception ex)
        {
            string message = string.Format(
                "Unhandled thread exception occured:\n{0}",
                ex);

            Logger.Instance.LogError(message);
            MessageBox.Show(message);
        }
    }
}
