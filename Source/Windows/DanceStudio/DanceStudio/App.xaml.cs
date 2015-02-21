// =======================================================================
// <copyright file="App.xaml.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-24-2014</date>
// =======================================================================

namespace DanceStudio
{
    using System;
    using System.Reflection;
    using System.Threading;
    using System.Windows;
    using System.Windows.Media;
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
            Logger.Instance.LogInfo(
                "Dance Studio version '{0}' was launched.",
                Assembly.GetExecutingAssembly().GetName().Version);

            // Set up listeners to handle unhandled exceptions (WPF swallows by default).
            // We want to be able to catch and log exceptions from the native layer.
            App.Current.DispatcherUnhandledException += this.App_DispatcherUnhandledException;
            System.Windows.Forms.Application.ThreadException += this.Application_ThreadException;

            // Register the main tick function for rendering OpenGL.
            CompositionTarget.Rendering += this.CompositionTarget_Rendering;
        }

        /// <summary>
        /// Gets or sets main <see cref="StepChartEditor"/> control.
        /// </summary>
        public static StepChartEditor StepChartEditor
        {
            get;
            set;
        }

        /// <summary>
        /// Handles the Rendering event of the CompositionTarget control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void CompositionTarget_Rendering(object sender, EventArgs e)
        {
            if (App.StepChartEditor != null)
            {
                App.StepChartEditor.Tick();
            }
        }

        /// <summary>
        /// Handles the ThreadException event of the Application control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="ex">The <see cref="ThreadExceptionEventArgs"/> instance containing the event data.</param>
        private void Application_ThreadException(object sender, ThreadExceptionEventArgs ex)
        {
            this.LogAndDisplayUnhandledException(ex.Exception);
        }

        /// <summary>
        /// Handles the DispatcherUnhandledException event of the App control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="ex">The <see cref="DispatcherUnhandledExceptionEventArgs"/> instance containing the event data.</param>
        private void App_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs ex)
        {
            this.LogAndDisplayUnhandledException(ex.Exception);
        }

        /// <summary>
        /// Logs and displays an unhandled exception.
        /// </summary>
        /// <param name="ex">The exception to log and display.</param>
        private void LogAndDisplayUnhandledException(Exception ex)
        {
            Exception dialogException = null;
            System.Runtime.InteropServices.SEHException sehException = ex as System.Runtime.InteropServices.SEHException;
            if (sehException != null)
            {
                try
                {
                    dialogException = ExceptionHelper.UnpackSEHException(sehException);
                }
                catch (Exception unpackException)
                {
                    dialogException = unpackException;
                }
            }
            else
            {
                Logger.Instance.LogError(
                    "Unhandled exception encountered in the application:\n{0}",
                    ex);

                dialogException = ex;
            }

            string message = string.Format(
                "Unhandled thread exception occured:\n{0}",
                dialogException ?? ex);

            Logger.Instance.LogError(message);
            //// ShowExceptionDialog(message);
        }

        /// <summary>
        /// Shows an exception message dialog.
        /// </summary>
        /// <param name="message">The message to show.</param>
        private void ShowExceptionDialog(string message)
        {
            System.Windows.Forms.MessageBox.Show(message);
        }
    }
}
