# About examplesOfOpenCV

A set of example to use OpenCV.

It is a good way to learn OpenCV.

# mans of functions and others

I find that my book is not good for learning OpenCV, It's mix the C API and the C++ API, I thik i must do something.My book is ***Arduino Computer Vision Programming*** by Ozen Ozkaya and Giray Yillikci, translated by Zhang Huadong.

I will do something.

### Mat image;
* From	:	Page 30
* Ref	:	[Mat()](http://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html#af1d014cecd1510cdf580bf2ed7e5aafc)
* Tips	:	*Mat* is a n-dimensional dense array class and *functions* will automaticly allocate the proper constructor.

### imread(argv[1], CV_LOAD_IMAGE_COLOR);
* From	:	Page 30
* Ref	:	[imread()](http://docs.opencv.org/master/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56)
* Tips	:	

    ```c++
    Mat cv::imread(const String & filename, int flags = IMREAD_COLOR)
    ```
* Ref	:	[enum cv::ImreadModes](http://docs.opencv.org/master/d4/da8/group__imgcodecs.html#ga61d9b0126a3e57d9277ac48327799c80)
* Ref	:	[anonymous enum(C API Image file reading and writing)](http://docs.opencv.org/master/da/d0a/group__imgcodecs__c.html#ga7ee8d0f117a79ca7eb1e0076a9182bcb)
