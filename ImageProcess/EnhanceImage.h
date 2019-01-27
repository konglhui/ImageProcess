#pragma once
#include "Image.h"
#include "DataStruct.h"
#include "ImageProcess.h"

class   EnhanceImage :public Image
{
public:
	EnhanceImage() {}
	EnhanceImage(unsigned char* data, int _width, int _height, int _channel)
		:Image(data,_width,_height,_channel)
	{
	}
	EnhanceImage( double* data, int width, int height, int channel)
		:int_data(data), width(width), height(height), channel(channel)
	{

	}
	double* int_data;
	int width;
	int height;
	int channel;
	~EnhanceImage() {}

	//static ImagePixelDouble getImagePixelDouble(int x,int y, EnhanceImage &img)
	//{
		//ImagePixelDouble output_value;
		//if (x < 0 || x>img.width - 1) return output_value;
		//if (y < 0 || y>img.height - 1) return output_value;
		//if (img.channel == 1)
		//{
		//	double value = img.double_data[y*img.width + x];
		//	output_value.blue = value;
		//	output_value.green = value;
		//	output_value.red = value;
		//	return output_value;
		//}
		//else if (img.channel == 3)
		//{
		//	double blue_value = img.double_data[(y*img.width + x)*img.channel];
		//	double green_value = img.double_data[(y*img.width + x)*img.channel + 1];
		//	double red_value = img.double_data[(y*img.width + x)*img.channel + 2];
		//	output_value.blue = blue_value;
		//	output_value.green = green_value;
		//	output_value.red = red_value;
		//	return output_value;
		//}
	//}

	//static void setImagePixelDouble(int x, int y, ImagePixelDouble pixel, EnhanceImage &img)
	//{
	//	if (img.channel == 1)
	//	{
	//		img.double_data[y * img.width + x] = pixel.blue;
	//	}
	//	if (img.channel == 3)
	//	{
	//		img.double_data[(y*img.width + x)*img.channel] = pixel.blue;
	//		img.double_data[(y*img.width + x)*img.channel + 1] = pixel.green;
	//		img.double_data[(y*img.width + x)*img.channel + 2] = pixel.red;
	//	}
	//}



	//»ý·ÖÍ¼·¨ÂË²¨
	static bool blurImage(const Image & img,Image &outputImg, int size);


};

