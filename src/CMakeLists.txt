# set include
include_directories(/usr/include/opencv /usr/include/opencv2 /usr/include/gsl )

# set list of src
set(SRC_LIST main.cpp)

# create executable file
add_executable(cameratest ${SRC_LIST})

# find opencv package and autoset the $OpenCV_LIBS
find_package(OpenCV REQUIRED)

# link to opencv and gsl lib
target_link_libraries(cameratest ${OpenCV_LIBS} gsl gslcblas m)

# install seting
install(TARGETS cameratest DESTINATION bin)

