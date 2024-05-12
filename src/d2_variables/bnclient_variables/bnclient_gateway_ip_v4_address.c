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

#include "d2_variables/bnclient_variables/bnclient_gateway_ip_v4_address.h"

#include <stddef.h>

#include "d2_dll.h"
#include "d2_std_types.h"
#include "d2_structs/d2_mpq_archive_handle.h"
#include "d2_version.h"

static ptrdiff_t GetOffset(void) {
#if D2_VERSION == D2_VERSION_1_09D
  return 0x1CC60;
#elif D2_VERSION == D2_VERSION_1_10
  return 0x1CF58;
#elif D2_VERSION == D2_VERSION_1_12
  return 0x1F2B8;
#elif D2_VERSION == D2_VERSION_1_13C
  return 0x1F300;
#elif D2_VERSION == D2_VERSION_1_13D
  return 0x1EEF8;
#endif
}

/**
 * External
 */

char** D2_BNClient_GatewayIpV4Address;

void D2_BNClient_GatewayIpV4Address_Init(void) {
  D2_BNClient_GatewayIpV4Address = D2Dll_GetAddressFromOffset(
      D2Dll_kBNClient,
      GetOffset());
}
