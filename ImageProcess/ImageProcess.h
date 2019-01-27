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
	
	//ͼ������
	static bool extensionImage(int size,const Image &image, Image &output_image);

	//���ɻҶ�ֱ��ͼ����
	bool genHist(double* histVec, const int & n);
	
	//����ֱ��ͼͼ��
	bool genHistImage(Image &new_image, const int &n);

	//���Ա任
	bool lineTrans(const double& d_fa, const int & d_fb);

	//٤��任
	bool gammaTrans(const double& gamma, const double& comp = 0.0);

	//�����任
	bool logTrans(const double& C);

	//��ֵ��
	bool threshold(const uchar& n_thre);

	//�ֶ����Ա任
	bool segmentLineTrans(const uchar& x1, const uchar& y1, const uchar& x2, const uchar& y2);

	//ֱ��ͼ���⻯
	bool histEqual();

	//ͼ������ƽ��
	static bool levelMove(const Image&img, Image&output_img, const int& x, const int& y); 

	//ͼ��ת ��0Ϊˮƽ��1λ��ֱ��
	static bool turnOver(const Image&img, Image&output_img, const int& pattern);

	//ͼ��ת��
	static bool transPosition(const Image&img, Image&output_img );

	//ͼ������,mode == 0 ˫���Բ�ֵ������Ϊ�����
	static bool zoomImage(Image&img, Image&output_img, const double& ratio, const int& mode);

	//ͼ����ת,mode == 0 ˫���Բ�ֵ������Ϊ�����
	static bool rotateImage(const Image&img, Image&output_img, const double& angle,const Point & rotatePoint ,const int& mode);

	//����任
	static bool affineTransform(const Image&img, Image&output_img, const std::vector<Point>& src_points, const std::vector<Point>&dst_points, const int& mode);
	
//͸�ӱ任
	static bool perspectiveTransform(const Image&img, Image&output_img, const std::vector<Point>& src_points, const std::vector<Point>&dst_points, const int& mode);
};

