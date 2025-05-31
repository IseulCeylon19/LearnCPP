@echo off
REM Check if an argument is provided
IF "%~1"=="" (
  echo Pass folder name as argument
  exit /b 1
)

REM Print the first argument
echo Folder: %~1

REM Remove the folder if it exists
IF EXIST "build" (
  rmdir /s /q "build"
  echo Removed folder: build
)

mkdir build
cd build

cmake -G "MinGW Makefiles" ../%~1

mingw32-make

main.exe
