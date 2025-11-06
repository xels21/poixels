PUSHD %~dp0
platformio.exe run --environment windows 
.pio\build\windows\program.exe --pixel-count 32 --http-port 8080
POPD