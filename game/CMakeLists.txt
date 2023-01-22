option(USE_SOLUTION_FOLDERS ON)         # 允许对项目文件按文件夹分类
option(GROUP_BY_EXPLORER ON)            # 按资源管理器目录结构分组

list(APPEND SubDir "runtime")

if(WIN32 AND MSVC)
    add_compile_options(/W4)
    add_compile_options(/wd4819)
endif()

# if(MSVC)
#     add_compile_options(/utf-8)
#     message(STATUS "optional:/utf-8")   
# endif(MSVC)

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

# ico compile command: windres -i "ico.rc" -o "ico.o"  


find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(FMT REQUIRED)
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

if(WIN32)
    add_executable(${PROJECT_NAME} ${AllFile} ${PROJECT_SOURCE_DIR}/game/main/ico.o)
else()
add_executable(${PROJECT_NAME} ${AllFile})
endif(WIN32)

target_link_libraries(
    ${PROJECT_NAME}
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
    fmt::fmt
    tysm_runtime
)
