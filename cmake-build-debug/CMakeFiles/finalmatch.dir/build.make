# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xuetf/workspace/c-workspace/sift2/finalmatch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/finalmatch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/finalmatch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/finalmatch.dir/flags.make

CMakeFiles/finalmatch.dir/cv.c.o: CMakeFiles/finalmatch.dir/flags.make
CMakeFiles/finalmatch.dir/cv.c.o: ../cv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/finalmatch.dir/cv.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/finalmatch.dir/cv.c.o   -c /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cv.c

CMakeFiles/finalmatch.dir/cv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/finalmatch.dir/cv.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cv.c > CMakeFiles/finalmatch.dir/cv.c.i

CMakeFiles/finalmatch.dir/cv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/finalmatch.dir/cv.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cv.c -o CMakeFiles/finalmatch.dir/cv.c.s

CMakeFiles/finalmatch.dir/cv.c.o.requires:

.PHONY : CMakeFiles/finalmatch.dir/cv.c.o.requires

CMakeFiles/finalmatch.dir/cv.c.o.provides: CMakeFiles/finalmatch.dir/cv.c.o.requires
	$(MAKE) -f CMakeFiles/finalmatch.dir/build.make CMakeFiles/finalmatch.dir/cv.c.o.provides.build
.PHONY : CMakeFiles/finalmatch.dir/cv.c.o.provides

CMakeFiles/finalmatch.dir/cv.c.o.provides.build: CMakeFiles/finalmatch.dir/cv.c.o


CMakeFiles/finalmatch.dir/img.c.o: CMakeFiles/finalmatch.dir/flags.make
CMakeFiles/finalmatch.dir/img.c.o: ../img.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/finalmatch.dir/img.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/finalmatch.dir/img.c.o   -c /Users/xuetf/workspace/c-workspace/sift2/finalmatch/img.c

CMakeFiles/finalmatch.dir/img.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/finalmatch.dir/img.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xuetf/workspace/c-workspace/sift2/finalmatch/img.c > CMakeFiles/finalmatch.dir/img.c.i

CMakeFiles/finalmatch.dir/img.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/finalmatch.dir/img.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xuetf/workspace/c-workspace/sift2/finalmatch/img.c -o CMakeFiles/finalmatch.dir/img.c.s

CMakeFiles/finalmatch.dir/img.c.o.requires:

.PHONY : CMakeFiles/finalmatch.dir/img.c.o.requires

CMakeFiles/finalmatch.dir/img.c.o.provides: CMakeFiles/finalmatch.dir/img.c.o.requires
	$(MAKE) -f CMakeFiles/finalmatch.dir/build.make CMakeFiles/finalmatch.dir/img.c.o.provides.build
.PHONY : CMakeFiles/finalmatch.dir/img.c.o.provides

CMakeFiles/finalmatch.dir/img.c.o.provides.build: CMakeFiles/finalmatch.dir/img.c.o


CMakeFiles/finalmatch.dir/kdtree.c.o: CMakeFiles/finalmatch.dir/flags.make
CMakeFiles/finalmatch.dir/kdtree.c.o: ../kdtree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/finalmatch.dir/kdtree.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/finalmatch.dir/kdtree.c.o   -c /Users/xuetf/workspace/c-workspace/sift2/finalmatch/kdtree.c

CMakeFiles/finalmatch.dir/kdtree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/finalmatch.dir/kdtree.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xuetf/workspace/c-workspace/sift2/finalmatch/kdtree.c > CMakeFiles/finalmatch.dir/kdtree.c.i

CMakeFiles/finalmatch.dir/kdtree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/finalmatch.dir/kdtree.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xuetf/workspace/c-workspace/sift2/finalmatch/kdtree.c -o CMakeFiles/finalmatch.dir/kdtree.c.s

CMakeFiles/finalmatch.dir/kdtree.c.o.requires:

.PHONY : CMakeFiles/finalmatch.dir/kdtree.c.o.requires

CMakeFiles/finalmatch.dir/kdtree.c.o.provides: CMakeFiles/finalmatch.dir/kdtree.c.o.requires
	$(MAKE) -f CMakeFiles/finalmatch.dir/build.make CMakeFiles/finalmatch.dir/kdtree.c.o.provides.build
.PHONY : CMakeFiles/finalmatch.dir/kdtree.c.o.provides

CMakeFiles/finalmatch.dir/kdtree.c.o.provides.build: CMakeFiles/finalmatch.dir/kdtree.c.o


CMakeFiles/finalmatch.dir/main.c.o: CMakeFiles/finalmatch.dir/flags.make
CMakeFiles/finalmatch.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/finalmatch.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/finalmatch.dir/main.c.o   -c /Users/xuetf/workspace/c-workspace/sift2/finalmatch/main.c

CMakeFiles/finalmatch.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/finalmatch.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xuetf/workspace/c-workspace/sift2/finalmatch/main.c > CMakeFiles/finalmatch.dir/main.c.i

CMakeFiles/finalmatch.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/finalmatch.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xuetf/workspace/c-workspace/sift2/finalmatch/main.c -o CMakeFiles/finalmatch.dir/main.c.s

CMakeFiles/finalmatch.dir/main.c.o.requires:

.PHONY : CMakeFiles/finalmatch.dir/main.c.o.requires

CMakeFiles/finalmatch.dir/main.c.o.provides: CMakeFiles/finalmatch.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/finalmatch.dir/build.make CMakeFiles/finalmatch.dir/main.c.o.provides.build
.PHONY : CMakeFiles/finalmatch.dir/main.c.o.provides

CMakeFiles/finalmatch.dir/main.c.o.provides.build: CMakeFiles/finalmatch.dir/main.c.o


CMakeFiles/finalmatch.dir/minpq.c.o: CMakeFiles/finalmatch.dir/flags.make
CMakeFiles/finalmatch.dir/minpq.c.o: ../minpq.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/finalmatch.dir/minpq.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/finalmatch.dir/minpq.c.o   -c /Users/xuetf/workspace/c-workspace/sift2/finalmatch/minpq.c

CMakeFiles/finalmatch.dir/minpq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/finalmatch.dir/minpq.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xuetf/workspace/c-workspace/sift2/finalmatch/minpq.c > CMakeFiles/finalmatch.dir/minpq.c.i

CMakeFiles/finalmatch.dir/minpq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/finalmatch.dir/minpq.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xuetf/workspace/c-workspace/sift2/finalmatch/minpq.c -o CMakeFiles/finalmatch.dir/minpq.c.s

CMakeFiles/finalmatch.dir/minpq.c.o.requires:

.PHONY : CMakeFiles/finalmatch.dir/minpq.c.o.requires

CMakeFiles/finalmatch.dir/minpq.c.o.provides: CMakeFiles/finalmatch.dir/minpq.c.o.requires
	$(MAKE) -f CMakeFiles/finalmatch.dir/build.make CMakeFiles/finalmatch.dir/minpq.c.o.provides.build
.PHONY : CMakeFiles/finalmatch.dir/minpq.c.o.provides

CMakeFiles/finalmatch.dir/minpq.c.o.provides.build: CMakeFiles/finalmatch.dir/minpq.c.o


CMakeFiles/finalmatch.dir/sift.c.o: CMakeFiles/finalmatch.dir/flags.make
CMakeFiles/finalmatch.dir/sift.c.o: ../sift.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/finalmatch.dir/sift.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/finalmatch.dir/sift.c.o   -c /Users/xuetf/workspace/c-workspace/sift2/finalmatch/sift.c

CMakeFiles/finalmatch.dir/sift.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/finalmatch.dir/sift.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xuetf/workspace/c-workspace/sift2/finalmatch/sift.c > CMakeFiles/finalmatch.dir/sift.c.i

CMakeFiles/finalmatch.dir/sift.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/finalmatch.dir/sift.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xuetf/workspace/c-workspace/sift2/finalmatch/sift.c -o CMakeFiles/finalmatch.dir/sift.c.s

CMakeFiles/finalmatch.dir/sift.c.o.requires:

.PHONY : CMakeFiles/finalmatch.dir/sift.c.o.requires

CMakeFiles/finalmatch.dir/sift.c.o.provides: CMakeFiles/finalmatch.dir/sift.c.o.requires
	$(MAKE) -f CMakeFiles/finalmatch.dir/build.make CMakeFiles/finalmatch.dir/sift.c.o.provides.build
.PHONY : CMakeFiles/finalmatch.dir/sift.c.o.provides

CMakeFiles/finalmatch.dir/sift.c.o.provides.build: CMakeFiles/finalmatch.dir/sift.c.o


# Object files for target finalmatch
finalmatch_OBJECTS = \
"CMakeFiles/finalmatch.dir/cv.c.o" \
"CMakeFiles/finalmatch.dir/img.c.o" \
"CMakeFiles/finalmatch.dir/kdtree.c.o" \
"CMakeFiles/finalmatch.dir/main.c.o" \
"CMakeFiles/finalmatch.dir/minpq.c.o" \
"CMakeFiles/finalmatch.dir/sift.c.o"

# External object files for target finalmatch
finalmatch_EXTERNAL_OBJECTS =

finalmatch: CMakeFiles/finalmatch.dir/cv.c.o
finalmatch: CMakeFiles/finalmatch.dir/img.c.o
finalmatch: CMakeFiles/finalmatch.dir/kdtree.c.o
finalmatch: CMakeFiles/finalmatch.dir/main.c.o
finalmatch: CMakeFiles/finalmatch.dir/minpq.c.o
finalmatch: CMakeFiles/finalmatch.dir/sift.c.o
finalmatch: CMakeFiles/finalmatch.dir/build.make
finalmatch: CMakeFiles/finalmatch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable finalmatch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/finalmatch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/finalmatch.dir/build: finalmatch

.PHONY : CMakeFiles/finalmatch.dir/build

CMakeFiles/finalmatch.dir/requires: CMakeFiles/finalmatch.dir/cv.c.o.requires
CMakeFiles/finalmatch.dir/requires: CMakeFiles/finalmatch.dir/img.c.o.requires
CMakeFiles/finalmatch.dir/requires: CMakeFiles/finalmatch.dir/kdtree.c.o.requires
CMakeFiles/finalmatch.dir/requires: CMakeFiles/finalmatch.dir/main.c.o.requires
CMakeFiles/finalmatch.dir/requires: CMakeFiles/finalmatch.dir/minpq.c.o.requires
CMakeFiles/finalmatch.dir/requires: CMakeFiles/finalmatch.dir/sift.c.o.requires

.PHONY : CMakeFiles/finalmatch.dir/requires

CMakeFiles/finalmatch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/finalmatch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/finalmatch.dir/clean

CMakeFiles/finalmatch.dir/depend:
	cd /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xuetf/workspace/c-workspace/sift2/finalmatch /Users/xuetf/workspace/c-workspace/sift2/finalmatch /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug /Users/xuetf/workspace/c-workspace/sift2/finalmatch/cmake-build-debug/CMakeFiles/finalmatch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/finalmatch.dir/depend
