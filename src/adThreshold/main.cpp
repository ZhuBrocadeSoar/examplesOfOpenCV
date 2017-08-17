/*************************************************************************
	> File Name: ../src/adThreshold/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Thu 17 Aug 2017 05:09:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;

int main(int argc, char** argv){
    // check file name
    if(argc != 2){
        puts(" Error: Invalid file name");
        puts(" Usage: testsoar <path/to/image>");
        return 1;
    }
    // image
    Mat imageSrc,  imageOut;
    // read with grayscale
    imageSrc = imread(argv[1], IMREAD_GRAYSCALE);
    // check image
    if(imageSrc.empty()){
        puts(" Error: Faild to open image");
        return 2;
    }
    // loop for proc
    const int constCVal[7] = {1, 2, 4, 8, 0, -1, -4};
    // filename for save
    char fileNameOut[32];
    for(int i = 0; i < 2; i++){
        // ADAPTIVE_THRESH_MEAN_C
        // ADAPTIVE_THRESH_GAUSSIAN_C
        for(int j = 0; j < 5; j++){
            // C = 1, 2, 4, 0, -1, -4
            // save gray
            sprintf(fileNameOut, "%d-A.jpg", j);
            imwrite(fileNameOut, imageSrc);
            sprintf(fileNameOut, "%d-H.jpg", j);
            imwrite(fileNameOut, imageSrc);
            for(int k = 0; k < 3; k++){
                // blockSize = 3, 5, 7
                // adaptiveThread
                adaptiveThreshold(imageSrc, imageOut, 255, i?ADAPTIVE_THRESH_MEAN_C:ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, k * 2 + 3, constCVal[j]);
                // save out
                if(i){
                    sprintf(fileNameOut, "%d-Mean-Size%dCst%d.jpg", j, k * 2 + 3, constCVal[j]);
                }else{
                    sprintf(fileNameOut, "%d-GAUS-Size%dCst%d.jpg", j, k * 2 + 3, constCVal[j]);
                }
                imwrite(fileNameOut, imageOut);
            }
        }
    }

    return 0;
}

