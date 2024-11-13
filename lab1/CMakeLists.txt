cmake_minimum_required(VERSION 3.28)
project(fundamental_alg CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Main executable with fork
add_executable(main_exec src/main.cpp src/io.cpp src/errors.cpp)

# Executable that will be called via exec in the child process
add_executable(child_exec src/child.cpp src/io.cpp src/errors.cpp)
