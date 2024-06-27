#include "glad/glad.h"

class Shader{
public:
  static GLuint compileShader(GLenum type, const char* src);
};
