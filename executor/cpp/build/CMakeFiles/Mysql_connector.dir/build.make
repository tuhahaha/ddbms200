# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/d/ddbms200/executor/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/ddbms200/executor/cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/Mysql_connector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Mysql_connector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Mysql_connector.dir/flags.make

CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.o: CMakeFiles/Mysql_connector.dir/flags.make
CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.o: ../mysql_connector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/ddbms200/executor/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.o"
	-I/usr/include/mysql  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.o -c /mnt/d/ddbms200/executor/cpp/mysql_connector.cpp

CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.i"
	-I/usr/include/mysql $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/ddbms200/executor/cpp/mysql_connector.cpp > CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.i

CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.s"
	-I/usr/include/mysql $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/ddbms200/executor/cpp/mysql_connector.cpp -o CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.s

# Object files for target Mysql_connector
Mysql_connector_OBJECTS = \
"CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.o"

# External object files for target Mysql_connector
Mysql_connector_EXTERNAL_OBJECTS =

libMysql_connector.a: CMakeFiles/Mysql_connector.dir/mysql_connector.cpp.o
libMysql_connector.a: CMakeFiles/Mysql_connector.dir/build.make
libMysql_connector.a: CMakeFiles/Mysql_connector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/ddbms200/executor/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMysql_connector.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Mysql_connector.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Mysql_connector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Mysql_connector.dir/build: libMysql_connector.a

.PHONY : CMakeFiles/Mysql_connector.dir/build

CMakeFiles/Mysql_connector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Mysql_connector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Mysql_connector.dir/clean

CMakeFiles/Mysql_connector.dir/depend:
	cd /mnt/d/ddbms200/executor/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/ddbms200/executor/cpp /mnt/d/ddbms200/executor/cpp /mnt/d/ddbms200/executor/cpp/build /mnt/d/ddbms200/executor/cpp/build /mnt/d/ddbms200/executor/cpp/build/CMakeFiles/Mysql_connector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Mysql_connector.dir/depend
