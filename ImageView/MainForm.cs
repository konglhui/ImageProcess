using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Reflection;
using ImageView.SingleProcessUI;
using System.Drawing.Imaging;
using System.Diagnostics;
using ImageView.SingleProcessUI.GeometricTrans;
namespace ImageView
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            pathName = "example.bmp";
            winImage = (Bitmap)Image.FromFile(pathName);
            if (winImage != null)
                ShowImage(winImage);
            else
                MessageBox.Show("没有图像");
        }
        //存储所有处理过的图像
        MyLinkedList imageList = new MyLinkedList();
        //输入文件的路径
        private string pathName = string.Empty;

        //单通道
        private PixelFormat singlePixel = PixelFormat.Format8bppIndexed;

        //展示图像
        private Bitmap winImage;

        //函数运行时间的
        string runTime = "aa";//string.Empty;
        
        //三个鼠标移动的参数
        private Point mouseDownPoint;
        private bool isMove = false;

        #region C#操作
        /// <summary>
        /// 显示图像
        /// </summary>
        /// <param name="Image"></param>
        public void ShowImage(Bitmap image)
        {
            winImage = image;
            this.imageList1.Images.Add(image);
            this.imageList.Add(image);
            InitImageSize();
            InitImageSite();
            this.pictureBox1.Image = image;
            //this.pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
            this.RunTimLabel.Text = runTime;
        }

        /// <summary>
        /// 读取图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ReadImge_Click(object sender, EventArgs e)
        {
            imageList1.Dispose();
            imageList.ClearImage();
            OpenFileDialog opndlg = new OpenFileDialog();

            opndlg.Filter = "所有文件|*.bmp;*.pcx;*.png;*.jpg;*.gif;" +

            "*.tif;*.ico;*.dcx;*.cgm;*.cdr;*.wmf;*.eps;*.emf;|" +

            "位图(*.bmp;*.jpg;*.png;...)|*.bmp;*.pcx;*.png;*.jpg;*.gif;*.tif;*.ico|" +

            "矢量图(*.wmf;*.eps;*.emf;...)|*.dcf;*.cgm;*.cdr;*.wmf;*.eps;*.emf";

            opndlg.Title = "打开图形文件";

            opndlg.ShowHelp = true;

            if (opndlg.ShowDialog() == DialogResult.OK)

            {
                pathName = opndlg.FileName;
                try
                {

                    Bitmap image = (Bitmap)Image.FromFile(pathName);
                    //byte[] sourcce = ImageTranslation.GetBGRValues(show_image, out strdie);
                    int channel = Image.GetPixelFormatSize(image.PixelFormat) / 8;
                    if (channel != 1 && channel != 3)
                    {
                        MessageBox.Show("不是8位或者是24位结构");
                        return;
                    }
                    ShowImage(image);
                    this.label1.Text = pathName;
                }
                catch (Exception exp)
                {
                    MessageBox.Show(exp.Message);
                }

            }
        }

        /// <summary>
        /// 保存图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void SaveImage_Click(object sender, EventArgs e)
        {
            if (winImage == null)
                return;

            SaveFileDialog saveDlg = new SaveFileDialog();

            saveDlg.Title = "保存为";

            saveDlg.OverwritePrompt = true;

            saveDlg.Filter = "BMP文件(*.bmp)|*.bmp|" + "Gif文件(*.gif)|*.gif|" +

            "JPEG文件(*.jpg)|*.jpg|" + "PNG文件(*.png)|*.png";

            saveDlg.ShowHelp = true;

            if (saveDlg.ShowDialog() == DialogResult.OK)
            {
                string fileName = saveDlg.FileName;
                string strFilExtn = fileName.Remove(0, fileName.Length - 3);
                switch (strFilExtn)
                {
                    case "bmp":
                        winImage.Save(fileName, System.Drawing.Imaging.ImageFormat.Bmp);
                        break;
                    case "jpg":
                        winImage.Save(fileName, System.Drawing.Imaging.ImageFormat.Jpeg);
                        break;
                    case "gif":
                        winImage.Save(fileName, System.Drawing.Imaging.ImageFormat.Gif);
                        break;
                    case "tif":
                        winImage.Save(fileName, System.Drawing.Imaging.ImageFormat.Tiff);
                        break;
                    case "png":
                        winImage.Save(fileName, System.Drawing.Imaging.ImageFormat.Png);
                        break;
                    default:
                        break;
                }
                //设定文件格式，Ctrl+E,D
            }
        }

        /// <summary>
        /// 24位转8位图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Image24To8_Click(object sender, EventArgs e)
        {
            Bitmap image;
            int channel = Image.GetPixelFormatSize(winImage.PixelFormat) / 8;
            if (channel != 3)
            {
                MessageBox.Show("不是24位图像");
                return;
            }
            image = ImageProcessCSharp.transForm24to8(winImage);
            ShowImage(image);
        }

        /// <summary>
        /// 8位转24位图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Image8To24_Click(object sender, EventArgs e)
        {
            Bitmap image;
            int channel = Image.GetPixelFormatSize(winImage.PixelFormat) / 8;
            if (channel != 1)
            {
                MessageBox.Show("不是8位图像");
                return;
            }
            image = ImageProcessCSharp.transForm8to24(winImage);
            ShowImage(image);
        }

        /// <summary>
        /// 获取图像列表
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ImageList_Click(object sender, EventArgs e)
        {
            try
            {
                ShowImageList();
            }
            catch (Exception msg)
            {
                throw msg;

            }
        }

        /// <summary>
        /// 显示pictureList中的小图像，进行索引
        /// </summary>
        private void ShowImageList()
        {
            //显示文件列表
            this.listView1.Items.Clear();
            this.listView1.LargeImageList = this.imageList1;
            this.listView1.View = View.LargeIcon;        //大图标显示
            //开始绑定
            this.listView1.BeginUpdate();
            //增加图片至ListView控件中
            for (int i = 0; i < imageList1.Images.Count; i++)
            {
                ListViewItem lvi = new ListViewItem();
                lvi.ImageIndex = i;
                lvi.Text = "pic" + i;
                this.listView1.Items.Add(lvi);
            }
            this.listView1.EndUpdate();
        }

        /// <summary>
        /// 双击显示图像列表的图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ShowImageLit_DoubleClick(object sender, EventArgs e)
        {
            if (this.listView1.SelectedItems.Count == 0)
                return;
            int index = this.listView1.SelectedItems[0].Index;
            winImage = imageList.getItem(index);
            this.pictureBox1.Image = winImage;
            //this.pictureBox1.Size = winImage.Size;
            this.pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
        }

        /// <summary>
        /// 判断通道数
        /// </summary>
        private bool JudegeImagePixelFormat()
        {
            if (winImage == null)
            {
                MessageBox.Show("请先加载图像");
                return true;
            }

            if (winImage.PixelFormat == PixelFormat.Format8bppIndexed)
            {
                return false;
            }
            else
            {
                MessageBox.Show("只支持单通道图像");
                return true;
            }
        }

        /// <summary>
        /// 参数错误
        /// </summary>
        private void ParamFalse()
        {
            MessageBox.Show("参数错误");
        }
        #endregion

        #region 图像缩放和移动方式
        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                mouseDownPoint.X = Cursor.Position.X; //记录鼠标左键按下时位置
                mouseDownPoint.Y = Cursor.Position.Y;
                isMove = true;
                pictureBox1.Focus(); //鼠标滚轮事件(缩放时)需要picturebox有焦点
            }
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                isMove = false;
            }
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            pictureBox1.Focus(); //鼠标在picturebox上时才有焦点，此时可以缩放
            if (isMove)
            {
                int x, y;   //新的pictureBox1.Location(x,y)
                int moveX, moveY; //X方向，Y方向移动大小。
                moveX = Cursor.Position.X - mouseDownPoint.X;
                moveY = Cursor.Position.Y - mouseDownPoint.Y;
                x = pictureBox1.Location.X + moveX;
                y = pictureBox1.Location.Y + moveY;
                pictureBox1.Location = new Point(x, y);
                mouseDownPoint.X = Cursor.Position.X;
                mouseDownPoint.Y = Cursor.Position.Y;
            }
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                mouseDownPoint.X = Cursor.Position.X; //记录鼠标左键按下时位置
                mouseDownPoint.Y = Cursor.Position.Y;
                isMove = true;
            }
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                isMove = false;
            }
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            panel2.Focus(); //鼠标不在picturebox上时焦点给别的控件，此时无法缩放   
            if (isMove)
            {
                int x, y;   //新的pictureBox1.Location(x,y)
                int moveX, moveY; //X方向，Y方向移动大小。
                moveX = Cursor.Position.X - mouseDownPoint.X;
                moveY = Cursor.Position.Y - mouseDownPoint.Y;
                x = pictureBox1.Location.X + moveX;
                y = pictureBox1.Location.Y + moveY;
                pictureBox1.Location = new Point(x, y);
                mouseDownPoint.X = Cursor.Position.X;
                mouseDownPoint.Y = Cursor.Position.Y;
            }
        }

        private void pictureBox1_MouseWheel(object sender, MouseEventArgs e)
        {
            int x = e.Location.X;
            int y = e.Location.Y;
            int ow = pictureBox1.Width;
            int oh = pictureBox1.Height;
            int VX, VY;  //因缩放产生的位移矢量
            int widthZoom = ow / 8; 
            int heightZoom = oh / 8;
            if (e.Delta > 0) //放大
            {
                //第①步
                if (pictureBox1.Width > winImage.Width *4)
                    return;
                pictureBox1.Width += widthZoom;
                pictureBox1.Height += heightZoom;
                ////第②步
                //PropertyInfo pInfo = pictureBox1.GetType().GetProperty("ImageRectangle", BindingFlags.Instance |
                // BindingFlags.NonPublic);
                //Rectangle rect = (Rectangle)pInfo.GetValue(pictureBox1, null);
                ////第③步
                //pictureBox1.Width = rect.Width;
                //pictureBox1.Height = rect.Height;
            }
            if (e.Delta < 0) //缩小
            {
                //防止一直缩成负值
                //if (pictureBox1.Width < winImage.Width / 10)
                //    return;
                if (ow < 20 || oh < 20)
                    return;
                pictureBox1.Width -= widthZoom;
                pictureBox1.Height -= heightZoom;
                //PropertyInfo pInfo = pictureBox1.GetType().GetProperty("ImageRectangle", BindingFlags.Instance |
                // BindingFlags.NonPublic);
                //Rectangle rect = (Rectangle)pInfo.GetValue(pictureBox1, null);
                //pictureBox1.Width = rect.Width;
                //pictureBox1.Height = rect.Height;
            }
            //第④步，求因缩放产生的位移，进行补偿，实现锚点缩放的效果
            VX = (int) ((double) x * (ow - pictureBox1.Width) / ow);
            VY = (int) ((double) y * (oh - pictureBox1.Height) / oh);
            pictureBox1.Location= new Point(pictureBox1.Location.X + VX, pictureBox1.Location.Y + VY);
        }

        private void InitImageSize()
        {
            int width = this.panel1.Width - 20;
            int height = this.panel1.Height - 20;
            float srcWidth = winImage.Width;
            float srcHeight = winImage.Height;

            //如果图片很小
            if (width > srcWidth && height > srcHeight)
            {
                pictureBox1.Size = winImage.Size;
                return;
            }

            float zoomWidth = width / srcWidth;
            float zoomHeight = height / srcHeight;

            //宽大于高
            if (zoomWidth > zoomHeight)
            {
                width = (int)(srcWidth * zoomHeight);
            }
            else
            {
                height = (int)(srcHeight * zoomWidth);
            }
            pictureBox1.Size = new Size(width, height);
        }

        private void InitImageSite()
        {
            int width = this.panel1.Width;
            int height = this.panel1.Height;
            int srcWidth = this.pictureBox1.Width;
            int srcHeight = this.pictureBox1.Height;

            int left = (Width - srcWidth) / 2;
            int top = (height - srcHeight) / 2;
            //int right = (left + srcWidth) / 2;
            //int bottom = (top + srcHeight) / 2;

            this.pictureBox1.Top = top;
            this.pictureBox1.Left = left;
        }

        #endregion

        #region 点运算



        /// <summary>
        /// 直方图按键
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void GenHistImage_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;

            GenHistForm paramForm = new GenHistForm();
            if (paramForm.ShowDialog() == DialogResult.OK)
            {
                int n = Convert.ToInt32(ParamData.paramData["n"]);
                Bitmap histImage = new Bitmap(n, 200, singlePixel);
                ParamData.paramData.Clear();
                if (GenHistImage(ref histImage, n))
                {

                    ShowImage(histImage);
                }
                else
                    ParamFalse();
            }
        }

        /// <summary>
        /// 生成直方图
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        private bool GenHistImage(ref Bitmap histImage,int n)
        {
            BitmapData srcData = winImage.LockBits(new Rectangle(0, 0, winImage.Width, winImage.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr srcPtr = srcData.Scan0;

            BitmapData histData = histImage.LockBits(new Rectangle(0, 0, histImage.Width, histImage.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr histPtr = histData.Scan0;
            Stopwatch watch = new Stopwatch();
            watch.Start();
            int flag = DllInterFace.GenhistInterface(srcPtr, winImage.Width, winImage.Height, 1, histPtr, histImage.Width, histImage.Height, 1, n);
            watch.Stop();
            runTime = watch.ElapsedMilliseconds.ToString();
            winImage.UnlockBits(srcData);
            histImage.UnlockBits(histData);
            if (flag == 1)
            {
                return true;
            }
            return false;
        }

        /// <summary>
        /// 线性变换按键
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void LineTrans_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;

            GenLineTransForm genLineTransForm = new GenLineTransForm();
            if(genLineTransForm.ShowDialog() == DialogResult.OK)
            {
                double d_fa = ParamData.paramData["d_fa"];
                int d_fb = Convert.ToInt32(ParamData.paramData["d_fb"]);
                Bitmap bitmap = (Bitmap)winImage.Clone();

                if (LineTrans(ref bitmap, d_fa, d_fb))
                {
                    ShowImage(bitmap);
                }
                else
                    ParamFalse();
            }
        }

        /// <summary>
        /// 生成图像
        /// </summary>
        /// <param name="bitmap"></param>
        /// <param name="d_fa"></param>
        /// <param name="d_fb"></param>
        /// <returns></returns>
        private bool LineTrans(ref Bitmap bitmap,double d_fa,int d_fb)
        {
            BitmapData bitmapData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr bitmapPtr = bitmapData.Scan0;

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            int flag = DllInterFace.GenLineTransInterFalce(bitmapPtr, bitmap.Width, bitmap.Height, 1, d_fa, d_fb);

            stopwatch.Stop();
            runTime = stopwatch.ElapsedMilliseconds.ToString();

            bitmap.UnlockBits(bitmapData);

            if (flag == 1)
                return true;
            return false;
        }

        /// <summary>
        /// gamm变换按键
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void GammTrans_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;

            GenGammTransForm genGammTransForm = new GenGammTransForm();
            if (genGammTransForm.ShowDialog() == DialogResult.OK)
            {
                double gamm = ParamData.paramData["gamm"];
                double comp =  ParamData.paramData["comp"];
                Bitmap bitmap = (Bitmap)winImage.Clone();

                if (GammTrans(ref bitmap, gamm, comp))
                {
                    ShowImage(bitmap);
                }
                else
                    ParamFalse();
            }
        }

        /// <summary>
        /// gamm变换
        /// </summary>
        /// <param name="bitmap"></param>
        /// <param name="gamma"></param>
        /// <param name="comp"></param>
        /// <returns></returns>
        private bool GammTrans(ref Bitmap bitmap,double gamma,double comp)
        {
            BitmapData bitmapData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr bitmapPtr = bitmapData.Scan0;

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            int flag = DllInterFace.GenGammTransInterFace(bitmapPtr, bitmap.Width, bitmap.Height, 1, gamma, comp);

            stopwatch.Stop();
            runTime = stopwatch.ElapsedMilliseconds.ToString();

            bitmap.UnlockBits(bitmapData);

            if (flag == 1)
                return true;
            return false;
        }

        /// <summary>
        /// 对数变换 按键
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void LogTrans_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;

            GenLogForm genLogForm = new GenLogForm();
            if (genLogForm.ShowDialog() == DialogResult.OK)
            {
                double log = ParamData.paramData["log"];

                Bitmap bitmap = (Bitmap)winImage.Clone();

                if (LogTrans(ref bitmap,log))
                {
                    ShowImage(bitmap);
                }
                else
                    ParamFalse();
            }
        }

        /// <summary>
        /// 对数变换
        /// </summary>
        /// <param name="bitmap"></param>
        /// <param name="log"></param>
        /// <returns></returns>
        private bool LogTrans(ref Bitmap bitmap,double log)
        {
            BitmapData bitmapData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr bitmapPtr = bitmapData.Scan0;

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            int flag = DllInterFace.GenLogTransInterface(bitmapPtr, bitmap.Width, bitmap.Height, 1, log);

            stopwatch.Stop();
            runTime = stopwatch.ElapsedMilliseconds.ToString();

            bitmap.UnlockBits(bitmapData);

            if (flag == 1)
                return true;
            return false;
        }

        /// <summary>
        /// 二值化 按键
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Threshold_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;

            GenThresholdForm genThresholdForm = new GenThresholdForm();
            if (genThresholdForm.ShowDialog() == DialogResult.OK)
            {
                int thresholdValue = Convert.ToInt32(ParamData.paramData["thresholdValue"]);

                Bitmap bitmap = (Bitmap)winImage.Clone();

                if (Threshold(ref bitmap, thresholdValue))
                {
                    ShowImage(bitmap);
                }
                else
                    ParamFalse();
            }
        }

        /// <summary>
        /// 二值化
        /// </summary>
        /// <param name="bitmap"></param>
        /// <param name="thresholdValue"></param>
        /// <returns></returns>
        private bool Threshold(ref Bitmap bitmap,int thresholdValue)
        {
            BitmapData bitmapData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr bitmapPtr = bitmapData.Scan0;

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            int flag = DllInterFace.GenThresholdInterface(bitmapPtr, bitmap.Width, bitmap.Height, 1, thresholdValue);

            stopwatch.Stop();
            runTime = stopwatch.ElapsedMilliseconds.ToString();

            bitmap.UnlockBits(bitmapData);

            if (flag == 1)
                return true;
            return false;
        }

        /// <summary>
        /// 线性分割 按键
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void SegmentTrans_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;

            GenSegmentTransForm genSegmentTransForm = new GenSegmentTransForm();
            if (genSegmentTransForm.ShowDialog() == DialogResult.OK)
            {
                int x1 = Convert.ToInt32(ParamData.paramData["x1"]);
                int y1 = Convert.ToInt32(ParamData.paramData["y1"]);
                int x2 = Convert.ToInt32(ParamData.paramData["x2"]);
                int y2 = Convert.ToInt32(ParamData.paramData["y2"]);

                Bitmap bitmap = (Bitmap)winImage.Clone();

                if (SegmentTrans(ref bitmap, x1,y1,x2,y2))
                {
                    ShowImage(bitmap);
                }
                else
                    ParamFalse();
            }
        }

        /// <summary>
        /// 线性分割
        /// </summary>
        /// <param name="bitmap"></param>
        /// <param name="x1"></param>
        /// <param name="y1"></param>
        /// <param name="x2"></param>
        /// <param name="y2"></param>
        /// <returns></returns>
        private bool SegmentTrans(ref Bitmap bitmap,int x1,int y1, int x2,int y2)
        {
            BitmapData bitmapData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr bitmapPtr = bitmapData.Scan0;

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            int flag = DllInterFace.GenSegmentTransInterface(bitmapPtr, bitmap.Width, bitmap.Height, 1, x1,y1,x2,y2);

            stopwatch.Stop();
            runTime = stopwatch.ElapsedMilliseconds.ToString();

            bitmap.UnlockBits(bitmapData);

            if (flag == 1)
                return true;
            return false;
        }

        /// <summary>
        /// 直方图均衡化 按键
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void HistEqual_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;
            Bitmap bitmap = (Bitmap)winImage.Clone();

            if (HistEqual(ref bitmap))
            {
                ShowImage(bitmap);
            }
            else
                ParamFalse();
        }

        /// <summary>
        /// 直方图均衡化
        /// </summary>
        /// <param name="bitmap"></param>
        /// <returns></returns>
        private bool HistEqual(ref Bitmap bitmap)
        {
            BitmapData bitmapData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr bitmapPtr = bitmapData.Scan0;

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            int flag = DllInterFace.GenHistEqualInterface(bitmapPtr, bitmap.Width, bitmap.Height, 1);

            stopwatch.Stop();
            runTime = stopwatch.ElapsedMilliseconds.ToString();

            bitmap.UnlockBits(bitmapData);

            if (flag == 1)
                return true;
            return false;
        }

        #endregion

        private void LevelMove_CLick(object sender, EventArgs e)
        {

        }

        private void TurnOver_Click(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// 图像旋转
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Rotate_Click(object sender, EventArgs e)
        {
            if (JudegeImagePixelFormat())
                return;

            RotateImageForm rotateImageForm = new RotateImageForm();
            if (rotateImageForm.ShowDialog() == DialogResult.OK)
            {
                double angle = ParamData.paramData["angle"];
                int x = Convert.ToInt32(ParamData.paramData["pointx"]);
                int y = Convert.ToInt32(ParamData.paramData["pointy"]);
                int mode = Convert.ToInt32(ParamData.paramData["mode"]);
                Bitmap histImage = (Bitmap)winImage.Clone();
                ParamData.paramData.Clear();
                if (GenRotateImage(ref histImage, angle,x,y,mode))
                {

                    ShowImage(histImage);
                }
                else
                    ParamFalse();
            }
        }

        /// <summary>
        /// 生成直方图
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        private bool GenRotateImage(ref Bitmap histImage, double angle,int x,int y,int mode)
        {
            BitmapData srcData = winImage.LockBits(new Rectangle(0, 0, winImage.Width, winImage.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr srcPtr = srcData.Scan0;

            BitmapData histData = histImage.LockBits(new Rectangle(0, 0, histImage.Width, histImage.Height), ImageLockMode.ReadWrite, singlePixel);
            IntPtr histPtr = histData.Scan0;
            Stopwatch watch = new Stopwatch();
            watch.Start();
            int flag = DllInterFace.GenRotateImageInterface(srcPtr, histPtr, winImage.Width, winImage.Height, 1, x, y, angle, mode);
            watch.Stop();
            runTime = watch.ElapsedMilliseconds.ToString();
            winImage.UnlockBits(srcData);
            histImage.UnlockBits(histData);
            if (flag == 1)
            {
                return true;
            }
            return false;
        }
    }
}
