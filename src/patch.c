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

/****************************************************************************
*                                                                           *
*   DLLmain.h                                                               *
*                                                                           *
*   Licensed under the Apache License, Version 2.0 (the "License");         *
*   you may not use this file except in compliance with the License.        *
*   You may obtain a copy of the License at                                 *
*                                                                           *
*   http://www.apache.org/licenses/LICENSE-2.0                              *
*                                                                           *
*   Unless required by applicable law or agreed to in writing, software     *
*   distributed under the License is distributed on an "AS IS" BASIS,       *
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
*   See the License for the specific language governing permissions and     *
*   limitations under the License.                                          *
*                                                                           *
*****************************************************************************/

#include "patch.h"

#include <stddef.h>
#include <wchar.h>
#include <windows.h>

#include "d2_dll.h"
#include "dll_error.h"
#include "patch_const.h"

void ApplyNopPatch(
    struct Patch* patch,
    unsigned char* address,
    const unsigned char* data,
    BOOL* is_write_process_memory_success) {
  size_t remaining_size;

  remaining_size = patch->data_size;
  while (remaining_size > 0) {
    size_t bytes_write_count;

    bytes_write_count = (remaining_size > sizeof(kPatchNop))
        ? sizeof(kPatchNop)
        : remaining_size;
    *is_write_process_memory_success = WriteProcessMemory(
        GetCurrentProcess(),
        address,
        data,
        bytes_write_count,
        NULL);
    if (!(*is_write_process_memory_success)) {
      goto bad;
    }

    remaining_size -= bytes_write_count;
  }

  return;

bad:
  return;
}

/**
 * External
 */

void Patch_Apply(struct Patch* patch) {
  BOOL is_write_process_memory_success;

  unsigned char* base_address;
  unsigned char* address;
  const unsigned char* data;

  base_address = (unsigned char*)D2Dll_GetModuleHandle(patch->dll);
  address = D2Dll_GetAddressFromOffset(patch->dll, patch->offset);
  data = patch->data;

  if (patch->is_relative) {
    data = data - address - patch->data_size;
    is_write_process_memory_success = WriteProcessMemory(
        GetCurrentProcess(),
        address,
        &data,
        patch->data_size,
        NULL);
  } else if (patch->data == kPatchNop) {
    ApplyNopPatch(patch, address, data, &is_write_process_memory_success);
  } else {
    is_write_process_memory_success = WriteProcessMemory(
        GetCurrentProcess(),
        address,
        data,
        patch->data_size,
        NULL);
  }

  if (!is_write_process_memory_success) {
    enum {
      kMessageCapacity = 256,
    };
    wchar_t message[kMessageCapacity];

    _snwprintf(
        message,
        kMessageCapacity,
        L"WriteProcessMemory failed with error code 0x%X.",
        GetLastError());
    D2TEMPLATE_ExitWithMessage(message, __FILEW__, __LINE__);
    goto bad;
  }

  return;

bad:
  return;
}
