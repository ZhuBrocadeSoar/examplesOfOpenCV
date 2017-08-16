/*************************************************************************
	> File Name: ../src/cvt_color/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Wed 16 Aug 2017 04:35:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

int main(int argc, char** argv){
    // check for filename
    if(argc != 2){
        puts(" Error: Invalid filename!");
        puts(" Usage: testsoar <path/to/image>");
    }
    // create soar image arraies
    Mat imageIn, imageOut;
    // read a image
    imageIn = imread(argv[1], IMREAD_COLOR);
    // convert to HSV, COLOR_RGB2HSV
    cvtColor(imageIn, imageOut, COLOR_RGB2HSV);
    // save
    char fileNameOut[128];
    sprintf(fileNameOut, "%s-RGB2HSV.jpg", argv[1]);
    imwrite(fileNameOut, imageOut);
    // convert to GRAY, COLOR_RGB2GRAY
    cvtColor(imageIn, imageOut, COLOR_RGB2GRAY);
    // save
    sprintf(fileNameOut, "%s-RGB2GRAY.jpg", argv[1]);
    imwrite(fileNameOut, imageOut);

    return 0;
}

