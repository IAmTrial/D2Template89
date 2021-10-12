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
*   D2Patch.h                                                               *
*   Copyright (C) Olivier Verville                                          *
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
*   This file is where you declare all your patches, in order to inject     *
*   your own code into the game. Each patch should be declared in the       *
*   array, in order to be handled by D2Template's patcher                   *
*                                                                           *
*****************************************************************************/

#ifndef D2TEMPLATE89_PATCHES_H_
#define D2TEMPLATE89_PATCHES_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void Patches_Apply(void);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* D2TEMPLATE89_PATCHES_H_ */
