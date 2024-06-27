#include "core/application.hpp"
#include "core/glfwHandler.hpp"
#include "core/input.hpp"
#include "core/program.hpp"
#include "core/renderer.hpp"
#include "core/update.hpp"
#include "events/inotify.hpp"
#include "objects/camera.hpp"
#include "rendering/batchRenderer.hpp"
#include "helpers/texture.hpp"

class Demo : public Application{
public:
  Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT);
  void init() override;
  void run() override;
private:
  //components
  GLFWHandler glfwHwnd; 
  Program program;
  InputHandler inputHwnd; 
  UpdateHandler updateHwnd;
  Renderer renderer; 
  InotifyHandler inotifyHwnd;
  Camera camera;
  BatchRenderer batchRenderer;
  Texture texture;

  // GLuint vao;
};
