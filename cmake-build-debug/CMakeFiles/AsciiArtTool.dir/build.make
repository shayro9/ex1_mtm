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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\shayr\Documents\GitHub\ex1_mtm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\AsciiArtTool.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\AsciiArtTool.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\AsciiArtTool.dir\flags.make

CMakeFiles\AsciiArtTool.dir\RLEList.c.obj: CMakeFiles\AsciiArtTool.dir\flags.make
CMakeFiles\AsciiArtTool.dir\RLEList.c.obj: ..\RLEList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AsciiArtTool.dir/RLEList.c.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\AsciiArtTool.dir\RLEList.c.obj /FdCMakeFiles\AsciiArtTool.dir\ /FS -c C:\Users\shayr\Documents\GitHub\ex1_mtm\RLEList.c
<<

CMakeFiles\AsciiArtTool.dir\RLEList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AsciiArtTool.dir/RLEList.c.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\AsciiArtTool.dir\RLEList.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\shayr\Documents\GitHub\ex1_mtm\RLEList.c
<<

CMakeFiles\AsciiArtTool.dir\RLEList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AsciiArtTool.dir/RLEList.c.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\AsciiArtTool.dir\RLEList.c.s /c C:\Users\shayr\Documents\GitHub\ex1_mtm\RLEList.c
<<

CMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.obj: CMakeFiles\AsciiArtTool.dir\flags.make
CMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.obj: ..\tool\AsciiArtTool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/AsciiArtTool.dir/tool/AsciiArtTool.c.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.obj /FdCMakeFiles\AsciiArtTool.dir\ /FS -c C:\Users\shayr\Documents\GitHub\ex1_mtm\tool\AsciiArtTool.c
<<

CMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AsciiArtTool.dir/tool/AsciiArtTool.c.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\shayr\Documents\GitHub\ex1_mtm\tool\AsciiArtTool.c
<<

CMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AsciiArtTool.dir/tool/AsciiArtTool.c.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.s /c C:\Users\shayr\Documents\GitHub\ex1_mtm\tool\AsciiArtTool.c
<<

CMakeFiles\AsciiArtTool.dir\tool\main.c.obj: CMakeFiles\AsciiArtTool.dir\flags.make
CMakeFiles\AsciiArtTool.dir\tool\main.c.obj: ..\tool\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/AsciiArtTool.dir/tool/main.c.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\AsciiArtTool.dir\tool\main.c.obj /FdCMakeFiles\AsciiArtTool.dir\ /FS -c C:\Users\shayr\Documents\GitHub\ex1_mtm\tool\main.c
<<

CMakeFiles\AsciiArtTool.dir\tool\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AsciiArtTool.dir/tool/main.c.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\AsciiArtTool.dir\tool\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\shayr\Documents\GitHub\ex1_mtm\tool\main.c
<<

CMakeFiles\AsciiArtTool.dir\tool\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AsciiArtTool.dir/tool/main.c.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\AsciiArtTool.dir\tool\main.c.s /c C:\Users\shayr\Documents\GitHub\ex1_mtm\tool\main.c
<<

# Object files for target AsciiArtTool
AsciiArtTool_OBJECTS = \
"CMakeFiles\AsciiArtTool.dir\RLEList.c.obj" \
"CMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.obj" \
"CMakeFiles\AsciiArtTool.dir\tool\main.c.obj"

# External object files for target AsciiArtTool
AsciiArtTool_EXTERNAL_OBJECTS =

AsciiArtTool.exe: CMakeFiles\AsciiArtTool.dir\RLEList.c.obj
AsciiArtTool.exe: CMakeFiles\AsciiArtTool.dir\tool\AsciiArtTool.c.obj
AsciiArtTool.exe: CMakeFiles\AsciiArtTool.dir\tool\main.c.obj
AsciiArtTool.exe: CMakeFiles\AsciiArtTool.dir\build.make
AsciiArtTool.exe: CMakeFiles\AsciiArtTool.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable AsciiArtTool.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\AsciiArtTool.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\AsciiArtTool.dir\objects1.rsp @<<
 /out:AsciiArtTool.exe /implib:AsciiArtTool.lib /pdb:C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug\AsciiArtTool.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\AsciiArtTool.dir\build: AsciiArtTool.exe
.PHONY : CMakeFiles\AsciiArtTool.dir\build

CMakeFiles\AsciiArtTool.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AsciiArtTool.dir\cmake_clean.cmake
.PHONY : CMakeFiles\AsciiArtTool.dir\clean

CMakeFiles\AsciiArtTool.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\shayr\Documents\GitHub\ex1_mtm C:\Users\shayr\Documents\GitHub\ex1_mtm C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug C:\Users\shayr\Documents\GitHub\ex1_mtm\cmake-build-debug\CMakeFiles\AsciiArtTool.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\AsciiArtTool.dir\depend

