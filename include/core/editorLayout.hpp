#pragma once
#include "helpers/framebuffer.hpp"
#include "helpers/textureHandler.hpp"
#include "scene/world.hpp"
class Editor{
public:
  void render(FrameBuffer &frameBuffer, TextureHandler &textureHandler, World &world);
private:
  int selectedGameObject;
};
