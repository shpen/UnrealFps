# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /cygdrive/c/Users/Artem/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Artem/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source/cmake-build-debug

# Utility rule file for FpsCpp-Mac-Test.

# Include the progress variables for this target.
include CMakeFiles/FpsCpp-Mac-Test.dir/progress.make

CMakeFiles/FpsCpp-Mac-Test:
	cd D:/Epic\ Games/UnrealEngine/Engine/Binaries/DotNET && UnrealBuildTool.exe FpsCpp Win64 Test -project="D:/Storage/Unreal/FpsCpp-4.15-Source/FpsCpp.uproject" -game

FpsCpp-Mac-Test: CMakeFiles/FpsCpp-Mac-Test
FpsCpp-Mac-Test: CMakeFiles/FpsCpp-Mac-Test.dir/build.make

.PHONY : FpsCpp-Mac-Test

# Rule to build all files generated by this target.
CMakeFiles/FpsCpp-Mac-Test.dir/build: FpsCpp-Mac-Test

.PHONY : CMakeFiles/FpsCpp-Mac-Test.dir/build

CMakeFiles/FpsCpp-Mac-Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FpsCpp-Mac-Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FpsCpp-Mac-Test.dir/clean

CMakeFiles/FpsCpp-Mac-Test.dir/depend:
	cd /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source/cmake-build-debug /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source/cmake-build-debug /cygdrive/d/Storage/Unreal/FpsCpp-4.15-Source/cmake-build-debug/CMakeFiles/FpsCpp-Mac-Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FpsCpp-Mac-Test.dir/depend

