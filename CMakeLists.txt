cmake_minimum_required(VERSION 3.10)
project(main C)

set(CMAKE_C_STANDART 11)

add_subdirectory(tests)
add_executable(main main.c)
add_subdirectory(libs)