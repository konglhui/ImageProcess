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
    public partial class GenLineTransForm : Form
    {
        public GenLineTransForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ParamData.paramData["d_fa"] = Convert.ToDouble(numericUpDown1.Value);
            ParamData.paramData["d_fb"] = Convert.ToDouble(numericUpDown2.Value);
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
