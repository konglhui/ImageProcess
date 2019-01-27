#pragma once
#include <memory>
#define  DLLEXPORT extern"C" _declspec(dllexport)
#define IS_OK 1;
#define IS_NG 0;
constexpr double Pi = 3.1415926;
typedef unsigned char uchar;

//图像单个像素数据结构
template<typename Type>
struct Point_
{
	Type x;
	Type y;
	Point_() :x(0), y(0)
	{
	}

	Point_(Type _x, Type _y) :x(_x), y(_y)
	{
	}
};
typedef Point_<int>		Point;
typedef Point_<double>	Point2f;
