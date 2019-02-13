#pragma once
#include "Image.h"
#include "ImageProcess.h"
class ThresholdImage:public ImageProcess
{
public:
	ThresholdImage() :ImageProcess()
	{

	}
	//���캯��
	ThresholdImage(unsigned char* tmp_data, int tmp_width, int tmp_height, int tmp_channel)
		: ImageProcess(tmp_data, tmp_width, tmp_height, tmp_channel)
	{

	}
	
	//��ֵ��ֵ��
	bool meanValueThreshold();
	
	//�ٷֱ���ֵ
	bool percentageThrshold(double value);

	//

	~ThresholdImage();
};

