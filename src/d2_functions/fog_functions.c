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

#include "fog_functions.h"

#include "fog_functions/fog_alloc_client_memory.h"
#include "fog_functions/fog_free_client_memory.h"

void D2_Fog_Functions_Init(void) {
  D2_Fog_AllocClientMemory_Init();
  D2_Fog_FreeClientMemory_Init();
}
