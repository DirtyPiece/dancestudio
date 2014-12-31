// =======================================================================
// <copyright file="SongPackViewModel.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-29-2014</date>
// =======================================================================

namespace DanceStudio.ViewModels
{
    using System;
    using System.Collections.Generic;
    using System.Collections.ObjectModel;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows;

    /// <summary>
    /// Represents a song pack view model which is used to bind the song pack
    /// model to the UI layer.
    /// </summary>
    public class SongPackViewModel : DependencyObject
    {
        /// <summary>
        /// Represents the field for the SongList dependency property.
        /// </summary>
        public static readonly DependencyProperty SongListProperty = DependencyProperty.Register(
            "SongList",
            typeof(ObservableCollection<SongViewModel>),
            typeof(SongPackViewModel),
            new PropertyMetadata(new ObservableCollection<SongViewModel>()));

        /// <summary>
        /// Gets or sets the list of song view models that belong to this pack.
        /// </summary>
        public ObservableCollection<SongViewModel> SongList
        {
            get
            {
                return (ObservableCollection<SongViewModel>)this.GetValue(SongPackViewModel.SongListProperty);
            }

            set
            {
                this.SetValue(SongPackViewModel.SongListProperty, value);
            }
        }
    }
}
