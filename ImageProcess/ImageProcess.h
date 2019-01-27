#pragma once
#include "DataStruct.h"
#include "Image.h"
#include "CommonAlgorithm.h"
class ImageProcess :public Image
{
public:
	ImageProcess():Image()
	{
	}
	~ImageProcess() { cleanUp(); }
	ImageProcess(unsigned char* tmp_data, int tmp_width, int tmp_height, int tmp_channel)
		:Image(tmp_data, tmp_width, tmp_height, tmp_channel)
	{

	}
	
	//图像扩充
	static bool extensionImage(int size,const Image &image, Image &output_image);

	//生成灰度直方图数据
	bool genHist(double* histVec, const int & n);
	
	//生成直方图图像
	bool genHistImage(Image &new_image, const int &n);

	//线性变换
	bool lineTrans(const double& d_fa, const int & d_fb);

	//伽马变换
	bool gammaTrans(const double& gamma, const double& comp = 0.0);

	//对数变换
	bool logTrans(const double& C);

	//二值化
	bool threshold(const uchar& n_thre);

	//分段线性变换
	bool segmentLineTrans(const uchar& x1, const uchar& y1, const uchar& x2, const uchar& y2);

	//直方图均衡化
	bool histEqual();

	//图像整体平移
	static bool levelMove(const Image&img, Image&output_img, const int& x, const int& y); 

	//图像翻转 ，0为水平，1位竖直。
	static bool turnOver(const Image&img, Image&output_img, const int& pattern);

	//图像转置
	static bool transPosition(const Image&img, Image&output_img );

	//图像缩放,mode == 0 双线性差值，其他为最近邻
	static bool zoomImage(Image&img, Image&output_img, const double& ratio, const int& mode);

	//图像旋转,mode == 0 双线性差值，其他为最近邻
	static bool rotateImage(const Image&img, Image&output_img, const double& angle,const Point & rotatePoint ,const int& mode);

	//仿射变换
	static bool affineTransform(const Image&img, Image&output_img, const std::vector<Point>& src_points, const std::vector<Point>&dst_points, const int& mode);
	
//透视变换
	static bool perspectiveTransform(const Image&img, Image&output_img, const std::vector<Point>& src_points, const std::vector<Point>&dst_points, const int& mode);
};

