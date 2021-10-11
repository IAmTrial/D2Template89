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

#ifndef D2TEMPLATE89_FILEW_H_
#define D2TEMPLATE89_FILEW_H_

#if _MSC_VER < 1600

#define D2TEMPLATE89_INTERNAL_CSTR_LIT_TO_CWSTR_LIT( \
    prefix, \
    lit \
) prefix ## lit

#define D2TEMPLATE89_INTERNAL_EXPAND_MACRO(prefix, x) \
    D2TEMPLATE89_INTERNAL_CSTR_LIT_TO_CWSTR_LIT(prefix, x)

#define __FILEW__ D2TEMPLATE89_INTERNAL_EXPAND_MACRO(L, __FILE__)

#endif /* _MSC_VER < 1600 */

#endif /* D2TEMPLATE89_FILEW_H_ */