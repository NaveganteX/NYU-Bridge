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
CMAKE_COMMAND = "/Users/lhon001/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/lhon001/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lhon001/Development/NYU_Bridge/practice/template_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lhon001/Development/NYU_Bridge/practice/template_example/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/template_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/template_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template_example.dir/flags.make

CMakeFiles/template_example.dir/main.cpp.o: CMakeFiles/template_example.dir/flags.make
CMakeFiles/template_example.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lhon001/Development/NYU_Bridge/practice/template_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template_example.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/template_example.dir/main.cpp.o -c /Users/lhon001/Development/NYU_Bridge/practice/template_example/main.cpp

CMakeFiles/template_example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_example.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lhon001/Development/NYU_Bridge/practice/template_example/main.cpp > CMakeFiles/template_example.dir/main.cpp.i

CMakeFiles/template_example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_example.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lhon001/Development/NYU_Bridge/practice/template_example/main.cpp -o CMakeFiles/template_example.dir/main.cpp.s

# Object files for target template_example
template_example_OBJECTS = \
"CMakeFiles/template_example.dir/main.cpp.o"

# External object files for target template_example
template_example_EXTERNAL_OBJECTS =

template_example: CMakeFiles/template_example.dir/main.cpp.o
template_example: CMakeFiles/template_example.dir/build.make
template_example: CMakeFiles/template_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lhon001/Development/NYU_Bridge/practice/template_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable template_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/template_example.dir/build: template_example

.PHONY : CMakeFiles/template_example.dir/build

CMakeFiles/template_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/template_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/template_example.dir/clean

CMakeFiles/template_example.dir/depend:
	cd /Users/lhon001/Development/NYU_Bridge/practice/template_example/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lhon001/Development/NYU_Bridge/practice/template_example /Users/lhon001/Development/NYU_Bridge/practice/template_example /Users/lhon001/Development/NYU_Bridge/practice/template_example/cmake-build-debug /Users/lhon001/Development/NYU_Bridge/practice/template_example/cmake-build-debug /Users/lhon001/Development/NYU_Bridge/practice/template_example/cmake-build-debug/CMakeFiles/template_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template_example.dir/depend

