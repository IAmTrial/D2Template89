cmake_minimum_required(VERSION 3.10)

# Name of the project, also is the name of the file

project(RENAME_ME__RENAME_ME__RENAME_ME)

# Define requirements for C

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

# Define requirements for C++

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Enable NASM

set(CMAKE_ASM_NASM_OBJECT_FORMAT win32)
enable_language(ASM_NASM)

# Remove MinGW compiled binary "lib" prefix

if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# Output DLL

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(${PROJECT_NAME} PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/resource.rc"

  "${CMAKE_CURRENT_SOURCE_DIR}/d2_dll.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2_dll.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/d2_functions.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2_functions.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/d2_std_types.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2_structs.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/d2_variables.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2_variables.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/d2_version.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/dll_error.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/dll_error.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/dll_main.c"

  "${CMAKE_CURRENT_SOURCE_DIR}/patch.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/patch.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/patch_const.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/patch_const.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/patches.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/patches.h"
)

add_subdirectory("d2_constants")
add_subdirectory("d2_functions")
add_subdirectory("d2_structs")
add_subdirectory("d2_variables")

get_property(SOURCE_FILES TARGET ${PROJECT_NAME} PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
