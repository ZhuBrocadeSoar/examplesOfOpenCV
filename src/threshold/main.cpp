/*************************************************************************
	> File Name: ../src/threshold/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Thu 17 Aug 2017 03:57:58 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

int main(int argc, char** argv){
    // check for file name
    if(argc != 5){
        puts(" Error: Invalid arguments");
        puts(" Usage: testsoar <path/to/image> <threshold_val> <max_val> <type>");
        puts("        threshold_val ranger in 0-255");
        puts("        max_val ranger in 0-255 and must grater than threshold_val");
        puts("        type:");
        puts("            1 - BINARY");
        puts("            2 - BINARY_INV");
        puts("            3 - TRUNC");
        puts("            4 - TOZERO");
        puts("            5 - TOZERO_INV");
    }
    // create images
    Mat imageSrc, imageGray, imageThreshold;
    // read img
    imageSrc = imread(argv[1], IMREAD_COLOR);
    // check img
    if(imageSrc.empty()){
        puts(" Error: Faild to open image");
        return -1;
    }
    // convert to gray
    cvtColor(imageSrc, imageGray, COLOR_RGB2GRAY);
    // get other arg 
    int thVal, maxVal, thType;
    sscanf(argv[2], "%d", &thVal);
    sscanf(argv[3], "%d", &maxVal);
    sscanf(argv[4], "%d", &thType);
    // check arguments
    bool argOk = 1;
    if(thVal < 0 || thVal > 255) argOk = 0;
    if(maxVal < 0 || maxVal > 255) argOk = 0;
    if(maxVal < thVal) argOk = 0;
    if(thType < 1 || thType > 5) argOk = 0;
    if(!argOk){
        puts("Error: Invalid arguments, enter testsoar only for help");
        return -2;
    }
    // filename for save
    char fileNameOut[128];
    // translate thType to sys-enum
    int sysEnum;
    char sysEnumName[5][16]={
        "BINARY",
        "BINARY_INV",
        "TRUNC",
        "TOZERO",
        "TOZERO_INV"
    };
    switch(thType){
        case 1:
            sysEnum = THRESH_BINARY;
            break;
        case 2:
            sysEnum = THRESH_BINARY_INV;
            break;
        case 3:
            sysEnum = THRESH_TRUNC;
            break;
        case 4:
            sysEnum = THRESH_TOZERO;
            break;
        case 5:
            sysEnum = THRESH_TOZERO_INV;
        default:
            break;
    }
    // threshold 
    threshold(imageGray, imageThreshold, thVal, maxVal, sysEnum);
    // assamble a file name for save
    sprintf(fileNameOut, "%d-thV%d-maxV%d-Type%s.jpg", thType, thVal, maxVal, sysEnumName[thType - 1]);
    // save image
    imwrite(fileNameOut, imageThreshold);

    return 0;
}

