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
include CMakeFiles\Control_Hijack.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\Control_Hijack.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Control_Hijack.dir\flags.make

CMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.obj: CMakeFiles\Control_Hijack.dir\flags.make
CMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.obj: ..\Drafts\control_hijack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Control_Hijack.dir/Drafts/control_hijack.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.obj /FdCMakeFiles\Control_Hijack.dir\ /FS -c C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Drafts\control_hijack.c
<<

CMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Control_Hijack.dir/Drafts/control_hijack.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Drafts\control_hijack.c
<<

CMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Control_Hijack.dir/Drafts/control_hijack.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.s /c C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\Drafts\control_hijack.c
<<

# Object files for target Control_Hijack
Control_Hijack_OBJECTS = \
"CMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.obj"

# External object files for target Control_Hijack
Control_Hijack_EXTERNAL_OBJECTS =

Control_Hijack.exe: CMakeFiles\Control_Hijack.dir\Drafts\control_hijack.c.obj
Control_Hijack.exe: CMakeFiles\Control_Hijack.dir\build.make
Control_Hijack.exe: CMakeFiles\Control_Hijack.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Control_Hijack.exe"
	"C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Control_Hijack.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Control_Hijack.dir\objects1.rsp @<<
 /out:Control_Hijack.exe /implib:Control_Hijack.lib /pdb:C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\Control_Hijack.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Control_Hijack.dir\build: Control_Hijack.exe
.PHONY : CMakeFiles\Control_Hijack.dir\build

CMakeFiles\Control_Hijack.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Control_Hijack.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Control_Hijack.dir\clean

CMakeFiles\Control_Hijack.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22 C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22 C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug C:\Users\Morphling\Desktop\UoE_2021_2022\STEP\Leetcode_22\cmake-build-debug\CMakeFiles\Control_Hijack.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Control_Hijack.dir\depend
