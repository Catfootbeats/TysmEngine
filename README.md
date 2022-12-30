Linux和OSX需要用包管理器安装SDL2，spdlog

Windows则需要把dynamicLib里面的sdl2.dll扔到build/game下面，vscode配置vcpkg，安装spdlog:x64-mingw-static

Mac我没试过

必须用gcc编译器，Windows记得装MinGW-w64的POSIX版
