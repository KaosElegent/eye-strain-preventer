#include <stdlib.h>  // To notify the user
#include <unistd.h> // To put the program to sleep
#include <iostream> // For console debugging
#include "opencv2/opencv.hpp" // To detect the user


using namespace std;

int main(int argc, char** argv) {
    int observation{};
    system("notify-send ['EyeCare Assistant'] Activated'");
    cv::VideoCapture cap;
    cv::CascadeClassifier face_cascade;
    face_cascade.load("../data/haarcascade_frontalface_default.xml");

    cv::Mat frame;
    vector<cv::Rect> faces;

    while (true){

        cap.open(0);
        if(!cap.isOpened()){
            cerr << "couldn't open capture." << endl;
            sleep(600);
        }

        cap >> frame;
        if(frame.empty()) break;

        // Detect face
        face_cascade.detectMultiScale(frame,faces);

        if (faces.size()) observation++;
        else observation=0;

        if(observation==10){
            system("notify-send ['EyeCare Assistant'] 'Look away from your screen!'");
            observation=0;
        }

        cap.release();
        sleep(3000);
    }


    return 0;
}