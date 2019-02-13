using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageView.SingleProcessUI.EnhanceImage
{
    public partial class BlurImage : Form
    {
        public BlurImage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ParamData.paramData["size"] = Convert.ToDouble(numericUpDown3.Value);

            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
