#include "glm/ext/vector_float3.hpp"
class Transform{
public:
  Transform(const glm::vec3 &pos = glm::vec3(0.0f), const glm::vec3 &rotation = glm::vec3(0.0f), const glm::vec3 &scale = glm::vec3(1.0f));
  glm::vec3 pos;
  glm::vec3 rotation;
  glm::vec3 scale;
};
