# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/build

# Include any dependencies generated for this target.
include CMakeFiles/mqttClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mqttClient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mqttClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mqttClient.dir/flags.make

CMakeFiles/mqttClient.dir/mqttClient.c.o: CMakeFiles/mqttClient.dir/flags.make
CMakeFiles/mqttClient.dir/mqttClient.c.o: ../mqttClient.c
CMakeFiles/mqttClient.dir/mqttClient.c.o: CMakeFiles/mqttClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mqttClient.dir/mqttClient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mqttClient.dir/mqttClient.c.o -MF CMakeFiles/mqttClient.dir/mqttClient.c.o.d -o CMakeFiles/mqttClient.dir/mqttClient.c.o -c /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/mqttClient.c

CMakeFiles/mqttClient.dir/mqttClient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mqttClient.dir/mqttClient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/mqttClient.c > CMakeFiles/mqttClient.dir/mqttClient.c.i

CMakeFiles/mqttClient.dir/mqttClient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mqttClient.dir/mqttClient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/mqttClient.c -o CMakeFiles/mqttClient.dir/mqttClient.c.s

# Object files for target mqttClient
mqttClient_OBJECTS = \
"CMakeFiles/mqttClient.dir/mqttClient.c.o"

# External object files for target mqttClient
mqttClient_EXTERNAL_OBJECTS =

bin/mqttClient: CMakeFiles/mqttClient.dir/mqttClient.c.o
bin/mqttClient: CMakeFiles/mqttClient.dir/build.make
bin/mqttClient: CMakeFiles/mqttClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/mqttClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mqttClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mqttClient.dir/build: bin/mqttClient
.PHONY : CMakeFiles/mqttClient.dir/build

CMakeFiles/mqttClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mqttClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mqttClient.dir/clean

CMakeFiles/mqttClient.dir/depend:
	cd /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/build /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/build /mnt/d/3-Linuxshare/Code/c_program/33_mqtt/mqtt_prj/build/CMakeFiles/mqttClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mqttClient.dir/depend
