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
CMAKE_SOURCE_DIR = "/cygdrive/d/Storage/Unreal/FpsCpp 4.15"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/d/Storage/Unreal/FpsCpp 4.15/cmake-build-debug"

# Utility rule file for FpsCppEditor-Mac-Shipping.

# Include the progress variables for this target.
include CMakeFiles/FpsCppEditor-Mac-Shipping.dir/progress.make

CMakeFiles/FpsCppEditor-Mac-Shipping:
	cd D:/Epic\ Games/UnrealEngine/Engine/Binaries/DotNET && UnrealBuildTool.exe FpsCppEditor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp\ 4.15/FpsCpp.uproject" -game

FpsCppEditor-Mac-Shipping: CMakeFiles/FpsCppEditor-Mac-Shipping
FpsCppEditor-Mac-Shipping: CMakeFiles/FpsCppEditor-Mac-Shipping.dir/build.make

.PHONY : FpsCppEditor-Mac-Shipping

# Rule to build all files generated by this target.
CMakeFiles/FpsCppEditor-Mac-Shipping.dir/build: FpsCppEditor-Mac-Shipping

.PHONY : CMakeFiles/FpsCppEditor-Mac-Shipping.dir/build

CMakeFiles/FpsCppEditor-Mac-Shipping.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FpsCppEditor-Mac-Shipping.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FpsCppEditor-Mac-Shipping.dir/clean

CMakeFiles/FpsCppEditor-Mac-Shipping.dir/depend:
	cd "/cygdrive/d/Storage/Unreal/FpsCpp 4.15/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/d/Storage/Unreal/FpsCpp 4.15" "/cygdrive/d/Storage/Unreal/FpsCpp 4.15" "/cygdrive/d/Storage/Unreal/FpsCpp 4.15/cmake-build-debug" "/cygdrive/d/Storage/Unreal/FpsCpp 4.15/cmake-build-debug" "/cygdrive/d/Storage/Unreal/FpsCpp 4.15/cmake-build-debug/CMakeFiles/FpsCppEditor-Mac-Shipping.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/FpsCppEditor-Mac-Shipping.dir/depend

