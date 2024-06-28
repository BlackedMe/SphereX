#include "core/application.hpp"
#include "core/glfwHandler.hpp"
#include "core/input.hpp"
#include "core/update.hpp"
#include "scene/world.hpp"
#include "helpers/texture.hpp"

class Demo : public Application{
public:
  Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT);
  void init() override;
  void run() override;
private:
  //components
  GLFWHandler glfwHwnd; 
  InputHandler inputHwnd; 
  Texture texture;
  World *world = new World;

  // GLuint vao;
};
