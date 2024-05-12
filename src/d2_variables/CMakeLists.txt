target_sources(${PROJECT_NAME} PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/bnclient_variables.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/bnclient_variables.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/d2client_variables.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/d2client_variables.h"
)

add_subdirectory("bnclient_variables")
add_subdirectory("d2client_variables")
