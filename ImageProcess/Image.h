#pragma once
#include <vector>
#include "DataStruct.h"

class  Image
{
public:
	//构造函数
	Image();
	//copyg构造函数
	Image(Image &img);
	Image(unsigned char* tmp_data, int tmp_width, int tmp_height, int tmp_channel);
	//析构函数
	virtual ~Image();
	void cleanUp();

public:
	//像素插值算法
	static uchar interpBilinearGray(const int &length,const int & x, const int &x1 , const int& y1, const int &multiple,const Image &img);
	static uchar interpBilinearGray(const Point2f& point, const Image &img);//给坐标

	
	//获取图像数组的总长度
	int getLength(){ return width * height * channel;}

	//根据当前点，获取旋转前的点，在根据差值算法计算像素值，angle单位角度
	static Point2f getRotatePoint(const Point& point,const double& angle);
	
	//给6个点制作需要求解的矩阵矩阵
	static bool affineMatrix(const std::vector<Point>& points1, const std::vector<Point>& points2, std::vector<std::vector<double>> &output_matrix1, std::vector<std::vector<double>>&output_matrix2);

	//给8个点制作需要的求解矩阵
	static bool perspectiveMatrix(const std::vector<Point>& points1, const std::vector<Point>& points2, std::vector<std::vector<double>> &output_matrix1, std::vector<std::vector<double>>&output_matrix2);

	//根据仿射矩阵计算仿射前的点
	static Point2f getAffinePoint(const std::vector<double>& x_matrix, const std::vector<double>& y_matrix, const Point &point);
	
	//根据透视矩阵四算透视前的点
	inline static Point2f getPerspectivePoint(const std::vector<double>& x_matrix, const std::vector<double>& y_matrix, const Point& point);

public:
	//文件数据
	unsigned char* data;
	int width;
	int height;
	int channel;

};

