# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/talksik/code/wifipicker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/talksik/code/wifipicker/build

# Utility rule file for appwifipicker_tooling.

# Include any custom commands dependencies for this target.
include CMakeFiles/appwifipicker_tooling.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/appwifipicker_tooling.dir/progress.make

wifipicker/Main.qml: ../Main.qml
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/talksik/code/wifipicker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying Main.qml to /home/talksik/code/wifipicker/build/wifipicker/Main.qml"
	cd /home/talksik/code/wifipicker && /usr/bin/cmake -E copy /home/talksik/code/wifipicker/Main.qml /home/talksik/code/wifipicker/build/wifipicker/Main.qml

appwifipicker_tooling: wifipicker/Main.qml
appwifipicker_tooling: CMakeFiles/appwifipicker_tooling.dir/build.make
.PHONY : appwifipicker_tooling

# Rule to build all files generated by this target.
CMakeFiles/appwifipicker_tooling.dir/build: appwifipicker_tooling
.PHONY : CMakeFiles/appwifipicker_tooling.dir/build

CMakeFiles/appwifipicker_tooling.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appwifipicker_tooling.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appwifipicker_tooling.dir/clean

CMakeFiles/appwifipicker_tooling.dir/depend:
	cd /home/talksik/code/wifipicker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/talksik/code/wifipicker /home/talksik/code/wifipicker /home/talksik/code/wifipicker/build /home/talksik/code/wifipicker/build /home/talksik/code/wifipicker/build/CMakeFiles/appwifipicker_tooling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/appwifipicker_tooling.dir/depend

