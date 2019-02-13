#pragma once
#include "Image.h"
#include "DataStruct.h"
#include "ImageProcess.h"

class   EnhanceImage :public Image
{
public:
	EnhanceImage() {}
	EnhanceImage(uchar* data, int _width, int _height, int _channel)
		:Image(data,_width,_height,_channel)
	{
	}

	~EnhanceImage() {}


	//生成积分图滤波
	void GetGrayIntegralImage(int* Integral);

	//滤波
	bool blurImage(Image &outputImg, int size);


};

