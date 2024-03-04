# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/aidan_oneill/Documents/julienne

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aidan_oneill/Documents/julienne

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/aidan_oneill/Documents/julienne/CMakeFiles /home/aidan_oneill/Documents/julienne//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/aidan_oneill/Documents/julienne/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named julienne

# Build rule for target.
julienne: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 julienne
.PHONY : julienne

# fast build rule for target.
julienne/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne.dir/build.make CMakeFiles/julienne.dir/build
.PHONY : julienne/fast

#=============================================================================
# Target rules for targets named julienne_files

# Build rule for target.
julienne_files: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 julienne_files
.PHONY : julienne_files

# fast build rule for target.
julienne_files/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/build
.PHONY : julienne_files/fast

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) $(MAKESILENT) -f test/CMakeFiles/test.dir/build.make test/CMakeFiles/test.dir/build
.PHONY : test/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) $(MAKESILENT) -f third_party/googletest/googlemock/CMakeFiles/gmock_main.dir/build.make third_party/googletest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) $(MAKESILENT) -f third_party/googletest/googlemock/CMakeFiles/gmock.dir/build.make third_party/googletest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) $(MAKESILENT) -f third_party/googletest/googletest/CMakeFiles/gtest_main.dir/build.make third_party/googletest/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) $(MAKESILENT) -f third_party/googletest/googletest/CMakeFiles/gtest.dir/build.make third_party/googletest/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne.dir/build.make CMakeFiles/julienne.dir/src/main.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne.dir/build.make CMakeFiles/julienne.dir/src/main.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne.dir/build.make CMakeFiles/julienne.dir/src/main.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/operator/csv_table_load_op.o: src/operator/csv_table_load_op.cpp.o
.PHONY : src/operator/csv_table_load_op.o

# target to build an object file
src/operator/csv_table_load_op.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/csv_table_load_op.cpp.o
.PHONY : src/operator/csv_table_load_op.cpp.o

src/operator/csv_table_load_op.i: src/operator/csv_table_load_op.cpp.i
.PHONY : src/operator/csv_table_load_op.i

# target to preprocess a source file
src/operator/csv_table_load_op.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/csv_table_load_op.cpp.i
.PHONY : src/operator/csv_table_load_op.cpp.i

src/operator/csv_table_load_op.s: src/operator/csv_table_load_op.cpp.s
.PHONY : src/operator/csv_table_load_op.s

# target to generate assembly for a file
src/operator/csv_table_load_op.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/csv_table_load_op.cpp.s
.PHONY : src/operator/csv_table_load_op.cpp.s

src/operator/csv_table_store_op.o: src/operator/csv_table_store_op.cpp.o
.PHONY : src/operator/csv_table_store_op.o

# target to build an object file
src/operator/csv_table_store_op.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/csv_table_store_op.cpp.o
.PHONY : src/operator/csv_table_store_op.cpp.o

src/operator/csv_table_store_op.i: src/operator/csv_table_store_op.cpp.i
.PHONY : src/operator/csv_table_store_op.i

# target to preprocess a source file
src/operator/csv_table_store_op.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/csv_table_store_op.cpp.i
.PHONY : src/operator/csv_table_store_op.cpp.i

src/operator/csv_table_store_op.s: src/operator/csv_table_store_op.cpp.s
.PHONY : src/operator/csv_table_store_op.s

# target to generate assembly for a file
src/operator/csv_table_store_op.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/csv_table_store_op.cpp.s
.PHONY : src/operator/csv_table_store_op.cpp.s

src/operator/gather_op.o: src/operator/gather_op.cpp.o
.PHONY : src/operator/gather_op.o

# target to build an object file
src/operator/gather_op.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/gather_op.cpp.o
.PHONY : src/operator/gather_op.cpp.o

src/operator/gather_op.i: src/operator/gather_op.cpp.i
.PHONY : src/operator/gather_op.i

# target to preprocess a source file
src/operator/gather_op.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/gather_op.cpp.i
.PHONY : src/operator/gather_op.cpp.i

src/operator/gather_op.s: src/operator/gather_op.cpp.s
.PHONY : src/operator/gather_op.s

# target to generate assembly for a file
src/operator/gather_op.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/gather_op.cpp.s
.PHONY : src/operator/gather_op.cpp.s

src/operator/join_op.o: src/operator/join_op.cpp.o
.PHONY : src/operator/join_op.o

# target to build an object file
src/operator/join_op.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/join_op.cpp.o
.PHONY : src/operator/join_op.cpp.o

src/operator/join_op.i: src/operator/join_op.cpp.i
.PHONY : src/operator/join_op.i

# target to preprocess a source file
src/operator/join_op.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/join_op.cpp.i
.PHONY : src/operator/join_op.cpp.i

src/operator/join_op.s: src/operator/join_op.cpp.s
.PHONY : src/operator/join_op.s

# target to generate assembly for a file
src/operator/join_op.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/join_op.cpp.s
.PHONY : src/operator/join_op.cpp.s

src/operator/table_partition_op.o: src/operator/table_partition_op.cpp.o
.PHONY : src/operator/table_partition_op.o

# target to build an object file
src/operator/table_partition_op.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/table_partition_op.cpp.o
.PHONY : src/operator/table_partition_op.cpp.o

src/operator/table_partition_op.i: src/operator/table_partition_op.cpp.i
.PHONY : src/operator/table_partition_op.i

# target to preprocess a source file
src/operator/table_partition_op.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/table_partition_op.cpp.i
.PHONY : src/operator/table_partition_op.cpp.i

src/operator/table_partition_op.s: src/operator/table_partition_op.cpp.s
.PHONY : src/operator/table_partition_op.s

# target to generate assembly for a file
src/operator/table_partition_op.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/operator/table_partition_op.cpp.s
.PHONY : src/operator/table_partition_op.cpp.s

src/planner/pisi_planner.o: src/planner/pisi_planner.cpp.o
.PHONY : src/planner/pisi_planner.o

# target to build an object file
src/planner/pisi_planner.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/planner/pisi_planner.cpp.o
.PHONY : src/planner/pisi_planner.cpp.o

src/planner/pisi_planner.i: src/planner/pisi_planner.cpp.i
.PHONY : src/planner/pisi_planner.i

# target to preprocess a source file
src/planner/pisi_planner.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/planner/pisi_planner.cpp.i
.PHONY : src/planner/pisi_planner.cpp.i

src/planner/pisi_planner.s: src/planner/pisi_planner.cpp.s
.PHONY : src/planner/pisi_planner.s

# target to generate assembly for a file
src/planner/pisi_planner.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/planner/pisi_planner.cpp.s
.PHONY : src/planner/pisi_planner.cpp.s

src/planner/sipi_planner.o: src/planner/sipi_planner.cpp.o
.PHONY : src/planner/sipi_planner.o

# target to build an object file
src/planner/sipi_planner.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/planner/sipi_planner.cpp.o
.PHONY : src/planner/sipi_planner.cpp.o

src/planner/sipi_planner.i: src/planner/sipi_planner.cpp.i
.PHONY : src/planner/sipi_planner.i

# target to preprocess a source file
src/planner/sipi_planner.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/planner/sipi_planner.cpp.i
.PHONY : src/planner/sipi_planner.cpp.i

src/planner/sipi_planner.s: src/planner/sipi_planner.cpp.s
.PHONY : src/planner/sipi_planner.s

# target to generate assembly for a file
src/planner/sipi_planner.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/planner/sipi_planner.cpp.s
.PHONY : src/planner/sipi_planner.cpp.s

src/scheduler/adaptivescheduler.o: src/scheduler/adaptivescheduler.cpp.o
.PHONY : src/scheduler/adaptivescheduler.o

# target to build an object file
src/scheduler/adaptivescheduler.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/scheduler/adaptivescheduler.cpp.o
.PHONY : src/scheduler/adaptivescheduler.cpp.o

src/scheduler/adaptivescheduler.i: src/scheduler/adaptivescheduler.cpp.i
.PHONY : src/scheduler/adaptivescheduler.i

# target to preprocess a source file
src/scheduler/adaptivescheduler.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/scheduler/adaptivescheduler.cpp.i
.PHONY : src/scheduler/adaptivescheduler.cpp.i

src/scheduler/adaptivescheduler.s: src/scheduler/adaptivescheduler.cpp.s
.PHONY : src/scheduler/adaptivescheduler.s

# target to generate assembly for a file
src/scheduler/adaptivescheduler.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/scheduler/adaptivescheduler.cpp.s
.PHONY : src/scheduler/adaptivescheduler.cpp.s

src/scheduler/scheduler.o: src/scheduler/scheduler.cpp.o
.PHONY : src/scheduler/scheduler.o

# target to build an object file
src/scheduler/scheduler.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/scheduler/scheduler.cpp.o
.PHONY : src/scheduler/scheduler.cpp.o

src/scheduler/scheduler.i: src/scheduler/scheduler.cpp.i
.PHONY : src/scheduler/scheduler.i

# target to preprocess a source file
src/scheduler/scheduler.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/scheduler/scheduler.cpp.i
.PHONY : src/scheduler/scheduler.cpp.i

src/scheduler/scheduler.s: src/scheduler/scheduler.cpp.s
.PHONY : src/scheduler/scheduler.s

# target to generate assembly for a file
src/scheduler/scheduler.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/scheduler/scheduler.cpp.s
.PHONY : src/scheduler/scheduler.cpp.s

src/thrift/Calculator.o: src/thrift/Calculator.cpp.o
.PHONY : src/thrift/Calculator.o

# target to build an object file
src/thrift/Calculator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/Calculator.cpp.o
.PHONY : src/thrift/Calculator.cpp.o

src/thrift/Calculator.i: src/thrift/Calculator.cpp.i
.PHONY : src/thrift/Calculator.i

# target to preprocess a source file
src/thrift/Calculator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/Calculator.cpp.i
.PHONY : src/thrift/Calculator.cpp.i

src/thrift/Calculator.s: src/thrift/Calculator.cpp.s
.PHONY : src/thrift/Calculator.s

# target to generate assembly for a file
src/thrift/Calculator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/Calculator.cpp.s
.PHONY : src/thrift/Calculator.cpp.s

src/thrift/Calculator_server.skeleton.o: src/thrift/Calculator_server.skeleton.cpp.o
.PHONY : src/thrift/Calculator_server.skeleton.o

# target to build an object file
src/thrift/Calculator_server.skeleton.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/Calculator_server.skeleton.cpp.o
.PHONY : src/thrift/Calculator_server.skeleton.cpp.o

src/thrift/Calculator_server.skeleton.i: src/thrift/Calculator_server.skeleton.cpp.i
.PHONY : src/thrift/Calculator_server.skeleton.i

# target to preprocess a source file
src/thrift/Calculator_server.skeleton.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/Calculator_server.skeleton.cpp.i
.PHONY : src/thrift/Calculator_server.skeleton.cpp.i

src/thrift/Calculator_server.skeleton.s: src/thrift/Calculator_server.skeleton.cpp.s
.PHONY : src/thrift/Calculator_server.skeleton.s

# target to generate assembly for a file
src/thrift/Calculator_server.skeleton.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/Calculator_server.skeleton.cpp.s
.PHONY : src/thrift/Calculator_server.skeleton.cpp.s

src/thrift/SharedService.o: src/thrift/SharedService.cpp.o
.PHONY : src/thrift/SharedService.o

# target to build an object file
src/thrift/SharedService.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/SharedService.cpp.o
.PHONY : src/thrift/SharedService.cpp.o

src/thrift/SharedService.i: src/thrift/SharedService.cpp.i
.PHONY : src/thrift/SharedService.i

# target to preprocess a source file
src/thrift/SharedService.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/SharedService.cpp.i
.PHONY : src/thrift/SharedService.cpp.i

src/thrift/SharedService.s: src/thrift/SharedService.cpp.s
.PHONY : src/thrift/SharedService.s

# target to generate assembly for a file
src/thrift/SharedService.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/SharedService.cpp.s
.PHONY : src/thrift/SharedService.cpp.s

src/thrift/SharedService_server.skeleton.o: src/thrift/SharedService_server.skeleton.cpp.o
.PHONY : src/thrift/SharedService_server.skeleton.o

# target to build an object file
src/thrift/SharedService_server.skeleton.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/SharedService_server.skeleton.cpp.o
.PHONY : src/thrift/SharedService_server.skeleton.cpp.o

src/thrift/SharedService_server.skeleton.i: src/thrift/SharedService_server.skeleton.cpp.i
.PHONY : src/thrift/SharedService_server.skeleton.i

# target to preprocess a source file
src/thrift/SharedService_server.skeleton.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/SharedService_server.skeleton.cpp.i
.PHONY : src/thrift/SharedService_server.skeleton.cpp.i

src/thrift/SharedService_server.skeleton.s: src/thrift/SharedService_server.skeleton.cpp.s
.PHONY : src/thrift/SharedService_server.skeleton.s

# target to generate assembly for a file
src/thrift/SharedService_server.skeleton.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/SharedService_server.skeleton.cpp.s
.PHONY : src/thrift/SharedService_server.skeleton.cpp.s

src/thrift/shared_types.o: src/thrift/shared_types.cpp.o
.PHONY : src/thrift/shared_types.o

# target to build an object file
src/thrift/shared_types.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/shared_types.cpp.o
.PHONY : src/thrift/shared_types.cpp.o

src/thrift/shared_types.i: src/thrift/shared_types.cpp.i
.PHONY : src/thrift/shared_types.i

# target to preprocess a source file
src/thrift/shared_types.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/shared_types.cpp.i
.PHONY : src/thrift/shared_types.cpp.i

src/thrift/shared_types.s: src/thrift/shared_types.cpp.s
.PHONY : src/thrift/shared_types.s

# target to generate assembly for a file
src/thrift/shared_types.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/shared_types.cpp.s
.PHONY : src/thrift/shared_types.cpp.s

src/thrift/tutorial_constants.o: src/thrift/tutorial_constants.cpp.o
.PHONY : src/thrift/tutorial_constants.o

# target to build an object file
src/thrift/tutorial_constants.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/tutorial_constants.cpp.o
.PHONY : src/thrift/tutorial_constants.cpp.o

src/thrift/tutorial_constants.i: src/thrift/tutorial_constants.cpp.i
.PHONY : src/thrift/tutorial_constants.i

# target to preprocess a source file
src/thrift/tutorial_constants.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/tutorial_constants.cpp.i
.PHONY : src/thrift/tutorial_constants.cpp.i

src/thrift/tutorial_constants.s: src/thrift/tutorial_constants.cpp.s
.PHONY : src/thrift/tutorial_constants.s

# target to generate assembly for a file
src/thrift/tutorial_constants.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/tutorial_constants.cpp.s
.PHONY : src/thrift/tutorial_constants.cpp.s

src/thrift/tutorial_types.o: src/thrift/tutorial_types.cpp.o
.PHONY : src/thrift/tutorial_types.o

# target to build an object file
src/thrift/tutorial_types.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/tutorial_types.cpp.o
.PHONY : src/thrift/tutorial_types.cpp.o

src/thrift/tutorial_types.i: src/thrift/tutorial_types.cpp.i
.PHONY : src/thrift/tutorial_types.i

# target to preprocess a source file
src/thrift/tutorial_types.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/tutorial_types.cpp.i
.PHONY : src/thrift/tutorial_types.cpp.i

src/thrift/tutorial_types.s: src/thrift/tutorial_types.cpp.s
.PHONY : src/thrift/tutorial_types.s

# target to generate assembly for a file
src/thrift/tutorial_types.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/thrift/tutorial_types.cpp.s
.PHONY : src/thrift/tutorial_types.cpp.s

src/value.o: src/value.cpp.o
.PHONY : src/value.o

# target to build an object file
src/value.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/value.cpp.o
.PHONY : src/value.cpp.o

src/value.i: src/value.cpp.i
.PHONY : src/value.i

# target to preprocess a source file
src/value.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/value.cpp.i
.PHONY : src/value.cpp.i

src/value.s: src/value.cpp.s
.PHONY : src/value.s

# target to generate assembly for a file
src/value.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/julienne_files.dir/build.make CMakeFiles/julienne_files.dir/src/value.cpp.s
.PHONY : src/value.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... gmock"
	@echo "... gmock_main"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... julienne"
	@echo "... julienne_files"
	@echo "... test"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/operator/csv_table_load_op.o"
	@echo "... src/operator/csv_table_load_op.i"
	@echo "... src/operator/csv_table_load_op.s"
	@echo "... src/operator/csv_table_store_op.o"
	@echo "... src/operator/csv_table_store_op.i"
	@echo "... src/operator/csv_table_store_op.s"
	@echo "... src/operator/gather_op.o"
	@echo "... src/operator/gather_op.i"
	@echo "... src/operator/gather_op.s"
	@echo "... src/operator/join_op.o"
	@echo "... src/operator/join_op.i"
	@echo "... src/operator/join_op.s"
	@echo "... src/operator/table_partition_op.o"
	@echo "... src/operator/table_partition_op.i"
	@echo "... src/operator/table_partition_op.s"
	@echo "... src/planner/pisi_planner.o"
	@echo "... src/planner/pisi_planner.i"
	@echo "... src/planner/pisi_planner.s"
	@echo "... src/planner/sipi_planner.o"
	@echo "... src/planner/sipi_planner.i"
	@echo "... src/planner/sipi_planner.s"
	@echo "... src/scheduler/adaptivescheduler.o"
	@echo "... src/scheduler/adaptivescheduler.i"
	@echo "... src/scheduler/adaptivescheduler.s"
	@echo "... src/scheduler/scheduler.o"
	@echo "... src/scheduler/scheduler.i"
	@echo "... src/scheduler/scheduler.s"
	@echo "... src/thrift/Calculator.o"
	@echo "... src/thrift/Calculator.i"
	@echo "... src/thrift/Calculator.s"
	@echo "... src/thrift/Calculator_server.skeleton.o"
	@echo "... src/thrift/Calculator_server.skeleton.i"
	@echo "... src/thrift/Calculator_server.skeleton.s"
	@echo "... src/thrift/SharedService.o"
	@echo "... src/thrift/SharedService.i"
	@echo "... src/thrift/SharedService.s"
	@echo "... src/thrift/SharedService_server.skeleton.o"
	@echo "... src/thrift/SharedService_server.skeleton.i"
	@echo "... src/thrift/SharedService_server.skeleton.s"
	@echo "... src/thrift/shared_types.o"
	@echo "... src/thrift/shared_types.i"
	@echo "... src/thrift/shared_types.s"
	@echo "... src/thrift/tutorial_constants.o"
	@echo "... src/thrift/tutorial_constants.i"
	@echo "... src/thrift/tutorial_constants.s"
	@echo "... src/thrift/tutorial_types.o"
	@echo "... src/thrift/tutorial_types.i"
	@echo "... src/thrift/tutorial_types.s"
	@echo "... src/value.o"
	@echo "... src/value.i"
	@echo "... src/value.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

