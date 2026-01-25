# Engine library
file(GLOB_RECURSE ENGINE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(Engine STATIC ${ENGINE_SOURCES})

# Get all subdirectories in include/
file(GLOB INCLUDE_SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/include/*")

# Public include directories - automatically available to targets that link Engine
target_include_directories(Engine PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
${INCLUDE_SUBDIRS}
)

target_link_libraries(Engine PUBLIC glfw)
