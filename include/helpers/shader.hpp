#include "helpers/definitions.hpp"
#include "glad/glad.h"

namespace ProjectName{

class Shader{
public:
  static GLuint compileShader(GLenum type, const char* src);
};
}
