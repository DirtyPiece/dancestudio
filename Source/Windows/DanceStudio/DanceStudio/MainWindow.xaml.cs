// =======================================================================
// <copyright file="MainWindow.xaml.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-24-2014</date>
// =======================================================================

namespace DanceStudio
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows;
    using System.Windows.Controls;
    using System.Windows.Data;
    using System.Windows.Documents;
    using System.Windows.Input;
    using System.Windows.Media;
    using System.Windows.Media.Imaging;
    using System.Windows.Navigation;
    using System.Windows.Shapes;
    using DanceStudio.Controller;
    using DanceStudio.Core.Cli;

    /// <summary>
    /// Represents the main window of the application.
    /// </summary>
    public partial class MainWindow : Window
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="MainWindow"/> class.
        /// </summary>
        public MainWindow()
        {
            this.InitializeComponent();
        }

        /// <summary>
        /// Handles the CanExecute event of the ViewDocumentationCommandBinding control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="CanExecuteRoutedEventArgs"/> instance containing the event data.</param>
        private void ViewDocumentationCommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        /// <summary>
        /// Handles the Executed event of the ViewOnlineDocumentationCommandBinding control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="ExecutedRoutedEventArgs"/> instance containing the event data.</param>
        private void ViewDocumentationCommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            HelpController.LaunchHelpDocumentation();
        }

        /// <summary>
        /// Handles the CanExecute event of the CloseCommandBinding control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="CanExecuteRoutedEventArgs"/> instance containing the event data.</param>
        private void CloseCommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        /// <summary>
        /// Handles the Executed event of the CloseCommandBinding control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="ExecutedRoutedEventArgs"/> instance containing the event data.</param>
        private void CloseCommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Handles the Closed event of the DanceStudioWindow control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void DanceStudioWindow_Closed(object sender, EventArgs e)
        {
            Logger.Instance.LogInfo("DanceStudio was closed.");
        }

        /// <summary>
        /// Handles the Loaded event of the DanceStudioWindow control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private void DanceStudioWindow_Loaded(object sender, RoutedEventArgs e)
        {
            // Now that the step chart editor is initialized, store the global property to it.
            App.StepChartEditor = this.MainStepChartEditor;
        }

        /// <summary>
        /// Handles the CanExecute event of the PlayStepChartEditorCommandBinding control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="CanExecuteRoutedEventArgs"/> instance containing the event data.</param>
        private void PlayStepChartEditorCommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        /// <summary>
        /// Handles the Executed event of the PlayStepChartEditorCommandBinding control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="ExecutedRoutedEventArgs"/> instance containing the event data.</param>
        private void PlayStepChartEditorCommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            AudioStream stream = new AudioStream(
                @"D:\ITG\Tools\OpenITG\Songs\Drunkers Pack 2\Number 1\Number 1 (Hypasonic Remix)ultimo.ogg");

            this.MainStepChartEditor.SetAudioStream(stream);
        }
    }
}
