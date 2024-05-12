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

#include "fog_free.h"

#include <stddef.h>

#include "../../d2_dll.h"
#include "../../d2_std_types.h"

typedef int (__fastcall *FuncType)(
    void* ptr,
    const char* source_file,
    i32 line,
    i32 unused__set_to_0);

static FuncType func_ptr;

static unsigned short GetOrdinal(void) {
  /* Valid for 1.07 and up. */
  return 10043;
}

/**
 * External
 */

void D2_Fog_Free_Init(void) {
  func_ptr = (FuncType)D2Dll_GetAddressFromOrdinal(
      D2Dll_kFog,
      GetOrdinal());
}

int D2_Fog_Free(
    void* ptr,
    const char* source_file,
    i32 line,
    i32 unused__set_to_0) {
  return func_ptr(ptr, source_file, line, unused__set_to_0);
}
