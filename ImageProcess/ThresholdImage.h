#pragma once
#include "Image.h"
#include "ImageProcess.h"
class ThresholdImage:public ImageProcess
{
public:
	ThresholdImage() :ImageProcess()
	{

	}
	//构造函数
	ThresholdImage(unsigned char* tmp_data, int tmp_width, int tmp_height, int tmp_channel)
		: ImageProcess(tmp_data, tmp_width, tmp_height, tmp_channel)
	{

	}
	
	//均值二值化
	bool meanValueThreshold();
	
	//百分比阈值
	bool percentageThrshold(double value);

	//

	~ThresholdImage();
};

