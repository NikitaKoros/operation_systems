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
CMAKE_SOURCE_DIR = /home/nikita/university/operation_systems/2_sem/lab1/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikita/university/operation_systems/2_sem/lab1/task2/build

# Include any dependencies generated for this target.
include CMakeFiles/task2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/task2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task2.dir/flags.make

CMakeFiles/task2.dir/task2.c.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/task2.c.o: /home/nikita/university/operation_systems/2_sem/lab1/task2/task2.c
CMakeFiles/task2.dir/task2.c.o: CMakeFiles/task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nikita/university/operation_systems/2_sem/lab1/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/task2.dir/task2.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/task2.dir/task2.c.o -MF CMakeFiles/task2.dir/task2.c.o.d -o CMakeFiles/task2.dir/task2.c.o -c /home/nikita/university/operation_systems/2_sem/lab1/task2/task2.c

CMakeFiles/task2.dir/task2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/task2.dir/task2.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/university/operation_systems/2_sem/lab1/task2/task2.c > CMakeFiles/task2.dir/task2.c.i

CMakeFiles/task2.dir/task2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/task2.dir/task2.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/university/operation_systems/2_sem/lab1/task2/task2.c -o CMakeFiles/task2.dir/task2.c.s

CMakeFiles/task2.dir/util_task2.c.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/util_task2.c.o: /home/nikita/university/operation_systems/2_sem/lab1/task2/util_task2.c
CMakeFiles/task2.dir/util_task2.c.o: CMakeFiles/task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nikita/university/operation_systems/2_sem/lab1/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/task2.dir/util_task2.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/task2.dir/util_task2.c.o -MF CMakeFiles/task2.dir/util_task2.c.o.d -o CMakeFiles/task2.dir/util_task2.c.o -c /home/nikita/university/operation_systems/2_sem/lab1/task2/util_task2.c

CMakeFiles/task2.dir/util_task2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/task2.dir/util_task2.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/university/operation_systems/2_sem/lab1/task2/util_task2.c > CMakeFiles/task2.dir/util_task2.c.i

CMakeFiles/task2.dir/util_task2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/task2.dir/util_task2.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/university/operation_systems/2_sem/lab1/task2/util_task2.c -o CMakeFiles/task2.dir/util_task2.c.s

CMakeFiles/task2.dir/errors.c.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/errors.c.o: /home/nikita/university/operation_systems/2_sem/lab1/task2/errors.c
CMakeFiles/task2.dir/errors.c.o: CMakeFiles/task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nikita/university/operation_systems/2_sem/lab1/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/task2.dir/errors.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/task2.dir/errors.c.o -MF CMakeFiles/task2.dir/errors.c.o.d -o CMakeFiles/task2.dir/errors.c.o -c /home/nikita/university/operation_systems/2_sem/lab1/task2/errors.c

CMakeFiles/task2.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/task2.dir/errors.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/university/operation_systems/2_sem/lab1/task2/errors.c > CMakeFiles/task2.dir/errors.c.i

CMakeFiles/task2.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/task2.dir/errors.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/university/operation_systems/2_sem/lab1/task2/errors.c -o CMakeFiles/task2.dir/errors.c.s

# Object files for target task2
task2_OBJECTS = \
"CMakeFiles/task2.dir/task2.c.o" \
"CMakeFiles/task2.dir/util_task2.c.o" \
"CMakeFiles/task2.dir/errors.c.o"

# External object files for target task2
task2_EXTERNAL_OBJECTS =

task2: CMakeFiles/task2.dir/task2.c.o
task2: CMakeFiles/task2.dir/util_task2.c.o
task2: CMakeFiles/task2.dir/errors.c.o
task2: CMakeFiles/task2.dir/build.make
task2: CMakeFiles/task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nikita/university/operation_systems/2_sem/lab1/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable task2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task2.dir/build: task2
.PHONY : CMakeFiles/task2.dir/build

CMakeFiles/task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task2.dir/clean

CMakeFiles/task2.dir/depend:
	cd /home/nikita/university/operation_systems/2_sem/lab1/task2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikita/university/operation_systems/2_sem/lab1/task2 /home/nikita/university/operation_systems/2_sem/lab1/task2 /home/nikita/university/operation_systems/2_sem/lab1/task2/build /home/nikita/university/operation_systems/2_sem/lab1/task2/build /home/nikita/university/operation_systems/2_sem/lab1/task2/build/CMakeFiles/task2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/task2.dir/depend

