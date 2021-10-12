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

#include "d2_variables.h"

#include "d2_variables/bnclient_variables.h"
#include "d2_variables/d2client_variables.h"

void D2_Variables_Init(void) {
  D2_BNClient_Variables_Init();
  D2_D2Client_Variables_Init();
}
