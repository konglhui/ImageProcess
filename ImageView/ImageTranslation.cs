using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;


namespace ImageView
{
    class ImageProcessCSharp
    {
        /// <summary>
        /// 获取bitmap的byte数据，并输出stride
        /// </summary>
        /// <param name="bmp"></param>
        /// <param name="stride"></param>
        /// <returns></returns>
        public static byte[] GetBGRValues(Bitmap bmp, out int stride)
        {
            var rect = new Rectangle(0, 0, bmp.Width, bmp.Height);
            var bmpData = bmp.LockBits(rect, System.Drawing.Imaging.ImageLockMode.ReadOnly, bmp.PixelFormat);
            stride = bmpData.Stride;
            //int channel = bmpData.Stride / bmp.Width; 
            var rowBytes = bmpData.Width * Image.GetPixelFormatSize(bmp.PixelFormat) / 8;
            var imgBytes = bmp.Height * rowBytes;
            byte[] rgbValues = new byte[imgBytes];
            IntPtr ptr = bmpData.Scan0;
            for (var i = 0; i < bmp.Height; i++)
            {
                Marshal.Copy(ptr, rgbValues, i * rowBytes, rowBytes);   //对齐
                ptr += bmpData.Stride; // next row
            }
            bmp.UnlockBits(bmpData);

            return rgbValues;
        }

        /// <summary>
        /// 从图像Byte数组获取Bitmap
        /// </summary>
        /// <param name="src"></param>
        /// <param name="w"></param>
        /// <param name="h"></param>
        /// <param name="stride"></param>
        /// <param name="format"></param>
        /// <returns></returns>
        public static Bitmap getBitmapByBytes(byte[] src, int w, int h,int channel /*int stride, PixelFormat format*/)
        {
            IntPtr ptr = getBytesPtr(src);
            PixelFormat format = new PixelFormat();
            int stride = ((w * channel + 3) / 4) * 4;

            int rowBytes = w * channel;
            byte[] rgbValues = new byte[stride * h];
            for (var i = 0; i < h; i++)
            {
                //int len = stride - (stride-rowBytes);
                Marshal.Copy(ptr, rgbValues, i * stride, rowBytes);   //对齐
                ptr += rowBytes; // next row
            }
            //Marshal.FreeHGlobal(ptr);
            ptr = getBytesPtr(rgbValues);

            if (channel == 1)
            {
                format = PixelFormat.Format8bppIndexed;
            }
            if(channel == 3)
            {
                format = PixelFormat.Format24bppRgb;
            }

            Bitmap bitmap = new Bitmap(w, h, stride, format, ptr);
            if (channel == 1)
            {
                bitmap.Palette = getGrayPalette();   //如果是单通道灰度图，默认的bitmap调色板不对，需要手动设置
            }
            return bitmap;
        }

        /// <summary>
        /// 获取bytes数组的头指针，非托管
        /// </summary>
        /// <param name="bytes"></param>
        /// <returns></returns>
        public static IntPtr getBytesPtr(byte[] bytes)
        {
            GCHandle hObject = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            return hObject.AddrOfPinnedObject();
        }

        /// <summary>
        /// 生成灰度图的调色板
        /// </summary>
        /// <returns></returns>
        public static ColorPalette getGrayPalette()
        {
            // 下面的代码是为了修改生成位图的索引表，从伪彩修改为灰度 
            ColorPalette tempPalette;
            using (Bitmap tempBmp = new Bitmap(1, 1, System.Drawing.Imaging.PixelFormat.Format8bppIndexed))
            {
                tempPalette = tempBmp.Palette;
            }
            for (int i = 0; i < 256; i++)
            {
                tempPalette.Entries[i] = System.Drawing.Color.FromArgb(i, i, i);
            }
            return tempPalette;
        }

        /// <summary>
        /// 24bit转8bit
        /// </summary>
        /// <param name="bmp"></param>
        /// <returns></returns>
        public static Bitmap transForm24to8(Bitmap bmp)
        {
            Rectangle rect = new Rectangle(0, 0, bmp.Width, bmp.Height);
            System.Drawing.Imaging.BitmapData bmpData = bmp.LockBits(rect, System.Drawing.Imaging.ImageLockMode.ReadWrite, bmp.PixelFormat);
            IntPtr ptr = bmpData.Scan0;
            int bytes = bmpData.Stride * bmpData.Height;
            byte[] rgbValues = new byte[bytes];
            System.Runtime.InteropServices.Marshal.Copy(ptr, rgbValues, 0, bytes);

            Rectangle rect2 = new Rectangle(0, 0, bmp.Width, bmp.Height);
            Bitmap bit = new Bitmap(bmp.Width, bmp.Height, PixelFormat.Format8bppIndexed);
            System.Drawing.Imaging.BitmapData bmpData2 = bit.LockBits(rect2, System.Drawing.Imaging.ImageLockMode.ReadWrite, bit.PixelFormat);
            IntPtr ptr2 = bmpData2.Scan0;
            int bytes2 = bmpData2.Stride * bmpData2.Height;
            byte[] rgbValues2 = new byte[bytes2];
            System.Runtime.InteropServices.Marshal.Copy(ptr2, rgbValues2, 0, bytes2);
            double colorTemp = 0;
            for (int i = 0; i < bmpData.Height; i++)
            {
                for (int j = 0; j < bmpData.Width * 3; j += 3)
                {
                    colorTemp = rgbValues[i * bmpData.Stride + j + 2] * 0.299 + rgbValues[i * bmpData.Stride + j + 1] * 0.578 + rgbValues[i * bmpData.Stride + j] * 0.114;
                    rgbValues2[i * bmpData2.Stride + j / 3] = (byte)colorTemp;
                }
            }
            System.Runtime.InteropServices.Marshal.Copy(rgbValues2, 0, ptr2, bytes2);
            bmp.UnlockBits(bmpData);
            ColorPalette tempPalette;
            {
                using (Bitmap tempBmp = new Bitmap(1, 1, PixelFormat.Format8bppIndexed))
                {
                    tempPalette = tempBmp.Palette;
                }
                for (int i = 0; i < 256; i++)
                {
                    tempPalette.Entries[i] = Color.FromArgb(i, i, i);
                }
                bit.Palette = tempPalette;
            }
            bit.UnlockBits(bmpData2);
            return bit;

        }
        
        /// <summary>
        /// 8位转24位
        /// </summary>
        /// <param name="bmp"></param>
        /// <returns></returns>
        public static Bitmap transForm8to24(Bitmap bmp)
        {

            System.Drawing.Rectangle rect = new System.Drawing.Rectangle(0, 0, bmp.Width, bmp.Height);

            System.Drawing.Imaging.BitmapData bitmapData = bmp.LockBits(rect, System.Drawing.Imaging.ImageLockMode.ReadOnly, bmp.PixelFormat);

            //计算实际8位图容量
            int size8 = bitmapData.Stride * bmp.Height;
            byte[] grayValues = new byte[size8];

            //// 申请目标位图的变量，并将其内存区域锁定  
            Bitmap TempBmp = new Bitmap(bmp.Width, bmp.Height, PixelFormat.Format24bppRgb);
            BitmapData TempBmpData = TempBmp.LockBits(new Rectangle(0, 0, bmp.Width, bmp.Height), ImageLockMode.WriteOnly, PixelFormat.Format24bppRgb);


            //// 获取图像参数以及设置24位图信息 
            int stride = TempBmpData.Stride;  // 扫描线的宽度  
            int offset = stride - TempBmp.Width;  // 显示宽度与扫描线宽度的间隙  
            IntPtr iptr = TempBmpData.Scan0;  // 获取bmpData的内存起始位置  
            int scanBytes = stride * TempBmp.Height;// 用stride宽度，表示这是内存区域的大小  

            //// 下面把原始的显示大小字节数组转换为内存中实际存放的字节数组  

            byte[] pixelValues = new byte[scanBytes];  //为目标数组分配内存  
            System.Runtime.InteropServices.Marshal.Copy(bitmapData.Scan0, grayValues, 0, size8);


            for (int i = 0; i < bmp.Height; i++)
            {

                for (int j = 0; j < bitmapData.Stride; j++)
                {

                    if (j >= bmp.Width)
                        continue;


                    int indexSrc = i * bitmapData.Stride + j;
                    int realIndex = i * TempBmpData.Stride + j * 3;

                    pixelValues[realIndex] = grayValues[indexSrc];
                    pixelValues[realIndex + 1] = grayValues[indexSrc];
                    pixelValues[realIndex + 2] = grayValues[indexSrc];

                }

            }

            //// 用Marshal的Copy方法，将刚才得到的内存字节数组复制到BitmapData中  
            System.Runtime.InteropServices.Marshal.Copy(pixelValues, 0, iptr, scanBytes);
            TempBmp.UnlockBits(TempBmpData);  // 解锁内存区域  
            bmp.UnlockBits(bitmapData);
            //string path = (g++).ToString() + "_24bit" + ".bmp";
            //TempBmp.Save(@"F:/图片/" + path);
            return TempBmp;
        }


    }
}
