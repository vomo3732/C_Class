using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBManager
{
    public partial class Form2 : Form
    {
        public string NewColumn;
        string STITLE;
        public Form2(string sTitle="column name")
        {
            //tbColumn.Text = sTitle;
            STITLE = sTitle;
            InitializeComponent();
        }
        
        private void tbColumn_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                this.DialogResult = DialogResult.OK;
                NewColumn = tbColumn.Text;
                Close();
            }
            else if (e.KeyCode == Keys.Escape)
            {
                this.DialogResult = DialogResult.Cancel;
                Close();
            }
            //Close();
        }
    }
}
