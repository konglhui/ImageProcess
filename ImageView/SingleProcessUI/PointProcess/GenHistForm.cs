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
    public partial class GenHistForm : Form
    {
        public GenHistForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ParamData.paramData["n"] = Convert.ToDouble(numericUpDown1.Value);
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
