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

# Utility rule file for FpsCppEditor-Mac-Shipping-clean.

# Include the progress variables for this target.
include CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/progress.make

CMakeFiles/FpsCppEditor-Mac-Shipping-clean:
	cd C:/Program\ Files/Epic\ Games/UE_4.15.old/Engine/Binaries/DotNET && UnrealBuildTool.exe FpsCppEditor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean

FpsCppEditor-Mac-Shipping-clean: CMakeFiles/FpsCppEditor-Mac-Shipping-clean
FpsCppEditor-Mac-Shipping-clean: CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/build.make

.PHONY : FpsCppEditor-Mac-Shipping-clean

# Rule to build all files generated by this target.
CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/build: FpsCppEditor-Mac-Shipping-clean

.PHONY : CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/build

CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/clean

CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/depend:
	cd /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Storage/Unreal/FpsCpp /cygdrive/d/Storage/Unreal/FpsCpp /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug /cygdrive/d/Storage/Unreal/FpsCpp/cmake-build-debug/CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FpsCppEditor-Mac-Shipping-clean.dir/depend

