// =======================================================================
// <copyright file="CustomCommands.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-25-2014</date>
// =======================================================================

namespace DanceStudio.Commands
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows.Input;

    /// <summary>
    /// Represents custom commands specific to Dance Studio that can be bound to
    /// UI elements in XAML files.  When the associated UI element is interacted with,
    /// these commands fire off business logic.
    /// </summary>
    public static class CustomCommands
    {
        /// <summary>
        /// The command that launches the user's browser to view the OneNote online documentation.
        /// </summary>
        public static readonly RoutedUICommand ViewOnlineDocumentation =
            new RoutedUICommand("View Online Documentation", "ViewOnlineDocumentation", typeof(CustomCommands));
    }
}
