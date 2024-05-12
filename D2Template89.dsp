# Microsoft Developer Studio Project File - Name="D2Template89" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=D2Template89 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "D2Template89.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "D2Template89.mak" CFG="D2Template89 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "D2Template89 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "D2Template89 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "D2Template89 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "D2TEMPLATE89_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 libunicows.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "D2Template89 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "D2TEMPLATE89_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libunicows.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "D2Template89 - Win32 Release"
# Name "D2Template89 - Win32 Debug"
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "d2_constants"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\d2_constants\d2_unit_types.h
# End Source File
# End Group
# Begin Group "d2_functions"

# PROP Default_Filter ""
# Begin Group "d2win_functions"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\d2_functions\d2win_functions\d2win_load_mpq.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\d2win_functions\d2win_load_mpq.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\d2win_functions\d2win_load_mpq_shim.asm

!IF  "$(CFG)" == "D2Template89 - Win32 Release"

# Begin Custom Build
InputDir=.\src\d2_functions\d2win_functions
IntDir=.\Release
InputPath=.\src\d2_functions\d2win_functions\d2win_load_mpq_shim.asm
InputName=d2win_load_mpq_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "D2Template89 - Win32 Debug"

# Begin Custom Build
InputDir=.\src\d2_functions\d2win_functions
IntDir=.\Debug
InputPath=.\src\d2_functions\d2win_functions\d2win_load_mpq_shim.asm
InputName=d2win_load_mpq_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "fog_functions"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\d2_functions\fog_functions\fog_alloc.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\fog_functions\fog_alloc.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\fog_functions\fog_free.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\fog_functions\fog_free.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\d2_functions\d2win_functions.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\d2win_functions.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\fog_functions.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions\fog_functions.h
# End Source File
# End Group
# Begin Group "d2_structs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\d2_structs\d2_lrtb_rect.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_structs\d2_mpq_archive_handle.h
# End Source File
# End Group
# Begin Group "d2_variables"

# PROP Default_Filter ""
# Begin Group "bnclient_variables"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\d2_variables\bnclient_variables\bnclient_gateway_ip_v4_address.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_variables\bnclient_variables\bnclient_gateway_ip_v4_address.h
# End Source File
# End Group
# Begin Group "d2client_variables"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\d2_variables\d2client_variables\d2client_is_automap_open.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_variables\d2client_variables\d2client_is_automap_open.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\d2_variables\bnclient_variables.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_variables\bnclient_variables.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_variables\d2client_variables.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_variables\d2client_variables.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\d2_constants.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_dll.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_dll.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_functions.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_std_types.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_structs.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_variables.c
# End Source File
# Begin Source File

SOURCE=.\src\d2_variables.h
# End Source File
# Begin Source File

SOURCE=.\src\d2_version.h
# End Source File
# Begin Source File

SOURCE=.\src\dll_error.c
# End Source File
# Begin Source File

SOURCE=.\src\dll_error.h
# End Source File
# Begin Source File

SOURCE=.\src\dll_main.c
# End Source File
# Begin Source File

SOURCE=.\src\filew.h
# End Source File
# Begin Source File

SOURCE=.\src\patch.c
# End Source File
# Begin Source File

SOURCE=.\src\patch.h
# End Source File
# Begin Source File

SOURCE=.\src\patch_const.c
# End Source File
# Begin Source File

SOURCE=.\src\patch_const.h
# End Source File
# Begin Source File

SOURCE=.\src\patches.c
# End Source File
# Begin Source File

SOURCE=.\src\patches.h
# End Source File
# Begin Source File

SOURCE=.\src\resource.rc
# End Source File
# End Group
# End Target
# End Project
