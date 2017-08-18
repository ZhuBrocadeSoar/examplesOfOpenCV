/*************************************************************************
	> File Name: ../src/erode/main.cpp
	> Author: Zhu Brocadesoar
	> Mail: brocadesoar@gmail.com
	> Created Time: Fri 18 Aug 2017 08:01:23 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;

// morphshapes have three
struct morPhShapeEnumSet{
    int Val;
    char name[5];
} morPhShapes[3] = {
    MORPH_RECT,
    "RECT",

    MORPH_CROSS,
    "CROS",

    MORPH_ELLIPSE,
    "ELLI"
};

// file name for save
char fileNameOut[32];

int main(int argc, char** argv){
    // check argc
    if(argc != 2){
        puts(" Error: Invalid file name");
        puts(" Usage: testsoar <path/to/image>");
        return 1;
    }
    // Mat
    Mat imageSrc, imageOut;
    // read
    imageSrc = imread(argv[1], IMREAD_UNCHANGED);
    // check src
    if(imageSrc.empty()){
        puts(" Error: Faild to open the image");
        return 2;
    }
    // loop for different erode
    for(int i = 0; i < 2; i++){
        // diff anchor
        for(int j = 0; j < 3; j++){
            // diff shape
            for(int k = 0; k < 3; k++){
                // diff ksize
                // erode
                erode(imageSrc,
                      imageOut, 
                      getStructuringElement(morPhShapes[j].Val,
                                            Size(k * 2 + 3, k * 2 + 3),
                                            i?Point(k * 2 + 3 - 1, k * 2 + 3 -1):Point(-1, -1)
                                           )
                     );
                // save
                sprintf(fileNameOut, "%d-Pt(%s)%sKS%d.jpg", i, i?"RiDn":"Cent", morPhShapes[j].name, k * 2 + 3);
                imwrite(fileNameOut, imageOut);
            }
        }
    }
    // save gray image
    imwrite("grayimage.jpg", imageSrc);

    return 0;
}

