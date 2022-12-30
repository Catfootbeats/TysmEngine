set(TARGET_NAME tysm-runtime)

file(GLOB_RECURSE HEADER_FILES *.h *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
set(AllFile ${HEADER_FILES} ${SOURCE_FILES})

find_package(SDL2 CONFIG REQUIRED)
#include(sdl2-config.cmake)

# Log system third party library
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
# include_directories(./../3rdparty/spdlog/include)

add_library(${TARGET_NAME} ${AllFile})


target_link_libraries(
    ${TARGET_NAME}
    PRIVATE
    ${SDL2_LIBRARIES}
    SDL2::SDL2main
    SDL2::SDL2
    spdlog::spdlog 
    spdlog::spdlog_header_only
    glm::glm
)
