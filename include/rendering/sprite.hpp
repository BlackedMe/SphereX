#include "glm/ext/vector_float2.hpp"
struct Sprite{
public:
  glm::vec2 texCoord[4]; //BL --> BR --> TR --> TL
  float texIndex;
};
