﻿// ------------------------------------------------------------------------------
//  <auto-generated>
//      This code was generated by coded UI test builder.
//      Version: 12.0.0.0
//
//      Changes to this file may cause incorrect behavior and will be lost if
//      the code is regenerated.
//  </auto-generated>
// ------------------------------------------------------------------------------

namespace DanceStudio.CodedUITests
{
    using System;
    using System.CodeDom.Compiler;
    using System.Collections.Generic;
    using System.Drawing;
    using System.Text.RegularExpressions;
    using System.Windows.Input;
    using Microsoft.VisualStudio.TestTools.UITest.Extension;
    using Microsoft.VisualStudio.TestTools.UITesting;
    using Microsoft.VisualStudio.TestTools.UITesting.WinControls;
    using Microsoft.VisualStudio.TestTools.UITesting.WpfControls;
    using Microsoft.VisualStudio.TestTools.UnitTesting;
    using Keyboard = Microsoft.VisualStudio.TestTools.UITesting.Keyboard;
    using Mouse = Microsoft.VisualStudio.TestTools.UITesting.Mouse;
    using MouseButtons = System.Windows.Forms.MouseButtons;
    
    
    [GeneratedCode("Coded UITest Builder", "12.0.31101.0")]
    public partial class UIMap
    {
        
        /// <summary>
        /// FileMenuExit_WhenClicked_ClosesTheApplication
        /// </summary>
        public void FileMenuExit_WhenClicked_ClosesTheApplication()
        {
            #region Variable Declarations
            WinEdit uINameEdit = this.UIDebugWindow.UIItemWindow.UIDanceStudioexeListItem.UINameEdit;
            WpfMenuItem uIExitMenuItem = this.UIDanceStudioWindow.UIMenu_1Menu.UIFileMenuItem.UIExitMenuItem;
            #endregion

            // Double-Click 'Name' text box
            Mouse.DoubleClick(uINameEdit, new Point(53, 14));

            // Click 'File' -> 'Exit' menu item
            Mouse.Click(uIExitMenuItem, new Point(33, 7));
        }
        
        #region Properties
        public UIDebugWindow UIDebugWindow
        {
            get
            {
                if ((this.mUIDebugWindow == null))
                {
                    this.mUIDebugWindow = new UIDebugWindow();
                }
                return this.mUIDebugWindow;
            }
        }
        
        public UIDanceStudioWindow UIDanceStudioWindow
        {
            get
            {
                if ((this.mUIDanceStudioWindow == null))
                {
                    this.mUIDanceStudioWindow = new UIDanceStudioWindow();
                }
                return this.mUIDanceStudioWindow;
            }
        }
        #endregion
        
        #region Fields
        private UIDebugWindow mUIDebugWindow;
        
        private UIDanceStudioWindow mUIDanceStudioWindow;
        #endregion
    }
    
    [GeneratedCode("Coded UITest Builder", "12.0.31101.0")]
    public class UIDebugWindow : WinWindow
    {
        
        public UIDebugWindow()
        {
            #region Search Criteria
            this.SearchProperties[WinWindow.PropertyNames.Name] = "Debug";
            this.SearchProperties[WinWindow.PropertyNames.ClassName] = "CabinetWClass";
            this.WindowTitles.Add("Debug");
            #endregion
        }
        
        #region Properties
        public UIItemWindow UIItemWindow
        {
            get
            {
                if ((this.mUIItemWindow == null))
                {
                    this.mUIItemWindow = new UIItemWindow(this);
                }
                return this.mUIItemWindow;
            }
        }
        #endregion
        
        #region Fields
        private UIItemWindow mUIItemWindow;
        #endregion
    }
    
    [GeneratedCode("Coded UITest Builder", "12.0.31101.0")]
    public class UIItemWindow : WinWindow
    {
        
        public UIItemWindow(UITestControl searchLimitContainer) : 
                base(searchLimitContainer)
        {
            #region Search Criteria
            this.SearchProperties[WinWindow.PropertyNames.AccessibleName] = "Items View";
            this.SearchProperties[WinWindow.PropertyNames.ClassName] = "DirectUIHWND";
            this.WindowTitles.Add("Debug");
            #endregion
        }
        
        #region Properties
        public UIDanceStudioexeListItem UIDanceStudioexeListItem
        {
            get
            {
                if ((this.mUIDanceStudioexeListItem == null))
                {
                    this.mUIDanceStudioexeListItem = new UIDanceStudioexeListItem(this);
                }
                return this.mUIDanceStudioexeListItem;
            }
        }
        #endregion
        
        #region Fields
        private UIDanceStudioexeListItem mUIDanceStudioexeListItem;
        #endregion
    }
    
    [GeneratedCode("Coded UITest Builder", "12.0.31101.0")]
    public class UIDanceStudioexeListItem : WinListItem
    {
        
        public UIDanceStudioexeListItem(UITestControl searchLimitContainer) : 
                base(searchLimitContainer)
        {
            #region Search Criteria
            this.SearchProperties[WinListItem.PropertyNames.Name] = "DanceStudio.exe";
            this.WindowTitles.Add("Debug");
            #endregion
        }
        
        #region Properties
        public WinEdit UINameEdit
        {
            get
            {
                if ((this.mUINameEdit == null))
                {
                    this.mUINameEdit = new WinEdit(this);
                    #region Search Criteria
                    this.mUINameEdit.SearchProperties[WinEdit.PropertyNames.Name] = "Name";
                    this.mUINameEdit.WindowTitles.Add("Debug");
                    #endregion
                }
                return this.mUINameEdit;
            }
        }
        #endregion
        
        #region Fields
        private WinEdit mUINameEdit;
        #endregion
    }
    
    [GeneratedCode("Coded UITest Builder", "12.0.31101.0")]
    public class UIDanceStudioWindow : WpfWindow
    {
        
        public UIDanceStudioWindow()
        {
            #region Search Criteria
            this.SearchProperties[WpfWindow.PropertyNames.Name] = "Dance Studio";
            this.SearchProperties.Add(new PropertyExpression(WpfWindow.PropertyNames.ClassName, "HwndWrapper", PropertyExpressionOperator.Contains));
            this.WindowTitles.Add("Dance Studio");
            #endregion
        }
        
        #region Properties
        public UIMenu_1Menu UIMenu_1Menu
        {
            get
            {
                if ((this.mUIMenu_1Menu == null))
                {
                    this.mUIMenu_1Menu = new UIMenu_1Menu(this);
                }
                return this.mUIMenu_1Menu;
            }
        }
        #endregion
        
        #region Fields
        private UIMenu_1Menu mUIMenu_1Menu;
        #endregion
    }
    
    [GeneratedCode("Coded UITest Builder", "12.0.31101.0")]
    public class UIMenu_1Menu : WpfMenu
    {
        
        public UIMenu_1Menu(UITestControl searchLimitContainer) : 
                base(searchLimitContainer)
        {
            #region Search Criteria
            this.SearchProperties[WpfMenu.PropertyNames.AutomationId] = "Menu_1";
            this.WindowTitles.Add("Dance Studio");
            #endregion
        }
        
        #region Properties
        public UIFileMenuItem UIFileMenuItem
        {
            get
            {
                if ((this.mUIFileMenuItem == null))
                {
                    this.mUIFileMenuItem = new UIFileMenuItem(this);
                }
                return this.mUIFileMenuItem;
            }
        }
        #endregion
        
        #region Fields
        private UIFileMenuItem mUIFileMenuItem;
        #endregion
    }
    
    [GeneratedCode("Coded UITest Builder", "12.0.31101.0")]
    public class UIFileMenuItem : WpfMenuItem
    {
        
        public UIFileMenuItem(UITestControl searchLimitContainer) : 
                base(searchLimitContainer)
        {
            #region Search Criteria
            this.SearchProperties[WpfMenuItem.PropertyNames.AutomationId] = "MenuItem_1";
            this.WindowTitles.Add("Dance Studio");
            #endregion
        }
        
        #region Properties
        public WpfMenuItem UIExitMenuItem
        {
            get
            {
                if ((this.mUIExitMenuItem == null))
                {
                    this.mUIExitMenuItem = new WpfMenuItem(this);
                    #region Search Criteria
                    this.mUIExitMenuItem.SearchProperties[WpfMenuItem.PropertyNames.AutomationId] = "MenuItem_2";
                    this.mUIExitMenuItem.SearchConfigurations.Add(SearchConfiguration.ExpandWhileSearching);
                    this.mUIExitMenuItem.WindowTitles.Add("Dance Studio");
                    #endregion
                }
                return this.mUIExitMenuItem;
            }
        }
        #endregion
        
        #region Fields
        private WpfMenuItem mUIExitMenuItem;
        #endregion
    }
}
