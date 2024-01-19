cmake_minimum_required(VERSION 3.10)

project(flow-ui)

if(UNIX AND NOT APPLE)
    message(FATAL_ERROR "Linux platform not supported." )
endif()
if(APPLE)
    message(FATAL_ERROR "MacOS platform not supported." )
endif()

set(LIB_SRC_FILES
    include/Flow.h
    src/Flow.cpp
    include/Platform/Window.h
)

set(LIB_WINDOWS_SRC_FILES
    src/Platform/Win32_Impl/Win32Window.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIB_SRC_FILES})

if(WIN32)
    add_library(flow-ui STATIC ${LIB_SRC_FILES} ${LIB_WINDOWS_SRC_FILES})
    target_compile_definitions(flow-ui PRIVATE PLATFORM_WINDOWS)
endif()

