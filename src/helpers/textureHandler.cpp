#include "helpers/textureHandler.hpp"
#include "rendering/textureAtlas.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"
#include "glad/glad.h"

void TextureHandler::init(GLenum internalFormat, GLsizei maxWidth, GLsizei maxHeight, GLsizei depth)
{
  TextureAtlas::maxWidth = maxWidth;
  TextureAtlas::maxHeight = maxHeight;

  count = 1;

  stbi_set_flip_vertically_on_load(1);
  GLuint texture = 0;

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D_ARRAY, texture);

  glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, internalFormat, maxWidth, maxHeight, depth);
  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  //a transparent texture (i.e default = no texture)
  glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0, maxWidth, maxHeight, 1, GL_RGBA, GL_UNSIGNED_BYTE, 0);
  textures.push_back(Texture(glm::vec2(0, 1), glm::vec2(1, 0), 0));
}

void TextureHandler::load(int count, const TextureAtlas *textureAtlases)
{
  for(int i = 0; i < count; this->count++, i++)
  {
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, this->count, TextureAtlas::maxWidth, TextureAtlas::maxHeight, 1, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, this->count, textureAtlases[i].dimension.x, textureAtlases[i].dimension.y, 1, GL_RGBA, GL_UNSIGNED_BYTE, &textureAtlases[i].data[0]);
    extractTextures(textureAtlases[i], this->count);
  }
}

void TextureHandler::extractTextures(const TextureAtlas &textureAtlas, float texIndex)
{
  float x = (float) textureAtlas.textureDimension.x/textureAtlas.dimension.x;
  float y = (float) textureAtlas.textureDimension.y/textureAtlas.dimension.y;

  glm::vec2 uv0 = textureAtlas.uv0;

  glm::vec2 numOfTextures;

  numOfTextures.x = int(textureAtlas.dimension.x/textureAtlas.textureDimension.x);
  numOfTextures.y = int(textureAtlas.dimension.y/textureAtlas.textureDimension.y);

  for(int i = 0; i < numOfTextures.y; i++)
  {
    for(int j = 0; j < numOfTextures.x; j++)
    {
      Texture texture(glm::vec2(x * j, 1 - y * i), glm::vec2(x * (j + 1), 1 - y * (i + 1)), texIndex);
      textures.push_back(texture);
    }
  }
}


