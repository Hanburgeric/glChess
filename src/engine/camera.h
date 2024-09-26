#ifndef GLCHESS_SRC_ENGINE_CAMERA_H_
#define GLCHESS_SRC_ENGINE_CAMERA_H_

// Vendor headers
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"

namespace glEngine {
class Camera {
 public:
  Camera();

  void Update();

  glm::mat4 CalcViewMatrix();

 private:
  glm::vec3 position_;

  glm::vec3 front_;
  glm::vec3 right_;
  glm::vec3 up_;

  float pitch_;
  float yaw_;
};
}

#endif //GLCHESS_SRC_ENGINE_CAMERA_H_
