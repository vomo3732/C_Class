using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsGraph
{

    
    public partial class Thick : Form
    {
        public string Circlethick;
        public string Circlerow;
        public string Circlecol;
        public Thick()
        {
            InitializeComponent();
        }

        private void thickButton_Click(object sender, EventArgs e)
        {
            Circlethick = tbThick.Text;
            Circlerow = tbRow.Text;
            Circlecol = tbCol.Text;
        }
    }
}
