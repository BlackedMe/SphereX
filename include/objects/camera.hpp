#include "glm/ext/matrix_float4x4.hpp"
class Camera{
public:
  void translate(const glm::vec2 &offset); 

  float movingSpeed = 0.5f;

  const glm::mat4 &getView();
private:
  glm::mat4 view = glm::mat4(1.0f);
};
