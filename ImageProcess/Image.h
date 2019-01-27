#pragma once
#include <vector>
#include "DataStruct.h"

class  Image
{
public:
	//���캯��
	Image();
	//copyg���캯��
	Image(Image &img);
	Image(unsigned char* tmp_data, int tmp_width, int tmp_height, int tmp_channel);
	//��������
	virtual ~Image();
	void cleanUp();

public:
	//���ز�ֵ�㷨
	static uchar interpBilinearGray(const int &length,const int & x, const int &x1 , const int& y1, const int &multiple,const Image &img);
	static uchar interpBilinearGray(const Point2f& point, const Image &img);//������

	
	//��ȡͼ��������ܳ���
	int getLength(){ return width * height * channel;}

	//���ݵ�ǰ�㣬��ȡ��תǰ�ĵ㣬�ڸ��ݲ�ֵ�㷨��������ֵ��angle��λ�Ƕ�
	static Point2f getRotatePoint(const Point& point,const double& angle);
	
	//��6����������Ҫ���ľ������
	static bool affineMatrix(const std::vector<Point>& points1, const std::vector<Point>& points2, std::vector<std::vector<double>> &output_matrix1, std::vector<std::vector<double>>&output_matrix2);

	//��8����������Ҫ��������
	static bool perspectiveMatrix(const std::vector<Point>& points1, const std::vector<Point>& points2, std::vector<std::vector<double>> &output_matrix1, std::vector<std::vector<double>>&output_matrix2);

	//���ݷ������������ǰ�ĵ�
	static Point2f getAffinePoint(const std::vector<double>& x_matrix, const std::vector<double>& y_matrix, const Point &point);
	
	//����͸�Ӿ�������͸��ǰ�ĵ�
	inline static Point2f getPerspectivePoint(const std::vector<double>& x_matrix, const std::vector<double>& y_matrix, const Point& point);

public:
	//�ļ�����
	unsigned char* data;
	int width;
	int height;
	int channel;

};

