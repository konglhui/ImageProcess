#include "stdafx.h"
#include "Image.h"

//默认构造函数
Image::Image()
{
}
Image::Image(Image& img) :data(img.data), width(img.width), height(img.height), channel(img.channel)
{
}

Image::Image(unsigned char* tmp_data, int tmp_width, int tmp_height, int tmp_channel)
	: data(tmp_data), width(tmp_width), height(tmp_height), channel(tmp_channel)
{
}

//析构函数
Image::~Image()
{
	cleanUp();
}

void Image::cleanUp()
{
	//delete[] data;
}

uchar Image::interpBilinearGray(const int& length, const int& x, const int& x1, const int& y1, const int& multiple, const Image& img)
{
	int length_width = length + img.width;
	int f12;
	int f34;
	if (y1 < 1)
	{
		f12 = img.data[length];
		if (x1 < 1)

			return f12;
		else
			f34 = img.data[length + 1];
	}
	else
	{
		uchar f2 = img.data[length_width];
		uchar f1 = img.data[length];
		uchar f3 = img.data[length + 1];
		uchar f4 = img.data[length_width + 1];
		f34 = (f3 + ((f4 - f3) * y1 >> multiple));
		f12 = (f1 + ((f2 - f1) * y1 >> multiple));
	}

	//四个连接点

	return  uchar((f12 + ((f34 - f12) * x1 >> multiple)));
}

inline uchar Image::interpBilinearGray(const Point2f& point, const Image& img)
{
	//先制作四个点
	int x1 = floor(point.x);
	int y1 = floor(point.y);
	int length = x1 + y1 * img.width;
	int length_width = length + img.width;

	//四个连接点
	uchar f1 = img.data[length];
	uchar f3 = img.data[length + 1];
	uchar f2 = img.data[length_width];
	uchar f4 = img.data[length_width + 1];

	double f12 = (f1 + (f2 - f1) * (point.y - y1));
	double f34 = (f3 + (f4 - f3) * (point.y - y1));

	return static_cast<uchar>(f12 + (f34 - f12) * (point.x - x1));
}

inline Point2f Image::getRotatePoint(const Point& point, const double& angle)
{
	double cosTheta = cos(angle / 180 * Pi);
	double sinTheta = sin(angle / 180 * Pi);
	return Point2f(cosTheta * point.x + sinTheta * point.y, cosTheta * point.y - sinTheta * point.x);
}

bool Image::affineMatrix(const std::vector<Point>& points1, const  std::vector<Point>& points2, std::vector<std::vector<double>>& output_matrix1, std::vector<std::vector<double>>& output_matrix2)
{
	if (points1.size() != points2.size())
		return false;
	for (int i = 0; i < points1.size(); i++)
	{
		std::vector<double> output;
		output.push_back(points1[i].x);
		output.push_back(points1[i].y);
		output.push_back(1);
		output.push_back(points2[i].x);
		output_matrix1.push_back(output);
	}

	for (int i = 0; i < points1.size(); i++)
	{
		std::vector<double> output;
		output.push_back(points1[i].x);
		output.push_back(points1[i].y);
		output.push_back(1);
		output.push_back(points2[i].y);
		output_matrix2.push_back(output);
	}
	return true;
}

inline Point2f Image::getAffinePoint(const std::vector<double>& x_matrix, const std::vector<double>& y_matrix, const Point& point)
{
	return Point2f(x_matrix[0] * point.x + x_matrix[1] * point.y + x_matrix[2],
		y_matrix[0] * point.x + y_matrix[1] * point.y + y_matrix[2]);
}

bool Image::perspectiveMatrix(const std::vector<Point>& points1, const std::vector<Point>& points2, std::vector<std::vector<double>>& output_matrix1, std::vector<std::vector<double>>& output_matrix2)
{
	if (points1.size() != points2.size())
		return false;

	for (int i = 0; i < points1.size(); i++)
	{
		std::vector<double> output;
		output.push_back(pow(points1[i].x, 2));
		output.push_back(points1[i].x * points1[i].y);
		output.push_back(pow(points1[i].y, 2));
		output.push_back(points1[i].x);
		output.push_back(points1[i].y);
		output.push_back(1);
		output.push_back(points2[i].x);
		output_matrix1.push_back(output);
	}

	for (int i = 0; i < points1.size(); i++)
	{
		std::vector<double> output;
		output.push_back(pow(points1[i].x, 2));
		output.push_back(points1[i].x * points1[i].y);
		output.push_back(pow(points1[i].y, 2));
		output.push_back(points1[i].x);
		output.push_back(points1[i].y);
		output.push_back(1);
		output.push_back(points2[i].y);
		output_matrix2.push_back(output);
	}

	return true;
}

inline Point2f Image::getPerspectivePoint(const std::vector<double>& x_matrix, const std::vector<double>& y_matrix, const Point& point)
{
	return Point2f(x_matrix[0] * pow(point.x, 2) + x_matrix[1] * point.x * point.y + x_matrix[2] * pow(point.y, 2) + x_matrix[3] * point.x + x_matrix[4] * point.y + x_matrix[5],
		y_matrix[0] * pow(point.x, 2) + y_matrix[1] * point.x * point.y + y_matrix[2] * pow(point.y, 2) + y_matrix[3] * point.x + y_matrix[4] * point.y + y_matrix[5]);
}