# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject

# Include any dependencies generated for this target.
include CMakeFiles/cf_cg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cf_cg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cf_cg.dir/flags.make

CMakeFiles/cf_cg.dir/src/window3D.cpp.o: CMakeFiles/cf_cg.dir/flags.make
CMakeFiles/cf_cg.dir/src/window3D.cpp.o: ../src/window3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cf_cg.dir/src/window3D.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cf_cg.dir/src/window3D.cpp.o -c /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/window3D.cpp

CMakeFiles/cf_cg.dir/src/window3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf_cg.dir/src/window3D.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/window3D.cpp > CMakeFiles/cf_cg.dir/src/window3D.cpp.i

CMakeFiles/cf_cg.dir/src/window3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf_cg.dir/src/window3D.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/window3D.cpp -o CMakeFiles/cf_cg.dir/src/window3D.cpp.s

CMakeFiles/cf_cg.dir/src/window3D.cpp.o.requires:

.PHONY : CMakeFiles/cf_cg.dir/src/window3D.cpp.o.requires

CMakeFiles/cf_cg.dir/src/window3D.cpp.o.provides: CMakeFiles/cf_cg.dir/src/window3D.cpp.o.requires
	$(MAKE) -f CMakeFiles/cf_cg.dir/build.make CMakeFiles/cf_cg.dir/src/window3D.cpp.o.provides.build
.PHONY : CMakeFiles/cf_cg.dir/src/window3D.cpp.o.provides

CMakeFiles/cf_cg.dir/src/window3D.cpp.o.provides.build: CMakeFiles/cf_cg.dir/src/window3D.cpp.o


CMakeFiles/cf_cg.dir/src/IFS.cpp.o: CMakeFiles/cf_cg.dir/flags.make
CMakeFiles/cf_cg.dir/src/IFS.cpp.o: ../src/IFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cf_cg.dir/src/IFS.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cf_cg.dir/src/IFS.cpp.o -c /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/IFS.cpp

CMakeFiles/cf_cg.dir/src/IFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf_cg.dir/src/IFS.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/IFS.cpp > CMakeFiles/cf_cg.dir/src/IFS.cpp.i

CMakeFiles/cf_cg.dir/src/IFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf_cg.dir/src/IFS.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/IFS.cpp -o CMakeFiles/cf_cg.dir/src/IFS.cpp.s

CMakeFiles/cf_cg.dir/src/IFS.cpp.o.requires:

.PHONY : CMakeFiles/cf_cg.dir/src/IFS.cpp.o.requires

CMakeFiles/cf_cg.dir/src/IFS.cpp.o.provides: CMakeFiles/cf_cg.dir/src/IFS.cpp.o.requires
	$(MAKE) -f CMakeFiles/cf_cg.dir/build.make CMakeFiles/cf_cg.dir/src/IFS.cpp.o.provides.build
.PHONY : CMakeFiles/cf_cg.dir/src/IFS.cpp.o.provides

CMakeFiles/cf_cg.dir/src/IFS.cpp.o.provides.build: CMakeFiles/cf_cg.dir/src/IFS.cpp.o


CMakeFiles/cf_cg.dir/src/utils.cpp.o: CMakeFiles/cf_cg.dir/flags.make
CMakeFiles/cf_cg.dir/src/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cf_cg.dir/src/utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cf_cg.dir/src/utils.cpp.o -c /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/utils.cpp

CMakeFiles/cf_cg.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf_cg.dir/src/utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/utils.cpp > CMakeFiles/cf_cg.dir/src/utils.cpp.i

CMakeFiles/cf_cg.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf_cg.dir/src/utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/utils.cpp -o CMakeFiles/cf_cg.dir/src/utils.cpp.s

CMakeFiles/cf_cg.dir/src/utils.cpp.o.requires:

.PHONY : CMakeFiles/cf_cg.dir/src/utils.cpp.o.requires

CMakeFiles/cf_cg.dir/src/utils.cpp.o.provides: CMakeFiles/cf_cg.dir/src/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/cf_cg.dir/build.make CMakeFiles/cf_cg.dir/src/utils.cpp.o.provides.build
.PHONY : CMakeFiles/cf_cg.dir/src/utils.cpp.o.provides

CMakeFiles/cf_cg.dir/src/utils.cpp.o.provides.build: CMakeFiles/cf_cg.dir/src/utils.cpp.o


CMakeFiles/cf_cg.dir/src/ORB.cpp.o: CMakeFiles/cf_cg.dir/flags.make
CMakeFiles/cf_cg.dir/src/ORB.cpp.o: ../src/ORB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cf_cg.dir/src/ORB.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cf_cg.dir/src/ORB.cpp.o -c /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/ORB.cpp

CMakeFiles/cf_cg.dir/src/ORB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf_cg.dir/src/ORB.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/ORB.cpp > CMakeFiles/cf_cg.dir/src/ORB.cpp.i

CMakeFiles/cf_cg.dir/src/ORB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf_cg.dir/src/ORB.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/ORB.cpp -o CMakeFiles/cf_cg.dir/src/ORB.cpp.s

CMakeFiles/cf_cg.dir/src/ORB.cpp.o.requires:

.PHONY : CMakeFiles/cf_cg.dir/src/ORB.cpp.o.requires

CMakeFiles/cf_cg.dir/src/ORB.cpp.o.provides: CMakeFiles/cf_cg.dir/src/ORB.cpp.o.requires
	$(MAKE) -f CMakeFiles/cf_cg.dir/build.make CMakeFiles/cf_cg.dir/src/ORB.cpp.o.provides.build
.PHONY : CMakeFiles/cf_cg.dir/src/ORB.cpp.o.provides

CMakeFiles/cf_cg.dir/src/ORB.cpp.o.provides.build: CMakeFiles/cf_cg.dir/src/ORB.cpp.o


CMakeFiles/cf_cg.dir/src/LSystem.cpp.o: CMakeFiles/cf_cg.dir/flags.make
CMakeFiles/cf_cg.dir/src/LSystem.cpp.o: ../src/LSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cf_cg.dir/src/LSystem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cf_cg.dir/src/LSystem.cpp.o -c /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/LSystem.cpp

CMakeFiles/cf_cg.dir/src/LSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf_cg.dir/src/LSystem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/LSystem.cpp > CMakeFiles/cf_cg.dir/src/LSystem.cpp.i

CMakeFiles/cf_cg.dir/src/LSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf_cg.dir/src/LSystem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/LSystem.cpp -o CMakeFiles/cf_cg.dir/src/LSystem.cpp.s

CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.requires:

.PHONY : CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.requires

CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.provides: CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/cf_cg.dir/build.make CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.provides.build
.PHONY : CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.provides

CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.provides.build: CMakeFiles/cf_cg.dir/src/LSystem.cpp.o


CMakeFiles/cf_cg.dir/src/window2D.cpp.o: CMakeFiles/cf_cg.dir/flags.make
CMakeFiles/cf_cg.dir/src/window2D.cpp.o: ../src/window2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cf_cg.dir/src/window2D.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cf_cg.dir/src/window2D.cpp.o -c /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/window2D.cpp

CMakeFiles/cf_cg.dir/src/window2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf_cg.dir/src/window2D.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/window2D.cpp > CMakeFiles/cf_cg.dir/src/window2D.cpp.i

CMakeFiles/cf_cg.dir/src/window2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf_cg.dir/src/window2D.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/src/window2D.cpp -o CMakeFiles/cf_cg.dir/src/window2D.cpp.s

CMakeFiles/cf_cg.dir/src/window2D.cpp.o.requires:

.PHONY : CMakeFiles/cf_cg.dir/src/window2D.cpp.o.requires

CMakeFiles/cf_cg.dir/src/window2D.cpp.o.provides: CMakeFiles/cf_cg.dir/src/window2D.cpp.o.requires
	$(MAKE) -f CMakeFiles/cf_cg.dir/build.make CMakeFiles/cf_cg.dir/src/window2D.cpp.o.provides.build
.PHONY : CMakeFiles/cf_cg.dir/src/window2D.cpp.o.provides

CMakeFiles/cf_cg.dir/src/window2D.cpp.o.provides.build: CMakeFiles/cf_cg.dir/src/window2D.cpp.o


# Object files for target cf_cg
cf_cg_OBJECTS = \
"CMakeFiles/cf_cg.dir/src/window3D.cpp.o" \
"CMakeFiles/cf_cg.dir/src/IFS.cpp.o" \
"CMakeFiles/cf_cg.dir/src/utils.cpp.o" \
"CMakeFiles/cf_cg.dir/src/ORB.cpp.o" \
"CMakeFiles/cf_cg.dir/src/LSystem.cpp.o" \
"CMakeFiles/cf_cg.dir/src/window2D.cpp.o"

# External object files for target cf_cg
cf_cg_EXTERNAL_OBJECTS =

../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/src/window3D.cpp.o
../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/src/IFS.cpp.o
../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/src/utils.cpp.o
../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/src/ORB.cpp.o
../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/src/LSystem.cpp.o
../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/src/window2D.cpp.o
../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/build.make
../lib/Debug/libcf_cg.a: CMakeFiles/cf_cg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ../lib/Debug/libcf_cg.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cf_cg.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cf_cg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cf_cg.dir/build: ../lib/Debug/libcf_cg.a

.PHONY : CMakeFiles/cf_cg.dir/build

CMakeFiles/cf_cg.dir/requires: CMakeFiles/cf_cg.dir/src/window3D.cpp.o.requires
CMakeFiles/cf_cg.dir/requires: CMakeFiles/cf_cg.dir/src/IFS.cpp.o.requires
CMakeFiles/cf_cg.dir/requires: CMakeFiles/cf_cg.dir/src/utils.cpp.o.requires
CMakeFiles/cf_cg.dir/requires: CMakeFiles/cf_cg.dir/src/ORB.cpp.o.requires
CMakeFiles/cf_cg.dir/requires: CMakeFiles/cf_cg.dir/src/LSystem.cpp.o.requires
CMakeFiles/cf_cg.dir/requires: CMakeFiles/cf_cg.dir/src/window2D.cpp.o.requires

.PHONY : CMakeFiles/cf_cg.dir/requires

CMakeFiles/cf_cg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cf_cg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cf_cg.dir/clean

CMakeFiles/cf_cg.dir/depend:
	cd /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject /home/kiara/HDa/Master/01_WS1617/Chaos_und_Fraktale/Praktikum/ChaosAndFractals/MakeFileProject/CMakeFiles/cf_cg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cf_cg.dir/depend

