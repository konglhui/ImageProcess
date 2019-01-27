#include "stdafx.h"
#include "ThresholdImage.h"


ThresholdImage::ThresholdImage()
{
}

ThresholdImage::~ThresholdImage()
{
}

bool ThresholdImage::meanValueThreshold()
{
	if (channel != 1)
		return false;
	int histVec[256];
	genHist(histVec);
	int sum = 0;
	int count = width * height;
	for (int i = 0; i < 256; ++i)
	{
		sum += histVec[i];
	}
	int thresholdValue = (sum + count / 2) / count;
	threshold(thresholdValue);
	return true;
}


