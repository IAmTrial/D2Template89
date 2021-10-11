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

#ifndef D2TEMPLATE89_D2_VERSION_H_
#define D2TEMPLATE89_D2_VERSION_H_

/*
 * D2_VERSION preprocessor is used to configure and compile a DLL for
 * a specific version of the game.
 *
 * For example:
 * #define D2_VERSION D2_VERSION_1_13C
 */

#define D2_VERSION_1_07 200106270L
#define D2_VERSION_1_08 200106271L
#define D2_VERSION_1_09 200108200L
#define D2_VERSION_1_09B 200109050L
#define D2_VERSION_1_09C 200111140L
#define D2_VERSION_1_09D 200112050L
#define D2_VERSION_1_10 200310280L
#define D2_VERSION_1_11 200508130L
#define D2_VERSION_1_11B 200509130L
#define D2_VERSION_1_12 200806170L
#define D2_VERSION_1_13C 201003230L
#define D2_VERSION_1_13D 201110270L


/* Set D2_VERSION here. */
#ifndef D2_VERSION
  #define D2_VERSION 
#endif /* D2_VERSION */

#endif /* D2TEMPLATE89_D2_VERSION_H_ */
