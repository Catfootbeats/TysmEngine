find_package(SDL2 CONFIG REQUIRED)

add_subdirectory(core)
include_directories(${PROJECT_SOURCE_DIR}/src/core)

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

if(WIN32)
	add_executable(${PROJECT_NAME} main.cpp ico.rc)
else()
	add_executable(${PROJECT_NAME} main.cpp)
endif()

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
	core
	$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
	$<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

