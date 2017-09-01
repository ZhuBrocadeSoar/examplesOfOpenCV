/*************************************************************************
	> File Name: ../src/sharpen_bar/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Fri 25 Aug 2017 08:56:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

// Mat
Mat imageRGB, imageBlurred, imageOut;

// Window name
char windowNameImgSrc[] = "原图";
char windowNameImgBlurred[] = "高斯模糊";
char windowNameImgSharpened[] = "锐化";
char windowNameCtrlBar[] = "效果控制器";

// Kernel Sixe Width
// kSize.width = kRadWidthCount?(kRadWidthCount * 2 + 1):0;
// kRadWidthCount 0~20
int kRadWidthCount = 1;
char tBNKRadWidthCount[] = "Kernel Size(Radius).width";
void tBCKRadWidthCount(int, void*);
int kRadWidth(void){
    return kRadWidthCount?(kRadWidthCount * 2 + 1):0;
}

// Kernel Size Height
// kSize.height = kRadHeightCount?(kRadHeightCount * 2 + 1):0;
// kRadHeightCount 0~20
int kRadHeightCount = 1;
char tBNKRadHeightCount[] = "Kernel Size(Radius).height";
void tBCKRadHeightCount(int, void*);
int kRadHeight(void){
    return kRadHeightCount?(kRadHeightCount * 2 + 1):0;
}

// Stdandard Deviation X
// sigmaX = (float)sigmaXCount / 10.0;
// sigmaXCount 0~200
int sigmaXCount = 1;
char tBNSigmaXCount[] = "Stdandard Deviation(Sigma).X x 10";
void tBCSigmaXCount(int, void*);
double sigmaX(void){
    return (double)sigmaXCount / 10.0;
}

// Stdandard Deviation Y
// sigmaY = (float)sigmaYCount / 10.0;
// sigmaYCount 0~200
int sigmaYCount = 1;
char tBNSigmaYCount[] = "Stdandard Deviation(Sigma).Y x 10";
void tBCSigmaYCount(int, void*);
double sigmaY(void){
    return (double)sigmaYCount / 10.0;
}

// Add Weight Alpha
// alpha = (float)(alphaCount - 50) / 10.0
// alphaCount 0~100
int alphaCount = 50;
char tBNAlphaCount[] = "Add Weight Alpha x 10 + 50";
void tBCAlphaCount(int, void*);
double alpha(void){
    return (double)(alphaCount - 50) / 10.0;
}

// Add Weight Beta
// beta = (float)(betaCount - 5o) / 10.0
// betaCount 0~100
int betaCount = 50;
char tBNBetaCount[] = "Add Weight Beta x 10 + 50";
void tBCBetaCount(int, void*);
double beta(void){
    return (double)(betaCount - 50) / 10.0;
}

// Add Weight Gamma
// gamma = (float)(gammaCount - 50) / 10.0
// gammaCount 0~100
int gammaCount = 50;
char tBNGammaCount[] = "Add Weight Gamma x 10 + 50";
void tBCGammaCount(int, void*);
double gamma(void){
    return (double)(gammaCount - 50) / 10.0;
}

// 检查参数冲突并修正
bool noArgsErr(void){
    if(kRadWidth() == 0 || kRadHeight() == 0){
        if(sigmaX() != 0 && sigmaY() != 0){
            return true;
        }
        return false;
    }
    if(sigmaY() == 0){
        if(sigmaX != 0){
            return true;
        }
        return false;
    }
    return true;
}

int main(int argc, char** argv){
    // check filename
    if(argc != 2){
        puts(" Error: Invalid filename");
        puts(" Usage: testsoar <path/to/image>");
        return 1;
    }
    imageRGB = imread(argv[1], IMREAD_COLOR);
    namedWindow(windowNameImgSrc, WINDOW_AUTOSIZE);
    namedWindow(windowNameImgBlurred, WINDOW_AUTOSIZE);
    namedWindow(windowNameImgSharpened, WINDOW_AUTOSIZE);
    namedWindow(windowNameCtrlBar, WINDOW_AUTOSIZE);
    createTrackbar(
            tBNKRadWidthCount,
            windowNameCtrlBar,
            &kRadWidthCount,
            20,
            tBCKRadWidthCount);
    createTrackbar(
            tBNKRadHeightCount,
            windowNameCtrlBar,
            &kRadHeightCount,
            20,
            tBCKRadHeightCount);
    createTrackbar(
            tBNSigmaXCount,
            windowNameCtrlBar,
            &sigmaXCount,
            200,
            tBCSigmaXCount);
    createTrackbar(
            tBNSigmaYCount,
            windowNameCtrlBar,
            &sigmaYCount,
            200,
            tBCSigmaYCount);
    createTrackbar(
            tBNAlphaCount,
            windowNameCtrlBar,
            &alphaCount,
            100,
            tBCAlphaCount);
    createTrackbar(
            tBNBetaCount,
            windowNameCtrlBar,
            &betaCount,
            100,
            tBCBetaCount);
    createTrackbar(
            tBNGammaCount,
            windowNameCtrlBar,
            &gammaCount,
            100,
            tBCGammaCount);
    setTrackbarPos(tBNKRadWidthCount, windowNameCtrlBar, 1);
    setTrackbarPos(tBNKRadHeightCount, windowNameCtrlBar, 1);
    setTrackbarPos(tBNSigmaXCount, windowNameCtrlBar, 1);
    setTrackbarPos(tBNSigmaYCount, windowNameCtrlBar, 1);
    setTrackbarPos(tBNAlphaCount, windowNameCtrlBar, 50);
    setTrackbarPos(tBNBetaCount, windowNameCtrlBar, 50);
    setTrackbarPos(tBNGammaCount, windowNameCtrlBar, 50);
    while(1){
        if(waitKey(10) == 27) break;
    }
    return 0;
}

void tBCKRadWidthCount(int, void*){
    if(!noArgsErr()){
        setTrackbarPos(tBNKRadWidthCount, windowNameCtrlBar, 1);
        kRadWidthCount = 1;
    }
    imshow(windowNameImgSrc, imageRGB);
    GaussianBlur(imageRGB, imageBlurred, Size(kRadWidth(), kRadHeight()), sigmaX(), sigmaY());
    imshow(windowNameImgBlurred, imageBlurred);
    addWeighted(imageRGB, alpha(), imageBlurred, beta(), gamma(), imageOut);
    imshow(windowNameImgSharpened, imageOut);
    return ;
}

void tBCKRadHeightCount(int, void*){
    if(!noArgsErr()){
        setTrackbarPos(tBNKRadHeightCount, windowNameCtrlBar, 1);
        kRadHeightCount = 1;
    }
    imshow(windowNameImgSrc, imageRGB);
    GaussianBlur(imageRGB, imageBlurred, Size(kRadWidth(), kRadHeight()), sigmaX(), sigmaY());
    imshow(windowNameImgBlurred, imageBlurred);
    addWeighted(imageRGB, alpha(), imageBlurred, beta(), gamma(), imageOut);
    imshow(windowNameImgSharpened, imageOut);
    return ;
}

void tBCSigmaXCount(int, void*){
    if(!noArgsErr()){
        setTrackbarPos(tBNSigmaXCount, windowNameCtrlBar, 1);
        sigmaXCount = 1;
    }
    imshow(windowNameImgSrc, imageRGB);
    GaussianBlur(imageRGB, imageBlurred, Size(kRadWidth(), kRadHeight()), sigmaX(), sigmaY());
    imshow(windowNameImgBlurred, imageBlurred);
    addWeighted(imageRGB, alpha(), imageBlurred, beta(), gamma(), imageOut);
    imshow(windowNameImgSharpened, imageOut);
    return ;
}

void tBCSigmaYCount(int, void*){
    if(!noArgsErr()){
        setTrackbarPos(tBNSigmaYCount, windowNameCtrlBar, 1);
        sigmaYCount = 1;
    }
    imshow(windowNameImgSrc, imageRGB);
    GaussianBlur(imageRGB, imageBlurred, Size(kRadWidth(), kRadHeight()), sigmaX(), sigmaY());
    imshow(windowNameImgBlurred, imageBlurred);
    addWeighted(imageRGB, alpha(), imageBlurred, beta(), gamma(), imageOut);
    imshow(windowNameImgSharpened, imageOut);
    return ;
}

void tBCAlphaCount(int, void*){
    imshow(windowNameImgSrc, imageRGB);
    GaussianBlur(imageRGB, imageBlurred, Size(kRadWidth(), kRadHeight()), sigmaX(), sigmaY());
    imshow(windowNameImgBlurred, imageBlurred);
    addWeighted(imageRGB, alpha(), imageBlurred, beta(), gamma(), imageOut);
    imshow(windowNameImgSharpened, imageOut);
    return ;
}

void tBCBetaCount(int, void*){
    imshow(windowNameImgSrc, imageRGB);
    GaussianBlur(imageRGB, imageBlurred, Size(kRadWidth(), kRadHeight()), sigmaX(), sigmaY());
    imshow(windowNameImgBlurred, imageBlurred);
    addWeighted(imageRGB, alpha(), imageBlurred, beta(), gamma(), imageOut);
    imshow(windowNameImgSharpened, imageOut);
    return ;
}

void tBCGammaCount(int, void*){
    imshow(windowNameImgSrc, imageRGB);
    GaussianBlur(imageRGB, imageBlurred, Size(kRadWidth(), kRadHeight()), sigmaX(), sigmaY());
    imshow(windowNameImgBlurred, imageBlurred);
    addWeighted(imageRGB, alpha(), imageBlurred, beta(), gamma(), imageOut);
    imshow(windowNameImgSharpened, imageOut);
    return ;
}

