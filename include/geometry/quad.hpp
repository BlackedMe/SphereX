#include "geometry/quadVertex.hpp"
#include "glm/ext/vector_float3.hpp"
struct Quad{
  Quad(float sideLength, float texIndex);
  Quad(const glm::vec3 &pos, const glm::vec3 &rotation, const glm::vec3 &scale, float sideLength, float texIndex);

  QuadVertex quadVertex[4];
  float sideLength;
};
