cmake_minimum_required (VERSION 2.8)

project (demo)

include_directories (test_func test_func1)

aux_source_directory (test_func SRC_LIST)
aux_source_directory (test_func1 SRC_LIST1)

add_executable (main main.c ${SRC_LIST} ${SRC_LIST1})