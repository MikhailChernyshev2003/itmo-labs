# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pavelchernyshev/Desktop/uint1024_t

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pavelchernyshev/Desktop/uint1024_t/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WordCount.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/WordCount.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WordCount.dir/flags.make

CMakeFiles/WordCount.dir/main.c.o: CMakeFiles/WordCount.dir/flags.make
CMakeFiles/WordCount.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pavelchernyshev/Desktop/uint1024_t/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/WordCount.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/WordCount.dir/main.c.o -c /Users/pavelchernyshev/Desktop/uint1024_t/main.c

CMakeFiles/WordCount.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/WordCount.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/pavelchernyshev/Desktop/uint1024_t/main.c > CMakeFiles/WordCount.dir/main.c.i

CMakeFiles/WordCount.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/WordCount.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/pavelchernyshev/Desktop/uint1024_t/main.c -o CMakeFiles/WordCount.dir/main.c.s

# Object files for target WordCount
WordCount_OBJECTS = \
"CMakeFiles/WordCount.dir/main.c.o"

# External object files for target WordCount
WordCount_EXTERNAL_OBJECTS =

WordCount: CMakeFiles/WordCount.dir/main.c.o
WordCount: CMakeFiles/WordCount.dir/build.make
WordCount: CMakeFiles/WordCount.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pavelchernyshev/Desktop/uint1024_t/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable WordCount"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WordCount.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WordCount.dir/build: WordCount
.PHONY : CMakeFiles/WordCount.dir/build

CMakeFiles/WordCount.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WordCount.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WordCount.dir/clean

CMakeFiles/WordCount.dir/depend:
	cd /Users/pavelchernyshev/Desktop/uint1024_t/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pavelchernyshev/Desktop/uint1024_t /Users/pavelchernyshev/Desktop/uint1024_t /Users/pavelchernyshev/Desktop/uint1024_t/cmake-build-debug /Users/pavelchernyshev/Desktop/uint1024_t/cmake-build-debug /Users/pavelchernyshev/Desktop/uint1024_t/cmake-build-debug/CMakeFiles/WordCount.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WordCount.dir/depend

