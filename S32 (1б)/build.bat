@echo off
rem Build and run helper for this project
cd /d %~dp0
echo Compiling main.cpp...
g++ -fexec-charset=UTF-8 main.cpp -o main.exe
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)
echo Running main.exe...
main.exe
exit /b 0
