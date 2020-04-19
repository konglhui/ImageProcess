#include "stdafx.h"
#include "Steger.h"

constexpr double sqrt3 = 1.732050807568877;

inline 
double calculateSigma(double line_width)
{
	return line_width / (2.0 * sqrt3);
}

bool stegerExtractPoint(const cv::Mat& src,std::vector<cv::Point2f>&  result_points,const float line_width, const cv::Mat& mask)
{
	if (src.empty())
		return IS_NG;
	cv::Mat img,img_mask;
	if (mask.empty())
		img_mask = cv::Mat::ones(cv::Size(src.cols, src.rows), CV_8UC1);
	else
		img_mask = mask;
	if (src.channels() == 3)
		cv::cvtColor(src, img, cv::COLOR_BGR2GRAY);
	else
		img = src.clone();

	img.convertTo(img, CV_32FC1);

	cv::Mat gauss_img,dx,dy,dxx,dyy,dxy;
	double sigma = calculateSigma(line_width);
	cv::GaussianBlur(img, gauss_img, cv::Size(0, 0), sigma, sigma);

	cv::Mat kernel_x = (cv::Mat_<float>(1, 3) << -1, 0, 1);
	cv::Mat kernel_y = (cv::Mat_<float>(3, 1)<< - 1, 0, 1);
	//cv::filter2D(gauss_img,dx,)
	cv::filter2D(gauss_img, dx, CV_32FC1, kernel_x);
	cv::filter2D(gauss_img, dy, CV_32FC1, kernel_y);

	cv::Mat kernel_xx = (cv::Mat_<float>(1, 3) << -1, 2, -1);
	cv::Mat kernel_yy = (cv::Mat_<float>(3, 1) << -1, 2, -1);
	cv::Mat kernel_xy = (cv::Mat_<float>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	cv::filter2D(gauss_img, dxx, CV_32FC1, kernel_xx);
	cv::filter2D(gauss_img, dyy, CV_32FC1,  kernel_yy);
	cv::filter2D(gauss_img, dxy, CV_32FC1, kernel_xy);

	for(int index_y=0;index_y < img.rows;index_y++)
	{
		const auto mask_ptr = img_mask.ptr<uchar>(index_y);
		const auto dx_ptr = dx.ptr<float>(index_y);
		const auto dy_ptr = dy.ptr<float>(index_y);
		const auto dxx_ptr = dxx.ptr<float>(index_y);
		const auto dyy_ptr = dyy.ptr<float>(index_y);
		const auto dxy_ptr = dxy.ptr<float>(index_y);
		for (int index_x = 0; index_x < img.cols; index_x++)
		{
			//非提取区域不操作
			if(mask_ptr[index_x] == 0 || img.at<float>(index_y,index_x) < 200)
				continue;
			const float dxx_value = dxx_ptr[index_x];
			const float dyy_value = dyy_ptr[index_x];
			const float dxy_value = dxy_ptr[index_x];

			cv::Mat hessian_matrix = (cv::Mat_<float>(2, 2) << dxx_value, dxy_value, dxy_value, dyy_value);
			cv::Mat eigen_value, eigen_vector;
			cv::eigen(hessian_matrix, eigen_value, eigen_vector);
			float nx, ny;
			if(fabs(eigen_value.at<float>(0,0)) > fabs(eigen_value.at<float>(1,0)))
			{
				nx = eigen_vector.at<float>(0, 0);
				ny = eigen_vector.at<float>(0, 1);
			}
			else
			{
				nx = eigen_vector.at<float>(1, 0);
				ny = eigen_vector.at<float>(1, 1);
			}
			const float dx_value = dx_ptr[index_x];
			const float dy_value = dy_ptr[index_x];

			const float t =  - 
						(dx_value * nx + dy_value * ny) /
						(dxx_value * pow(nx, 2) + 2 * dxy_value * nx * ny + dyy_value * pow(ny, 2));
			const float px = t * nx;
			const float py = t * ny;
			if (fabs(px) <= 0.5 && fabs(py) <= 0.5)
				result_points.emplace_back(index_x + px, index_y + py);
		}
	}
	
	return IS_OK;
}
