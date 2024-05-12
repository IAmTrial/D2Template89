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
      static const wchar_t kPath[] = L"BNClient.dll";
      return kPath;
    }

    case D2Dll_kD2Client: {
      static const wchar_t kPath[] = L"D2Client.dll";
      return kPath;
    }

    case D2Dll_kD2CMP: {
      static const wchar_t kPath[] = L"D2CMP.dll";
      return kPath;
    }

    case D2Dll_kD2Common: {
      static const wchar_t kPath[] = L"D2Common.dll";
      return kPath;
    }

    case D2Dll_kD2DDraw: {
      static const wchar_t kPath[] = L"D2DDraw.dll";
      return kPath;
    }

    case D2Dll_kD2Direct3D: {
      static const wchar_t kPath[] = L"D2Direct3D.dll";
      return kPath;
    }

    case D2Dll_kD2GDI: {
      static const wchar_t kPath[] = L"D2GDI.dll";
      return kPath;
    }

    case D2Dll_kD2GFX: {
      static const wchar_t kPath[] = L"D2GFX.dll";
      return kPath;
    }

    case D2Dll_kD2Game: {
      static const wchar_t kPath[] = L"D2Game.dll";
      return kPath;
    }

    case D2Dll_kD2Glide: {
      static const wchar_t kPath[] = L"D2Glide.dll";
      return kPath;
    }

    case D2Dll_kD2Lang: {
      static const wchar_t kPath[] = L"D2Lang.dll";
      return kPath;
    }

    case D2Dll_kD2Launch: {
      static const wchar_t kPath[] = L"D2Launch.dll";
      return kPath;
    }

    case D2Dll_kD2MCPClient: {
      static const wchar_t kPath[] = L"D2MCPClient.dll";
      return kPath;
    }

    case D2Dll_kD2Multi: {
      static const wchar_t kPath[] = L"D2Multi.dll";
      return kPath;
    }

    case D2Dll_kD2Net: {
      static const wchar_t kPath[] = L"D2Net.dll";
      return kPath;
    }

    case D2Dll_kD2Sound: {
      static const wchar_t kPath[] = L"D2Sound.dll";
      return kPath;
    }

    case D2Dll_kD2Win: {
      static const wchar_t kPath[] = L"D2Win.dll";
      return kPath;
    }

    case D2Dll_kFog: {
      static const wchar_t kPath[] = L"Fog.dll";
      return kPath;
    }

    case D2Dll_kStorm: {
      static const wchar_t kPath[] = L"Storm.dll";
      return kPath;
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
