# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tony\Dokumente\LoginApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tony\Dokumente\LoginApp\build

# Include any dependencies generated for this target.
include _deps/googletest-build/googletest/CMakeFiles/gtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/googletest-build/googletest/CMakeFiles/gtest.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/googletest-build/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/googletest-build/googletest/CMakeFiles/gtest.dir/flags.make

_deps/googletest-build/googletest/gtest_autogen/timestamp: C:/Qt_NewVersions/Qt6.6/6.6.3/mingw_64/./bin/moc.exe
_deps/googletest-build/googletest/gtest_autogen/timestamp: C:/Qt_NewVersions/Qt6.6/6.6.3/mingw_64/./bin/uic.exe
_deps/googletest-build/googletest/gtest_autogen/timestamp: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\tony\Dokumente\LoginApp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target gtest"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && "C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen C:/Users/tony/Dokumente/LoginApp/build/_deps/googletest-build/googletest/CMakeFiles/gtest_autogen.dir/AutogenInfo.json Release
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/tony/Dokumente/LoginApp/build/_deps/googletest-build/googletest/gtest_autogen/timestamp

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/flags.make
_deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/includes_CXX.rsp
_deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj: _deps/googletest-build/googletest/gtest_autogen/mocs_compilation.cpp
_deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tony\Dokumente\LoginApp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && C:\Qt_6.6\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\gtest.dir\gtest_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\gtest.dir\gtest_autogen\mocs_compilation.cpp.obj -c C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest\gtest_autogen\mocs_compilation.cpp

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.i"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && C:\Qt_6.6\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest\gtest_autogen\mocs_compilation.cpp > CMakeFiles\gtest.dir\gtest_autogen\mocs_compilation.cpp.i

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.s"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && C:\Qt_6.6\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest\gtest_autogen\mocs_compilation.cpp -o CMakeFiles\gtest.dir\gtest_autogen\mocs_compilation.cpp.s

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/flags.make
_deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/includes_CXX.rsp
_deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: _deps/googletest-src/googletest/src/gtest-all.cc
_deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tony\Dokumente\LoginApp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && C:\Qt_6.6\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj -MF CMakeFiles\gtest.dir\src\gtest-all.cc.obj.d -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-src\googletest\src\gtest-all.cc

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && C:\Qt_6.6\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-src\googletest\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && C:\Qt_6.6\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-src\googletest\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/gtest_autogen/mocs_compilation.cpp.obj
lib/libgtest.a: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
lib/libgtest.a: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: _deps/googletest-build/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\tony\Dokumente\LoginApp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ..\..\..\lib\libgtest.a"
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/googletest-build/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a
.PHONY : _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/clean:
	cd /d C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : _deps/googletest-build/googletest/CMakeFiles/gtest.dir/clean

_deps/googletest-build/googletest/CMakeFiles/gtest.dir/depend: _deps/googletest-build/googletest/gtest_autogen/timestamp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tony\Dokumente\LoginApp C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-src\googletest C:\Users\tony\Dokumente\LoginApp\build C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest C:\Users\tony\Dokumente\LoginApp\build\_deps\googletest-build\googletest\CMakeFiles\gtest.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/googletest-build/googletest/CMakeFiles/gtest.dir/depend

