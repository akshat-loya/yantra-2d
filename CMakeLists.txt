cmake_minimum_required(VERSION 3.22)
project(yantra-2d VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(
    Engine/include
    Editor/include
    External/include
)

# Engine library (empty placeholder)
file(GLOB_RECURSE ENGINE_SOURCES Engine/src/*.cpp)
add_library(Engine STATIC ${ENGINE_SOURCES})

# Editor executable
file(GLOB_RECURSE EDITOR_SOURCES Editor/src/*.cpp)
add_executable(Editor ${EDITOR_SOURCES})

# Link Engine to Editor
target_link_libraries(Editor PRIVATE Engine)
