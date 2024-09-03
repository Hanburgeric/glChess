cmake_minimum_required(VERSION 3.28)
project(glChess)

set(CMAKE_CXX_STANDARD 26)

# GLAD
include_directories(vendor/glad/include)
set(GLAD vendor/glad/include/glad/gl.h vendor/glad/src/gl.c)

# GLFW
add_subdirectory(vendor/glfw-3.4)

# SRC
set(SRC src/renderer/program.cc src/renderer/program.h
        src/renderer/shader.cc src/renderer/shader.h)

add_executable(${PROJECT_NAME} ${GLAD} main.cc ${SRC})

target_link_libraries(${PROJECT_NAME} glfw)
