# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/brick-breaker-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/brick-breaker-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/brick-breaker-test.dir/flags.make

Debug/brick-breaker-test/brick-breaker-test.app/Contents/Resources/CinderApp.icns: /Users/trishamenon/Desktop/Cinder/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/brick-breaker-test/brick-breaker-test.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/trishamenon/Desktop/Cinder/samples/data/CinderApp.icns Debug/brick-breaker-test/brick-breaker-test.app/Contents/Resources/CinderApp.icns

CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.o: ../tests/test_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_main.cc

CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_main.cc > CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.i

CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_main.cc -o CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.s

CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.o: ../src/brick_breaker_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/brick_breaker_app.cc

CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/brick_breaker_app.cc > CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.i

CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/brick_breaker_app.cc -o CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.s

CMakeFiles/brick-breaker-test.dir/src/game_container.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/src/game_container.cc.o: ../src/game_container.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/brick-breaker-test.dir/src/game_container.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/src/game_container.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/game_container.cc

CMakeFiles/brick-breaker-test.dir/src/game_container.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/src/game_container.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/game_container.cc > CMakeFiles/brick-breaker-test.dir/src/game_container.cc.i

CMakeFiles/brick-breaker-test.dir/src/game_container.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/src/game_container.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/game_container.cc -o CMakeFiles/brick-breaker-test.dir/src/game_container.cc.s

CMakeFiles/brick-breaker-test.dir/src/ball.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/src/ball.cc.o: ../src/ball.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/brick-breaker-test.dir/src/ball.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/src/ball.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/ball.cc

CMakeFiles/brick-breaker-test.dir/src/ball.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/src/ball.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/ball.cc > CMakeFiles/brick-breaker-test.dir/src/ball.cc.i

CMakeFiles/brick-breaker-test.dir/src/ball.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/src/ball.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/ball.cc -o CMakeFiles/brick-breaker-test.dir/src/ball.cc.s

CMakeFiles/brick-breaker-test.dir/src/paddle.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/src/paddle.cc.o: ../src/paddle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/brick-breaker-test.dir/src/paddle.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/src/paddle.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/paddle.cc

CMakeFiles/brick-breaker-test.dir/src/paddle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/src/paddle.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/paddle.cc > CMakeFiles/brick-breaker-test.dir/src/paddle.cc.i

CMakeFiles/brick-breaker-test.dir/src/paddle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/src/paddle.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/paddle.cc -o CMakeFiles/brick-breaker-test.dir/src/paddle.cc.s

CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.o: ../src/physics_engine.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/physics_engine.cc

CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/physics_engine.cc > CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.i

CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/src/physics_engine.cc -o CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.s

CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.o: ../tests/test_game_container.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_game_container.cc

CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_game_container.cc > CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.i

CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_game_container.cc -o CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.s

CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.o: ../tests/test_paddle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_paddle.cc

CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_paddle.cc > CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.i

CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_paddle.cc -o CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.s

CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.o: CMakeFiles/brick-breaker-test.dir/flags.make
CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.o: ../tests/test_physics_engine.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.o -c /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_physics_engine.cc

CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_physics_engine.cc > CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.i

CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/tests/test_physics_engine.cc -o CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.s

# Object files for target brick-breaker-test
brick__breaker__test_OBJECTS = \
"CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.o" \
"CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.o" \
"CMakeFiles/brick-breaker-test.dir/src/game_container.cc.o" \
"CMakeFiles/brick-breaker-test.dir/src/ball.cc.o" \
"CMakeFiles/brick-breaker-test.dir/src/paddle.cc.o" \
"CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.o" \
"CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.o" \
"CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.o" \
"CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.o"

# External object files for target brick-breaker-test
brick__breaker__test_EXTERNAL_OBJECTS =

Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/tests/test_main.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/src/brick_breaker_app.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/src/game_container.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/src/ball.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/src/paddle.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/src/physics_engine.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/tests/test_game_container.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/tests/test_paddle.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/tests/test_physics_engine.cc.o
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/build.make
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: /Users/trishamenon/Desktop/Cinder/lib/macosx/Debug/libcinder.a
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: /Users/trishamenon/Desktop/Cinder/lib/macosx/libboost_system.a
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: /Users/trishamenon/Desktop/Cinder/lib/macosx/libboost_filesystem.a
Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test: CMakeFiles/brick-breaker-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/brick-breaker-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/brick-breaker-test.dir/build: Debug/brick-breaker-test/brick-breaker-test.app/Contents/MacOS/brick-breaker-test
CMakeFiles/brick-breaker-test.dir/build: Debug/brick-breaker-test/brick-breaker-test.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/brick-breaker-test.dir/build

CMakeFiles/brick-breaker-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/brick-breaker-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/brick-breaker-test.dir/clean

CMakeFiles/brick-breaker-test.dir/depend:
	cd /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13 /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13 /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug /Users/trishamenon/Desktop/Cinder/my-projects/final-project-trisham13/cmake-build-debug/CMakeFiles/brick-breaker-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/brick-breaker-test.dir/depend

