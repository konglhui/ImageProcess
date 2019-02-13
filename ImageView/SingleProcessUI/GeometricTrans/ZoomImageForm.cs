using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageView.SingleProcessUI.GeometricTrans
{
    public partial class ZoomImageForm : Form
    {
        public ZoomImageForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ParamData.paramData["ratio"] = Convert.ToDouble(numericUpDown3.Value);
            if (comboBox1.Text == "双线性插值")
            {
                ParamData.paramData["mode"] = 0;
            }
            else
            {
                ParamData.paramData["mode"] = 1;
            }
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
