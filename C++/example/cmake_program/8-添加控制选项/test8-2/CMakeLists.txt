cmake_minimum_required (VERSION 3.5)

project (demo)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (SRC_LIST ${PROJECT_SOURCE_DIR}/main.c)

option (WWW1 "print one message" OFF)
option (WWW2 "print another message" OFF)

if(WWW1)
    message (STATUS "option WWW1 ON")
    add_definitions (-DWWW1)
endif()

if(WWW2)
    message (STATUS "option WWW2 ON")
    add_definitions (-DWWW2)
endif()

add_executable (main ${SRC_LIST})
