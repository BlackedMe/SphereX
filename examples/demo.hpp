#include "core/application.hpp"
#include "core/glfwHandler.hpp"
#include "core/imguiHandler.hpp"
#include "core/input.hpp"
#include "core/update.hpp"
#include "core/editorLayout.hpp"
#include "scene/world.hpp"
#include "helpers/texture.hpp"
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
  Editor editor;
  Texture texture;
  FrameBuffer frameBuffer;
  World *world = new World;
  // GLuint vao;
};
