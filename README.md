# About examplesOfOpenCV

A set of example to use OpenCV.

It is a good way to learn OpenCV.

# mans of functions and others

I find that my book is not good for learning OpenCV, It's mix the C API and the C++ API, I thik i must do something.My book is ***Arduino Computer Vision Programming*** by Ozen Ozkaya and Giray Yillikci, translated by Zhang Huadong.

I will do something.

### Mat image;
* From		:	Page 30
* Include	:	opencv2/core.hpp
* Ref		:	[Mat()](http://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html#af1d014cecd1510cdf580bf2ed7e5aafc)
* Tips		:	*Mat* is a n-dimensional dense array class and *functions* will automaticly allocate the proper constructor.

### imread(argv[1], CV_LOAD_IMAGE_COLOR);
* From		:	Page 30
* Include	:	opencv2/imgcodecs.hpp
* Ref		:	[imread()](http://docs.opencv.org/master/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56)

    ```c++
    Mat cv::imread(const String & filename, int flags = IMREAD_COLOR)
    ```
* Ref		:	[enum cv::ImreadModes](http://docs.opencv.org/master/d4/da8/group__imgcodecs.html#ga61d9b0126a3e57d9277ac48327799c80)
* Ref		:	[anonymous enum(C API Image file reading and writing)](http://docs.opencv.org/master/da/d0a/group__imgcodecs__c.html#ga7ee8d0f117a79ca7eb1e0076a9182bcb)

### if(image.data == NULL){
* From		:	Page 30
* Include	:	opencv2/core.hpp
* Ref		:	

    ```c++
    uchar* cv::Mat::data
    ```
* Tips		:	pointer to the data

### namedWindow("Read Static Image", WINDOW_AUTOSIZE);
* From		:	page 30
* Include	:	opencv2/highgui.hpp
* Ref		:	[namedWindow()](http://docs.opencv.org/master/d7/dfc/group__highgui.html#ga5afdf8410934fd099df85c75b2e0888b)

    ```c++
    void cv::namedWindow(const String & winname, int flags = WINDOW_AUTOSIZE)
    ```
* Ref		:	[WindowFlags](http://docs.opencv.org/master/d7/dfc/group__highgui.html#gabf7d2c5625bc59ac130287f925557ac3)

### imshow("Read Static Image", image);
* From		:	page 30
* Include	:	opencv2/highgui.hpp
* Ref		:	[imshow()](http://docs.opencv.org/master/d7/dfc/group__highgui.html#ga453d42fe4cb60e5723281a89973ee563)

    ```c++
    void cv::imshow(const String & winname, InputArray mat)
    ```
* Tips		:	It will creating a window if the window was not created before this functions

### waitKey(0);
* From		:	Page 30
* Include	:	opencv2/highgui.hpp
* Ref		:	[waitKey()](http://docs.opencv.org/master/d7/dfc/group__highgui.html#ga5628525ad33f52eab17feebcfba38bd7)

    ```c++
    int cv::waitKey(int delay = 0)
    // delay in milliseconds,ms; 0 means "forever"
    ```
* Ref		:	[keyCode?](http://blog.csdn.net/woshinia/article/details/12841797)
