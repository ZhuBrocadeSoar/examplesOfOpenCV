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
    virtual bool cv::VideoCapture::read(OutputArray image)
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

    ![smooth](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/smooth.png)

### addWeighted(frameIn, 1.5, frameBlurred, -0.5, 0, frameOut);
* From		:	Page 51
* Include	:	opencv2/core.hpp
* Ref		:	[addWeighted()](http://docs.opencv.org/master/d2/de8/group__core__array.html#gafafb2513349db3bcff51f54ee5592a19)

	```c++
    void cv::addWeighted(InputArray src1, double alpha, InputArray src2, double beta, double gamma, OutputArray dst, int dtype = -1)
    ```

* Pictures	:
    ![sharpen1](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/sharpen1.png)
    ![sharpen1](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/sharpen2.png)
    ![sharpen1](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/sharpen3.png)

### cvtColor(frameIn, frameInGray, CV_BGR2GRAY);
* From		:	Page 52
* Include	:	opencv2/imgproc.hpp
* Ref		:	[cvtColor()](http://docs.opencv.org/master/d7/d1b/group__imgproc__misc.html#ga397ae87e1288a81d2363b61574eb8cab)

	```c++
    void cv::cvtColor(InputArray src, OutputArray dst, int code, int dstCn = 0)
    ```
* Ref		:	[ColorConversionCode](http://docs.opencv.org/master/d7/d1b/group__imgproc__misc.html#ga4e0972be5de079fed4e3a10e24ef5ef0)

* Pictures	:
    ![cvt_color](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/cvt_color.png)

### threshold(frameInGray, frameInBinary, threshold_value, max_BINARY_value, threshold_type);
* From		:	Page 53
* Include	:	opencv2/imgproc.hpp
* Ref		:	[threshold()](http://docs.opencv.org/master/d7/d1b/group__imgproc__misc.html#gae8a4a146d1ca78c626a53577199e9c57)

	```c++
    double cv::threshold(InputArray src, OutputArray dst, double thresh, double maxval, int type)
    ```
* Pictures	:
    ![threshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/threshold.png)

### adaptiveThreshold(frameInGray, frameOut, MAX_BINARY_VALUE, ADAPTIVE_METHOD, THRESHOLD_TYPE, block_size, ADAPTIVE_CONSTANT);
* From		:	Page 54
* Include	:	opencv2/imgproc.hpp	
* Ref		:	[adaptiveThreshold()](http://docs.opencv.org/master/d7/d1b/group__imgproc__misc.html#ga72b913f352e4a1b1b397736707afcde3)

	```c++
    void cv::adaptiveThreshold(InputArray src, OutputArray dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C)
    ```	
* Pictures	:
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/adThreshold.png)
    ![adThreshold_INV](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/adThresholdINV.png)

### erode(frameInBinary, frameOut, kernel);
* From		:	Page 55	
* Include	:	opencv2/imgproc.hpp	
* Ref		:	[erode()](http://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#gaeb1e0c1033e3f6b891a25d0511362aeb)

	```c++
    void cv::erode(InputArray src, OutputArray dst, InputArray kernel, Point anchor = Point(-1, -1), int iterations = 1, int borderType = BORDER_CONSTANT, const Scalar & borderValue = morphologyDefaultBorderValue() )
    ```	
* Ref		:	[erode(src, dst, element);](http://docs.opencv.org/master/d8/dc0/morphology2_8cpp-example.html#a9)

	```c++
    Mat element = getStructuringElement(element_shape, Size(an * 2 + 1, an * 2 +1), Point(an, an));
    ```	
* Ref		:	[getStructuringElement()](http://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#gac342a1bb6eabf6f55c803b09268e36dc)

	```c++
    Mat cv::getStructuringElement(int shape, Size ksize, Point anchor = Point(-1, -1))
    ```	
* Tips		:	Note that only the shape of a cross-shaped element depends on the anchor position. In other casses the anchor just regulates how much the result of the morphological operation is shifted.

* Ref		:	[MorphShapes](http://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#gac2db39b56866583a95a5680313c314ad)

* Pictures	:
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/erode.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/erode1.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/erode2.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/erode3.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/erode4.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/erode5.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/erode6.png)

### dilate(frameInBinary, frameOut, kernel);
* From		:	Page 56	
* Ref		:	[dilate()](http://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#ga4ff0f3318642c4f469d0e11f242f3b6c)

	```c++
    void cv::dilate(InputArray src, OutputArray dst, InputArray kernel, Point anchor = Point(-1, -1), int iterations = 1, int borderType = BORDER_CONSTANT, const Scalar & borderValue = morphologyDefaultBorderValue() )
    ```	

* Pictures	:
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/dilate.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/dilate1.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/dilate2.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/dilate3.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/dilate4.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/dilate5.png)
    ![adThreshold](https://raw.githubusercontent.com/ZhuBrocadeSoar/examplesOfOpenCV/master/img/result/dilate6.png)
