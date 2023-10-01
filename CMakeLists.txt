cmake_minimum_required (VERSION 3.24)
project (ClangExtensionsTest)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set (BUILD_PATH ${CMAKE_CURRENT_BINARY_DIR})

add_compile_definitions(SOURCE_PATH="${SOURCE_PATH}")
add_compile_definitions(BUILD_PATH="${BUILD_PATH}")

add_subdirectory (CompileTimeIO)
add_subdirectory (MixinType)

configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/.clangd.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/.clangd)
