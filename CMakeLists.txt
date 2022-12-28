cmake_minimum_required(VERSION 3.8)
project(tysm VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# 添加所有子目录到 allSubDir
list(APPEND allSubDir "src")


# 遍历生成
foreach(dirname ${allSubDir})
    add_subdirectory(${dirname})
endforeach()


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
