# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Workspace\grad_desc_ht

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Workspace\grad_desc_ht\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/grad_desc_ht.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/grad_desc_ht.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/grad_desc_ht.dir/flags.make

CMakeFiles/grad_desc_ht.dir/src/main.cpp.obj: CMakeFiles/grad_desc_ht.dir/flags.make
CMakeFiles/grad_desc_ht.dir/src/main.cpp.obj: CMakeFiles/grad_desc_ht.dir/includes_CXX.rsp
CMakeFiles/grad_desc_ht.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Workspace\grad_desc_ht\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/grad_desc_ht.dir/src/main.cpp.obj"
	C:\MinGW-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\grad_desc_ht.dir\src\main.cpp.obj -c D:\Workspace\grad_desc_ht\src\main.cpp

CMakeFiles/grad_desc_ht.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grad_desc_ht.dir/src/main.cpp.i"
	C:\MinGW-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Workspace\grad_desc_ht\src\main.cpp > CMakeFiles\grad_desc_ht.dir\src\main.cpp.i

CMakeFiles/grad_desc_ht.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grad_desc_ht.dir/src/main.cpp.s"
	C:\MinGW-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Workspace\grad_desc_ht\src\main.cpp -o CMakeFiles\grad_desc_ht.dir\src\main.cpp.s

# Object files for target grad_desc_ht
grad_desc_ht_OBJECTS = \
"CMakeFiles/grad_desc_ht.dir/src/main.cpp.obj"

# External object files for target grad_desc_ht
grad_desc_ht_EXTERNAL_OBJECTS =

grad_desc_ht.exe: CMakeFiles/grad_desc_ht.dir/src/main.cpp.obj
grad_desc_ht.exe: CMakeFiles/grad_desc_ht.dir/build.make
grad_desc_ht.exe: ../lib/x64/libOpenCL.a
grad_desc_ht.exe: CMakeFiles/grad_desc_ht.dir/linklibs.rsp
grad_desc_ht.exe: CMakeFiles/grad_desc_ht.dir/objects1.rsp
grad_desc_ht.exe: CMakeFiles/grad_desc_ht.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Workspace\grad_desc_ht\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable grad_desc_ht.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\grad_desc_ht.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/grad_desc_ht.dir/build: grad_desc_ht.exe

.PHONY : CMakeFiles/grad_desc_ht.dir/build

CMakeFiles/grad_desc_ht.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\grad_desc_ht.dir\cmake_clean.cmake
.PHONY : CMakeFiles/grad_desc_ht.dir/clean

CMakeFiles/grad_desc_ht.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Workspace\grad_desc_ht D:\Workspace\grad_desc_ht D:\Workspace\grad_desc_ht\cmake-build-debug D:\Workspace\grad_desc_ht\cmake-build-debug D:\Workspace\grad_desc_ht\cmake-build-debug\CMakeFiles\grad_desc_ht.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/grad_desc_ht.dir/depend

