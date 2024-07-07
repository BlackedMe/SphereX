#pragma once
#include "glm/ext/vector_int2.hpp"
#include "glm/ext/vector_float2.hpp"
class TextureAtlas{
public:
  TextureAtlas(const glm::ivec2 &textureDimension);

  void loadData(const char* src);

  static int maxWidth;
  static int maxHeight;

  glm::ivec2 dimension;
  glm::ivec2 textureDimension;

  glm::vec2 uv0;
  glm::vec2 uv1;

  unsigned char *data;
};
