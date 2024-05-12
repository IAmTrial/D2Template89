target_sources(${PROJECT_NAME} PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/d2win_functions.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2win_functions.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/fog_functions.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/fog_functions.h"
)

add_subdirectory("d2win_functions")
add_subdirectory("fog_functions")
