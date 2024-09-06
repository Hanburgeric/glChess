#include "engine.h"

// System headers
#include <optional>
#include <vector>

// User headers
#include "event_handler/input_handler.h"
#include "renderer/renderer.h"

namespace glEngine {
void Engine::OnCursorPos(double xpos, double ypos) {
  input_handler_.OnCursorPos(xpos, ypos);
}

void Engine::OnKey(int key, int action) {
  input_handler_.OnKey(key, action);
}

void Engine::OnMouseButton(int button, int action) {
  input_handler_.OnMouseButton(button, action);
}

void Engine::OnScroll(double xoffset, double yoffset) {
  input_handler_.OnScroll(xoffset, yoffset);
}

void Engine::NewFrame() {
  input_handler_.NewFrame();
}

void Engine::Update() {
  // Do nothing
}

void Engine::Render() {
  // Do nothing
}
}
