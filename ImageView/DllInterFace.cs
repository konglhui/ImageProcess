using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ImageView
{
    class DllInterFace
    {
        /// <summary>
        /// 直方图
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="outData"></param>
        /// <param name="outWidth"></param>
        /// <param name="outHeight"></param>
        /// <param name="outChannel"></param>
        /// <param name="n"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenhistInterface(IntPtr data, int width, int height, int channel, IntPtr outData, int outWidth, int outHeight, int outChannel, int n);

        /// <summary>
        /// 线性变换
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="d_fa"></param>
        /// <param name="d_fb"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenLineTransInterFalce(IntPtr data, int width, int height, int channel, double d_fa, int d_fb);

        /// <summary>
        /// gamm变换
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="d_fa"></param>
        /// <param name="d_fb"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenGammTransInterFace(IntPtr data, int width, int height, int channel, double gamma, double comp = 0.0);

        /// <summary>
        /// log变换
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="C"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenLogTransInterface(IntPtr data, int width, int height, int channel, double C);

        /// <summary>
        /// 二值化
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="thresholdValue"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenThresholdInterface(IntPtr data, int width, int height, int channel, int thresholdValue);

        /// <summary>
        /// 线性分割变换
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="d_fa"></param>
        /// <param name="d_fb"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenSegmentTransInterface(IntPtr data, int width, int height, int channel, int x1, int y1, int x2, int y2);

        /// <summary>
        /// 直方图均衡化
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenHistEqualInterface(IntPtr data, int width, int height, int channel);

        /// <summary>
        /// 生成旋转图像
        /// </summary>
        /// <param name="data"></param>
        /// <param name="outputData"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="rotateX"></param>
        /// <param name="rotateY"></param>
        /// <param name="rotateAngle"></param>
        /// <param name="mode"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenRotateImageInterface(IntPtr data, IntPtr outputData, int width, int height, int channel, int rotateX, int rotateY, double rotateAngle, int mode);

        /// <summary>
        /// 图像缩放
        /// </summary>
        /// <param name="data"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="outData"></param>
        /// <param name="outWidth"></param>
        /// <param name="outHeight"></param>
        /// <param name="outChannel"></param>
        /// <param name="ratio"></param>
        /// <param name="mode"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenZoomImageInterface(IntPtr data, int width, int height, int channel, IntPtr outData, int outWidth, int outHeight, int outChannel, double ratio, int mode);

        /// <summary>
        /// 平移
        /// </summary>
        /// <param name="data"></param>
        /// <param name="outputData"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenLevelMoveImageInterface(IntPtr data, IntPtr outputData, int width, int height, int channel, int x, int y);

        /// <summary>
        /// 图像翻转
        /// </summary>
        /// <param name="data"></param>
        /// <param name="outputData"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="mode"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenTurnOverImageInterface(IntPtr data, IntPtr outputData, int width, int height, int channel, int mode);

        /// <summary>
        /// 图像转置
        /// </summary>
        /// <param name="data"></param>
        /// <param name="outputData"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenTransPositionImageInterface(IntPtr data, IntPtr outputData, int width, int height, int channel);

        /// <summary>
        /// 均值滤波
        /// </summary>
        /// <param name="data"></param>
        /// <param name="outputData"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="channel"></param>
        /// <param name="size"></param>
        /// <returns></returns>
        [DllImport("ImageProcess.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int GenBlurImageInterface(IntPtr data, IntPtr outputData,  int width,  int height,  int channel, int size);




    }

}
