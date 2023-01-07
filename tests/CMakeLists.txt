project(tests C)

add_compile_options(-g)

add_executable(test1 test1.c)
add_executable(test2 test2.c)
add_executable(test3 test3.c)

target_link_libraries(test1 cmocka)
target_link_libraries(test1 messages_to_console)
target_link_libraries(test1 memory)

target_link_libraries(test2 cmocka)
target_link_libraries(test2 messages_to_console)
target_link_libraries(test2 memory)

target_link_libraries(test3 cmocka)
target_link_libraries(test3 messages_to_console)
target_link_libraries(test3 memory)