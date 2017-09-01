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

// Mat
Mat imageSrc, imageGauss, imageGray, imageEdges;

// window names
char wdowNameSrc[] = "原图像";
char wdowNameGauss[] = "高斯模糊";
char wdowNameGray[] = "灰度图像";
char wdowNameEdges[] = "边缘图像";
char wdowNameCtrl[] = "控制面板";

// Kernel Size Height
// kSizeW = 0,3,5,7...41
// kSizeWCt = 0,1,2,3...20
// kSizeW = kSizeWCt * 2 + kSizeWCt?1:0;
int kSizeWCt = 1;
int kSizeW(void){
    return kSizeWCt * 2 + (kSizeWCt?1:0);
}
char tBNameKSizeWCt[] = "Kernel Size Width Count(map to 0,3,5,7...)";
void tBCallKSizeWCt(int, void*);
void tBInitKSizeWCt(void){
    kSizeWCt = 1;
    setTrackbarPos(tBNameKSizeWCt, wdowNameCtrl, kSizeWCt);
    return ;
}

// Kernel Size Height
// kSizeH = 0,3,5,7...41
// kSizeHCt = 0,1,2,3...20
// kSizeH = kSizeHCt * 2 + kSizeHCt?1:0;
int kSizeHCt = 1;
int kSizeH(void){
    return kSizeHCt * 2 + (kSizeHCt?1:0);
}
char tBNameKSizeHCt[] = "Kernel Size Height Count(map to 0,3,5,7...)";
void tBCallKSizeHCt(int, void*);
void tBInitKSizeHCt(void){
    kSizeHCt = 1;
    setTrackbarPos(tBNameKSizeHCt, wdowNameCtrl, kSizeHCt);
    return ;
}

// max of kSizeCt
const int kSizeCtMax = 20;

// Standard Deviation X
// sDeviX = 0~20
// sDeviXCt = 0,1,2,3...200
// sDeviX = (double)sDeviXCt / 10.0;
int sDeviXCt = 1;
double sDeviX(void){
    return (double)sDeviXCt / 10.0;
}
char tBNameSDeviXCt[] = "Standard Deviation X Count(map to 0~20.0)";
void tBCallSDeviXCt(int, void*);
void tBInitSDeviXCt(void){
    sDeviXCt = 1;
    setTrackbarPos(tBNameSDeviXCt, wdowNameCtrl, sDeviXCt);
    return ;
}

// Standard Deviation Y
// sDeviY = 0~20
// sDeviYCt = 0,1,2,3...200
// sDeviY = (double)sDeviYCt / 10.0;
int sDeviYCt = 1;
double sDeviY(void){
    return (double)sDeviYCt / 10.0;
}
char tBNameSDeviYCt[] = "Standard Deviation Y Count(map to 0~20.0)";
void tBCallSDeviYCt(int, void*);
void tBInitSdeviYCt(void){
    sDeviYCt = 1;
    setTrackbarPos(tBNameSDeviYCt, wdowNameCtrl, sDeviYCt);
    return ;
}

// max of sDeviCt
const int sDeviCtMax = 200;

// Threshold 1
// thd1 = 0,1,2,3...256
// thd1Ct = 0,1,2,3...256
// thd1 = thd1Ct;
int thd1Ct = 128;
int thd1(void){
    return thd1Ct;
}
char tBNameThd1Ct[] = "Threshold 1 Count(map to 0,1,2,3...256)";
void tBCallThd1Ct(int, void*);
void tBInitThd1Ct(void){
    thd1Ct = 128;
    setTrackbarPos(tBNameThd1Ct, wdowNameCtrl, thd1Ct);
    return ;
}

// Threshold 2
// thd2 = 0,1,2,3...256
// thd2Ct = 0,1,2,3...256
// thd2 = thd2Ct;
int thd2Ct = 256;
int thd2(void){
    return thd2Ct;
}
char tBNameThd2Ct[] = "Threshold 2 Count(map to 0,1,2,3...256)";
void tBCallThd2Ct(int, void*);
void tBInitThd2Ct(void){
    thd2Ct = 256;
    setTrackbarPos(tBNameThd2Ct, wdowNameCtrl, thd2Ct);
    return ;
}

// max of thdCt
const int thdCtMax = 256;

// Aperture Size
// apeSize = 3,5,7
// apeSizeCt = 0,1,2
// apeSize = (apeSizeCt + 1) * 2 + 1;
int apeSizeCt = 0;
int apeSize(void){
    return (apeSizeCt + 1) * 2 + 1;
}
char tBNameApeSizeCt[] = "Aperture Size Count(map to 3,5,7)";
void tBCallApeSizeCt(int, void*);
void tBInitApeSizeCt(void){
    apeSizeCt = 0;
    setTrackbarPos(tBNameApeSizeCt, wdowNameCtrl, apeSizeCt);
    return ;
}

// max of apeSizeCt
const int apeSizeCtMax = 2;

bool isInvalid(void){
    if(kSizeW() == 0 || kSizeH() == 0){
        if(sDeviX() != 0 && sDeviY() != 0){
            return false;
        }
        return true;
    }
    if(sDeviY() == 0){
        if(sDeviX != 0){
            return false;
        }
        return true;
    }
    return false;
}

void runCanny(void);
void showImage(void);

int main(int argc, char** argv){
    // check file name 
    if(argc != 2){
        puts(" Error: Invalid file name");
        puts(" Usage: testsoar <path/to/color_image>");
        return 1;
    }
    imageSrc = imread(argv[1], IMREAD_COLOR);
    // check image
    if(imageSrc.empty()){
        puts(" Error: Could not open image");
        return 2;
    }
    // Create Windows
    namedWindow(wdowNameSrc);
    namedWindow(wdowNameGauss);
    namedWindow(wdowNameGray);
    namedWindow(wdowNameEdges);
    namedWindow(wdowNameCtrl);
    // Create Trackbar
    createTrackbar(tBNameKSizeWCt, wdowNameCtrl, &kSizeWCt, kSizeCtMax, tBCallKSizeWCt);
    tBInitKSizeWCt();
    createTrackbar(tBNameKSizeHCt, wdowNameCtrl, &kSizeHCt, kSizeCtMax, tBCallKSizeHCt);
    tBInitKSizeHCt();
    createTrackbar(tBNameSDeviXCt, wdowNameCtrl, &sDeviXCt, sDeviCtMax, tBCallSDeviXCt);
    tBInitSDeviXCt();
    createTrackbar(tBNameSDeviYCt, wdowNameCtrl, &sDeviYCt, sDeviCtMax, tBCallSDeviYCt);
    tBInitSdeviYCt();
    createTrackbar(tBNameThd1Ct, wdowNameCtrl, &thd1Ct, thdCtMax, tBCallThd1Ct);
    tBInitThd1Ct();
    createTrackbar(tBNameThd2Ct, wdowNameCtrl, &thd2Ct, thdCtMax, tBCallThd2Ct);
    tBInitThd2Ct();
    createTrackbar(tBNameApeSizeCt, wdowNameCtrl, &apeSizeCt, apeSizeCtMax, tBCallApeSizeCt);
    tBInitApeSizeCt();
    while(1){
        if(waitKey(10) == 27) break;
    }

    return 0;
}

void tBCallKSizeWCt(int, void*){
//    if(isInvalid()){
//        kSizeWCt = 1;
//        setTrackbarPos(tBNameKSizeWCt, wdowNameCtrl, 1);
//    }
    runCanny();
    showImage();
    return ;
}

void tBCallKSizeHCt(int, void*){
//    if(isInvalid()){
//        kSizeHCt = 1;
//        setTrackbarPos(tBNameKSizeHCt, wdowNameCtrl, 1);
//    }
    runCanny();
    showImage();
    return ;
}

void tBCallSDeviXCt(int, void*){
//    if(isInvalid()){
//        sDeviXCt = 1;
//        setTrackbarPos(tBNameSDeviXCt, wdowNameCtrl, 1);
//    }
    runCanny();
    showImage();
    return ;
}

void tBCallSDeviYCt(int, void*){
//    if(isInvalid()){
//        sDeviXCt = 1;
//        setTrackbarPos(tBNameSDeviYCt, wdowNameCtrl, 1);
//    }
    runCanny();
    showImage();
    return ;
}

void tBCallThd1Ct(int, void*){
    // 
    runCanny();
    showImage();
    return ;
}

void tBCallThd2Ct(int, void*){
    // 
    runCanny();
    showImage();
    return ;
}

void tBCallApeSizeCt(int, void*){
    // 
    runCanny();
    showImage();
    return ;
}

void runCanny(void){
    GaussianBlur(imageSrc, imageGauss, Size(kSizeW(), kSizeH()), sDeviX(), sDeviY());
    cvtColor(imageGauss, imageGray, COLOR_RGB2GRAY);
    Canny(imageGray, imageEdges, thd1(), thd2(), apeSize());
    return ;
}

void showImage(void){
    imshow(wdowNameSrc, imageSrc);
    imshow(wdowNameGauss, imageGauss);
    imshow(wdowNameGray, imageGray);
    imshow(wdowNameEdges, imageEdges);
    return ;
}

