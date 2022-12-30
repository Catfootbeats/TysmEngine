set(TARGET_NAME tysm-runtime)

file(GLOB_RECURSE HEADER_FILES *.h *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
set(AllFile ${HEADER_FILES} ${SOURCE_FILES})

if(UNIX)
    find_package(SDL2 REQUIRED)
elseif(WIN32)
    #find_package(SDL2 REQUIRED)
    include(sdl2-config.cmake)
else()
    message("unknow platform")
endif()

# Log system third party library
find_package(spdlog REQUIRED)
# include_directories(./../3rdparty/spdlog/include)

add_library(${TARGET_NAME} ${AllFile})


target_link_libraries(
    ${TARGET_NAME}
    PRIVATE
    SDL2::SDL2main
    SDL2::SDL2
    spdlog::spdlog 
    spdlog::spdlog_header_only
)
