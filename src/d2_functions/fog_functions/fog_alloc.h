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

#ifndef D2TEMPLATE89_D2_FUNCTIONS_FOG_FUNCTIONS_FOG_ALLOC_H_
#define D2TEMPLATE89_D2_FUNCTIONS_FOG_FUNCTIONS_FOG_ALLOC_H_

#include "d2_std_types.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

void D2_Fog_Alloc_Init(void);

void* D2_Fog_Alloc(
    i32 size,
    const char* source_file,
    i32 line,
    i32 unused__set_to_0);

#ifdef __cplusplus
}  /* extern "C" */
#endif  /* __cplusplus */

#endif  /* D2TEMPLATE89_D2_FUNCTIONS_FOG_FUNCTIONS_FOG_ALLOC_H_ */
