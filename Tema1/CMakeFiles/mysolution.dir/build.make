# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1"

# Include any dependencies generated for this target.
include CMakeFiles/mysolution.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mysolution.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mysolution.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mysolution.dir/flags.make

CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o: CMakeFiles/mysolution.dir/flags.make
CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o: src/tema1_paoo.cpp
CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o: CMakeFiles/mysolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/adi08/PAOO/Teme PAOO/PAOO/Tema1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o -MF CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o.d -o CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o -c "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1/src/tema1_paoo.cpp"

CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1/src/tema1_paoo.cpp" > CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.i

CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1/src/tema1_paoo.cpp" -o CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.s

# Object files for target mysolution
mysolution_OBJECTS = \
"CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o"

# External object files for target mysolution
mysolution_EXTERNAL_OBJECTS =

mysolution: CMakeFiles/mysolution.dir/src/tema1_paoo.cpp.o
mysolution: CMakeFiles/mysolution.dir/build.make
mysolution: CMakeFiles/mysolution.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/adi08/PAOO/Teme PAOO/PAOO/Tema1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mysolution"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mysolution.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mysolution.dir/build: mysolution
.PHONY : CMakeFiles/mysolution.dir/build

CMakeFiles/mysolution.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mysolution.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mysolution.dir/clean

CMakeFiles/mysolution.dir/depend:
	cd "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1" "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1" "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1" "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1" "/home/adi08/PAOO/Teme PAOO/PAOO/Tema1/CMakeFiles/mysolution.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/mysolution.dir/depend
