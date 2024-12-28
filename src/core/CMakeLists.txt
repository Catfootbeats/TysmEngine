set(TARGET_NAME core)

file(GLOB_RECURSE HEADER_FILES *.h *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.c *.cpp)
set(FILES ${HEADER_FILES} ${SOURCE_FILES})

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
#find_package(sdl2-gfx CONFIG REQUIRED)

add_library(${TARGET_NAME} STATIC ${FILES})

target_include_directories(${TARGET_NAME} PRIVATE .)
target_link_libraries(
    ${TARGET_NAME}
	PUBLIC
	$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
	$<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
	$<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
    $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
    $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>
	#SDL2::SDL2_gfx
    spdlog::spdlog_header_only 
)

