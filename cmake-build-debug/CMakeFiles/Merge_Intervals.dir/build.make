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
include CMakeFiles\Merge_Intervals.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\Merge_Intervals.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Merge_Intervals.dir\flags.make

CMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.obj: CMakeFiles\Merge_Intervals.dir\flags.make
CMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.obj: ..\Double_Pointer\56_Merge_Intervals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Merge_Intervals.dir/Double_Pointer/56_Merge_Intervals.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.obj /FdCMakeFiles\Merge_Intervals.dir\ /FS -c C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Double_Pointer\56_Merge_Intervals.cpp
<<

CMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Merge_Intervals.dir/Double_Pointer/56_Merge_Intervals.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Double_Pointer\56_Merge_Intervals.cpp
<<

CMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Merge_Intervals.dir/Double_Pointer/56_Merge_Intervals.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.s /c C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Double_Pointer\56_Merge_Intervals.cpp
<<

# Object files for target Merge_Intervals
Merge_Intervals_OBJECTS = \
"CMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.obj"

# External object files for target Merge_Intervals
Merge_Intervals_EXTERNAL_OBJECTS =

Merge_Intervals.exe: CMakeFiles\Merge_Intervals.dir\Double_Pointer\56_Merge_Intervals.cpp.obj
Merge_Intervals.exe: CMakeFiles\Merge_Intervals.dir\build.make
Merge_Intervals.exe: CMakeFiles\Merge_Intervals.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Merge_Intervals.exe"
	"C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Merge_Intervals.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Merge_Intervals.dir\objects1.rsp @<<
 /out:Merge_Intervals.exe /implib:Merge_Intervals.lib /pdb:C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\Merge_Intervals.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Merge_Intervals.dir\build: Merge_Intervals.exe
.PHONY : CMakeFiles\Merge_Intervals.dir\build

CMakeFiles\Merge_Intervals.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Merge_Intervals.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Merge_Intervals.dir\clean

CMakeFiles\Merge_Intervals.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22 C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22 C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles\Merge_Intervals.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Merge_Intervals.dir\depend
