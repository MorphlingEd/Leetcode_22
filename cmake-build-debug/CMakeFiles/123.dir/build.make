# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\123.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\123.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\123.dir\flags.make

CMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.obj: CMakeFiles\123.dir\flags.make
CMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.obj: ..\Dynamic_Programming\123_Best_Time_Stock_III.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/123.dir/Dynamic_Programming/123_Best_Time_Stock_III.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.obj /FdCMakeFiles\123.dir\ /FS -c C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Dynamic_Programming\123_Best_Time_Stock_III.cpp
<<

CMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/123.dir/Dynamic_Programming/123_Best_Time_Stock_III.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Dynamic_Programming\123_Best_Time_Stock_III.cpp
<<

CMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/123.dir/Dynamic_Programming/123_Best_Time_Stock_III.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.s /c C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Dynamic_Programming\123_Best_Time_Stock_III.cpp
<<

# Object files for target 123
123_OBJECTS = \
"CMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.obj"

# External object files for target 123
123_EXTERNAL_OBJECTS =

123.exe: CMakeFiles\123.dir\Dynamic_Programming\123_Best_Time_Stock_III.cpp.obj
123.exe: CMakeFiles\123.dir\build.make
123.exe: CMakeFiles\123.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 123.exe"
	"C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\123.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\123.dir\objects1.rsp @<<
 /out:123.exe /implib:123.lib /pdb:C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\123.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\123.dir\build: 123.exe
.PHONY : CMakeFiles\123.dir\build

CMakeFiles\123.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\123.dir\cmake_clean.cmake
.PHONY : CMakeFiles\123.dir\clean

CMakeFiles\123.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22 C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22 C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles\123.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\123.dir\depend

