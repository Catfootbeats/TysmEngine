cmake -S . -B build -G"Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=1
if %errorlevel%==0 (cmake --build build) else (echo error)
if %errorlevel%==0 (.\build\game\tysm-game.exe) else (echo error)
