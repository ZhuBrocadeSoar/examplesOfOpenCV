/*************************************************************************
	> File Name: ../src/canny/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Fri 18 Aug 2017 10:21:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

int main(int argc, char** argv){
    // check file name 
    if(argc != 2){
        puts(" Error: Invalid file name");
        puts(" Usage: testsoar <path/to/color_image>");
        return 1;
    }
    // Mat
    Mat imageSrc, imageGauss, imageGray, imageEdges;
    imageSrc = imread(argv[1], IMREAD_COLOR);
    // GaussianBlur
    GaussianBlur(imageSrc, imageGauss, Size(3, 3), 0, 0);
    // convert to gray
    cvtColor(imageGauss, imageGray, COLOR_RGB2GRAY);

    return 0;
}

