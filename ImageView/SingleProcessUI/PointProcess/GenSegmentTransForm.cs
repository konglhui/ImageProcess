using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageView.SingleProcessUI
{
    public partial class GenSegmentTransForm : Form
    {
        public GenSegmentTransForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ParamData.paramData["x1"] = Convert.ToDouble(numericUpDown1.Value);
            ParamData.paramData["y1"] = Convert.ToDouble(numericUpDown2.Value);
            ParamData.paramData["x2"] = Convert.ToDouble(numericUpDown3.Value);
            ParamData.paramData["y2"] = Convert.ToDouble(numericUpDown4.Value);
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
