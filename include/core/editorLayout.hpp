#pragma once
#include "helpers/framebuffer.hpp"
#include "scene/world.hpp"
class Editor{
public:
  static void render(FrameBuffer &frameBuffer, World &world);
private:
  static int selectedGameObject;
};
