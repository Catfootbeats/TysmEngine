cmake_minimum_required(VERSION 3.10)
project(tysm VERSION 0.0.1)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
if(CMAKE_BUILD_TYPE STREQUAL Debug)
add_definitions(-DDEBUG)
endif()

add_subdirectory(src)

# set(VCPKG_TARGET_TRIPLET x64-mingw-static)

