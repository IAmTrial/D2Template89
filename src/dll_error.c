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

#include "dll_error.h"

#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>

#define MESSAGE_FORMAT L"File: %ls\n" \
    L"Line: %d" \
    L"%ls"

/*
 * This is allocated as a global, so calls to error functions do not
 * trigger stack overflow error.
 */
static wchar_t full_message[D2TEMPLATE_Error_kMessageCapacity];

/**
 * External
 */

void D2TEMPLATE_ExitWithMessage(
    const wchar_t* message,
    const wchar_t* file,
    int line) {

  _snwprintf(
      full_message,
      D2TEMPLATE_Error_kMessageCapacity,
      MESSAGE_FORMAT,
      file,
      line,
      message);
  MessageBoxW(NULL, L"D2Template Error", message, MB_OK | MB_ICONERROR);
  exit(EXIT_FAILURE);
}
