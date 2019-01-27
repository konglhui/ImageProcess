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
    public partial class RotateImageForm : Form
    {
        public RotateImageForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ParamData.paramData["angle"] = Convert.ToDouble(numericUpDown1.Value);
            ParamData.paramData["pointx"] = Convert.ToDouble(numericUpDown1.Value);
            ParamData.paramData["pointy"] = Convert.ToDouble(numericUpDown1.Value);
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
    }
}
