using System.Reflection;
namespace ImageView
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.开始ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.读取图像ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.保存图像ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.图像列表ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.位转8位ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.位转24位ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.图像点运算ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.灰度直方图ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.线性变换ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.gamm变换ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.log变换ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.二值化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.分段线性变换ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.直方图均衡化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.图像几何变换ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.平移ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.翻转ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.转置ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.缩放ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.旋转ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.仿射ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.透视ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.listView1 = new System.Windows.Forms.ListView();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.RunTimLabel = new System.Windows.Forms.Label();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.图像增强ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.均值滤波ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.开始ToolStripMenuItem,
            this.图像点运算ToolStripMenuItem,
            this.图像几何变换ToolStripMenuItem,
            this.图像增强ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 25);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 开始ToolStripMenuItem
            // 
            this.开始ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.读取图像ToolStripMenuItem,
            this.保存图像ToolStripMenuItem,
            this.图像列表ToolStripMenuItem,
            this.位转8位ToolStripMenuItem,
            this.位转24位ToolStripMenuItem});
            this.开始ToolStripMenuItem.Name = "开始ToolStripMenuItem";
            this.开始ToolStripMenuItem.Size = new System.Drawing.Size(44, 21);
            this.开始ToolStripMenuItem.Text = "开始";
            // 
            // 读取图像ToolStripMenuItem
            // 
            this.读取图像ToolStripMenuItem.Name = "读取图像ToolStripMenuItem";
            this.读取图像ToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.读取图像ToolStripMenuItem.Text = "读取图像";
            this.读取图像ToolStripMenuItem.Click += new System.EventHandler(this.ReadImge_Click);
            // 
            // 保存图像ToolStripMenuItem
            // 
            this.保存图像ToolStripMenuItem.Name = "保存图像ToolStripMenuItem";
            this.保存图像ToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.保存图像ToolStripMenuItem.Text = "保存图像";
            this.保存图像ToolStripMenuItem.Click += new System.EventHandler(this.SaveImage_Click);
            // 
            // 图像列表ToolStripMenuItem
            // 
            this.图像列表ToolStripMenuItem.Name = "图像列表ToolStripMenuItem";
            this.图像列表ToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.图像列表ToolStripMenuItem.Text = "图像列表";
            this.图像列表ToolStripMenuItem.Click += new System.EventHandler(this.ImageList_Click);
            // 
            // 位转8位ToolStripMenuItem
            // 
            this.位转8位ToolStripMenuItem.Name = "位转8位ToolStripMenuItem";
            this.位转8位ToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.位转8位ToolStripMenuItem.Text = "24位转8位";
            this.位转8位ToolStripMenuItem.Click += new System.EventHandler(this.Image24To8_Click);
            // 
            // 位转24位ToolStripMenuItem
            // 
            this.位转24位ToolStripMenuItem.Name = "位转24位ToolStripMenuItem";
            this.位转24位ToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.位转24位ToolStripMenuItem.Text = "8位转24位";
            this.位转24位ToolStripMenuItem.Click += new System.EventHandler(this.Image8To24_Click);
            // 
            // 图像点运算ToolStripMenuItem
            // 
            this.图像点运算ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.灰度直方图ToolStripMenuItem,
            this.线性变换ToolStripMenuItem,
            this.gamm变换ToolStripMenuItem,
            this.log变换ToolStripMenuItem,
            this.二值化ToolStripMenuItem,
            this.分段线性变换ToolStripMenuItem,
            this.直方图均衡化ToolStripMenuItem});
            this.图像点运算ToolStripMenuItem.Name = "图像点运算ToolStripMenuItem";
            this.图像点运算ToolStripMenuItem.Size = new System.Drawing.Size(56, 21);
            this.图像点运算ToolStripMenuItem.Text = "点运算";
            // 
            // 灰度直方图ToolStripMenuItem
            // 
            this.灰度直方图ToolStripMenuItem.Name = "灰度直方图ToolStripMenuItem";
            this.灰度直方图ToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.灰度直方图ToolStripMenuItem.Text = "灰度直方图";
            this.灰度直方图ToolStripMenuItem.Click += new System.EventHandler(this.GenHistImage_Click);
            // 
            // 线性变换ToolStripMenuItem
            // 
            this.线性变换ToolStripMenuItem.Name = "线性变换ToolStripMenuItem";
            this.线性变换ToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.线性变换ToolStripMenuItem.Text = "线性变换";
            this.线性变换ToolStripMenuItem.Click += new System.EventHandler(this.LineTrans_Click);
            // 
            // gamm变换ToolStripMenuItem
            // 
            this.gamm变换ToolStripMenuItem.Name = "gamm变换ToolStripMenuItem";
            this.gamm变换ToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.gamm变换ToolStripMenuItem.Text = "gamm变换";
            this.gamm变换ToolStripMenuItem.Click += new System.EventHandler(this.GammTrans_Click);
            // 
            // log变换ToolStripMenuItem
            // 
            this.log变换ToolStripMenuItem.Name = "log变换ToolStripMenuItem";
            this.log变换ToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.log变换ToolStripMenuItem.Text = "log变换";
            this.log变换ToolStripMenuItem.Click += new System.EventHandler(this.LogTrans_Click);
            // 
            // 二值化ToolStripMenuItem
            // 
            this.二值化ToolStripMenuItem.Name = "二值化ToolStripMenuItem";
            this.二值化ToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.二值化ToolStripMenuItem.Text = "二值化";
            this.二值化ToolStripMenuItem.Click += new System.EventHandler(this.Threshold_Click);
            // 
            // 分段线性变换ToolStripMenuItem
            // 
            this.分段线性变换ToolStripMenuItem.Name = "分段线性变换ToolStripMenuItem";
            this.分段线性变换ToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.分段线性变换ToolStripMenuItem.Text = "分段线性变换";
            this.分段线性变换ToolStripMenuItem.Click += new System.EventHandler(this.SegmentTrans_Click);
            // 
            // 直方图均衡化ToolStripMenuItem
            // 
            this.直方图均衡化ToolStripMenuItem.Name = "直方图均衡化ToolStripMenuItem";
            this.直方图均衡化ToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.直方图均衡化ToolStripMenuItem.Text = "直方图均衡化";
            this.直方图均衡化ToolStripMenuItem.Click += new System.EventHandler(this.HistEqual_Click);
            // 
            // 图像几何变换ToolStripMenuItem
            // 
            this.图像几何变换ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.平移ToolStripMenuItem,
            this.翻转ToolStripMenuItem,
            this.转置ToolStripMenuItem,
            this.缩放ToolStripMenuItem,
            this.旋转ToolStripMenuItem,
            this.仿射ToolStripMenuItem,
            this.透视ToolStripMenuItem});
            this.图像几何变换ToolStripMenuItem.Name = "图像几何变换ToolStripMenuItem";
            this.图像几何变换ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.图像几何变换ToolStripMenuItem.Text = "几何变换";
            // 
            // 平移ToolStripMenuItem
            // 
            this.平移ToolStripMenuItem.Name = "平移ToolStripMenuItem";
            this.平移ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.平移ToolStripMenuItem.Text = "平移";
            this.平移ToolStripMenuItem.Click += new System.EventHandler(this.LevelMove_CLick);
            // 
            // 翻转ToolStripMenuItem
            // 
            this.翻转ToolStripMenuItem.Name = "翻转ToolStripMenuItem";
            this.翻转ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.翻转ToolStripMenuItem.Text = "翻转";
            this.翻转ToolStripMenuItem.Click += new System.EventHandler(this.TurnOver_Click);
            // 
            // 转置ToolStripMenuItem
            // 
            this.转置ToolStripMenuItem.Name = "转置ToolStripMenuItem";
            this.转置ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.转置ToolStripMenuItem.Text = "转置";
            this.转置ToolStripMenuItem.Click += new System.EventHandler(this.TransPosition_Click);
            // 
            // 缩放ToolStripMenuItem
            // 
            this.缩放ToolStripMenuItem.Name = "缩放ToolStripMenuItem";
            this.缩放ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.缩放ToolStripMenuItem.Text = "缩放";
            this.缩放ToolStripMenuItem.Click += new System.EventHandler(this.ZoomImage_Click);
            // 
            // 旋转ToolStripMenuItem
            // 
            this.旋转ToolStripMenuItem.Name = "旋转ToolStripMenuItem";
            this.旋转ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.旋转ToolStripMenuItem.Text = "旋转";
            this.旋转ToolStripMenuItem.Click += new System.EventHandler(this.Rotate_Click);
            // 
            // 仿射ToolStripMenuItem
            // 
            this.仿射ToolStripMenuItem.Name = "仿射ToolStripMenuItem";
            this.仿射ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.仿射ToolStripMenuItem.Text = "仿射";
            // 
            // 透视ToolStripMenuItem
            // 
            this.透视ToolStripMenuItem.Name = "透视ToolStripMenuItem";
            this.透视ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.透视ToolStripMenuItem.Text = "透视";
            // 
            // listView1
            // 
            this.listView1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.listView1.Location = new System.Drawing.Point(3, 0);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(82, 470);
            this.listView1.TabIndex = 1;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.DoubleClick += new System.EventHandler(this.ShowImageLit_DoubleClick);
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Location = new System.Drawing.Point(6, 28);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(703, 467);
            this.panel1.TabIndex = 2;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            this.panel1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseUp);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.pictureBox1.Location = new System.Drawing.Point(-6, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(700, 452);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDown);
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
            this.pictureBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseUp);
            this.pictureBox1.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseWheel);
            // 
            // panel2
            // 
            this.panel2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel2.Controls.Add(this.listView1);
            this.panel2.Location = new System.Drawing.Point(712, 25);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(88, 473);
            this.panel2.TabIndex = 3;
            // 
            // imageList1
            // 
            this.imageList1.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.imageList1.ImageSize = new System.Drawing.Size(16, 16);
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // RunTimLabel
            // 
            this.RunTimLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.RunTimLabel.AutoSize = true;
            this.RunTimLabel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.RunTimLabel.Location = new System.Drawing.Point(597, 15);
            this.RunTimLabel.Name = "RunTimLabel";
            this.RunTimLabel.Size = new System.Drawing.Size(53, 12);
            this.RunTimLabel.TabIndex = 5;
            this.RunTimLabel.Text = "运行时间";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.RunTimLabel);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.groupBox1.Location = new System.Drawing.Point(0, 486);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(800, 30);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "label1";
            // 
            // 图像增强ToolStripMenuItem
            // 
            this.图像增强ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.均值滤波ToolStripMenuItem});
            this.图像增强ToolStripMenuItem.Name = "图像增强ToolStripMenuItem";
            this.图像增强ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.图像增强ToolStripMenuItem.Text = "图像增强";
            // 
            // 均值滤波ToolStripMenuItem
            // 
            this.均值滤波ToolStripMenuItem.Name = "均值滤波ToolStripMenuItem";
            this.均值滤波ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.均值滤波ToolStripMenuItem.Text = "均值滤波";
            this.均值滤波ToolStripMenuItem.Click += new System.EventHandler(this.BlurImage_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 516);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel2.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 开始ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 读取图像ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 保存图像ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图像列表ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 位转8位ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 位转24位ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图像点运算ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 灰度直方图ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 线性变换ToolStripMenuItem;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.Label RunTimLabel;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ToolStripMenuItem gamm变换ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem log变换ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 二值化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 分段线性变换ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 直方图均衡化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图像几何变换ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 平移ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 翻转ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 转置ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 缩放ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 旋转ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 仿射ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 透视ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图像增强ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 均值滤波ToolStripMenuItem;
    }
}

