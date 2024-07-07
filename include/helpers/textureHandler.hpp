#pragma once
#include "glad/glad.h"
#include "rendering/texture.hpp"
#include <vector>

class TextureAtlas;

class TextureHandler{
public:
  void init(GLenum internalFormat, GLsizei maxWidth, GLsizei maxHeight, GLsizei depth);
  void load(int count, const TextureAtlas *textureAtlases);
  int count = 0;
  std::vector<Texture> textures;
private:
  void extractTextures(const TextureAtlas &textureAtlas, float texIndex);
};
