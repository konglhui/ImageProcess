#include "stdafx.h"
#include "EnhanceImage.h"

bool EnhanceImage::blurImage(const Image & img, Image &outputImg,  int size)
{
	if (size == 0 || img.channel != outputImg.channel)
		return false;
	int	center = size / 2;
	size = center * 2 + 1;
	int temp_width = img.width + 2 * center;
	int temp_height = img.height + 2 * center;
	int length = temp_height * temp_width;
	uchar *temp_data = new uchar[length];

	Image temp_image(temp_data, temp_width, temp_height, img.channel);

	ImageProcess::extensionImage(center, temp_image, temp_image);

	double *double_data = new double[length];
	memset(double_data, 0, length * sizeof(length));

	//EnhanceImage enhanceImage(double_data, temp_width, temp_height, channel);

	//ImagePixelDouble pixel,pixel1,pixel2,pixel3,pixel4;
	//double x1, x2, x3, x4, x5;
	//double all_size = size * size;
	//for (int i = 0;i<temp_image.height; i++)
	//{
	//	for (int j = 0; j < temp_image.width; j++)
	//	{
	//		if (channel == 1)
	//		{
	//			x1 = getPixel(j, i, temp_image).blue / all_size;
	//			x2 = getImagePixelDouble(j, i - 1, enhanceImage).blue;
	//			x3 = getImagePixelDouble(j - 1, i , enhanceImage).blue;
	//			x4 = getImagePixelDouble(j - 1, i - 1, enhanceImage).blue;
	//			x5 = (x1 + x2 + x3 - x4) ;
	//			setImagePixelDouble(j, i, ImagePixelDouble(x5, x5, x5), enhanceImage);
	//		}
	//		else
	//		{
	//			pixel1 = getImagePixelDouble(j, i, enhanceImage);
	//			pixel2 = getImagePixelDouble(j, i - 1, enhanceImage);
	//			pixel3 = getImagePixelDouble(j, i - 1, enhanceImage);
	//			pixel4 = getImagePixelDouble(j - 1, i - 1, enhanceImage);
	//			pixel = (pixel1 + pixel2 + pixel3 - pixel4);
	//			return false;
	//		}
	//	}
	//}

	//ImagePixel blur_pixel;
	//uchar blur_x;
	//int step = center + 1;
	//for (int i = 0; i < height; i++)
	//{
	//	for (int j = 0; j < width; j++)
	//	{
	//		if (channel == 1)
	//		{
	//			x1 = getImagePixelDouble(j - 1, i - 1, enhanceImage).blue;
	//			x2 = getImagePixelDouble(j + 2 * center, i - 1, enhanceImage).blue;
	//			x3 = getImagePixelDouble(j + 2 * center, i + 2 * center, enhanceImage).blue;
	//			x4 = getImagePixelDouble(j - 1, i + 2 * center, enhanceImage).blue;
	//			x5 = (x3 - x4 - x2 + x1);
	//			blur_x = round(x5);
	//			setPixel(j, i, ImagePixel(blur_x, blur_x, blur_x));
	//		}
	//		else
	//		{
	//			pixel1 = getImagePixelDouble(j - center, i - center, enhanceImage);
	//			pixel2 = getImagePixelDouble(j - center, i + center, enhanceImage);
	//			pixel3 = getImagePixelDouble(j + center, i + center, enhanceImage);
	//			pixel4 = getImagePixelDouble(j - center, i + center, enhanceImage);
	//			blur_pixel = (pixel4 - pixel3 - pixel2 + pixel1).doubleToUchar();
	//			setPixel(j, i, blur_pixel);
	//		}
	//	}
	//}

	delete[] temp_data;
	delete[] double_data;
	return true;
}
