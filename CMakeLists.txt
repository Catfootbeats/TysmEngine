cmake_minimum_required(VERSION 3.10)
project(tysm VERSION 0.0.1)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
if(CMAKE_BUILD_TYPE STREQUAL Debug)
add_definitions(-DDEBUG)
endif()

add_subdirectory(src)

execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/src/res"  "${PROJECT_BINARY_DIR}/src/res"
)

