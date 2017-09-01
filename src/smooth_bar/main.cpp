/*************************************************************************
	> File Name: ../src/smooth_bar/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Fri 25 Aug 2017 07:58:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

char windowName[] = "平滑效果对比";
char trackBarNameKRad[] = "Kernel Radius";
int kRadCount = 0;
// kSize = kRadCount?(kRadCount * 2 + 1):0;
// kRadCount <= 20;
char trackBarNameStdDev[] = "Stdandard Deviation x 10";
int stdDevCount = 0;
// stdDev = (float)stdDev / 10.0;
// stdDev <= 20.0
// 创建图像变量
Mat imageRGB, imageOut;

void trackBarCallbackKRad(int, void*);
void trackBarCallbackStdDev(int, void*);

int main(int argc, char** argv){
    // 检查参数
    if(argc != 2){
        puts(" Error: Invalid filename");
        puts(" Usage: testsoar <path/to/image>");
        return 1;
    }
    imageRGB = imread(argv[1], IMREAD_COLOR);
    // 检查图像读入
    if(imageRGB.empty()){
        puts(" Error: Could not open the image");
        return 2;
    }
    // 创建窗口
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, imageRGB);
    namedWindow("原图", WINDOW_AUTOSIZE);
    imshow("原图", imageRGB);
    // 创建滚动条
    createTrackbar(trackBarNameKRad, windowName, &kRadCount, 20, trackBarCallbackKRad);
    createTrackbar(trackBarNameStdDev, windowName, &stdDevCount, 200, trackBarCallbackStdDev);
    while(1){
        if(waitKey(10) == 27) break;
    }
    return 0;
}

void trackBarCallbackKRad(int, void*){
    if(stdDevCount == 0 && kRadCount == 0){
        kRadCount = 1;
    }
    GaussianBlur(imageRGB, imageOut, Size(kRadCount?(kRadCount * 2 + 1):0,kRadCount?(kRadCount * 2 + 1):0), (float)stdDevCount / 10.0, (float)stdDevCount / 10.0);
    imshow(windowName, imageOut);
    return ;
}

void trackBarCallbackStdDev(int, void*){
    if(kRadCount == 0 && stdDevCount == 0){
        stdDevCount = 1;
    }
    GaussianBlur(imageRGB, imageOut, Size(kRadCount?(kRadCount * 2 + 1):0,kRadCount?(kRadCount * 2 + 1):0), (float)stdDevCount / 10.0, (float)stdDevCount / 10.0);
    imshow(windowName, imageOut);
    return ;
}

