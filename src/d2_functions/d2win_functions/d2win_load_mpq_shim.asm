; D2Template89
; Copyright 2021-2024 Mir Drualga
;
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
;     http://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.

global _D2_D2Win_LoadMpq_1_11_Shim

extern _D2_D2Win_LoadMpq_FuncPtr

section .data

section .bss

section .text

; struct D2MpqArchiveHandle* D2_D2Win_LoadMpq_1_11_Shim(
;    const char* dll_file_name,
;    const char* mpq_file_name,
;    const char* mpq_name,
;    i32 is_set_err_on_drive_query_fail,
;    void* (*on_fail_callback)(void),
;    i32 priority)
_D2_D2Win_LoadMpq_1_11_Shim:
    push ebp
    mov ebp, esp

    push ecx
    push edx

    mov eax, dword [ebp + 28]
    push dword [ebp + 24]
    push dword [ebp + 20]
    push dword [ebp + 16]
    push dword [ebp + 12]
    push dword [ebp + 8]
    call dword [_D2_D2Win_LoadMpq_FuncPtr]

    pop edx
    pop ecx

    leave
    ret
