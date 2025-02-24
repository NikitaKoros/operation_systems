cmake_minimum_required(VERSION 3.28)
project(fundamental_alg C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")  
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall")

add_executable(main_exec src/main.c src/io.c src/errors.c src/utils_lab2.c)