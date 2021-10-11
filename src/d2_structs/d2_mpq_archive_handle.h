/**
 * D2Template89
 * Copyright 2021 Mir Drualga
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

#ifndef D2TEMPLATE89_D2_STRUCTS_D2_MPQ_ARCHIVE_HANDLE_H_
#define D2TEMPLATE89_D2_STRUCTS_D2_MPQ_ARCHIVE_HANDLE_H_

#include <windows.h>

#include "../d2_std_types.h"

#pragma pack(push, 1)

/* sizeof: 0x10 */ struct D2MpqArchiveHandle {
  /* 0x00 */ void* mpq_archive;
  /* 0x04 */ char mpq_archive_path[MAX_PATH];
};

#pragma pack(pop)

#endif /* D2TEMPLATE89_D2_STRUCTS_D2_MPQ_ARCHIVE_HANDLE_H_ */
