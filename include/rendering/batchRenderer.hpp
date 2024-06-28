#pragma once
#include "core/glfwHandler.hpp"
#include "geometry/quadVertex.hpp"
#include "glad/glad.h"
#define maxNumQuad 1028
class BatchRenderer{
public:
  void init();

  void render(GLuint program, GLFWwindow *window);

  void addQuad(const glm::vec2 &pos, float sideLength = 0.5f, float texIndex = 0);
private:
  QuadVertex quads[4 * maxNumQuad];

  int lastIndex = 0;

  GLuint vao, vbo;
};
