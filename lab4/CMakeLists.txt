cmake_minimum_required(VERSION 3.28)
project(fundamental_alg CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

#add_subdirectory(lib_buddy_allocator)
#add_subdirectory(lib_power_two_allocator)



add_executable(main_exec src/main.cpp src/io.cpp src/errors.cpp)
