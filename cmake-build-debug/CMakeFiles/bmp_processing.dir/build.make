# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/viktor/CLionProjects/bmp_processing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/viktor/CLionProjects/bmp_processing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bmp_processing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bmp_processing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bmp_processing.dir/flags.make

CMakeFiles/bmp_processing.dir/main.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bmp_processing.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/main.c.o   -c /home/viktor/CLionProjects/bmp_processing/main.c

CMakeFiles/bmp_processing.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/main.c > CMakeFiles/bmp_processing.dir/main.c.i

CMakeFiles/bmp_processing.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/main.c -o CMakeFiles/bmp_processing.dir/main.c.s

CMakeFiles/bmp_processing.dir/validCoorFirst.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/validCoorFirst.c.o: ../validCoorFirst.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bmp_processing.dir/validCoorFirst.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/validCoorFirst.c.o   -c /home/viktor/CLionProjects/bmp_processing/validCoorFirst.c

CMakeFiles/bmp_processing.dir/validCoorFirst.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/validCoorFirst.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/validCoorFirst.c > CMakeFiles/bmp_processing.dir/validCoorFirst.c.i

CMakeFiles/bmp_processing.dir/validCoorFirst.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/validCoorFirst.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/validCoorFirst.c -o CMakeFiles/bmp_processing.dir/validCoorFirst.c.s

CMakeFiles/bmp_processing.dir/printFileHeader.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/printFileHeader.c.o: ../printFileHeader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/bmp_processing.dir/printFileHeader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/printFileHeader.c.o   -c /home/viktor/CLionProjects/bmp_processing/printFileHeader.c

CMakeFiles/bmp_processing.dir/printFileHeader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/printFileHeader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/printFileHeader.c > CMakeFiles/bmp_processing.dir/printFileHeader.c.i

CMakeFiles/bmp_processing.dir/printFileHeader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/printFileHeader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/printFileHeader.c -o CMakeFiles/bmp_processing.dir/printFileHeader.c.s

CMakeFiles/bmp_processing.dir/printInfoHeader.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/printInfoHeader.c.o: ../printInfoHeader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/bmp_processing.dir/printInfoHeader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/printInfoHeader.c.o   -c /home/viktor/CLionProjects/bmp_processing/printInfoHeader.c

CMakeFiles/bmp_processing.dir/printInfoHeader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/printInfoHeader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/printInfoHeader.c > CMakeFiles/bmp_processing.dir/printInfoHeader.c.i

CMakeFiles/bmp_processing.dir/printInfoHeader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/printInfoHeader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/printInfoHeader.c -o CMakeFiles/bmp_processing.dir/printInfoHeader.c.s

CMakeFiles/bmp_processing.dir/angle.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/angle.c.o: ../angle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/bmp_processing.dir/angle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/angle.c.o   -c /home/viktor/CLionProjects/bmp_processing/angle.c

CMakeFiles/bmp_processing.dir/angle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/angle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/angle.c > CMakeFiles/bmp_processing.dir/angle.c.i

CMakeFiles/bmp_processing.dir/angle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/angle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/angle.c -o CMakeFiles/bmp_processing.dir/angle.c.s

CMakeFiles/bmp_processing.dir/drawLine.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/drawLine.c.o: ../drawLine.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/bmp_processing.dir/drawLine.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/drawLine.c.o   -c /home/viktor/CLionProjects/bmp_processing/drawLine.c

CMakeFiles/bmp_processing.dir/drawLine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/drawLine.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/drawLine.c > CMakeFiles/bmp_processing.dir/drawLine.c.i

CMakeFiles/bmp_processing.dir/drawLine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/drawLine.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/drawLine.c -o CMakeFiles/bmp_processing.dir/drawLine.c.s

CMakeFiles/bmp_processing.dir/inversion1.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/inversion1.c.o: ../inversion1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/bmp_processing.dir/inversion1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/inversion1.c.o   -c /home/viktor/CLionProjects/bmp_processing/inversion1.c

CMakeFiles/bmp_processing.dir/inversion1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/inversion1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/inversion1.c > CMakeFiles/bmp_processing.dir/inversion1.c.i

CMakeFiles/bmp_processing.dir/inversion1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/inversion1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/inversion1.c -o CMakeFiles/bmp_processing.dir/inversion1.c.s

CMakeFiles/bmp_processing.dir/validCoorSecond.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/validCoorSecond.c.o: ../validCoorSecond.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/bmp_processing.dir/validCoorSecond.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/validCoorSecond.c.o   -c /home/viktor/CLionProjects/bmp_processing/validCoorSecond.c

CMakeFiles/bmp_processing.dir/validCoorSecond.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/validCoorSecond.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/validCoorSecond.c > CMakeFiles/bmp_processing.dir/validCoorSecond.c.i

CMakeFiles/bmp_processing.dir/validCoorSecond.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/validCoorSecond.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/validCoorSecond.c -o CMakeFiles/bmp_processing.dir/validCoorSecond.c.s

CMakeFiles/bmp_processing.dir/inversion2.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/inversion2.c.o: ../inversion2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/bmp_processing.dir/inversion2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/inversion2.c.o   -c /home/viktor/CLionProjects/bmp_processing/inversion2.c

CMakeFiles/bmp_processing.dir/inversion2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/inversion2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/inversion2.c > CMakeFiles/bmp_processing.dir/inversion2.c.i

CMakeFiles/bmp_processing.dir/inversion2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/inversion2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/inversion2.c -o CMakeFiles/bmp_processing.dir/inversion2.c.s

CMakeFiles/bmp_processing.dir/cropping.c.o: CMakeFiles/bmp_processing.dir/flags.make
CMakeFiles/bmp_processing.dir/cropping.c.o: ../cropping.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/bmp_processing.dir/cropping.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_processing.dir/cropping.c.o   -c /home/viktor/CLionProjects/bmp_processing/cropping.c

CMakeFiles/bmp_processing.dir/cropping.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_processing.dir/cropping.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viktor/CLionProjects/bmp_processing/cropping.c > CMakeFiles/bmp_processing.dir/cropping.c.i

CMakeFiles/bmp_processing.dir/cropping.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_processing.dir/cropping.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viktor/CLionProjects/bmp_processing/cropping.c -o CMakeFiles/bmp_processing.dir/cropping.c.s

# Object files for target bmp_processing
bmp_processing_OBJECTS = \
"CMakeFiles/bmp_processing.dir/main.c.o" \
"CMakeFiles/bmp_processing.dir/validCoorFirst.c.o" \
"CMakeFiles/bmp_processing.dir/printFileHeader.c.o" \
"CMakeFiles/bmp_processing.dir/printInfoHeader.c.o" \
"CMakeFiles/bmp_processing.dir/angle.c.o" \
"CMakeFiles/bmp_processing.dir/drawLine.c.o" \
"CMakeFiles/bmp_processing.dir/inversion1.c.o" \
"CMakeFiles/bmp_processing.dir/validCoorSecond.c.o" \
"CMakeFiles/bmp_processing.dir/inversion2.c.o" \
"CMakeFiles/bmp_processing.dir/cropping.c.o"

# External object files for target bmp_processing
bmp_processing_EXTERNAL_OBJECTS =

bmp_processing: CMakeFiles/bmp_processing.dir/main.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/validCoorFirst.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/printFileHeader.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/printInfoHeader.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/angle.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/drawLine.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/inversion1.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/validCoorSecond.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/inversion2.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/cropping.c.o
bmp_processing: CMakeFiles/bmp_processing.dir/build.make
bmp_processing: CMakeFiles/bmp_processing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable bmp_processing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bmp_processing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bmp_processing.dir/build: bmp_processing

.PHONY : CMakeFiles/bmp_processing.dir/build

CMakeFiles/bmp_processing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bmp_processing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bmp_processing.dir/clean

CMakeFiles/bmp_processing.dir/depend:
	cd /home/viktor/CLionProjects/bmp_processing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viktor/CLionProjects/bmp_processing /home/viktor/CLionProjects/bmp_processing /home/viktor/CLionProjects/bmp_processing/cmake-build-debug /home/viktor/CLionProjects/bmp_processing/cmake-build-debug /home/viktor/CLionProjects/bmp_processing/cmake-build-debug/CMakeFiles/bmp_processing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bmp_processing.dir/depend

