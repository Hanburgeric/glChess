cmake_minimum_required(VERSION 3.28)
project(glChess)

set(CMAKE_CXX_STANDARD 26)

# GLAD
include_directories(vendor/glad/include)
set(GLAD vendor/glad/include/glad/gl.h vendor/glad/src/gl.c)

# GLFW
add_subdirectory(vendor/glfw-3.4)

add_executable(${PROJECT_NAME} ${GLAD} main.cc)

target_link_libraries(${PROJECT_NAME} glfw)
