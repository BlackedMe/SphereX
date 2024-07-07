#include "geometry/quad.hpp"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
Quad::Quad(Texture &texture, float sideLength) : sideLength(sideLength)
{
  const glm::vec2 &uv0 = texture.uv0;
  const glm::vec2 &uv1 = texture.uv1;

  float texIndex = texture.texIndex;
  float halfLength = sideLength / 2;

  quadVertex[0] = {glm::vec3(-halfLength, -halfLength, 0), glm::vec2(uv0.x, uv1.y), texIndex};
  quadVertex[1] = {glm::vec3(halfLength, -halfLength, 0), uv1, texIndex};
  quadVertex[2] = {glm::vec3(halfLength, halfLength, 0), glm::vec2(uv1.x, uv0.y), texIndex};
  quadVertex[3] = {glm::vec3(-halfLength, halfLength, 0), uv0, texIndex};

}
Quad::Quad(Transform &transform, Texture &texture, float sideLength) : sideLength(sideLength)
{
  const glm::vec3 &pos = transform.pos;
  const glm::vec3 &rotation = transform.rotation;
  const glm::vec3 &scale = transform.scale;

  glm::mat4 model(1.0f);
  model = glm::translate(model, pos);
  model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
  model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
  model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::scale(model, scale);

  *this = Quad(texture, sideLength); 

  for(int i = 0; i < 4; i++)
  {
    quadVertex[i].pos = model * glm::vec4(quadVertex[i].pos, 1.0f);
  }
}
