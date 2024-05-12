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

#ifndef D2TEMPLATE89_D2_FUNCTIONS_D2WIN_FUNCTIONS_D2WIN_LOAD_MPQ_H_
#define D2TEMPLATE89_D2_FUNCTIONS_D2WIN_FUNCTIONS_D2WIN_LOAD_MPQ_H_

#include "../../d2_std_types.h"
#include "../../d2_structs/d2_mpq_archive_handle.h"
#include "../../d2_version.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void D2_D2Win_LoadMpq_Init(void);

#if D2_VERSION <= D2_VERSION_1_10

struct D2MpqArchiveHandle* D2_D2Win_LoadMpq(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    i32 unused__set_to_0,
    i32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    i32 priority);

#elif D2_VERSION <= D2_VERSION_1_13D

struct D2MpqArchiveHandle* D2_D2Win_LoadMpq(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    i32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    i32 priority);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* D2TEMPLATE89_D2_FUNCTIONS_D2WIN_FUNCTIONS_D2WIN_LOAD_MPQ_H_ */
