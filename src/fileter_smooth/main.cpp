/*************************************************************************
	> File Name: ../src/fileter_smooth/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Wed 16 Aug 2017 02:36:35 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(int argc, char** argv){
    // check file name
    if(argc != 2){
        puts(" Error: Invalid file name");
        puts(" Usage: testsoar <path/to/img>");
    }
    // read a img
    Mat imageIn;
    imageIn = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat imageOut;
    // size of the fileter
    int sizeOfFileter = 3;
    // step of size adding
    int stepOfSize = 2;
    // standard deviation
    int stdDeviation = 1;
    // index of stdDeviation adding
    int indexStdDeviation = 2;
    // filename set
    char fileNameOut[128];
    for(int i = 0; i < 4; i++){
        stdDeviation = 1;
        for(int j = 0; j < 4; j++){
            GaussianBlur(imageIn, imageOut, Size(sizeOfFileter, sizeOfFileter), stdDeviation, stdDeviation);
            sprintf(fileNameOut, "%s-size=%d-stdD=%d.jpg", argv[1], sizeOfFileter, stdDeviation);
            imwrite(fileNameOut, imageOut);

            // index
            stdDeviation *= indexStdDeviation;
        }
        // step
        sizeOfFileter += stepOfSize;
    }

    return 0;
}

