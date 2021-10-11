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

#include "d2_dll.h"

#include <stddef.h>
#include <wchar.h>
#include <windows.h>

#include "dll_error.h"
#include "filew.h"

void* d2dll_base_address_table[D2Dll_kNumDlls] = { 0 };

/**
 * External
 */

const wchar_t* D2Dll_GetPath(enum D2Dll dll) {
  switch (dll) {
    case D2Dll_kBNClient: {
      return L"BNClient.dll";
    }

    case D2Dll_kD2Client: {
      return L"D2Client.dll";
    }

    case D2Dll_kD2CMP: {
      return L"D2CMP.dll";
    }

    case D2Dll_kD2Common: {
      return L"D2Common.dll";
    }

    case D2Dll_kD2DDraw: {
      return L"D2DDraw.dll";
    }

    case D2Dll_kD2Direct3D: {
      return L"D2Direct3D.dll";
    }

    case D2Dll_kD2GDI: {
      return L"D2GDI.dll";
    }

    case D2Dll_kD2GFX: {
      return L"D2GFX.dll";
    }

    case D2Dll_kD2Game: {
      return L"D2Game.dll";
    }

    case D2Dll_kD2Glide: {
      return L"D2Glide.dll";
    }

    case D2Dll_kD2Lang: {
      return L"D2Lang.dll";
    }

    case D2Dll_kD2Launch: {
      return L"D2Launch.dll";
    }

    case D2Dll_kD2MCPClient: {
      return L"D2MCPClient.dll";
    }

    case D2Dll_kD2Multi: {
      return L"D2Multi.dll";
    }

    case D2Dll_kD2Net: {
      return L"D2Net.dll";
    }

    case D2Dll_kD2Sound: {
      return L"D2Sound.dll";
    }

    case D2Dll_kD2Win: {
      return L"D2Win.dll";
    }

    case D2Dll_kFog: {
      return L"Fog.dll";
    }

    case D2Dll_kStorm: {
      return L"Storm.dll";
    }

    default: {
      enum {
        kMessageCapacity = 64,
      };
      wchar_t message[kMessageCapacity];

      _snwprintf(
          message,
          kMessageCapacity,
          L"Unrecognized DLL with value %d.",
          dll);
      D2TEMPLATE_ExitWithMessage(message, __FILEW__, __LINE__);
      return L"";
    }
  }
}

HMODULE D2Dll_GetModuleHandle(enum D2Dll dll) {
  if (d2dll_base_address_table[dll] == NULL) {
    const wchar_t* path;

    path = D2Dll_GetPath(dll);
    d2dll_base_address_table[dll] = LoadLibraryW(path);
    if (d2dll_base_address_table[dll] == NULL) {
      wchar_t message[MAX_PATH + 21];

      _snwprintf(
          message,
          MAX_PATH + 21,
          L"Could not load DLL: %ls",
          path);
      D2TEMPLATE_ExitWithMessage(message, __FILEW__, __LINE__);

      goto bad_return;
    }
  }

  return d2dll_base_address_table[dll];

bad_return:
  return NULL;
}

void* D2Dll_GetAddressFromExportedName(enum D2Dll dll, const char* exported_name) {
  HMODULE module_handle;
  FARPROC address;

  module_handle = D2Dll_GetModuleHandle(dll);
  address = GetProcAddress(module_handle, exported_name);
  if (address == NULL) {
    enum {
      kMessageCapacity = 256,
    };

    wchar_t message[kMessageCapacity];

    _snwprintf(
        message,
        kMessageCapacity,
        L"GetProcAddress failed with error code 0x%X.",
        GetLastError());
    D2TEMPLATE_ExitWithMessage(message, __FILEW__, __LINE__);
    goto bad_return;
  }

  return address;

bad_return:
  return NULL;
}

void* D2Dll_GetAddressFromOffset(enum D2Dll dll, ptrdiff_t offset) {
  char* base_address;

  base_address = (char*)D2Dll_GetModuleHandle(dll);

  return base_address + offset;
}

void* D2Dll_GetAddressFromOrdinal(enum D2Dll dll, unsigned short ordinal) {
  HMODULE module_handle;
  FARPROC address;

  module_handle = D2Dll_GetModuleHandle(dll);
  address = GetProcAddress(module_handle, (LPCSTR)ordinal);
  if (address == NULL) {
    enum {
      kMessageCapacity = 256,
    };

    wchar_t message[kMessageCapacity];

    _snwprintf(
        message,
        kMessageCapacity,
        L"GetProcAddress failed with error code 0x%X.",
        GetLastError());
    D2TEMPLATE_ExitWithMessage(message, __FILEW__, __LINE__);
    goto bad_return;
  }

  return address;

bad_return:
  return NULL;
}
