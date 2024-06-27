#include "helpers/texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"
#include "glad/glad.h"

void Texture::init(GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth)
{
  stbi_set_flip_vertically_on_load(1);
  GLuint texture = 0;

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D_ARRAY, texture);

  glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, internalFormat, width, height, depth);
  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void Texture::load(int numTextures, const char **src)
{
  int x, y, n;
  unsigned char ** data = new unsigned char *[numTextures];
  for(int i = 0; i < numTextures; i++)
  {
    data[i] = stbi_load(src[i], &x, &y, &n, 0);
  }
  for(int i = 0; i < numTextures; i++)
  {
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, x, y, 1, GL_RGBA, GL_UNSIGNED_BYTE, &data[i][0]);
  }
}
