#include "camera.h"

// Vendor headers
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
#include "glm/vec3.hpp"

namespace glEngine {
void Camera::Update() {
  float x = glm::cos(glm::radians(yaw_)) * glm::cos(glm::radians(pitch_));
  float y = glm::sin(glm::radians(pitch_));
  float z = glm::sin(glm::radians(yaw_)) * glm::cos(glm::radians(pitch_));
  front_ = glm::normalize(glm::vec3(x, y, z));
  right_ = glm::normalize(glm::cross(front_, glm::vec3(0.0F, 1.0F, 0.0F)));
  up_ = glm::normalize(glm::cross(right_, front_));
}
}