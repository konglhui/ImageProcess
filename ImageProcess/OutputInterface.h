#pragma once
#include"DataStruct.h"
#include "Image.h"
#include "ImageProcess.h"

//���ɻҶ�ֱ��ͼ
DLLEXPORT
int _stdcall GenhistInterface(uchar * data, const int width, const int height, const int channel, uchar*outData,  int outWidth,  int outHeight,  int outChannel, int n);

//ͼ������Ա任
DLLEXPORT
int _stdcall GenLineTransInterFalce(uchar * data, const int width, const int height, const int channel,const double d_fa,const int d_fb);

//gamm�任
DLLEXPORT
int _stdcall GenGammTransInterFace(uchar * data, const int width, const int height, const int channel, const double gamma, const double comp);

//log�任
DLLEXPORT
int _stdcall GenLogTransInterface(uchar * data, const int width, const int height, const int channel, const double C);

//��ֵ��
DLLEXPORT
int _stdcall GenThresholdInterface(uchar * data, const int width, const int height, const int channel,const int thresholdValue);

//���Էָ�任
DLLEXPORT
int _stdcall GenSegmentTransInterface(uchar * data, const int width, const int height, const int channel, int x1, int y1, int x2, int y2);

//ֱ��ͼ�任
DLLEXPORT
int _stdcall GenHistEqualInterface(uchar * data, const int width, const int height, const int channel);

///ͼ����ת
DLLEXPORT
int _stdcall GenRotateImageInterface(uchar*data, uchar*outputData, const int width, const int height, const int channel, const int rotateX, const int rotateY, const double rotateAngle, const int mode);