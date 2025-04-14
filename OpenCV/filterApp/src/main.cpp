#include "app.hpp"
#include "constants.h"

void on_trackbar_change_gaussian_blur(int, void*);

int main(int argc, char** argv) {

    ImageDataGaussian data;
    
    // Argument handling
    if(argc < 2) {
        std::cout << "Using example image, to use specific image please enter the path of the image.\n";;
        data.image = cv::imread("../share/exampleImage.jpeg");
        if(data.image.empty()) {
            std::cerr << "Could not open or find the image!\n";
            std::cerr << "exampleImage.jpeg file can be corrupted!\n";
            return -1;
        }
    }
    else if(argc == 2) {
        data.image = cv::imread(argv[1]);
        if(data.image.empty()) {
            std::cerr << "Could not open or find the image!\n";
            return -1;
        }
    }
    else {
        std::cerr << "Too many arguments!\n";
        std::cerr << "Usage: ./filterApp <image_path>(optional)\n";
        return -1;
    }

    //Original image for reference
    cv::namedWindow(window_original, cv::WINDOW_AUTOSIZE);
    cv::imshow( window_original, data.image);

    // Blurring part
    cv::namedWindow(window_blurred, cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("Kernel Size", window_blurred, &data.kernelSize, 15, 
        on_trackbar_change_gaussian_blur, &data);
    cv::createTrackbar("Sigma", window_blurred, &data.sigma, 5, 
        on_trackbar_change_gaussian_blur, &data);
    cv::createTrackbar("Colored", window_blurred, &data.colored, 1, 
        on_trackbar_change_gaussian_blur, &data);
    on_trackbar_change_gaussian_blur(0, &data);


    while(true) {
        int key = cv::waitKey(100);  // Wait for 100ms for more responsive UI
        if(key == 27) {  // ESC key
            break;
        }
    }

    // Clean up
    cv::destroyAllWindows();
    return 0;
}

void on_trackbar_change_gaussian_blur(int, void* userData) {

    ImageDataGaussian* data = static_cast<ImageDataGaussian*> (userData);

    //int kernelSize = cv::getTrackbarPos("Kernel Size", window_blurred);
    //int sigma = cv::getTrackbarPos("Sigma", window_blurred);

    if (data->kernelSize % 2 == 0) {
        data->kernelSize += 1;
    }
    if (data->kernelSize < 3) {
        data->kernelSize = 3;
    }

    // Apply Gaussian blur with the updated parameters
    cv::Mat blurredImage = blurImageGaussian(*data);
    
    // Display the blurred image
    cv::imshow(window_blurred, blurredImage);
}