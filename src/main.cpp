#include "opencv2/opencv.hpp"
#include "iostream"

using namespace std;

int main(int argc, char** argv) {
    cv::namedWindow("testing", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;

    cap.open(0);

    if(!cap.isOpened()){
        cerr << "couldn't open capture." << endl;
        return -1;
    }

    cv::Mat frame;

    while (true){
        cap >> frame;
        if(frame.empty()) break;

        cv::imshow("testing",frame);
        if(cv::waitKey(30) >= 0) break;
    }


    return 0;
}