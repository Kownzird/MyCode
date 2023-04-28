cmake_minimum_required (VERSION 3.5)

project (demo)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set (SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.c)

include_directories (${PROJECT_SOURCE_DIR}/testFunc/inc)

find_library (TESTFUNC_LIB testFunc HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib) #默认调用动态库
# find_library (TESTFUNC_LIB libtestFunc.a HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib) #指定库文件

add_executable (main ${SRC_LIST})

target_link_libraries (main ${TESTFUNC_LIB})