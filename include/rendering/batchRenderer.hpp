#pragma once
#include "core/glfwHandler.hpp"
#include "geometry/quad.hpp"
#include "glad/glad.h"
#include "geometry/transform.hpp"
#define maxNumQuad 1024
class BatchRenderer{
public:
  void init();

  void render(GLuint program, GLFWwindow *window);

  void addQuad(Transform &transform, Texture &texture, float sideLength = 0.5f);

  void modifyQuad(int index, Transform &transform, Texture &texture);
private:
  std::vector<Quad> quad;

  GLuint vao, vbo;
};
