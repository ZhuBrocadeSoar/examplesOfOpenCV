# check cmake version
cmake_minimum_required(VERSION 2.8)

# pick a name for this project
project(examplesOfOpenCV)

# set subdirectory
add_subdirectory(src bin)

# take a copy of executable file to /home/soar/bin/ when run make install
set(CMAKE_INSTALL_PREFIX /home/soar)
