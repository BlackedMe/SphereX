#include "geometry/quad.hpp"
#include "geometry/quadVertex.hpp"
#include "rendering/batchRenderer.hpp"

void addQuad(BatchRenderer &renderer, const glm::vec2 &pos, float sideLength, float texIndex)
{
  sideLength /= 2;
  QuadVertex quadVertex[4];
  quadVertex[0] = {glm::vec2(pos.x - sideLength, pos.y - sideLength), glm::vec2(0, 0), texIndex};
  quadVertex[1] = {glm::vec2(pos.x + sideLength, pos.y - sideLength), glm::vec2(1, 0), texIndex};
  quadVertex[2] = {glm::vec2(pos.x + sideLength, pos.y + sideLength), glm::vec2(1, 1), texIndex};
  quadVertex[3] = {glm::vec2(pos.x - sideLength, pos.y + sideLength), glm::vec2(0, 1), texIndex};

  renderer.addQuad(quadVertex);
}
