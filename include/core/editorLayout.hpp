#pragma once
#include "helpers/framebuffer.hpp"
#include "fileSystem/fileSystem.hpp"
#include "scene/world.hpp"
class Editor{
public:
  void render(FrameBuffer &frameBuffer, World &world);

  FileSystem fileSystem;
private:
  int selectedGameObject = -1;

  GLuint texture;
};
