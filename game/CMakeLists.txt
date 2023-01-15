option(USE_SOLUTION_FOLDERS ON)         # 允许对项目文件按文件夹分类
option(GROUP_BY_EXPLORER ON)            # 按资源管理器目录结构分组

list(APPEND SubDir "runtime")

if(WIN32)
    add_compile_options(/W4)
    add_compile_options(/wd4819)
endif()

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
find_package(SDL2_image CONFIG REQUIRED)

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

if(MSVC)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/game/main/resources"  "${PROJECT_SOURCE_DIR}/build/game/Debug/resources"
) 

else()
execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/game/main/resources"  "${PROJECT_SOURCE_DIR}/build/game/Release/resources")
endif(CMAKE_BUILD_TYPE STREQUAL Debug)

# TODO gcc编译器资源文件复制
# else(execute_process(COMMAND ${CMAKE_COMMAND} -E
# copy_directory "${PROJECT_SOURCE_DIR}/game/main/resources"  "${PROJECT_SOURCE_DIR}/build"
# ) )
endif(MSVC)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_image_LIBRARIES}
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
    tysm_runtime
    spdlog::spdlog
    spdlog::spdlog_header_only
)
