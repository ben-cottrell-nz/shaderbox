cmake_minimum_required(VERSION 2.8.12)
project(ShaderTest)
include_directories("include")
link_directories("lib")
set(SOURCES
    src/main.cpp
    src/glad.c
    src/shader.cpp)
set(CMAKE_CXX_STANDARD 11)
add_executable(ShaderTest ${SOURCES})
target_link_libraries(ShaderTest glfw3 m rt dl X11 pthread)
