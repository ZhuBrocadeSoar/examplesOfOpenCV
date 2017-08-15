/*************************************************************************
	> File Name: ../src/fileter_sharpen/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Wed 16 Aug 2017 04:56:57 AM CST
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
    Mat imageOut2;
    // size of the fileter
    int sizeOfFileter = 3;
    // step of size adding
    int stepOfSize = 2;
    // standard deviation
    int stdDeviation = 1;
    // index of stdDeviation adding
    int indexStdDeviation = 2;
    // alpha
    float alpha = 1.5;
    // step of alpha
    float stepOfAlpha = 1.0;
    // beta
    float beta = -0.5;
    // step of beta
    float stepOfBeta = -1.0;
    // gamma
    float gamma = 0.0;
    // step of gamma
    float stepOfGamma = -0.5;
    // filename set
    char fileNameOut[128];
    for(int i = 0; i < 4; i++){
        gamma = 0.0;
        for(int j = 0; j < 4; j++){
            GaussianBlur(imageIn, imageOut, Size(sizeOfFileter, sizeOfFileter), stdDeviation, stdDeviation);
            addWeighted(imageIn, alpha, imageOut, beta, gamma, imageOut2);
            sprintf(fileNameOut, "size=%d-stdD=%d-a=%.2f-b=%.2f-c=%.2f.jpg", sizeOfFileter, stdDeviation, alpha, beta, gamma);
            imwrite(fileNameOut, imageOut2);

            // step
            gamma += stepOfGamma;
        }
        // step
        alpha += stepOfAlpha;
    }

    return 0;
}

