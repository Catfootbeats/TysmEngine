# TysmEngine

This is a galgame engine used SDL2. It's haven't finish. Welcome to PR your code to finish this project. (～￣▽￣)～

# The packages used

- spdlog
- SDL2
- SDL2_ttf
- SDL2_image
- SDL2_mixer
- fmt
  
Thanks all developers of these library.

# How to build this project ?

1. You need to install vcpkg on your computer.You can refer the [page](https://github.com/microsoft/vcpkg) of vcpkg.
2. Install spdlog, SDL2, SDL2_ttf, SDL2_image, SDL2_mixer and fmt with vcpkg.
3. Install CMake on your computer.
4. Run `cmake -S . -B build` in the terminal.(If you were using other compiler, you can change this command.)
5. Run `cmake --build build` in the terminal.

## tips

- If you can't run the execution. You can try to move resources in `game/main` to the path of execution.
- If you are using MSVC for your compiler. You need to change all of the source code file to UTF-8 with BOW.

# TODO

- [x] Window System
- [x] Render System
- [x] Scene base
- [x] Start Scene
- [x] UI base
- [x] text and UI text
- [x] image and UI image
- [ ] UI button
- [ ] Gaming Scene
- [ ] Level Manager
- [ ] Save and Read Config
- [ ] etc...
