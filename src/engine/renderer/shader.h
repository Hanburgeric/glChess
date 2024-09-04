#ifndef GLCHESS_SRC_ENGINE_RENDERER_SHADER_H_
#define GLCHESS_SRC_ENGINE_RENDERER_SHADER_H_

// System headers
#include <string>

// Vendor headers
#include "glad/gl.h"

namespace glEngine::renderer {
class Shader {
 public:
  Shader(GLenum shader_type, const std::string& file_name);
  ~Shader();

  [[nodiscard]] unsigned int GetShader() const;

 private:
  unsigned int shader_;
};
}

#endif //GLCHESS_SRC_ENGINE_RENDERER_SHADER_H_
