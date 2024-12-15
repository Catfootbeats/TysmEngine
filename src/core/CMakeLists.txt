set(TARGET_NAME core)

file(GLOB_RECURSE HEADER_FILES *.h *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.c *.cpp)
set(FILES ${HEADER_FILES} ${SOURCE_FILES})

find_package(SDL2 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(${TARGET_NAME} STATIC ${FILES})

target_include_directories(${TARGET_NAME} PRIVATE .)
target_link_libraries(
    ${TARGET_NAME}
	PUBLIC
	$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
	$<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    spdlog::spdlog_header_only 
)

