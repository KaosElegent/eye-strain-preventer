#include <stdlib.h>  // To notify the user
#include <unistd.h> // To put the program to sleep
#include <iostream> // For console debugging
#include "opencv2/opencv.hpp" // To detect the user


using namespace std;

int main(int argc, char** argv) {
    system("notify-send ['EyeCare Assistant'] 'Look away from your screen!'");
    cv::VideoCapture cap;
    cv::CascadeClassifier face_cascade;
    face_cascade.load("../data/haarcascade_frontalface_default.xml");

    cv::Mat frame;
    vector<cv::Rect> faces;

    while (true){

        cap.open(0);
        if(!cap.isOpened()){
            cerr << "couldn't open capture." << endl;
            return -1;
        }

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
        cap.release();
        sleep(30);
    }


    return 0;
}