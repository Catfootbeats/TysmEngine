set(TARGET_NAME tysm_runtime)

file(GLOB_RECURSE HEADER_FILES *.h *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
set(AllFile ${HEADER_FILES} ${SOURCE_FILES})

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

# Log system third party library
find_package(spdlog CONFIG REQUIRED)

# if(MSVC)
#     add_compile_options(/utf-8)
#     message(STATUS "optional:/utf-8")   
# endif(MSVC)

add_library(${TARGET_NAME} ${AllFile})
# add_library(${TARGET_NAME} STATIC ${AllFile})

target_link_libraries(
    ${TARGET_NAME}
    PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_image_LIBRARIES}
    ${SDL2_ttf_LIBRARIES}
    ${SDL2_mixer_LIBRARIES}
    SDL2::SDL2main
    SDL2::SDL2
    $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
    $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
    $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>
    spdlog::spdlog 
    spdlog::spdlog_header_only
)
