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

# Utility rule file for appwifipicker_qmllint_json.

# Include any custom commands dependencies for this target.
include CMakeFiles/appwifipicker_qmllint_json.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/appwifipicker_qmllint_json.dir/progress.make

CMakeFiles/appwifipicker_qmllint_json: /home/talksik/Qt/6.6.1/gcc_64/bin/qmllint
CMakeFiles/appwifipicker_qmllint_json: ../Main.qml
	cd /home/talksik/code/wifipicker && /home/talksik/Qt/6.6.1/gcc_64/bin/qmllint --bare -I /home/talksik/code/wifipicker/build -I /home/talksik/Qt/6.6.1/gcc_64/./qml --resource /home/talksik/code/wifipicker/build/.rcc/qmake_wifipicker.qrc --resource /home/talksik/code/wifipicker/build/.rcc/appwifipicker_raw_qml_0.qrc /home/talksik/code/wifipicker/Main.qml --json /home/talksik/code/wifipicker/build/appwifipicker_qmllint.json

appwifipicker_qmllint_json: CMakeFiles/appwifipicker_qmllint_json
appwifipicker_qmllint_json: CMakeFiles/appwifipicker_qmllint_json.dir/build.make
.PHONY : appwifipicker_qmllint_json

# Rule to build all files generated by this target.
CMakeFiles/appwifipicker_qmllint_json.dir/build: appwifipicker_qmllint_json
.PHONY : CMakeFiles/appwifipicker_qmllint_json.dir/build

CMakeFiles/appwifipicker_qmllint_json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appwifipicker_qmllint_json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appwifipicker_qmllint_json.dir/clean

CMakeFiles/appwifipicker_qmllint_json.dir/depend:
	cd /home/talksik/code/wifipicker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/talksik/code/wifipicker /home/talksik/code/wifipicker /home/talksik/code/wifipicker/build /home/talksik/code/wifipicker/build /home/talksik/code/wifipicker/build/CMakeFiles/appwifipicker_qmllint_json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/appwifipicker_qmllint_json.dir/depend

