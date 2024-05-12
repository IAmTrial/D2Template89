/**
 * D2Template89
 * Copyright 2021-2024 Mir Drualga
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "d2_functions/d2win_functions/d2win_load_mpq.h"

#include <stddef.h>

#include "d2_dll.h"
#include "d2_std_types.h"
#include "d2_structs/d2_mpq_archive_handle.h"
#include "d2_version.h"

#if D2_VERSION <= D2_VERSION_1_10

typedef struct D2MpqArchiveHandle* (__fastcall *FuncType)(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    i32 unused__set_to_0,
    i32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    i32 priority);

#elif D2_VERSION <= D2_VERSION_1_13D

typedef struct D2MpqArchiveHandle* (*FuncType)(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    i32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    i32 priority);

struct D2MpqArchiveHandle* D2_D2Win_LoadMpq_1_11_Shim(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    i32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    i32 priority);

#endif

extern FuncType D2_D2Win_LoadMpq_FuncPtr;
FuncType D2_D2Win_LoadMpq_FuncPtr;

static ptrdiff_t GetOffset(void) {
#if D2_VERSION == D2_VERSION_1_09D
  return 0x142FB;
#elif D2_VERSION == D2_VERSION_1_10
  return 0x12399;
#elif D2_VERSION == D2_VERSION_1_12
  return 0x7E40;
#elif D2_VERSION == D2_VERSION_1_13C
  return 0x7E60;
#elif D2_VERSION == D2_VERSION_1_13D
  return 0x7E50;
#endif
}

/**
 * External
 */

void D2_D2Win_LoadMpq_Init(void) {
  D2_D2Win_LoadMpq_FuncPtr = (FuncType)D2Dll_GetAddressFromOffset(
      D2Dll_kD2Win,
      GetOffset());
}

#if D2_VERSION <= D2_VERSION_1_10

struct D2MpqArchiveHandle* D2_D2Win_LoadMpq(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    i32 unused__set_to_0,
    i32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    i32 priority) {
  return D2_D2Win_LoadMpq_FuncPtr(
      dll_file_name,
      mpq_file_name,
      mpq_name,
      unused__set_to_0,
      is_set_err_on_drive_query_fail,
      on_fail_callback,
      priority);
}

#elif D2_VERSION <= D2_VERSION_1_13D

struct D2MpqArchiveHandle* D2_D2Win_LoadMpq(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    i32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    i32 priority) {
  return D2_D2Win_LoadMpq_1_11_Shim(
      dll_file_name,
      mpq_file_name,
      mpq_name,
      is_set_err_on_drive_query_fail,
      on_fail_callback,
      priority);
}

#endif
