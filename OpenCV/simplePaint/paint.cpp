#include "MyPixel.h"


int main(int argc, char *argv[]) {

	int row=300, col=300;//for debugging reason I initialize these values
	bool isValidSize = false;
	while (!isValidSize) {
		if (argc == 3) {
			row = std::stoi(argv[0]);
			col = std::stoi(argv[1]);
		}
		else {
			std::cout << "\n" << argWarning << "\n";
			std::cin >> row >> col;
		}
		if (row < 300 || col < 300 || row > 1080 || col>1920) {
			std::cout << sizeWarning;
		}
		else {
			isValidSize = true;
		}
	}
	
	MyPixel obj(row,col);
	obj.createWindow();
	cv::destroyAllWindows();
	return 0;
}
