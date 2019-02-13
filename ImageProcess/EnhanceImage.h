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


	//���ɻ���ͼ�˲�
	void GetGrayIntegralImage(int* Integral);

	//�˲�
	bool blurImage(Image &outputImg, int size);


};

