#include "rendering/textureAtlas.hpp"
#include "vendor/stb_image.h"

int TextureAtlas::maxWidth = 320;
int TextureAtlas::maxHeight = 320;

TextureAtlas::TextureAtlas(const glm::ivec2 &textureDimension) : textureDimension(textureDimension) {};

void TextureAtlas::loadData(const char* src)
{
  int n;
  data = stbi_load(src, &dimension.x, &dimension.y, &n, 0); 
  uv0 = glm::vec2(0, dimension.y/maxHeight);
  uv1 = glm::vec2(dimension.x/maxWidth , 0);
}
