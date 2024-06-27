#include "rendering/sprite.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glad/glad.h"
class SpriteRenderer{
public:
  void render(GLuint program, const glm::vec3 &pos);
private:
  Sprite sprite;
};
