#include "geometry/quadVertex.hpp"
#include "geometry/transform.hpp"
#include "rendering/texture.hpp"

struct Quad{
  Quad(Texture &texture, float sideLength);
  Quad(Transform &transform, Texture &texture, float sideLength);

  QuadVertex quadVertex[4];
  float sideLength;
};
