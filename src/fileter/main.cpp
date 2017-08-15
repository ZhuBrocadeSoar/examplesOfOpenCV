/*************************************************************************
	> File Name: ../src/fileter/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Tue 15 Aug 2017 11:10:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char** argv){
    // cli user interface
    // which fileter
    char charInFileter;
    // size of a fileter
    int sizeInFileter;
    // standard deviation
    float sigmaXIn, sigmaYIn;
    // file name
    char fileNameIn[128];
    // frames
    Mat frameIn, frameBlurred, frameOut;
    while(1){
        puts("This is a demo of fileter");
        puts("Step 1,Select a fileter or exit:");
        puts(" 1) smooth");
        puts(" 2) sharpen");
        puts(" 3) exit");
        printf("Your Select:");
        scanf("%c", &charInFileter);
        cin.clear();
        if(charInFileter == '1' || charInFileter == '2'){
            // process smooth fileter
            // get size
            puts("Step 2,Enter a integer for fileter's size:");
            printf("Your size:");
            scanf("%d", &sizeInFileter);
            cin.clear();
            if(sizeInFileter < 3 || sizeInFileter % 2 == 0){
                // invalid size
                puts("Invalid size");
                continue;
            }else{
                // get standard deviation
                puts("Step 3,Enter two float numbers for X's&Y's standard deviation,devided by comma(,):");
                printf("Your float numbers:");
                scanf("%f,%f", &sigmaXIn, &sigmaYIn);
                cin.clear();
                // get image file name
                puts("Step 4,Enter the file name of the image");
                printf("Your file:");
                scanf("%s", &fileNameIn);
                cin.clear();
                // read the image
                frameIn = imread(fileNameIn, CV_LOAD_IMAGE_COLOR);
                if(charInFileter == '1'){
                    // GaussianBlur
                    GaussianBlur(frameIn, frameBlurred, Size(sizeInFileter, sizeInFileter), sigmaXIn, sigmaYIn);
                    // show image
                    char titleName[128];
                    sprintf(titleName, "Smooth, Size - (%d, %d), sigmaX - %f, sigmaY - %f, file - %s", sizeInFileter, sizeInFileter, sigmaXIn, sigmaYIn, fileNameIn);
                    // show the image
                    imshow(titleName, frameBlurred);
                    // wait ESC key keycode = 27
                    do{
                        if(waitKey(0) == 27){
                            break;
                        }
                    }while(1);
                }
                if(charInFileter == '2'){
                    // get 
                }
            }
        }else if(charInFileter == '3'){
            // exit
            break;
        }else{
            // invalid select
            puts("Invalid select");
            continue;
        }
    }

    // return
    return 0;
}

