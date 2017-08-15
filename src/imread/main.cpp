/*************************************************************************
	> File Name: src/imread/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Tue 15 Aug 2017 09:46:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char** argv){
    // check file name
    if(argc != 2){
        puts(" Error: invalid input file\n");
        puts(" Usage: test <path/to/image>\n");
        return -1;
    }

    // def image
    Mat image;

    // read with imread()
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    // check for invalid input
    if(image.data == NULL){
        printf(" Error: faild to open %s\n", argv[1]);
        return -1;
    }

    // edit title of window
    char titleOfWindow[128];
    sprintf(titleOfWindow, "Image-%s", argv[1]);

    // create a window
    namedWindow(titleOfWindow, CV_WINDOW_AUTOSIZE);

    // show the image
    imshow(titleOfWindow, image);

    // wait for keystroke
    waitKey(0);

    // return
    return 0;
}

