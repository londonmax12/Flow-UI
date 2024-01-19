cmake_minimum_required(VERSION 3.10)

project(example-app)

set(LIB_SRC_FILES
    src/example.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIB_SRC_FILES})
add_executable(example-app ${LIB_SRC_FILES})

target_link_libraries(example-app PRIVATE flow-ui)