project(tests C)

add_compile_options(-g)

add_executable(test1 test1.c)

target_link_libraries(test1 cmocka)
target_link_libraries(test1 messages_to_console)
target_link_libraries(test1 memory)