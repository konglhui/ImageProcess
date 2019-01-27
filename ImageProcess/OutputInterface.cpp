#include "stdafx.h"
#include "OutputInterface.h"

//生成直方图
DLLEXPORT
int _stdcall GenhistInterface(uchar * data, const int width, const int height, const int channel,uchar*outData, const int outWidth, const int outHeight, const int outChannel,   int n)
{
	if (channel != 1)
		return FALSE;
	ImageProcess src(data, width, height, channel);
	Image dst(outData, outWidth, outHeight, outChannel);
	if (src.genHistImage(dst, n))
		return TRUE;
	else
		return FALSE;
}

//线性变换
DLLEXPORT
int _stdcall GenLineTransInterFalce(uchar * data, const int width, const int height, const int channel, double d_fa, int d_fb)
{
	if (channel != 1)
		return FALSE;
	ImageProcess dst(data, width, height, channel);
	if (dst.lineTrans(d_fa, d_fb))
		return TRUE;
	else
		return FALSE;
}

//gamm变换
DLLEXPORT
int _stdcall GenGammTransInterFace(uchar * data, const int width, const int height, const int channel, const double gamma, const double comp = 0.0)
{
	if (channel != 1)
		return FALSE;
	ImageProcess dst(data, width, height, channel);
	if (dst.gammaTrans(gamma, comp))
		return TRUE;
	else
		return FALSE;
}

//log变换
DLLEXPORT
int _stdcall GenLogTransInterface(uchar * data, const int width, const int height, const int channel, const double C)
{
	if (channel != 1)
		return FALSE;
	ImageProcess dst(data, width, height, channel);
	if (dst.logTrans(C))
		return TRUE;
	else
		return FALSE;
}

//二值化
DLLEXPORT
int _stdcall GenThresholdInterface(uchar * data, const int width, const int height, const int channel, const int thresholdValue)
{
	if (channel != 1 && thresholdValue > 255)
		return FALSE;
	ImageProcess dst(data, width, height, channel);
	if (dst.threshold(thresholdValue))
		return TRUE;
	else
		return FALSE;
}

//线性分割变换
DLLEXPORT
int _stdcall GenSegmentTransInterface(uchar * data, const int width, const int height, const int channel, int x1, int y1, int x2, int y2)
{
	if (channel != 1)
		return FALSE;
	auto temp = [](int& x)
	{
		if (x < 0) 
		{ 
			x = 0; 
			return; 
		}
		if (x > 255) 
		{
			x = 255; 
			return; 
		}
	};
	temp(x1);
	temp(x2);
	temp(y1);
	temp(y2);
	ImageProcess dst(data, width, height, channel);
	if (dst.segmentLineTrans(x1,y1,x2,y2))
		return TRUE;
	else
		return FALSE;
}

//直方图变换，有待继续优化
DLLEXPORT
int _stdcall GenHistEqualInterface(uchar * data, const int width, const int height, const int channel)
{
	if (channel != 1)
		return FALSE;
	ImageProcess dst(data, width, height, channel);
	if (dst.histEqual())
		return TRUE;
	else
		return FALSE;
}

//图像旋转
//mode == 0为 双线性插值，其他为最近邻插值
DLLEXPORT
int _stdcall GenRotateImageInterface(uchar*data, uchar*outputData, const int width, const int height, const int channel, const int rotateX, const int rotateY, const double rotateAngle, const int mode)
{
	if (channel != 1)
		return FALSE;
	Image src(data, width, height, channel);
	Image dst(outputData, width, height, channel);
	if (ImageProcess::rotateImage(src,dst,rotateAngle,Point(rotateX,rotateY),mode))
		return TRUE;
	else
		return FALSE;
}