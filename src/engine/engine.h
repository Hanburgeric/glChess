#ifndef GLCHESS_SRC_ENGINE_ENGINE_H_
#define GLCHESS_SRC_ENGINE_ENGINE_H_

// User headers
#include "event_handler/input_handler.h"
#include "renderer/renderer.h"

namespace glEngine {
class Engine {
 public:
  // Clear certain data in preparation for a new frame
  void NewFrame();

  // Handle user input
  const event_handler::InputHandler& GetInputHandler() const;

  void OnCursorPos(double xpos, double ypos);
  void OnKey(int key, int action);
  void OnMouseButton(int button, int action);
  void OnScroll(double xoffset, double yoffset);

 private:
  event_handler::InputHandler input_handler_;
  renderer::Renderer renderer_;
};
}

#endif //GLCHESS_SRC_ENGINE_ENGINE_H_
