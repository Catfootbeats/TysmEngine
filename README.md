Linux和OSX需要用包管理器安装SDL2，spdlog

Windows则需要把dynamicLib里面的sdl2.dll扔到build/game下面，vscode配置vcpkg，安装spdlog:x64-mingw-static
msvc装:x64-windows
Windows下sdl2:x64-mingw-static里面的`SDL_stdinc.h`第69行`#include <strings.h>`被注释掉了，为了clangd在Windows下不报错

Mac我没试过

必须用gcc编译器，Windows记得装MinGW-w64的POSIX版
