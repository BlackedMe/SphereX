#pragma once
#include "core/glfwHandler.hpp"
#include "geometry/quad.hpp"
#include "glad/glad.h"
#include "glm/ext/vector_float3.hpp"
#define maxNumQuad 1024
class BatchRenderer{
public:
  void init();

  void render(GLuint program, GLFWwindow *window);

  void addQuad(const glm::vec3 &pos, const glm::vec3 &rotation, const glm::vec3 &scale, float sideLength = 0.5f, float texIndex = 0);

  void modifyQuad(int index, const glm::vec3 &pos, const glm::vec3 &rotation, const glm::vec3 &scale);
private:
  std::vector<Quad> quad;

  GLuint vao, vbo;
};
