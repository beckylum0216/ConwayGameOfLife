# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug

# Include any dependencies generated for this target.
include Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/depend.make

# Include the progress variables for this target.
include Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/progress.make

# Include the compile flags for this target's objects.
include Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/flags.make

Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.obj: Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/flags.make
Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.obj: Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/includes_CXX.rsp
Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.obj: ../Test_Conways_Game_Of_Life/pch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.obj"
	cd /d D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TEST_CONWAYS_GOL.dir\pch.cpp.obj -c D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\Test_Conways_Game_Of_Life\pch.cpp

Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.i"
	cd /d D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\Test_Conways_Game_Of_Life\pch.cpp > CMakeFiles\TEST_CONWAYS_GOL.dir\pch.cpp.i

Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.s"
	cd /d D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\Test_Conways_Game_Of_Life\pch.cpp -o CMakeFiles\TEST_CONWAYS_GOL.dir\pch.cpp.s

# Object files for target TEST_CONWAYS_GOL
TEST_CONWAYS_GOL_OBJECTS = \
"CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.obj"

# External object files for target TEST_CONWAYS_GOL
TEST_CONWAYS_GOL_EXTERNAL_OBJECTS =

Test_Conways_Game_Of_Life/libTEST_CONWAYS_GOL.a: Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/pch.cpp.obj
Test_Conways_Game_Of_Life/libTEST_CONWAYS_GOL.a: Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/build.make
Test_Conways_Game_Of_Life/libTEST_CONWAYS_GOL.a: Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTEST_CONWAYS_GOL.a"
	cd /d D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life && $(CMAKE_COMMAND) -P CMakeFiles\TEST_CONWAYS_GOL.dir\cmake_clean_target.cmake
	cd /d D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TEST_CONWAYS_GOL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/build: Test_Conways_Game_Of_Life/libTEST_CONWAYS_GOL.a

.PHONY : Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/build

Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/clean:
	cd /d D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life && $(CMAKE_COMMAND) -P CMakeFiles\TEST_CONWAYS_GOL.dir\cmake_clean.cmake
.PHONY : Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/clean

Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\Test_Conways_Game_Of_Life D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life D:\Murdoch\ICT290\Tutorial3b_Conways_Game_Of_Life\cmake-build-debug\Test_Conways_Game_Of_Life\CMakeFiles\TEST_CONWAYS_GOL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Test_Conways_Game_Of_Life/CMakeFiles/TEST_CONWAYS_GOL.dir/depend
