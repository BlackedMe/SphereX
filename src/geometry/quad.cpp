#include "geometry/quad.hpp"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
Quad::Quad(float sideLength, float texIndex) : sideLength(sideLength)
{
  float halfLength = sideLength / 2;
  quadVertex[0] = {glm::vec3(-halfLength, -halfLength, 0), glm::vec2(0, 0), texIndex};
  quadVertex[1] = {glm::vec3(halfLength, -halfLength, 0), glm::vec2(1, 0), texIndex};
  quadVertex[2] = {glm::vec3(halfLength, halfLength, 0), glm::vec2(1, 1), texIndex};
  quadVertex[3] = {glm::vec3(-halfLength, halfLength, 0), glm::vec2(0, 1), texIndex};
}

Quad::Quad(const glm::vec3 &pos, const glm::vec3 &rotation, const glm::vec3 &scale, float sideLength, float texIndex) : sideLength(sideLength)
{
  glm::mat4 model(1.0f);
  model = glm::translate(model, pos);
  model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
  model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
  model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::scale(model, scale);

  *this = Quad(sideLength, texIndex); 

  for(int i = 0; i < 4; i++)
  {
    quadVertex[i].pos = model * glm::vec4(quadVertex[i].pos, 1.0f);
  }
}
