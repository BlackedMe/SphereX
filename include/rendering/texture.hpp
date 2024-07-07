#pragma once
#include "glm/ext/vector_float2.hpp"
struct Texture{
public:
  Texture(const glm::vec2 &uv0 = glm::vec2(0, 1), const glm::vec2 &uv1 = glm::vec2(1, 0), float texIndex = 0);
  glm::vec2 uv0;
  glm::vec2 uv1;

  float texIndex;
};
