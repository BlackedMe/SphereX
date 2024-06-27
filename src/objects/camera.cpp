#include "objects/camera.hpp"
#include "glm/ext/vector_float2.hpp"
#include "glm/ext/matrix_transform.hpp"

void Camera::translate(const glm::vec2 &offset)
{
  view = glm::translate(view, glm::vec3(offset, 0));  
}

const glm::mat4 &Camera::getView()
{
  return view;
}
