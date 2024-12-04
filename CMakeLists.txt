cmake_minimum_required(VERSION 3.10)

project(tysm)

find_package(fmt CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
    

add_executable(tysm src/main.cpp)

target_link_libraries(
        tysm
        PRIVATE
        fmt::fmt-header-only
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )

set(VCPKG_TARGET_TRIPLET x64-mingw-static)
