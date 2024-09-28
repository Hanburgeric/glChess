// System headers
#include <iostream>

// Vendor headers
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/mat4x4.hpp"
#include "glm/trigonometric.hpp"
#include "glm/vec3.hpp"

// User headers
#include "src/engine/engine.h"
#include "src/engine/renderer/program.h"
#include "src/engine/renderer/shader.h"

// OpenGL callback functions
namespace gl {
void APIENTRY DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                   GLsizei length, const GLchar* message, const void* user_param);
}

// GLFW callback functions
namespace glfw {
void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
void ErrorCallback(int error_code, const char* description);
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
}

int main() {
  // Set GLFW error callback
  (void)glfwSetErrorCallback(glfw::ErrorCallback);

  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "glfwInit failed" << std::endl;
    return 1;
  }

  // Configure window hints
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

  // Initialize window
  GLFWwindow* window = glfwCreateWindow(1600, 900, "glEngine", nullptr, nullptr);

  if (!window) {
    std::cerr << "glfwCreateWindow failed" << std::endl;
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  // Set remaining GLFW callbacks
  (void)glfwSetCursorPosCallback(window, glfw::CursorPosCallback);
  (void)glfwSetFramebufferSizeCallback(window, glfw::FramebufferSizeCallback);
  (void)glfwSetKeyCallback(window, glfw::KeyCallback);
  (void)glfwSetMouseButtonCallback(window, glfw::MouseButtonCallback);
  (void)glfwSetScrollCallback(window, glfw::ScrollCallback);

  if (!gladLoadGL(glfwGetProcAddress)) {
    std::cerr << "gladLoadGL failed" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return 1;
  }

  // Enable and set OpenGL debug message callback
  glEnable(GL_DEBUG_OUTPUT);
  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(gl::DebugMessageCallback, nullptr);

  // Enable remaining OpenGL capabilities
  glEnable(GL_DEPTH_TEST);

  // Create engine instance and link with window
  glEngine::Engine engine;
  glfwSetWindowUserPointer(window, &engine);

  // Load shaders
  glEngine::renderer::Shader default_vert(GL_VERTEX_SHADER, "../shaders/default.vert");
  glEngine::renderer::Shader default_frag(GL_FRAGMENT_SHADER, "../shaders/default.frag");

  // Link shaders
  glEngine::renderer::Program default_prog({default_vert, default_frag});

  // TEMPORARY
  float vertices[] = {
      -0.5F, -0.5F, -0.5F,  0.0F, 0.0F,
       0.5F, -0.5F, -0.5F,  1.0F, 0.0F,
       0.5F,  0.5F, -0.5F,  1.0F, 1.0F,
       0.5F,  0.5F, -0.5F,  1.0F, 1.0F,
      -0.5F,  0.5F, -0.5F,  0.0F, 1.0F,
      -0.5F, -0.5F, -0.5F,  0.0F, 0.0F,

      -0.5F, -0.5F,  0.5F,  0.0F, 0.0F,
       0.5F, -0.5F,  0.5F,  1.0F, 0.0F,
       0.5F,  0.5F,  0.5F,  1.0F, 1.0F,
       0.5F,  0.5F,  0.5F,  1.0F, 1.0F,
      -0.5F,  0.5F,  0.5F,  0.0F, 1.0F,
      -0.5F, -0.5F,  0.5F,  0.0F, 0.0F,

      -0.5F,  0.5F,  0.5F,  1.0F, 0.0F,
      -0.5F,  0.5F, -0.5F,  1.0F, 1.0F,
      -0.5F, -0.5F, -0.5F,  0.0F, 1.0F,
      -0.5F, -0.5F, -0.5F,  0.0F, 1.0F,
      -0.5F, -0.5F,  0.5F,  0.0F, 0.0F,
      -0.5F,  0.5F,  0.5F,  1.0F, 0.0F,

       0.5F,  0.5F,  0.5F,  1.0F, 0.0F,
       0.5F,  0.5F, -0.5F,  1.0F, 1.0F,
       0.5F, -0.5F, -0.5F,  0.0F, 1.0F,
       0.5F, -0.5F, -0.5F,  0.0F, 1.0F,
       0.5F, -0.5F,  0.5F,  0.0F, 0.0F,
       0.5F,  0.5F,  0.5F,  1.0F, 0.0F,

      -0.5F, -0.5F, -0.5F,  0.0F, 1.0F,
       0.5F, -0.5F, -0.5F,  1.0F, 1.0F,
       0.5F, -0.5F,  0.5F,  1.0F, 0.0F,
       0.5F, -0.5F,  0.5F,  1.0F, 0.0F,
      -0.5F, -0.5F,  0.5F,  0.0F, 0.0F,
      -0.5F, -0.5F, -0.5F,  0.0F, 1.0F,

      -0.5F,  0.5F, -0.5F,  0.0F, 1.0F,
       0.5F,  0.5F, -0.5F,  1.0F, 1.0F,
       0.5F,  0.5F,  0.5F,  1.0F, 0.0F,
       0.5F,  0.5F,  0.5F,  1.0F, 0.0F,
      -0.5F,  0.5F,  0.5F,  0.0F, 0.0F,
      -0.5F,  0.5F, -0.5F,  0.0F, 1.0F
  };

  glm::vec3 cube_positions[] = {
      glm::vec3( 0.0F,  0.0F,   0.0F),
      glm::vec3( 2.0F,  5.0F, -15.0F),
      glm::vec3(-1.5F, -2.2F,  -2.5F),
      glm::vec3(-3.8F, -2.0F, -12.3F),
      glm::vec3 (2.4F, -0.4F,  -3.5F),
      glm::vec3(-1.7F,  3.0F,  -7.5F),
      glm::vec3( 1.3F, -2.0F,  -2.5F),
      glm::vec3( 1.5F,  2.0F,  -2.5F),
      glm::vec3( 1.5F,  0.2F,  -1.5F),
      glm::vec3(-1.3F,  1.0F,  -1.5F)
  };

  unsigned int vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  unsigned int vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0U, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0U);

  glVertexAttribPointer(1U, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1U);

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    // Handle events
    glfwPollEvents();

    // Update
    engine.Update();

    // Render
    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use program
    glUseProgram(default_prog.GetProgram());

    // Set projection matrix
    int width;
    int height;
    glfwGetFramebufferSize(window, &width, &height);
    glm::mat4 projection = glm::perspective(glm::radians(45.0F),
                                            static_cast<float>(width) / static_cast<float>(height),
                                            0.1F, 100.0F);
    glUniformMatrix4fv(default_prog.GetUniformLocation("projection"), 1, false, glm::value_ptr(projection));

    // Set view matrix
    glm::mat4 view = engine.GetCamera().CalcViewMatrix();
    glUniformMatrix4fv(default_prog.GetUniformLocation("view"), 1, false, glm::value_ptr(view));

    glBindVertexArray(vao);
    for (unsigned int i = 0U; i < 10U; i++ ) {
      // Set model matrix
      glm::mat4 model(1.0F);
      model = glm::scale(model, glm::vec3(1.0F));
      model = glm::translate(model, cube_positions[i]);
      model = glm::rotate(model, glm::radians(20.0F * i), glm::vec3(1.0F, 0.3F, 0.5F));
      glUniformMatrix4fv(default_prog.GetUniformLocation("model"), 1, false, glm::value_ptr(model));

      // Render indexed geometry
      //glDrawElements(mode, count, component_type, byte_offset);

      // Render non-indexed geometry
      glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    // Swap buffers
    glfwSwapBuffers(window);
  }

  // Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}

// Debug callback functions
namespace gl {
void APIENTRY DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                   GLsizei length, const GLchar* message, const void* user_param) {
  std::cerr << "(" << id << ") " << message << std::endl;
}
}

// GLFW callback functions
namespace glfw {
void CursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
  auto* engine = static_cast<glEngine::Engine*>(glfwGetWindowUserPointer(window));
  engine->OnCursorPos(xpos, ypos);
}

void ErrorCallback(int error_code, const char* description) {
  std::cerr << "(" << error_code << ") " << description << std::endl;
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
  auto* engine = static_cast<glEngine::Engine*>(glfwGetWindowUserPointer(window));
  glViewport(0, 0, width, height);
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  auto* engine = static_cast<glEngine::Engine*>(glfwGetWindowUserPointer(window));
  engine->OnKey(key, action);
}

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
  auto* engine = static_cast<glEngine::Engine*>(glfwGetWindowUserPointer(window));
  engine->OnMouseButton(button, action);
}

void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
  auto* engine = static_cast<glEngine::Engine*>(glfwGetWindowUserPointer(window));
  engine->OnScroll(xoffset, yoffset);
}
}
