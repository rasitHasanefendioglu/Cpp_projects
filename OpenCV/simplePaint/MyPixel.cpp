#include "MyPixel.h"

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{

	//commented codes are for debugging purposes. left for further debugging 

	if (event == cv::EVENT_LBUTTONDOWN)
	{
		//std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << "\n";
		//cv::circle(image, cv::Point(x,y), 2, cv::Scalar(0,0,0),5,cv::FILLED);
		center = cv::Point(x, y);
		drawLine = true;
		drawPixel = false;

	}
	else if (event == cv::EVENT_LBUTTONUP) {
		drawLine = false;
		drawPixel = true;
	}
	else if (event == cv::EVENT_RBUTTONDOWN)
	{
		//std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << "\n";
		//cv::circle(image, cv::Point(x,y), 5, cv::Scalar(255, 255, 255), cv::FILLED);
		center = cv::Point(x, y);
		deleteLine = true;
		drawPixel = false;
	}
	else if (event == cv::EVENT_RBUTTONUP) {
		deleteLine = false;
		drawPixel = true;
	}
	else if (event == cv::EVENT_MBUTTONDOWN)
	{
		//std::cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << "\n";
		//cv::circle(image, cv::Point(x, y), 30, cv::Scalar(0, 0, 0), cv::FILLED);
		center = cv::Point(x, y);
		drawCircle = true;
		drawPixel = false;

	}
	else if (event == cv::EVENT_MBUTTONUP) {
		drawCircle = false;
		drawPixel = true;
	}
	else if (event == cv::EVENT_MOUSEMOVE)
	{
		//std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << "\n";

		center = cv::Point(x, y);
	}
}
cv::Scalar MyPixel::pixColor() {
	cv::Scalar color(
		(double)std::rand() / RAND_MAX * 255,
		(double)std::rand() / RAND_MAX * 255,
		(double)std::rand() / RAND_MAX * 255
	);
	return color;
}

void MyPixel::lineDraw() {
	cv::circle(image, center, 5, pixColor(), cv::FILLED);
}
void MyPixel::lineDelete() {
	cv::circle(image, center, 10, windowColor, cv::FILLED);
}
void MyPixel::circleDraw() {

	cv::circle(image, center, 30, pixColor(), cv::FILLED);

}
void MyPixel::pixelDraw() {

	image.at<cv::Vec3b>(center)[0] = (double)std::rand() / RAND_MAX * 255;
	image.at<cv::Vec3b>(center)[1] = (double)std::rand() / RAND_MAX * 255;
	image.at<cv::Vec3b>(center)[2] = (double)std::rand() / RAND_MAX * 255;
}
void MyPixel::coloring() {
	//TODO: change this with switch case
	if (drawLine) {
		lineDraw();
	}
	else if (deleteLine) {
		lineDelete();
	}
	else if (drawCircle) {
		circleDraw();
	}
	else if (drawPixel) {
		pixelDraw();
	}
}

void MyPixel::createWindow(cv::Scalar winColor) {
	windowColor = winColor;
	cv::Mat img(size, CV_8UC3, winColor);
	image = img.clone();
	cv::namedWindow(winName, 1);
	if (image.empty())
	{
		std::cout << windowWarning;
		return;    // Unsuccessful.
	}
	while (true) {
		coloring();
		cv::imshow(winName, image);
		cv::setMouseCallback(winName, CallBackFunc, 0);
		cv::waitKey(1);

	}
}