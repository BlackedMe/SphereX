#include "scene/camera.hpp"
#include "helpers/uniform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/vector_float2.hpp"
#include "glm/ext/matrix_transform.hpp"

void Camera::updateOrtho(float aspectRatio)
{
  proj = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f);
}

void Camera::update(GLuint program)
{
  uniformMatrix4fv(program, "view", 1, GL_FALSE, &view[0][0]);
  uniformMatrix4fv(program, "proj", 1, GL_FALSE, &proj[0][0]);
}

void Camera::translate(const glm::vec2 &offset)
{
  view = glm::translate(view, glm::vec3(offset, 0));  
}

const glm::mat4 &Camera::getView()
{
  return view;
}
