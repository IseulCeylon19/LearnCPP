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

REM https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-build-configurations/
g++ -Werror -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic-errors -fanalyzer -ggdb -DDEBUG -o main ../%~1/main.cpp

REM for release build, uncomment the next line
REM g++ -Werror -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic-errors -std=c++17 -O2 -DNDEBUG -o main ../%~1/main.cpp

main

cd ..
