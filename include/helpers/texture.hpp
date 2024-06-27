#include "helpers/definitions.hpp"
#include "glad/glad.h"

namespace ProjectName{

class Texture{
public:
  static void init(GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth);
  static void load(int numTextures, const char ** src);
};
}
