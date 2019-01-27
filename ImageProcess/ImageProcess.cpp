#include "stdafx.h"
#include "ImageProcess.h"

bool ImageProcess::extensionImage(int size, const Image &image, Image &output_image)
{
	//扩充左、右边界
	for (int i = 0; i < image.height; ++i)
	{
		int leftlength = i * image.width;
		int rightLength = leftlength + image.width;
		int outLeftLength = (i + size)*output_image.width;
		int outRightLength = outLeftLength + size + image.width;
		for (int j = 0; j < size; ++j)
		{
			output_image.data[outLeftLength + j] = image.data[leftlength + size - 1 - j];
			output_image.data[outRightLength + j] = image.data[rightLength - j - 1];
		}
	}

	//复制原图
	int a = 0;
	for (int i = 0; i < image.height; ++i)
	{
		//int length = i * image.height;
		int outLength = (i + size) * output_image.width +size;
		for (int j = 0; j < image.width; ++j)
		{
			output_image.data[outLength + j] = image.data[a];
			++a;
		}
	}

	//memcpy上下边界
	for (int i = 0; i < size; i++)
	{
		memcpy(output_image.data + i * output_image.width, output_image.data + (2 * size - 1 - i) *output_image.width, output_image.width);
		memcpy(output_image.data + (output_image.height - i - 1) * output_image.width, output_image.data + (output_image.height - 2*size + i ) *output_image.width, output_image.width);
	}
	return true;
}

bool ImageProcess::genHist( double* histVec, const int& n)
{
	if (n <= 0 || n > 256)
	{
		return false;
	}
	//histVec.resize(n, 0);
	int d_divide = 256.0 /n;
	uchar tmp_gray;

	for (int i = 0; i < height; ++i)
	{
		int heightLength = i * width;
		for (int j = 0; j < width; ++j)
		{
			tmp_gray = data[heightLength + j];
			histVec[tmp_gray] ++ ;
		}
		
	}
	//histVec[128] = 122922;
	double square = width * height;
	for (int k = 0; k < n; ++k)
	{
		histVec[k] = histVec[k]/ square;
	}
	return true;
}
bool ImageProcess::genHist(int* histVec)
{
	uchar* lineData;
	for (int i = 0; i < height; ++i)
	{
		lineData = data + i * width;
		for (int j = 0; j < width; ++j)
		{
			histVec[lineData[j]] ++;
		}
	}
}


bool ImageProcess::genHistImage(Image &newImage, const int& n)
{
	//先生成灰度直方图
	double* histVec  = new double[n];
	memset(histVec, 0, n * sizeof(double));
	if (!genHist(histVec, n))
		return false;
	//找最大值
	double maxValue = 0;
	for (int i = 0; i < n; ++i)
	{
		if (histVec[i] > maxValue)
			maxValue = histVec[i];
	}
	int length = newImage.height - 10;
	//maxValue *= 0.83333;
	for (int j = 0; j < newImage.width; ++j)
	{
		for (int i = 0; i < newImage.height - 10; ++i )
		{
			if (i >= (1 - histVec[j] / maxValue) * length)
			{
				newImage.data[j + (i+10) * newImage.width] = 255;
			}
		}
	}
	delete[]histVec;
}


bool ImageProcess::lineTrans(const double& d_fa, const int& d_fb)
{
	if (channel != 1)
		return false;
	uchar gray;
	int target;
	int pixelLength;
	for (int i = 0; i < height; i++)
	{
		int length = i * width;
		for (int j = 0; j < width; j++)
		{
			pixelLength = length + j;
			gray = data[pixelLength];
			target = round(gray * d_fa) + d_fb;
			if (target < 0)
				target = 0;
			else if (target > 255)
				target = 255;
			data[pixelLength] = target;
		}
	}
	return true;
}

bool ImageProcess::gammaTrans(const double& gamma, const double& comp )
{
	if (channel != 1)
		return false;

	uchar gray;
	int target;
	int pixelLength;
	for (int i = 0; i < height; i++)
	{
		int length = i * width;
		for (int j = 0; j < width; j++)
		{
			pixelLength = length + j;
			gray = data[pixelLength];
			target = pow((gray + comp) / 255.0, gamma) * 255;
			if (target < 0)
				target = 0;
			else if (target > 255)
				target = 255;
			data[pixelLength] = target;
		}
	}
	return true;
}

bool ImageProcess::logTrans(const double& C)
{
	if (channel != 1)
		return false;

	uchar gray;
	int target;	
	int pixelLength;
	for (int i = 0; i < height; i++)
	{
		int length = i * width;
		for (int j = 0; j < width; j++)
		{
			pixelLength = length + j;
			gray = data[pixelLength];
			target = C * log(double(gray + 1));
			if (target < 0)
				target = 0;
			else if (target > 255)
				target = 255;
			data[pixelLength] = target;
		}
	}
	return true;
}

bool ImageProcess::threshold(const uchar& n_thre )
{
	if (channel != 1)
		return false;

	uchar gray[256];
	int i;
	for (i = 0; i < n_thre; ++i)
		gray[i] = 0;
	for (; i < 256; ++i)
		gray[i] = 255;

	uchar* lineData;
	for (int i = 0; i < height; i++)
	{
		lineData = data + i * width;
		for (int j = 0; j < width; j++)
		{
			lineData[j] = gray[lineData[j]];
		}
	}
	return true;
}

bool ImageProcess::segmentLineTrans(const uchar& x1, const uchar& y1, const uchar& x2, const uchar& y2)
{
	if (channel != 1)
		return false;

	uchar gray;
	int target;
	int pixelLength;
	for (int i = 0; i < height; i++)
	{
		int length = i * width;
		for (int j = 0; j < width; j++)
		{
			pixelLength = length + j;
			gray = data[pixelLength];
			if (gray < x1)
				target = gray * y1 / x1;
			else if (gray < x2)
				target = (y2 - y1) * gray / (x2 - x1);
			else
				target = (255 - y2) * gray / (255 - x2);
			data[pixelLength] = target;
		}

	}
	return true;
}

bool ImageProcess::histEqual()
{
	if (channel != 1)
		return false;
	

	double temp_hist[256] = { 0 };
	genHist(temp_hist, 256);

	int grayIndex[256] = { 0 };
	int target;
	grayIndex[0] = round(temp_hist[0] * 255);
	for (int n = 1; n < 256; ++n)
	{
		 target = round(*(temp_hist + n) * 255+ grayIndex[n-1]);
		 if (target < 0)
			 target = 0;
		 else if (target > 255)
			 target = 255;
		 grayIndex[n] = target;
	}




	uchar gray;

	double d_temp;
	int pixelLength;
	for (int i = 0; i < height; i++)
	{
		int length = i * width;
		for (int j = 0; j < width; j++)
		{
			pixelLength = length + j;
			gray = data[pixelLength];
			data[pixelLength] = grayIndex[gray];
		}
	}
	return true;
}


bool ImageProcess::levelMove(const Image&img, Image&output_img, const int& x,const int& y)
{
	if (x > img.width || y > img.height || img.channel == 1)
		return false;

	uchar  target;
	int pixelLength;
	for (int i = 0; i < img.height - y; i++)
	{
		int length = i * img.width;
		for (int j = 0; j < img.width - x; j++)
		{
			pixelLength = length + j;
			target = img.data[pixelLength];
			output_img.data[pixelLength] = target;
		}
	}

	return true;
}

bool ImageProcess::turnOver(const Image&img, Image&output_img, const int& pattern)
{
	if (img.channel != 1)
		return false;

	uchar  target;
	if (pattern == 0)
	{
		for (int i = 0; i < img.height; i++)
		{
			int length = i * img.width;
			for (int j = 0; j < img.width; j++)
			{
				target = img.data[length + j];
				output_img.data[length + output_img.width - 1 - j] = target;
			}
		}
	}

	if (pattern == 1)
	{
		for (int i = 0; i < img.height; i++)
		{
			int length = i * img.width;
			int outputWidth = (img.height - 1 - i) * img.width;
			for (int j = 0; j < img.width; j++)
			{
				target = img.data[length + j];
				output_img.data[outputWidth + j];
			}
		}
	}
	return true;
}

bool ImageProcess::transPosition(const Image&img, Image&output_img )
{
	if (img.channel != 1)
		return false;

	uchar target;
	for (int i = 0; i < img.height; i++)
	{
		int length = i * img.width;
		for (int j = 0; j < img.width; j++)
		{
			target = img.data[length + j];
			output_img.data[j * output_img.width + i] = target;
		}
	}
	return true;
}
 
bool ImageProcess::zoomImage(Image&img, Image&output_img, const double& ratio, const int& mode)
{
	int multiple = 10;
	int multipleValue = pow(2, multiple);
	uchar  gray;


	if (mode == 0)
	{
		auto temp = [&ratio,&multipleValue](int *tempArray,double*tempRemainderArray,int length)
		{
			for (int i = 0; i < length; i++)
			{
				double temp = i / ratio;
				tempArray[i] = floor(temp);
				tempRemainderArray[i] = (temp - tempArray[i]) * multipleValue;
			}
		};

		int *intY = new int[output_img.height]();
		double *yRemainder = new double[output_img.height]();
		int *intX = new int[output_img.width]();
		double *xRemainder = new double[output_img.width]();

		temp(intY, yRemainder, output_img.height);
		temp(intX, xRemainder, output_img.width);

		for (int i = 0; i < output_img.height; i++)
		{
			int yLength = intY[i] * img.width;
			int outputLength = i * output_img.width;
			for (int j = 0; j < output_img.width; j++)
			{
				//output_img.data[outputLength + j] = interpBilinearGray(yLength + intX[j], intX[j], xRemainder[j], yRemainder[i], multiple, img);
			}
		}

		delete[]intY;
		delete[]intX;
		delete[]yRemainder;
		delete[]xRemainder;
	}
	else
	{
		auto temp = [ &ratio](int *tempArray, int length)
		{
			for (int i = 0; i < length; i++)
			{
				double temp = i / ratio;
				tempArray[i] = temp < length - 1 ? round(temp) : floor(temp);
			}
		};

		int *intY = new int[output_img.height]();
		int *intX = new int[output_img.width]();
		temp(intX, output_img.width);
		temp(intY, output_img.height);

		for (int i = 0; i < output_img.height; i++)
		{
			int length = intY[i] * img.width;
			int outputLength = i * output_img.width;
			for (int j = 0; j < output_img.width; j++)
			{
				output_img.data[outputLength + j] = img.data[length + intX[j]];
			}
		}		
		delete[]intY;
		delete[]intX;
	}

	return true;
}

bool ImageProcess::rotateImage(const Image&img, Image&output_img, const double& angle,const Point &rotatePoint, const int& mode)
{
	uchar  gray;

	int multiple = 10;
	int multipleValue = pow(2, 10);
	double cosTheta = cos(angle / 180 * Pi);
	double sinTheta = sin(angle / 180 * Pi);
	//return Point2f(cosTheta* point.x + sinTheta * point.y, cosTheta * point.y - sinTheta * point.x);
	//double* xCos = new double[img.width]();
	//double* xSin = new double[img.width]();
	//double* yCos = new double[img.height]();
	//double* ySin = new double[img.height]();

	//for (int i = 0; i < img.width; ++i)
	//{
	//	xCos[i] = (i - rotatePoint.x) * cosTheta;
	//	xSin[i] = (i - rotatePoint.x) * sinTheta;
	//}

	//for (int i = 0; i < img.height; ++i)
	//{
	//	yCos[i] = (i - rotatePoint.y) * cosTheta;
	//	ySin[i] = (i - rotatePoint.y) * sinTheta;
	//}
	double xCos = -rotatePoint.x * cosTheta;
	double xSin = -rotatePoint.x * sinTheta;
	double yCos = -rotatePoint.y * cosTheta;
	double ySin = -rotatePoint.y * sinTheta;
	double xCoeffi = (1 - cosTheta) * rotatePoint.x - sinTheta * rotatePoint.y;
	double yCoeffi = (1 - cosTheta) * rotatePoint.y + sinTheta * rotatePoint.x;

	uchar*lineData = output_img.data;
	for (int i = 0; i < output_img.height; i++)
	{
		Point2f point(xCoeffi + ySin, yCoeffi + yCos);
		double tempXCos = xCos;
		double tempXSin = xSin;
		for (int j = 0; j < output_img.width; j++)
		{
			point.x += tempXCos;
			point.y -= tempXSin;
 			if (point.x <0 || point.y < 0 || point.x > img.width - 1 || point.y > img.height - 1)
				continue;
			int length = round(point.y) * img.width + round(point.x);
			gray = img.data[length];

			lineData[j] = gray;
			tempXCos += xCos;
			tempXSin += xSin;
		}
		ySin += sinTheta;
		yCos += cosTheta;
		lineData += output_img.height;
	}
//else
//gray = interpNearsetGray(point, img);
	return true;
}

//bool ImageProcess::affineTransform(const Image&img, Image&output_img, const std::vector<Point>& src_points, const std::vector<Point>&dst_points,const int& mode)
//{
//	uchar  gray;
//	ImagePixel pixel;
//	Point2f point;
//	//计算仿射变换矩阵
//	std::vector<std::vector<double>> x_matrix, y_matrix;
//	bool is_true = affineMatrix(dst_points, src_points, x_matrix, y_matrix);
//	if (is_true)
//	{
//		std::vector<double> x_affine_matrix,y_affine_matrix;
//		bool b_gass1 = CommonAlgorithm::gaussionSolveMatrix(x_matrix, x_affine_matrix);
//		bool b_gass2 = CommonAlgorithm::gaussionSolveMatrix(y_matrix, y_affine_matrix);
//		if (b_gass1 && b_gass2)
//		{
//			if (output_img.channel == 1)
//			{
//				for (int i = 0; i < output_img.height; i++)
//				{
//					for (int j = 0; j < output_img.width; j++)
//					{
//						point = getAffinePoint(x_affine_matrix, y_affine_matrix, Point(j, i));
//						if (mode == 0)
//							gray = interpBilinearGray(point, img);
//						else
//							gray = interpNearsetGray(point, img);
//						setPixel(j, i, gray, output_img);
//					}
//				}
//			}
//			if (output_img.channel == 3)
//			{
//				for (int i = 0; i < output_img.height; i++)
//				{
//					for (int j = 0; j < output_img.width; j++)
//					{
//						point = getAffinePoint(x_affine_matrix, y_affine_matrix, Point(j, i));
//						if (mode == 0)
//							pixel = interpBilinear(point, img);
//						else
//							pixel = interpNearset(point, img);
//						setPixel(j, i, pixel, output_img);
//					}
//				}
//			}
//
//		}
//	}
//	return true;
//}
//
//bool ImageProcess::perspectiveTransform(const Image&img, Image&output_img, const std::vector<Point>& src_points, const std::vector<Point>&dst_points,const  int& mode)
//{
//
//	uchar  gray;
//	ImagePixel pixel;
//	Point2f point;
//	//计算仿射变换矩阵
//	std::vector<std::vector<double>> x_matrix, y_matrix;
//	bool is_true = perspectiveMatrix(dst_points, src_points, x_matrix, y_matrix);
//	if (is_true)
//	{
//		std::vector<double> x_perspective_matrix, y_perspective_matrix;
//		bool b_gass1 = CommonAlgorithm::gaussionSolveMatrix(x_matrix, x_perspective_matrix);
//		bool b_gass2 = CommonAlgorithm::gaussionSolveMatrix(y_matrix, y_perspective_matrix);
//
//		if (b_gass1 && b_gass2)
//		{
//			if (output_img.channel == 1)
//			{
//				for (int i = 0; i < output_img.height; i++)
//				{
//					for (int j = 0; j < output_img.width; j++)
//					{
//						point = getPerspectivePoint(x_perspective_matrix, y_perspective_matrix, Point(j, i));
//						if (mode == 0)
//							gray = interpBilinearGray(point, img);
//						else
//							gray = interpNearsetGray(point, img);
//						setPixel(j, i, gray, output_img);
//					}
//				}
//			}
//			if (output_img.channel == 3)
//			{
//				for (int i = 0; i < output_img.height; i++)
//				{
//					for (int j = 0; j < output_img.width; j++)
//					{
//						point = getPerspectivePoint(x_perspective_matrix, y_perspective_matrix, Point(j, i));
//						if (mode == 0)
//							pixel = interpBilinear(point, img);
//						else
//							pixel = interpNearset(point, img);
//						setPixel(j, i, pixel, output_img);
//					}
//				}
//			}
//
//		}
//	}
//
//
//	return true;
//}
//
