# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/nikita/operation_systems/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikita/operation_systems/lab2/build

# Include any dependencies generated for this target.
include CMakeFiles/main_exec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_exec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_exec.dir/flags.make

CMakeFiles/main_exec.dir/src/main.c.o: CMakeFiles/main_exec.dir/flags.make
CMakeFiles/main_exec.dir/src/main.c.o: /home/nikita/operation_systems/lab2/src/main.c
CMakeFiles/main_exec.dir/src/main.c.o: CMakeFiles/main_exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nikita/operation_systems/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main_exec.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_exec.dir/src/main.c.o -MF CMakeFiles/main_exec.dir/src/main.c.o.d -o CMakeFiles/main_exec.dir/src/main.c.o -c /home/nikita/operation_systems/lab2/src/main.c

CMakeFiles/main_exec.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main_exec.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/operation_systems/lab2/src/main.c > CMakeFiles/main_exec.dir/src/main.c.i

CMakeFiles/main_exec.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main_exec.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/operation_systems/lab2/src/main.c -o CMakeFiles/main_exec.dir/src/main.c.s

CMakeFiles/main_exec.dir/src/io.c.o: CMakeFiles/main_exec.dir/flags.make
CMakeFiles/main_exec.dir/src/io.c.o: /home/nikita/operation_systems/lab2/src/io.c
CMakeFiles/main_exec.dir/src/io.c.o: CMakeFiles/main_exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nikita/operation_systems/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main_exec.dir/src/io.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_exec.dir/src/io.c.o -MF CMakeFiles/main_exec.dir/src/io.c.o.d -o CMakeFiles/main_exec.dir/src/io.c.o -c /home/nikita/operation_systems/lab2/src/io.c

CMakeFiles/main_exec.dir/src/io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main_exec.dir/src/io.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/operation_systems/lab2/src/io.c > CMakeFiles/main_exec.dir/src/io.c.i

CMakeFiles/main_exec.dir/src/io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main_exec.dir/src/io.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/operation_systems/lab2/src/io.c -o CMakeFiles/main_exec.dir/src/io.c.s

CMakeFiles/main_exec.dir/src/errors.c.o: CMakeFiles/main_exec.dir/flags.make
CMakeFiles/main_exec.dir/src/errors.c.o: /home/nikita/operation_systems/lab2/src/errors.c
CMakeFiles/main_exec.dir/src/errors.c.o: CMakeFiles/main_exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nikita/operation_systems/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main_exec.dir/src/errors.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_exec.dir/src/errors.c.o -MF CMakeFiles/main_exec.dir/src/errors.c.o.d -o CMakeFiles/main_exec.dir/src/errors.c.o -c /home/nikita/operation_systems/lab2/src/errors.c

CMakeFiles/main_exec.dir/src/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main_exec.dir/src/errors.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/operation_systems/lab2/src/errors.c > CMakeFiles/main_exec.dir/src/errors.c.i

CMakeFiles/main_exec.dir/src/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main_exec.dir/src/errors.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/operation_systems/lab2/src/errors.c -o CMakeFiles/main_exec.dir/src/errors.c.s

CMakeFiles/main_exec.dir/src/utils_lab2.c.o: CMakeFiles/main_exec.dir/flags.make
CMakeFiles/main_exec.dir/src/utils_lab2.c.o: /home/nikita/operation_systems/lab2/src/utils_lab2.c
CMakeFiles/main_exec.dir/src/utils_lab2.c.o: CMakeFiles/main_exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nikita/operation_systems/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main_exec.dir/src/utils_lab2.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_exec.dir/src/utils_lab2.c.o -MF CMakeFiles/main_exec.dir/src/utils_lab2.c.o.d -o CMakeFiles/main_exec.dir/src/utils_lab2.c.o -c /home/nikita/operation_systems/lab2/src/utils_lab2.c

CMakeFiles/main_exec.dir/src/utils_lab2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main_exec.dir/src/utils_lab2.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/operation_systems/lab2/src/utils_lab2.c > CMakeFiles/main_exec.dir/src/utils_lab2.c.i

CMakeFiles/main_exec.dir/src/utils_lab2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main_exec.dir/src/utils_lab2.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/operation_systems/lab2/src/utils_lab2.c -o CMakeFiles/main_exec.dir/src/utils_lab2.c.s

# Object files for target main_exec
main_exec_OBJECTS = \
"CMakeFiles/main_exec.dir/src/main.c.o" \
"CMakeFiles/main_exec.dir/src/io.c.o" \
"CMakeFiles/main_exec.dir/src/errors.c.o" \
"CMakeFiles/main_exec.dir/src/utils_lab2.c.o"

# External object files for target main_exec
main_exec_EXTERNAL_OBJECTS =

main_exec: CMakeFiles/main_exec.dir/src/main.c.o
main_exec: CMakeFiles/main_exec.dir/src/io.c.o
main_exec: CMakeFiles/main_exec.dir/src/errors.c.o
main_exec: CMakeFiles/main_exec.dir/src/utils_lab2.c.o
main_exec: CMakeFiles/main_exec.dir/build.make
main_exec: CMakeFiles/main_exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nikita/operation_systems/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable main_exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_exec.dir/build: main_exec
.PHONY : CMakeFiles/main_exec.dir/build

CMakeFiles/main_exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_exec.dir/clean

CMakeFiles/main_exec.dir/depend:
	cd /home/nikita/operation_systems/lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikita/operation_systems/lab2 /home/nikita/operation_systems/lab2 /home/nikita/operation_systems/lab2/build /home/nikita/operation_systems/lab2/build /home/nikita/operation_systems/lab2/build/CMakeFiles/main_exec.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main_exec.dir/depend

