#include "app.hpp"

cv::Mat blurImage(const cv::Mat& inputImage, int kernelSize, int sigma, bool colored) {
    if (kernelSize % 2 == 0) {
        std::cerr << "Kernel size must be odd.\n";
        return inputImage;
    }
    cv::Mat blurredImage;
    if(!colored && inputImage.channels() == 3) {
        cv::cvtColor(inputImage, blurredImage, cv::COLOR_BGR2GRAY);
    } else {
        blurredImage = inputImage.clone();
    }
    cv::GaussianBlur(blurredImage, blurredImage, cv::Size(kernelSize, kernelSize), sigma, sigma);
    return blurredImage;
}