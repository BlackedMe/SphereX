#pragma once
#include "glm/ext/matrix_float4x4.hpp"
#include "glad/glad.h"
class Camera{
public:
  void update(GLuint program);

  void translate(const glm::vec2 &offset); 

  float movingSpeed = 1.0f;

  const glm::mat4 &getView();
private:
  glm::mat4 view = glm::mat4(1.0f);
};
