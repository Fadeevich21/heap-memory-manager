cmake_minimum_required(VERSION 3.10)
project(main C)

set(CMAKE_C_STANDART 11)

add_subdirectory(tests)

add_executable(main main.c)

add_subdirectory(libs)
target_link_libraries(main color_print)
target_link_libraries(main messages_to_console)
target_link_libraries(main memory)
# target_link_libraries(main chunk)
