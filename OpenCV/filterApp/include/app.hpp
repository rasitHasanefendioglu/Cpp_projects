#ifndef APP_HPP
#define APP_HPP
#include "utils.hpp"

struct ImageDataGaussian {
    cv::Mat image;
    int kernelSize = 3;
    int sigma = 0;
    int colored = 0;
};

cv::Mat blurImageGaussian(ImageDataGaussian input);

#endif // APP_HPP