#include "stdafx.h"
#include "EnhanceImage.h"
#include <stack>



void EnhanceImage::GetGrayIntegralImage(int* Integral)
{
	memset(Integral, 0, (width + 1) * sizeof(int));
	for (int i = 0; i < height ; ++i)
	{
		uchar * singleRow = data + i * width;
		int * singleIntegralUpRow = Integral + i * (width + 1) + 1;
		int * singleIntegralRow = Integral + (i + 1) * (width + 1) + 1;
		singleIntegralRow[-1] = 0;
		int sum = 0;
		for (int j = 0; j < width ; ++j)
		{
			sum += singleRow[j];
			singleIntegralRow[j] = sum + singleIntegralUpRow[j];
		}
	}
}

bool EnhanceImage::blurImage( Image &outputImg,  int size)
{
	if (size == 0 || channel != outputImg.channel)
		return false;
	int	center = size / 2;
	size = center * 2 + 1;
	int extensionWidth = width + 2 * center;
	int extensionHeight = height + 2 * center;
	int extensionLength = extensionWidth * extensionHeight;
	//Í¼ÏñÀ©³ä
	uchar *extensionData = new uchar[extensionLength]();
	EnhanceImage extensionImage(extensionData, extensionWidth, extensionHeight, channel);
	ImageProcess::ExtensionImage(center, *this, extensionImage);

	//Í¼Ïñ»ý·ÖÍ¼
	int* Integral = new int[(extensionWidth + 1) * (extensionHeight + 1)]();
	extensionImage.GetGrayIntegralImage(Integral);

	//¾ùÖµÂË²¨
	int squareSize = size * size;
	int integralWidth = extensionWidth + 1;
	for (int i = 0; i < height; ++i)
	{
		uchar* linePointer = outputImg.data + i * width;
		int* upLine = Integral + i * integralWidth;
		int* downLine = Integral + (i+size) * integralWidth;
		for (int j = 0; j < width; ++j)
		{
			linePointer[j] = (upLine[j] + downLine[j + size] - upLine[j + size] - downLine[j] + center) / squareSize;
   		}
	}


	delete[] Integral;
	delete[] extensionData;

	return true;
}

