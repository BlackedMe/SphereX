#include "glad/glad.h"
class Renderable{
public:
  virtual void render(GLuint program) = 0;
};
