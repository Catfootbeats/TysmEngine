find_package(SDL2 CONFIG REQUIRED)

add_subdirectory(core)
include_directories(${PROJECT_SOURCE_DIR}/src/core)


if(WIN32)
	add_executable(${PROJECT_NAME} main.cpp ico.rc)
else()
	add_executable(${PROJECT_NAME} main.cpp)
endif()

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
	core
)

