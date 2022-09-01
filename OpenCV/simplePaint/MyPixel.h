#pragma once
#include "MyWindow.h"

#include <cstdlib>//for random integer

class MyPixel : MyWindow {
	cv::Scalar windowColor= cv::Scalar(255,255,255);
	cv::Scalar pixColor();
public:
	using MyWindow::MyWindow;
	void lineDraw();
	void lineDelete();
	void circleDraw();
	void pixelDraw();

	void coloring();


	void createWindow(cv::Scalar = cv::Scalar(255, 255, 255));
};