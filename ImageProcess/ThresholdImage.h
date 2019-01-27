#pragma once
#include "Image.h"
class ThresholdImage:public Image
{
public:
	ThresholdImage();
	//���캯��
	ThresholdImage(unsigned char* tmp_data, int tmp_width, int tmp_height, int tmp_channel)
		: Image(tmp_data, tmp_width, tmp_height, tmp_channel)
	{

	}
	
	bool meanValueThreshold();
	

	~ThresholdImage();
};

