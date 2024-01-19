cmake_minimum_required(VERSION 3.10)

project(flow-ui)

set(LIB_SRC_FILES
    include/flow.h
    src/flow.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIB_SRC_FILES})

add_library(flow-ui STATIC ${LIB_SRC_FILES})