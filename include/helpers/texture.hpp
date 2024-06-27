#include "glad/glad.h"

class Texture{
public:
  static void init(GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth);
  static void load(int numTextures, const char ** src);
};
