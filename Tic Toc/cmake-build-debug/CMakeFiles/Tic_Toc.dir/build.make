# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programs\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Programming\Function\Tic Toc"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Programming\Function\Tic Toc\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Tic_Toc.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Tic_Toc.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Tic_Toc.dir\flags.make

CMakeFiles\Tic_Toc.dir\main.cpp.obj: CMakeFiles\Tic_Toc.dir\flags.make
CMakeFiles\Tic_Toc.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Programming\Function\Tic Toc\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tic_Toc.dir/main.cpp.obj"
	D:\pr\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Tic_Toc.dir\main.cpp.obj /FdCMakeFiles\Tic_Toc.dir\ /FS -c "D:\Programming\Function\Tic Toc\main.cpp"
<<

CMakeFiles\Tic_Toc.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tic_Toc.dir/main.cpp.i"
	D:\pr\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Tic_Toc.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Programming\Function\Tic Toc\main.cpp"
<<

CMakeFiles\Tic_Toc.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tic_Toc.dir/main.cpp.s"
	D:\pr\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Tic_Toc.dir\main.cpp.s /c "D:\Programming\Function\Tic Toc\main.cpp"
<<

# Object files for target Tic_Toc
Tic_Toc_OBJECTS = \
"CMakeFiles\Tic_Toc.dir\main.cpp.obj"

# External object files for target Tic_Toc
Tic_Toc_EXTERNAL_OBJECTS =

Tic_Toc.exe: CMakeFiles\Tic_Toc.dir\main.cpp.obj
Tic_Toc.exe: CMakeFiles\Tic_Toc.dir\build.make
Tic_Toc.exe: CMakeFiles\Tic_Toc.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Programming\Function\Tic Toc\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tic_Toc.exe"
	"D:\Programs\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Tic_Toc.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- D:\pr\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Tic_Toc.dir\objects1.rsp @<<
 /out:Tic_Toc.exe /implib:Tic_Toc.lib /pdb:"D:\Programming\Function\Tic Toc\cmake-build-debug\Tic_Toc.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Tic_Toc.dir\build: Tic_Toc.exe

.PHONY : CMakeFiles\Tic_Toc.dir\build

CMakeFiles\Tic_Toc.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tic_Toc.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Tic_Toc.dir\clean

CMakeFiles\Tic_Toc.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\Programming\Function\Tic Toc" "D:\Programming\Function\Tic Toc" "D:\Programming\Function\Tic Toc\cmake-build-debug" "D:\Programming\Function\Tic Toc\cmake-build-debug" "D:\Programming\Function\Tic Toc\cmake-build-debug\CMakeFiles\Tic_Toc.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Tic_Toc.dir\depend

