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
CMAKE_SOURCE_DIR = /Users/lhon001/Development/NYU_Bridge/practice/stack_queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stack_queue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stack_queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stack_queue.dir/flags.make

CMakeFiles/stack_queue.dir/main.cpp.o: CMakeFiles/stack_queue.dir/flags.make
CMakeFiles/stack_queue.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lhon001/Development/NYU_Bridge/practice/stack_queue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stack_queue.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stack_queue.dir/main.cpp.o -c /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/main.cpp

CMakeFiles/stack_queue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack_queue.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/main.cpp > CMakeFiles/stack_queue.dir/main.cpp.i

CMakeFiles/stack_queue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack_queue.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/main.cpp -o CMakeFiles/stack_queue.dir/main.cpp.s

# Object files for target stack_queue
stack_queue_OBJECTS = \
"CMakeFiles/stack_queue.dir/main.cpp.o"

# External object files for target stack_queue
stack_queue_EXTERNAL_OBJECTS =

stack_queue: CMakeFiles/stack_queue.dir/main.cpp.o
stack_queue: CMakeFiles/stack_queue.dir/build.make
stack_queue: CMakeFiles/stack_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lhon001/Development/NYU_Bridge/practice/stack_queue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stack_queue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stack_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stack_queue.dir/build: stack_queue

.PHONY : CMakeFiles/stack_queue.dir/build

CMakeFiles/stack_queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stack_queue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stack_queue.dir/clean

CMakeFiles/stack_queue.dir/depend:
	cd /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lhon001/Development/NYU_Bridge/practice/stack_queue /Users/lhon001/Development/NYU_Bridge/practice/stack_queue /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/cmake-build-debug /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/cmake-build-debug /Users/lhon001/Development/NYU_Bridge/practice/stack_queue/cmake-build-debug/CMakeFiles/stack_queue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stack_queue.dir/depend
