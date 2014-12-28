// =======================================================================
// <copyright file="MainMenuTests.cs" company="Bean and Cheese Studios">
// Copyright 2015 Bean and Cheese Studios
// </copyright>
// <date>12-26-2014</date>
// =======================================================================

namespace DanceStudio.CodedUITests
{
    using Microsoft.VisualStudio.TestTools.UITesting;
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    /// <summary>
    /// Represents coded UI tests that verify the functionality of Dance Studio's main
    /// menu items and operations.
    /// </summary>
    [CodedUITest]
    public class MainMenuTests
    {
        /// <summary>
        /// The test context instance passed when running the tests.
        /// </summary>
        private TestContext testContextInstance;

        /// <summary>
        /// The private backing map field for running generated UI tests.
        /// </summary>
        private UIMap map;

        /// <summary>
        /// Initializes a new instance of the <see cref="MainMenuTests"/> class.
        /// </summary>
        public MainMenuTests()
        {
        }

        /// <summary>
        /// Gets or sets the test context which provides
        /// information about and functionality for the current test run.
        /// </summary>
        public TestContext TestContext
        {
            get
            {
                return this.testContextInstance;
            }

            set
            {
                this.testContextInstance = value;
            }
        }

        /// <summary>
        /// Gets the UI map used to run the auto-generated UI test code.
        /// </summary>
        public UIMap UIMap
        {
            get
            {
                if (this.map == null)
                {
                    this.map = new UIMap();
                }

                return this.map;
            }
        }

        /// <summary>
        /// Tests that clicking File->Exit from the main menu closes the application properly.
        /// </summary>
        [TestMethod]
        [Owner("DirtyPiece")]
        public void FileMenuExit_WhenClicked_ClosesTheApplication()
        {
            // To generate code for this test, select "Generate Code for Coded UI Test" from the shortcut menu and select one of the menu items.
            this.UIMap.FileMenuExit_WhenClicked_ClosesTheApplication();
        }
    }
}
