cmake_minimum_required(VERSION 3.22)
project(yantra-2d VERSION 0.1 LANGUAGES CXX)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories
add_subdirectory(Engine)
add_subdirectory(External/glfw)

# Editor executable
file(GLOB_RECURSE EDITOR_SOURCES Editor/src/*.cpp)
add_executable(Editor ${EDITOR_SOURCES})

# Link Engine to Editor
# Engine's include directories are automatically available via target_link_libraries
target_link_libraries(Editor PRIVATE Engine)
target_link_libraries(Engine PRIVATE glfw)
target_link_libraries(Engine PRIVATE OpenGL::GL)

# Editor's own include directory
target_include_directories(Editor PRIVATE Editor/include External/include)
