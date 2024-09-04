cmake_minimum_required(VERSION 3.28)
project(glChess)

set(CMAKE_CXX_STANDARD 23)

# GLAD
include_directories(vendor/glad/include)
set(GLAD vendor/glad/include/glad/gl.h vendor/glad/src/gl.c)

# GLFW
add_subdirectory(vendor/glfw-3.4)

# GLM
add_subdirectory(vendor/glm-1.0.1)

# JSON
add_subdirectory(vendor/json-3.11.3)

# SRC
set(SRC src/engine/engine.cc src/engine/engine.h
        src/engine/event_handler/input_handler.cc src/engine/event_handler/input_handler.h
        src/engine/renderer/camera.cc src/engine/renderer/camera.h
        src/engine/renderer/program.cc src/engine/renderer/program.h
        src/engine/renderer/shader.cc src/engine/renderer/shader.h
        src/engine/renderer/renderer.cc src/engine/renderer/renderer.h)

add_executable(${PROJECT_NAME} ${GLAD} main.cc ${SRC})

target_link_libraries(${PROJECT_NAME} glfw glm::glm nlohmann_json::nlohmann_json)
