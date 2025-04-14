#include <vector>

#include "app.hpp"

cv::Mat blurImageGaussian(ImageDataGaussian input) {
    if (input.kernelSize % 2 == 0 || input.kernelSize < 1) {
        std::cerr << "Kernel size must be odd.\n";
        return input.image;
    }
    cv::Mat blurredImage;
    if(!input.colored && input.image.channels() == 3) {
        cv::cvtColor(input.image, blurredImage, cv::COLOR_BGR2GRAY);
    } 
    else if(input.colored && input.image.channels() == 3){
        std::vector<cv::Mat> channels(3);
        cv::split(input.image,channels);
        for(int i = 0; i < 3; i++){
            cv::GaussianBlur(channels[i], channels[i], cv::Size(input.kernelSize, 
                input.kernelSize), input.sigma, input.sigma);
        }
        cv::merge(channels, blurredImage);
        return blurredImage;
        
    }
    else {
        blurredImage = input.image.clone();
    }
    cv::GaussianBlur(blurredImage, blurredImage, cv::Size(input.kernelSize, 
        input.kernelSize), input.sigma, input.sigma);
    return blurredImage;
}