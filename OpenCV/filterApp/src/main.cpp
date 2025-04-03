#include "app.hpp"

int main(int argc, char** argv) {

    cv::Mat inputImage;
    
    if(argc < 2) {
        std::cout << "Using example image, to use specific image please enter the path of the image.\n";;
        inputImage = cv::imread("../share/exampleImage.jpeg");
        if(inputImage.empty()) {
            std::cerr << "Could not open or find the image!\n";
            std::cerr << "exampleImage.jpeg file can be corrupted!\n";
            return -1;
        }
    }
    else if(argc == 2) {
        inputImage = cv::imread(argv[1]);
        if(inputImage.empty()) {
            std::cerr << "Could not open or find the image!\n";
            return -1;
        }
    }
    else {
        std::cerr << "Too many arguments!\n";
        std::cerr << "Usage: ./filterApp <image_path>(optional)\n";
        return -1;
    }
    int kernelSize = 5;
    int sigma = 0;
    bool colored = false;
    /*cv::Mat blurredImage = blurImage(inputImage, kernelSize, sigma, colored);
    if(blurredImage.empty()) {
        std::cerr << "Blurring failed!\n";
        return -1;
    }*/
    std::string windowName = "Original Image";
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
    cv::imshow( windowName, inputImage);
    //cv::imshow("Blurred Image", blurredImage);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}