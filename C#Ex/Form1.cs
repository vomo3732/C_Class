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
    public partial class Form1 : Form
    {
        Graphics GDC;

        public Form1()
        {
            InitializeComponent();
            GDC = CanvasDraw.CreateGraphics();
        }

        private void mnuDraw_Click(object sender, EventArgs e)
        {

        }
        private void CanvasDraw_Paint(object sender, PaintEventArgs e)
        {
            //Pen pp=new Pen(Color.Red, 10);
            //e.Graphics.DrawEllipse(pp, 100, 100, 200, 200);
        }
        int thick = 3;
        int row = 10;
        int col = 20;
        private void CanvasDraw_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                Pen pp=new Pen(Color.Black, thick);
                GDC.DrawEllipse(pp, e.X, e.Y, row, col);
            }
        }

        private void CanvasDraw_Resize(object sender, EventArgs e)
        {
            GDC = CanvasDraw.CreateGraphics();
        }

        private void mnuErase_Click(object sender, EventArgs e)
        {
            GDC.Clear(DefaultBackColor);
        }

        private void mnuThick_Click(object sender, EventArgs e)
        {
            Thick dlg = new Thick();
            DialogResult ret = dlg.ShowDialog();
            if (ret == DialogResult.OK)
            {
                string circlethickness = dlg.Circlethick;
                string circlewidth = dlg.Circlerow;
                string circlehigh = dlg.Circlecol;
                thick = int.Parse(circlethickness);
                row = int.Parse(circlewidth);
                col = int.Parse(circlehigh);
            }
        }
    }
}
