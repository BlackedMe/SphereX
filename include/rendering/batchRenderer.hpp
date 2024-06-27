#pragma once
#include "geometry/quadVertex.hpp"
#include "glad/glad.h"
#define maxNumQuad 1028
class BatchRenderer{
public:
  void init();
  void render(GLuint program);

  void addQuad(QuadVertex *quadVertex);
private:
  QuadVertex quads[4 * maxNumQuad];

  int lastIndex = 0;

  GLuint vao, vbo;
};
