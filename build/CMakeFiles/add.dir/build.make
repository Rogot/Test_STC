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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maksim/eclipse-workspace/TestSTC_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maksim/eclipse-workspace/TestSTC_1/build

# Include any dependencies generated for this target.
include CMakeFiles/add.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/add.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/add.dir/flags.make

CMakeFiles/add.dir/Parser/Parser.cpp.o: CMakeFiles/add.dir/flags.make
CMakeFiles/add.dir/Parser/Parser.cpp.o: ../Parser/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maksim/eclipse-workspace/TestSTC_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/add.dir/Parser/Parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/add.dir/Parser/Parser.cpp.o -c /home/maksim/eclipse-workspace/TestSTC_1/Parser/Parser.cpp

CMakeFiles/add.dir/Parser/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/add.dir/Parser/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maksim/eclipse-workspace/TestSTC_1/Parser/Parser.cpp > CMakeFiles/add.dir/Parser/Parser.cpp.i

CMakeFiles/add.dir/Parser/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/add.dir/Parser/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maksim/eclipse-workspace/TestSTC_1/Parser/Parser.cpp -o CMakeFiles/add.dir/Parser/Parser.cpp.s

# Object files for target add
add_OBJECTS = \
"CMakeFiles/add.dir/Parser/Parser.cpp.o"

# External object files for target add
add_EXTERNAL_OBJECTS =

libadd.so: CMakeFiles/add.dir/Parser/Parser.cpp.o
libadd.so: CMakeFiles/add.dir/build.make
libadd.so: CMakeFiles/add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maksim/eclipse-workspace/TestSTC_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libadd.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/add.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/add.dir/build: libadd.so

.PHONY : CMakeFiles/add.dir/build

CMakeFiles/add.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/add.dir/cmake_clean.cmake
.PHONY : CMakeFiles/add.dir/clean

CMakeFiles/add.dir/depend:
	cd /home/maksim/eclipse-workspace/TestSTC_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maksim/eclipse-workspace/TestSTC_1 /home/maksim/eclipse-workspace/TestSTC_1 /home/maksim/eclipse-workspace/TestSTC_1/build /home/maksim/eclipse-workspace/TestSTC_1/build /home/maksim/eclipse-workspace/TestSTC_1/build/CMakeFiles/add.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/add.dir/depend

