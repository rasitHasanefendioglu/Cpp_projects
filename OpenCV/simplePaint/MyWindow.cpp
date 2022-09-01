#include "MyWindow.h"

MyWindow::MyWindow() {

}
void MyWindow:: setSize(int row, int col) {
	size.height = row;
	size.width = col;
}
MyWindow::MyWindow(int row, int col) {
	size.height = row;
	size.width = col;
}
void MyWindow::createWindow(cv::Scalar color ) {
	cv::Mat image(size, CV_8UC3, color);
	cv::namedWindow(winName, 1);
	if (image.empty())
	{
		std::cout << windowWarning;
		return;    // Unsuccessful.
	}
	cv::imshow(winName, image);
	cv::waitKey();
}
/*class MyWindow {
protected:
	cv::Size size;
	cv::Mat image;
public:
	MyWindow();//default constructor
	void setSize(int row,int col) {
		size.height = row;
		size.width = col;
	}
	MyWindow(int row, int col) {

		size.height = row;
		size.width = col;


	}
	virtual void createWindow(cv::Scalar color=cv::Scalar(255, 255, 255)) {
		cv::Mat image(size, CV_8UC3, color);
		cv::namedWindow(winName, 1);
		if (image.empty())
		{
			std::cout << windowWarning;
			return;    // Unsuccessful.
		}
		cv::imshow(winName, image);
		cv::waitKey();
	}


};*/