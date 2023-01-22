cmake_minimum_required(VERSION 3.8)
project(tysm-game VERSION 0.1.0)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 20)

# 添加所有子目录到 allSubDir
list(APPEND allSubDir "game")

# if(MSVC)
#     add_compile_options(/utf-8)
#     message(STATUS "optional:/utf-8")   
# endif(MSVC)

# 遍历生成
foreach(dirname ${allSubDir})
    add_subdirectory(${dirname})
endforeach()

execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/game/main/resources"  "${PROJECT_SOURCE_DIR}/resources"
)

if(NOT MSVC)

# gcc编译器资源文件复制
execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/game/main/resources"  "${PROJECT_SOURCE_DIR}/build/game/resources"
)

if(WIN32)
execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/build/game/runtime/libtysm_runtime.dll"  "${PROJECT_SOURCE_DIR}/build/game")
else()
    execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/build/game/runtime/libtysm_runtime.so"  "${PROJECT_SOURCE_DIR}/build/game")
endif(WIN32)
endif(NOT MSVC)

if(MSVC)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/game/main/resources"  "${PROJECT_SOURCE_DIR}/build/game/Debug/resources"
) 

else()
execute_process(COMMAND ${CMAKE_COMMAND} -E
copy_directory "${PROJECT_SOURCE_DIR}/game/main/resources"  "${PROJECT_SOURCE_DIR}/build/game/Release/resources")
endif(CMAKE_BUILD_TYPE STREQUAL Debug)

endif(MSVC)


# #########
# include_directories(engine)
# #GLOB和GLOB_RECURSE区别 后者包含子目录
# file(GLOB_RECURSE main ${CMAKE_CURRENT_SOURCE_DIR}/main/*.cpp)
# 
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/engine/runtime)
# list(APPEND EXTRA_LIBS TysmRuntime)
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine/runtime")
# add_executable(${PROJECT_NAME} main)
# 
# target_link_libraries(${PROJECT_NAME} PUBLIC TysmRuntime )
# 
# target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})
# 
# add_dependencies(${PROJECT_NAME} TysmRuntime)
# 
