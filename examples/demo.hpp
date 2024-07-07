#include "core/application.hpp"
#include "core/glfwHandler.hpp"
#include "core/imguiHandler.hpp"
#include "core/input.hpp"
#include "core/update.hpp"
#include "core/editorLayout.hpp"
#include "helpers/textureHandler.hpp"
#include "scene/world.hpp"
#include "helpers/framebuffer.hpp"

class Demo : public Application{
public:
  Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT);
  void init() override;
  void run() override;
private:
  //components
  GLFWHandler glfwHwnd; 
  InputHandler inputHwnd; 
  ImGuiHandler imGuiHandler;
  TextureHandler textureHandler;
  Editor editor;
  FrameBuffer frameBuffer;
  World *world = new World;
};
