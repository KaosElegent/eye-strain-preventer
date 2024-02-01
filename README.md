
# Eyecare Assistant

Hey there! This repo contains the source code for **Eyecare Assistant**. This project is meant to showcase my ability to use C++ and OpenCV. It is capable of detecting faces and prmpt the user to take frequent breaks from looking at the screen.

# Table of Contents

- [Challanges](https://github.com/KaosElegent/eyecare-assistant/tree/main#challanges)

- [Files](https://github.com/KaosElegent/eyecare-assistant/tree/main#files)

- [What is this?](https://github.com/KaosElegent/eyecare-assistant/tree/main#what-is-this)

- [Notes](https://github.com/KaosElegent/eyecare-assistant/tree/main#notes)

# Challanges
Using OpenCV with C++ was more challanging than I expected at first. Since I use Ubuntu for programming, I had to do the following:
1) Install the required build dependencies:
**cmake, gcc, g++, libavcodec-dev, libavformat-dev, libswscale-dev, libgstreamer-plugins-base1.0-dev, libgstreamer1.0-dev, libgtk-3-dev, libpng-dev, libjpeg-dev, libopenexr-dev, libtiff-dev, libwebp-dev**
2) Download the source code from OpenCV's Repo.
3) Create a 'build' directory and configue the installation with CMake using the default parameters.
4) 'make' and then 'make install' to build the files.

The default directory for installation was '/usr/local/' and the compilation took approximately 60 minutes.
After the installation I had to do the following:

1) Create sym links with the following (for standard #include statements): **ln -s /usr/local/include/opencv4/opencv2/ /usr/local/include/opencv2**
2) Compile the final code using: **g++ -Wall -std=c++11 -o main main.cpp -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lopencv_objdetect -lopencv_core**


# Files

-  src/main.cpp **(Source Code)**
- img/test.jpeg **(Test image)**


# What is this?

- The Eyecare Assistant is meant to combat digital eyestrain caused by users staring at their screens for long periods of time.
- It does so by facial detection and will help reduce Computer Vision Syndrome (CSV) that affects almost 90% of users past the 2-hour mark.
- This software will check for the presence of the user and if it noticies that the user has been present in the last 10 checks without any break, then a system-wide notification (Ubuntu support only right now) is issued to ask the user to take a break.

# Notes

- I've used OpenCV with python before but this is the first time I'm using it with C++.
