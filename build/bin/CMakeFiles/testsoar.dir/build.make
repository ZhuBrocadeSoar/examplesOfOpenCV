# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/soar/examplesOfOpenCV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/soar/examplesOfOpenCV/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/testsoar.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/testsoar.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/testsoar.dir/flags.make

bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o: bin/CMakeFiles/testsoar.dir/flags.make
bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o: ../src/fileter/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/soar/examplesOfOpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o"
	cd /home/soar/examplesOfOpenCV/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testsoar.dir/fileter/main.cpp.o -c /home/soar/examplesOfOpenCV/src/fileter/main.cpp

bin/CMakeFiles/testsoar.dir/fileter/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testsoar.dir/fileter/main.cpp.i"
	cd /home/soar/examplesOfOpenCV/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/soar/examplesOfOpenCV/src/fileter/main.cpp > CMakeFiles/testsoar.dir/fileter/main.cpp.i

bin/CMakeFiles/testsoar.dir/fileter/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testsoar.dir/fileter/main.cpp.s"
	cd /home/soar/examplesOfOpenCV/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/soar/examplesOfOpenCV/src/fileter/main.cpp -o CMakeFiles/testsoar.dir/fileter/main.cpp.s

bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.requires:

.PHONY : bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.requires

bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.provides: bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.requires
	$(MAKE) -f bin/CMakeFiles/testsoar.dir/build.make bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.provides.build
.PHONY : bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.provides

bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.provides.build: bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o


# Object files for target testsoar
testsoar_OBJECTS = \
"CMakeFiles/testsoar.dir/fileter/main.cpp.o"

# External object files for target testsoar
testsoar_EXTERNAL_OBJECTS =

bin/testsoar: bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o
bin/testsoar: bin/CMakeFiles/testsoar.dir/build.make
bin/testsoar: /usr/lib/libopencv_stitching.so.3.2.0
bin/testsoar: /usr/lib/libopencv_superres.so.3.2.0
bin/testsoar: /usr/lib/libopencv_videostab.so.3.2.0
bin/testsoar: /usr/lib/libopencv_aruco.so.3.2.0
bin/testsoar: /usr/lib/libopencv_bgsegm.so.3.2.0
bin/testsoar: /usr/lib/libopencv_bioinspired.so.3.2.0
bin/testsoar: /usr/lib/libopencv_ccalib.so.3.2.0
bin/testsoar: /usr/lib/libopencv_dpm.so.3.2.0
bin/testsoar: /usr/lib/libopencv_freetype.so.3.2.0
bin/testsoar: /usr/lib/libopencv_fuzzy.so.3.2.0
bin/testsoar: /usr/lib/libopencv_hdf.so.3.2.0
bin/testsoar: /usr/lib/libopencv_line_descriptor.so.3.2.0
bin/testsoar: /usr/lib/libopencv_optflow.so.3.2.0
bin/testsoar: /usr/lib/libopencv_reg.so.3.2.0
bin/testsoar: /usr/lib/libopencv_saliency.so.3.2.0
bin/testsoar: /usr/lib/libopencv_stereo.so.3.2.0
bin/testsoar: /usr/lib/libopencv_structured_light.so.3.2.0
bin/testsoar: /usr/lib/libopencv_surface_matching.so.3.2.0
bin/testsoar: /usr/lib/libopencv_tracking.so.3.2.0
bin/testsoar: /usr/lib/libopencv_xfeatures2d.so.3.2.0
bin/testsoar: /usr/lib/libopencv_ximgproc.so.3.2.0
bin/testsoar: /usr/lib/libopencv_xobjdetect.so.3.2.0
bin/testsoar: /usr/lib/libopencv_xphoto.so.3.2.0
bin/testsoar: /usr/lib/libopencv_shape.so.3.2.0
bin/testsoar: /usr/lib/libopencv_phase_unwrapping.so.3.2.0
bin/testsoar: /usr/lib/libopencv_rgbd.so.3.2.0
bin/testsoar: /usr/lib/libopencv_calib3d.so.3.2.0
bin/testsoar: /usr/lib/libopencv_video.so.3.2.0
bin/testsoar: /usr/lib/libopencv_datasets.so.3.2.0
bin/testsoar: /usr/lib/libopencv_dnn.so.3.2.0
bin/testsoar: /usr/lib/libopencv_face.so.3.2.0
bin/testsoar: /usr/lib/libopencv_plot.so.3.2.0
bin/testsoar: /usr/lib/libopencv_text.so.3.2.0
bin/testsoar: /usr/lib/libopencv_features2d.so.3.2.0
bin/testsoar: /usr/lib/libopencv_flann.so.3.2.0
bin/testsoar: /usr/lib/libopencv_objdetect.so.3.2.0
bin/testsoar: /usr/lib/libopencv_ml.so.3.2.0
bin/testsoar: /usr/lib/libopencv_highgui.so.3.2.0
bin/testsoar: /usr/lib/libopencv_photo.so.3.2.0
bin/testsoar: /usr/lib/libopencv_videoio.so.3.2.0
bin/testsoar: /usr/lib/libopencv_imgcodecs.so.3.2.0
bin/testsoar: /usr/lib/libopencv_imgproc.so.3.2.0
bin/testsoar: /usr/lib/libopencv_core.so.3.2.0
bin/testsoar: bin/CMakeFiles/testsoar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/soar/examplesOfOpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testsoar"
	cd /home/soar/examplesOfOpenCV/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testsoar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/testsoar.dir/build: bin/testsoar

.PHONY : bin/CMakeFiles/testsoar.dir/build

bin/CMakeFiles/testsoar.dir/requires: bin/CMakeFiles/testsoar.dir/fileter/main.cpp.o.requires

.PHONY : bin/CMakeFiles/testsoar.dir/requires

bin/CMakeFiles/testsoar.dir/clean:
	cd /home/soar/examplesOfOpenCV/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/testsoar.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/testsoar.dir/clean

bin/CMakeFiles/testsoar.dir/depend:
	cd /home/soar/examplesOfOpenCV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/soar/examplesOfOpenCV /home/soar/examplesOfOpenCV/src /home/soar/examplesOfOpenCV/build /home/soar/examplesOfOpenCV/build/bin /home/soar/examplesOfOpenCV/build/bin/CMakeFiles/testsoar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/testsoar.dir/depend

