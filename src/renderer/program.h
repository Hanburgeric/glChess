#ifndef GLCHESS_SRC_RENDERER_PROGRAM_H_
#define GLCHESS_SRC_RENDERER_PROGRAM_H_

// System headers
#include <initializer_list>

// User headers
#include "shader.h"

namespace glEngine::renderer {
class Program {
 public:
  Program(const std::initializer_list<Shader>& shaders);
  ~Program();

  [[nodiscard]] unsigned int GetProgram() const;

 private:
  unsigned int program_;
};
}

#endif //GLCHESS_SRC_RENDERER_PROGRAM_H_
