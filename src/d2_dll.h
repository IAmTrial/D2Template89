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

#ifndef D2TEMPLATE89_D2_DLL_H_
#define D2TEMPLATE89_D2_DLL_H_

#include <stddef.h>
#include <wchar.h>
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum D2Dll {
  D2Dll_kBNClient,
  D2Dll_kD2Client,
  D2Dll_kD2CMP,
  D2Dll_kD2Common,
  D2Dll_kD2DDraw,
  D2Dll_kD2Direct3D,
  D2Dll_kD2GDI,
  D2Dll_kD2GFX,
  D2Dll_kD2Game,
  D2Dll_kD2Glide,
  D2Dll_kD2Lang,
  D2Dll_kD2Launch,
  D2Dll_kD2MCPClient,
  D2Dll_kD2Multi,
  D2Dll_kD2Net,
  D2Dll_kD2Sound,
  D2Dll_kD2Win,
  D2Dll_kFog,
  D2Dll_kStorm,
};

enum {
  D2Dll_kNumDlls = D2Dll_kStorm + 1,
};

const wchar_t* D2Dll_GetPath(enum D2Dll dll);
HMODULE D2Dll_GetModuleHandle(enum D2Dll dll);
void* D2Dll_GetAddressFromExportedName(enum D2Dll dll, const char* exported_name);
void* D2Dll_GetAddressFromOffset(enum D2Dll dll, ptrdiff_t offset);
void* D2Dll_GetAddressFromOrdinal(enum D2Dll dll, unsigned short ordinal);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* D2TEMPLATE89_D2_DLL_H_ */
