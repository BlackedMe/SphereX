#pragma once
#include "rendering/texture.hpp"
#include "glm/ext/vector_float2.hpp"
class SpriteRenderer{
public:
  void useTexture(Texture &texture);

  glm::vec2 uv0; //top left corner
  glm::vec2 uv1; //bottom right corner

  float texIndex;
};
