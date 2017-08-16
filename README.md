# About examplesOfOpenCV

A set of example to use OpenCV.

It is a good way to learn OpenCV.

# Mans of functions and others

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

### VideoCapture cap(CV_CAP_ANY);
* From		:	Page 32
* Include	:	opencv2/videoio.hpp
* Ref		:	[VideoCapture()](http://docs.opencv.org/master/d8/dfe/classcv_1_1VideoCapture.html#a5d5f5dacb77bbebdcbfb341e3d4355c1)

    ```c++
    cv::VideoCapture::VideoCapture(int index)
    ```
* Ref		:	[cv::VideoCaptureAPIs](http://docs.opencv.org/master/d8/dfe/classcv_1_1VideoCapture.html#a5d5f5dacb77bbebdcbfb341e3d4355c1)

### cap >> frame;
* From		:	Page 32
* Include	:	opencv2/videoio.hpp
* Ref		:	[operator>>()](http://docs.opencv.org/master/d8/dfe/classcv_1_1VideoCapture.html#a199844fb74226a28b3ce3a39d1ff6765)
	
    ```c++
    virtual VideoCapture& cv::VideoCapture::operator>> (Mat & image)
    ```
* Ref		:	[read()](http://docs.opencv.org/master/d8/dfe/classcv_1_1VideoCapture.html#a473055e77dd7faa4d26d686226b292c1)

	```c++
    virtual bool cv::VideoCapture::read(OutPutArray image)
    ```

### if(frame.empty()){
* From		:	Page 32
* Include	:	opencv2/core.hpp
* Ref		:	[empty()](http://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html#abbec3525a852e77998aba034813fded4)

    ```c++
    bool cv::Mat::empty()const
    ```
* Tips		:	Returns true if the array has no elements.
    
    The method returns true if Mat::total() is 0 or if Mat::data is NULL. Because of pop\_back() and resize() methods M.total() == 0 does not imply that M.data == NULL. 

### imwrite(argv[1], frame);
* From		:	Page 32
* Include	:	opencv2/imgcodecs.hpp
* Ref		:	[imwrite()](http://docs.opencv.org/master/d4/da8/group__imgcodecs.html#gabbc7ef1aa2edfaa87772f1202d67e0ce)

    ```c++
    bool cv::imwrite(const String & filename, InputArray img, const std::vector< int > & params = std::vector< int >())
    ```
* Ref		:	[enum cv::ImwriteFlags](http://docs.opencv.org/master/d4/da8/group__imgcodecs.html#ga292d81be8d76901bff7988d18d2b42ac)

### GaussianBlur(frameIn, frameOut, Size(7, 7), 1.5, 1.5);
* From		:	Page 50
* Include	:	opencv2/imgproc.hpp
* Ref		:	[GaussianBlur()](http://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#gaabe8c836e97159a9193fb0b11ac52cf1)

    ```c++
    void cv::GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY = 0, int borderType = BORDER_DEFAULT)
    ```
* Ref		:	

    ```c++
    typedef Size2i cv::Size
    ```
* Ref		:

    ```c++
    typedef Size_<int> cv::Size2i
    ```
* Ref		:

    ```c+++
    template<typename _Tp> cv::Size_<_Tp>::Size_(_Tp _width, _Tp _height)
    ```
* Picture	:	

    ![diff](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/smooth.png)
