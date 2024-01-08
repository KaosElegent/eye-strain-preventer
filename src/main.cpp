// CPP program to detects face in a video

// Include required header files from OpenCV directory

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat image;
	image = imread("");
	namedWindow("display", WINDOW_AUTOSIZE);
	imshow("display", image);
	waitkey(0);
	return 0;
}

