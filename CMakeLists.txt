cmake_minimum_required (VERSION 3.24)
project (ClangExtensionsTest)

add_compile_definitions (SOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions (BUILD_PATH="${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory (CompileTimeIO)
add_subdirectory (MixinType)