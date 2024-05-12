target_sources(${PROJECT_NAME} PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/d2win_load_mpq_shim.asm"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2win_load_mpq.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2win_load_mpq.h"
)
