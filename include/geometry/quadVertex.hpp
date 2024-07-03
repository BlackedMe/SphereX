#pragma once
#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
struct QuadVertex{
  glm::vec3 pos;
  glm::vec2 texCoord;
  float texIndex;
};
