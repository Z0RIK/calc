project(calc C)

add_library(raygui INTERFACE ${CMAKE_CURRENT_LIST_DIR}/raygui/src/raygui.h)

set_target_properties(raygui PROPERTIES LINKER_LANGUAGE C)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/raylib raylib)