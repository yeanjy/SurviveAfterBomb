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
CMAKE_SOURCE_DIR = /home/yean/faculdade/SurviveAfterBomb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yean/faculdade/SurviveAfterBomb

# Include any dependencies generated for this target.
include CMakeFiles/bomba.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bomba.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bomba.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bomba.dir/flags.make

CMakeFiles/bomba.dir/src/survivor.cpp.o: CMakeFiles/bomba.dir/flags.make
CMakeFiles/bomba.dir/src/survivor.cpp.o: src/survivor.cpp
CMakeFiles/bomba.dir/src/survivor.cpp.o: CMakeFiles/bomba.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yean/faculdade/SurviveAfterBomb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bomba.dir/src/survivor.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bomba.dir/src/survivor.cpp.o -MF CMakeFiles/bomba.dir/src/survivor.cpp.o.d -o CMakeFiles/bomba.dir/src/survivor.cpp.o -c /home/yean/faculdade/SurviveAfterBomb/src/survivor.cpp

CMakeFiles/bomba.dir/src/survivor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bomba.dir/src/survivor.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yean/faculdade/SurviveAfterBomb/src/survivor.cpp > CMakeFiles/bomba.dir/src/survivor.cpp.i

CMakeFiles/bomba.dir/src/survivor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bomba.dir/src/survivor.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yean/faculdade/SurviveAfterBomb/src/survivor.cpp -o CMakeFiles/bomba.dir/src/survivor.cpp.s

CMakeFiles/bomba.dir/src/main.cpp.o: CMakeFiles/bomba.dir/flags.make
CMakeFiles/bomba.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/bomba.dir/src/main.cpp.o: CMakeFiles/bomba.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yean/faculdade/SurviveAfterBomb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bomba.dir/src/main.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bomba.dir/src/main.cpp.o -MF CMakeFiles/bomba.dir/src/main.cpp.o.d -o CMakeFiles/bomba.dir/src/main.cpp.o -c /home/yean/faculdade/SurviveAfterBomb/src/main.cpp

CMakeFiles/bomba.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bomba.dir/src/main.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yean/faculdade/SurviveAfterBomb/src/main.cpp > CMakeFiles/bomba.dir/src/main.cpp.i

CMakeFiles/bomba.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bomba.dir/src/main.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yean/faculdade/SurviveAfterBomb/src/main.cpp -o CMakeFiles/bomba.dir/src/main.cpp.s

CMakeFiles/bomba.dir/src/app.cpp.o: CMakeFiles/bomba.dir/flags.make
CMakeFiles/bomba.dir/src/app.cpp.o: src/app.cpp
CMakeFiles/bomba.dir/src/app.cpp.o: CMakeFiles/bomba.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yean/faculdade/SurviveAfterBomb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bomba.dir/src/app.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bomba.dir/src/app.cpp.o -MF CMakeFiles/bomba.dir/src/app.cpp.o.d -o CMakeFiles/bomba.dir/src/app.cpp.o -c /home/yean/faculdade/SurviveAfterBomb/src/app.cpp

CMakeFiles/bomba.dir/src/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bomba.dir/src/app.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yean/faculdade/SurviveAfterBomb/src/app.cpp > CMakeFiles/bomba.dir/src/app.cpp.i

CMakeFiles/bomba.dir/src/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bomba.dir/src/app.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yean/faculdade/SurviveAfterBomb/src/app.cpp -o CMakeFiles/bomba.dir/src/app.cpp.s

# Object files for target bomba
bomba_OBJECTS = \
"CMakeFiles/bomba.dir/src/survivor.cpp.o" \
"CMakeFiles/bomba.dir/src/main.cpp.o" \
"CMakeFiles/bomba.dir/src/app.cpp.o"

# External object files for target bomba
bomba_EXTERNAL_OBJECTS =

bin/bomba: CMakeFiles/bomba.dir/src/survivor.cpp.o
bin/bomba: CMakeFiles/bomba.dir/src/main.cpp.o
bin/bomba: CMakeFiles/bomba.dir/src/app.cpp.o
bin/bomba: CMakeFiles/bomba.dir/build.make
bin/bomba: CMakeFiles/bomba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/yean/faculdade/SurviveAfterBomb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bin/bomba"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bomba.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bomba.dir/build: bin/bomba
.PHONY : CMakeFiles/bomba.dir/build

CMakeFiles/bomba.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bomba.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bomba.dir/clean

CMakeFiles/bomba.dir/depend:
	cd /home/yean/faculdade/SurviveAfterBomb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yean/faculdade/SurviveAfterBomb /home/yean/faculdade/SurviveAfterBomb /home/yean/faculdade/SurviveAfterBomb /home/yean/faculdade/SurviveAfterBomb /home/yean/faculdade/SurviveAfterBomb/CMakeFiles/bomba.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bomba.dir/depend

