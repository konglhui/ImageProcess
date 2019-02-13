﻿using System;
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
    public partial class TurnOverImageForm : Form
    {
        public TurnOverImageForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.Text == "水平方向")
            {
                ParamData.paramData["mode"] = 0;
            }
            else if(comboBox1.Text == "竖直方向")
            {
                ParamData.paramData["mode"] = 1;
            }
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
