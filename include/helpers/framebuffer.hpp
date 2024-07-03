#pragma once
#include "glm/ext/vector_float2.hpp"
#include "glad/glad.h"

class FrameBuffer{
public:
  void init(const int width, const int height);
  void resize(const int width, const int height);
  void bind() const;
  void unbind() const;
  GLuint getTexture() const;
  glm::vec2 viewportSize = glm::vec2(0);
private:
  GLuint fbo;
  GLuint texture;
};
