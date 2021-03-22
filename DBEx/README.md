
#### 03/22
SQL언어에 대한 문법적인 내용을 배웠고 C#환경에서 Grid를 이용하는 법을 다룸

```
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsDBManager
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnInput_Click(object sender, EventArgs e)
        {
            string str = tbInput.Text; 
            
            dbGrid.Columns.Add(str, str);
            dbGrid.Rows.Add( );
        }

        private void btnValue_Click(object sender, EventArgs e)
        {
            string str = tbValue.Text;
            dbGrid.Rows[1].Cells[2].Value = str;
        }

    }
}

```
