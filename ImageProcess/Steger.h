#pragma once
#include "init.h"
#include <opencv2/opencv.hpp>

Dll_EXPORT bool stegerExtractPoint(const cv::Mat& src, std::vector<cv::Point2f>& result_points, const float line_width, const cv::Mat& mask = cv::Mat());
