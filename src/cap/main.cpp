/*************************************************************************
	> File Name: ../src/cap/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Tue 15 Aug 2017 10:21:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char** argv){
    // check file name for saving
    if(argc != 2){
        printf("Error: invaild file name for saving\n");
        return -1;
    }

    // capture obj
    VideoCapture camera(CV_CAP_ANY);
    
    // frame
    Mat frame;

    // loop for video
    while(1){
        // capture
        camera >> frame;

        // show image
        imshow("Press BACKSPACE to take a picture and save it", frame);

        // check the keystroke
        if(waitKey(10) < 10) break;
    }

    // save the picture
    imwrite(argv[1], frame);

    // return 
    return 0;
}

