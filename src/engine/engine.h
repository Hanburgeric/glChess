#ifndef GLCHESS_SRC_ENGINE_ENGINE_H_
#define GLCHESS_SRC_ENGINE_ENGINE_H_

// User headers
#include "camera.h"
#include "event_handler/input_handler.h"
#include "renderer/renderer.h"

namespace glEngine {
class Engine {
 public:
  // Handle events
  void OnCursorPos(double xpos, double ypos);
  void OnKey(int key, int action);
  void OnMouseButton(int button, int action);
  void OnScroll(double xoffset, double yoffset);

  // Update
  void Update();

  // Render
  void Render();

  // Camera
  const Camera& GetCamera() const;

 private:
  event_handler::InputHandler input_handler_;
  renderer::Renderer renderer_;

  Camera camera_;
};
}

#endif //GLCHESS_SRC_ENGINE_ENGINE_H_
