cmake_minimum_required (VERSION 2.8)

project (demo)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories (include)

aux_source_directory (src SRC_LIST)

add_executable (main ${SRC_LIST})
