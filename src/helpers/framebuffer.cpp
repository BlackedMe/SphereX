#include "helpers/framebuffer.hpp"

void FrameBuffer::init(const int width, const int height)
{
  glGenFramebuffers(1, &fbo);
  glBindFramebuffer(GL_FRAMEBUFFER, fbo);

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glBindTexture(GL_TEXTURE_2D, 0);
}

void FrameBuffer::resize(const int width, const int height)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
  glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint FrameBuffer::getTexture() const
{
  return texture;
}

void FrameBuffer::bind() const
{
  glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

void FrameBuffer::unbind() const
{
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
