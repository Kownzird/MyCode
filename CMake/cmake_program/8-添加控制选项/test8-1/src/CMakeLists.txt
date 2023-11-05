cmake_minimum_required (VERSION 3.5)

add_executable (main1 main1.c)

if(MYDEBUG)
    add_executable (main2 main2.c)
else()
    message (STATUS "Currently is not in debug mode")
endif()