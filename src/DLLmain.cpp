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
*---------------------------------------------------------------------------*
*                                                                           *
*   https://github.com/olivier-verville/D2Template                          *
*                                                                           *
*   D2Template core file, do not modify unless you know what you're doing   *
*                                                                           *
*****************************************************************************/

#include <windows.h>

#include "DllError.h"
#include "patches.h"

int __fastcall D2TEMPLATE_GetDebugPrivilege()
{
  void* hToken;
  LUID luid;
  TOKEN_PRIVILEGES tokenPrivileges;

  if (OpenProcessToken(GetCurrentProcess(),TOKEN_ALL_ACCESS,&hToken) == 0)
  {
    D2TEMPLATE_ExitWithMessage(
        L"OpenProcessToken Failed",
        __FILEW__,
        __LINE__);
    return 0;
  }

  if (LookupPrivilegeValue(0,SE_DEBUG_NAME,&luid) == 0)
  {
    D2TEMPLATE_ExitWithMessage(
        L"LookupPrivilegeValue Failed",
        __FILEW__,
        __LINE__);
    CloseHandle(hToken);
    return 0;
  }

  tokenPrivileges.PrivilegeCount = 1;
  tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
  tokenPrivileges.Privileges[0].Luid = luid;
  if (AdjustTokenPrivileges(hToken,0,&tokenPrivileges,sizeof(tokenPrivileges),0,0) == 0)
  {
    D2TEMPLATE_ExitWithMessage(
        L"AdjustTokenPrivileges Failed",
        __FILEW__,
        __LINE__);
    CloseHandle(hToken);
    return 0;
  }

  CloseHandle(hToken);
  return 1;
}

int __stdcall DllAttach()
{
  D2TEMPLATE_GetDebugPrivilege();

  void* hGame = GetCurrentProcess();
  if (!hGame) 
  {
    D2TEMPLATE_ExitWithMessage(
        L"Failed to retrieve process",
        __FILEW__,
        __LINE__);
    return 0;
  }

  Patches_Apply();

  return 1;
}

int __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, void* lpReserved)
{
  switch (dwReason)
  {
    case DLL_PROCESS_ATTACH:
    {
      if (!DllAttach()) {
        D2TEMPLATE_ExitWithMessage(
            L"Couldn't attach to Diablo II",
            __FILEW__,
            __LINE__);
      }
      break;
    }
  }

  return TRUE;
}
