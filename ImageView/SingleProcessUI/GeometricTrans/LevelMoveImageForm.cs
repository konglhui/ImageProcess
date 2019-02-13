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
    public partial class LevelMoveImageForm : Form
    {
        public LevelMoveImageForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ParamData.paramData["x"] = Convert.ToDouble(numericUpDown1.Value);
            ParamData.paramData["y"] = Convert.ToDouble(numericUpDown2.Value);
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
