# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/projects/il4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/projects/il4

# Include any dependencies generated for this target.
include thirdparty/glfw/tests/CMakeFiles/title.dir/depend.make

# Include the progress variables for this target.
include thirdparty/glfw/tests/CMakeFiles/title.dir/progress.make

# Include the compile flags for this target's objects.
include thirdparty/glfw/tests/CMakeFiles/title.dir/flags.make

thirdparty/glfw/tests/CMakeFiles/title.dir/title.c.o: thirdparty/glfw/tests/CMakeFiles/title.dir/flags.make
thirdparty/glfw/tests/CMakeFiles/title.dir/title.c.o: thirdparty/glfw/tests/title.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/il4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object thirdparty/glfw/tests/CMakeFiles/title.dir/title.c.o"
	cd /home/user/projects/il4/thirdparty/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/title.dir/title.c.o -c /home/user/projects/il4/thirdparty/glfw/tests/title.c

thirdparty/glfw/tests/CMakeFiles/title.dir/title.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/title.c.i"
	cd /home/user/projects/il4/thirdparty/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/il4/thirdparty/glfw/tests/title.c > CMakeFiles/title.dir/title.c.i

thirdparty/glfw/tests/CMakeFiles/title.dir/title.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/title.c.s"
	cd /home/user/projects/il4/thirdparty/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/il4/thirdparty/glfw/tests/title.c -o CMakeFiles/title.dir/title.c.s

thirdparty/glfw/tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o: thirdparty/glfw/tests/CMakeFiles/title.dir/flags.make
thirdparty/glfw/tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o: thirdparty/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/il4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object thirdparty/glfw/tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o"
	cd /home/user/projects/il4/thirdparty/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/title.dir/__/deps/glad_gl.c.o -c /home/user/projects/il4/thirdparty/glfw/deps/glad_gl.c

thirdparty/glfw/tests/CMakeFiles/title.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/__/deps/glad_gl.c.i"
	cd /home/user/projects/il4/thirdparty/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/il4/thirdparty/glfw/deps/glad_gl.c > CMakeFiles/title.dir/__/deps/glad_gl.c.i

thirdparty/glfw/tests/CMakeFiles/title.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/__/deps/glad_gl.c.s"
	cd /home/user/projects/il4/thirdparty/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/il4/thirdparty/glfw/deps/glad_gl.c -o CMakeFiles/title.dir/__/deps/glad_gl.c.s

# Object files for target title
title_OBJECTS = \
"CMakeFiles/title.dir/title.c.o" \
"CMakeFiles/title.dir/__/deps/glad_gl.c.o"

# External object files for target title
title_EXTERNAL_OBJECTS =

thirdparty/glfw/tests/title: thirdparty/glfw/tests/CMakeFiles/title.dir/title.c.o
thirdparty/glfw/tests/title: thirdparty/glfw/tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o
thirdparty/glfw/tests/title: thirdparty/glfw/tests/CMakeFiles/title.dir/build.make
thirdparty/glfw/tests/title: thirdparty/glfw/src/libglfw3.a
thirdparty/glfw/tests/title: /usr/lib/x86_64-linux-gnu/libm.so
thirdparty/glfw/tests/title: /usr/lib/x86_64-linux-gnu/librt.so
thirdparty/glfw/tests/title: /usr/lib/x86_64-linux-gnu/libm.so
thirdparty/glfw/tests/title: /usr/lib/x86_64-linux-gnu/libX11.so
thirdparty/glfw/tests/title: thirdparty/glfw/tests/CMakeFiles/title.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/projects/il4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable title"
	cd /home/user/projects/il4/thirdparty/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/title.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thirdparty/glfw/tests/CMakeFiles/title.dir/build: thirdparty/glfw/tests/title

.PHONY : thirdparty/glfw/tests/CMakeFiles/title.dir/build

thirdparty/glfw/tests/CMakeFiles/title.dir/clean:
	cd /home/user/projects/il4/thirdparty/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/title.dir/cmake_clean.cmake
.PHONY : thirdparty/glfw/tests/CMakeFiles/title.dir/clean

thirdparty/glfw/tests/CMakeFiles/title.dir/depend:
	cd /home/user/projects/il4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/projects/il4 /home/user/projects/il4/thirdparty/glfw/tests /home/user/projects/il4 /home/user/projects/il4/thirdparty/glfw/tests /home/user/projects/il4/thirdparty/glfw/tests/CMakeFiles/title.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/glfw/tests/CMakeFiles/title.dir/depend

