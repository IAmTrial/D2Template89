# D2Template89
# Copyright 2021 Mir Drualga
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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

# List all of the source files here

set(SOURCE_FILES
    "src/resource.rc"

    "src/D2Constants.h"
    "src/D2DataTables.h"
    "src/D2PacketDef.h"
    "src/D2Patch.h"
    "src/D2PatchConst.h"
    "src/D2Ptrs.h"
    "src/D2Structs.h"
    "src/DLLmain.cpp"
    "src/DLLmain.h"
    "src/TemplateIncludes.h"
)

# Output DLL

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
