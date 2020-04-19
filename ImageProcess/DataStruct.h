#pragma once
#include "init.h"
typedef unsigned char uchar;

//ͼ�񵥸��������ݽṹ
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
