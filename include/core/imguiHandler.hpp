#include "imgui/imgui.h"
class GLFWwindow;

class ImGuiHandler{
public:
  void init(GLFWwindow *window);
  void startNewFrame();
  void render();
  void terminate();
private:
  ImGuiIO *io;
};
