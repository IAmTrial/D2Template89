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

#ifndef D2TEMPLATE89_DLL_ERROR_H_
#define D2TEMPLATE89_DLL_ERROR_H_

#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum {
  /*
   * An error message beyond 512 characters would be unreasonable. Try
   * writing to stderr if more than 512 characters are needed.
   */
  D2TEMPLATE_Error_kMessageCapacity = 512,
};

void D2TEMPLATE_ExitWithMessage(
    const wchar_t* message,
    const wchar_t* file,
    int line);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* D2TEMPLATE89_DLL_ERROR_H_ */
