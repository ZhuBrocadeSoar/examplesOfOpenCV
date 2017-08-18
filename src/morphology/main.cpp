/*************************************************************************
	> File Name: ../src/morphology/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Fri 18 Aug 2017 06:00:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

// alias 5 morph types
struct morPhTypeEnumSet{
    int val;
    char alias[5];
} morPhTypes[5] = {
    MORPH_OPEN,
    "OPEN",

    MORPH_CLOSE,
    "CLOS",

    MORPH_GRADIENT,
    "GRAD",

    MORPH_TOPHAT,
    "TOPH",

    MORPH_BLACKHAT,
    "BLAH"
};

// file name for save
char fileNameOut[32];

int main(int argc, char** argv){
    // check argc
    if(argc != 2){
        puts(" Error: Invalid file name");
        puts(" Usage: testsoar <path/to/binary_image>");
        return 1;
    }
    // Mat
    Mat imageSrc, imageOut;
    // read
    imageSrc = imread(argv[1], IMREAD_UNCHANGED);
    // check imageSrc
    if(imageSrc.empty()){
        puts(" Error: Faild to open the image");
        return 2;
    }
    // loop for a set of jpgs
    for(int i = 0; i < 5; i++){
        // diff morph type
        for(int k = 0; k < 3; k++){
            // diff size of kernel
            // morphology
            morphologyEx(imageSrc,
                         imageOut,
                         morPhTypes[i].val,
                         getStructuringElement(MORPH_CROSS,
                                               Size(k * 2 + 3, k * 2 + 3),
                                               Point(-1, -1)
                                              )
                        );
            // save
            sprintf(fileNameOut, "CROSS-%s-KS%d.jpg", morPhTypes[i].alias, k * 2 + 3);
            imwrite(fileNameOut, imageOut);
        }
    }

    return 0;
}

