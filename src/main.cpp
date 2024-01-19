#include "opencv2/opencv.hpp"
#include "iostream"

using namespace std;

int main(int argc, char** argv) {
    cv::VideoCapture cap;
    cv::CascadeClassifier face_cascade;
    
    cap.open(0);
    face_cascade.load("../data/haarcascade_frontalface_default.xml");

    if(!cap.isOpened()){
        cerr << "couldn't open capture." << endl;
        return -1;
    }

    cv::Mat frame;
    vector<cv::Rect> faces;

    while (true){
        cap >> frame;
        if(frame.empty()) break;

        // Detect face
        face_cascade.detectMultiScale(frame,faces);

        // Draw rectangles around faces for demonstration
        for(size_t i = 0; i < faces.size(); ++i){
            cv::rectangle(frame, faces[i], cv::Scalar(255,0,0),2);
        }

        cv::imshow("testing",frame);
        if(cv::waitKey(30) >= 0) break;
    }


    return 0;
}