#ifndef APP_HPP
#define APP_HPP
#include "utils.hpp"

cv::Mat blurImage(const cv::Mat& inputImage, int kernelSize, int sigma = 0, bool colored = false);

#endif // APP_HPP