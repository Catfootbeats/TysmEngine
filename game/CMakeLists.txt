option(USE_SOLUTION_FOLDERS ON)         # 允许对项目文件按文件夹分类
option(GROUP_BY_EXPLORER ON)            # 按资源管理器目录结构分组

list(APPEND SubDir "runtime")

# 遍历生成
foreach(dirname ${SubDir})
    add_subdirectory(${dirname})
endforeach()

# 递归查找所有文件
file(GLOB_RECURSE HEADER_FILES 
    ${PROJECT_SOURCE_DIR}/game/main/*.h
    ${PROJECT_SOURCE_DIR}/game/main/*.hpp)
file(GLOB_RECURSE SOURCE_FILES 
    ${PROJECT_SOURCE_DIR}/game/main/*.cpp 
    ${PROJECT_SOURCE_DIR}/game/main/*.c)


find_package(SDL2 CONFIG REQUIRED)
#include(sdl2-config.cmake)

find_package(glm CONFIG REQUIRED)
find_package(spdlog REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/game/runtime)

# 对文件下分组
set(AllFile ${HEADER_FILES} ${SOURCE_FILES})
foreach(fileItem ${AllFile})
    get_filename_component(PARENT_DIR "${fileItem}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")
    set(GROUP "${GROUP}")
    source_group("${GROUP}" FILES "${fileItem}")
endforeach()

add_executable(${PROJECT_NAME} ${AllFile})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${SDL2_LIBRARIES}
    SDL2::SDL2main
    SDL2::SDL2
    tysm-runtime
    spdlog::spdlog
    spdlog::spdlog_header_only
    glm::glm
)