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
CMAKE_SOURCE_DIR = /cygdrive/d/Storage/Unreal/FpsCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug

# Utility rule file for UE4Game.

# Include the progress variables for this target.
include CMakeFiles/UE4Game.dir/progress.make

CMakeFiles/UE4Game:
	cd C:/Program\ Files/Epic\ Games/UE_4.15.old/Engine/Binaries/DotNET && UnrealBuildTool.exe UE4Game Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game

UE4Game: CMakeFiles/UE4Game
UE4Game: CMakeFiles/UE4Game.dir/build.make

.PHONY : UE4Game

# Rule to build all files generated by this target.
CMakeFiles/UE4Game.dir/build: UE4Game

.PHONY : CMakeFiles/UE4Game.dir/build

CMakeFiles/UE4Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UE4Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UE4Game.dir/clean

CMakeFiles/UE4Game.dir/depend:
	cd /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Storage/Unreal/FpsCpp /cygdrive/d/Storage/Unreal/FpsCpp /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug/CMakeFiles/UE4Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UE4Game.dir/depend

