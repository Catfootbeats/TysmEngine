set(TARGET_NAME tysm_runtime)

file(GLOB_RECURSE HEADER_FILES *.h *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
set(AllFile ${HEADER_FILES} ${SOURCE_FILES})

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

# Log system third party library
find_package(spdlog CONFIG REQUIRED)

add_library(${TARGET_NAME} ${AllFile})


target_link_libraries(
    ${TARGET_NAME}
    PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_image_LIBRARIES}
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
    spdlog::spdlog 
    spdlog::spdlog_header_only
)
