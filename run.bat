cmake -S . -B build -G"Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cmake --build build
.\build\tysm-game.exe
