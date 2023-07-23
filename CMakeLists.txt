cmake_minimum_required(VERSION 3.8)

project(calc C)

# Setup output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/bin") # .exe and .dll
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib") # .so and .dylib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib") # .lib and .a

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/deps)

add_executable(calc ${CMAKE_CURRENT_LIST_DIR}/src/main.c)

target_link_libraries(calc 
    PRIVATE raygui
    PRIVATE raylib)

target_include_directories(calc
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/deps/raylib/src
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/deps/raygui/src)