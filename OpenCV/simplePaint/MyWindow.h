#pragma once


#include <opencv2/opencv.hpp>//for opencv libs

#include <iostream>//for cpp 



const std::string sizeWarning = "\nYou have entered wrong size please enter numbers between (300,1080) for row and (300,1920) for column\n";
const std::string windowWarning = "\nImage not created. Something went wrong. \n";
const std::string winName = "ÝmageWindow";
const std::string argWarning = "Wrong number of argument therefore enter row and column again";

static cv::Mat image;
static cv::Point center;
static bool drawLine = false, deleteLine = false, drawCircle = false, drawPixel = true;

class MyWindow
{
protected:
	
	cv::Size size;
public:
	MyWindow();
	void setSize(int , int );
	MyWindow(int , int );
	virtual void createWindow(cv::Scalar  = cv::Scalar(255, 255, 255));


};



