# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "/Users/lhon001/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/lhon001/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/lhon001/Development/NYU Bridge/hw2_q1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/lhon001/Development/NYU Bridge/hw2_q1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/hw2_q1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw2_q1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw2_q1.dir/flags.make

CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.o: CMakeFiles/hw2_q1.dir/flags.make
CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.o: ../lh3024_hw2_q1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lhon001/Development/NYU Bridge/hw2_q1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.o -c "/Users/lhon001/Development/NYU Bridge/hw2_q1/lh3024_hw2_q1.cpp"

CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lhon001/Development/NYU Bridge/hw2_q1/lh3024_hw2_q1.cpp" > CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.i

CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lhon001/Development/NYU Bridge/hw2_q1/lh3024_hw2_q1.cpp" -o CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.s

# Object files for target hw2_q1
hw2_q1_OBJECTS = \
"CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.o"

# External object files for target hw2_q1
hw2_q1_EXTERNAL_OBJECTS =

hw2_q1: CMakeFiles/hw2_q1.dir/lh3024_hw2_q1.cpp.o
hw2_q1: CMakeFiles/hw2_q1.dir/build.make
hw2_q1: CMakeFiles/hw2_q1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/lhon001/Development/NYU Bridge/hw2_q1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw2_q1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw2_q1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw2_q1.dir/build: hw2_q1

.PHONY : CMakeFiles/hw2_q1.dir/build

CMakeFiles/hw2_q1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw2_q1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw2_q1.dir/clean

CMakeFiles/hw2_q1.dir/depend:
	cd "/Users/lhon001/Development/NYU Bridge/hw2_q1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/lhon001/Development/NYU Bridge/hw2_q1" "/Users/lhon001/Development/NYU Bridge/hw2_q1" "/Users/lhon001/Development/NYU Bridge/hw2_q1/cmake-build-debug" "/Users/lhon001/Development/NYU Bridge/hw2_q1/cmake-build-debug" "/Users/lhon001/Development/NYU Bridge/hw2_q1/cmake-build-debug/CMakeFiles/hw2_q1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/hw2_q1.dir/depend

