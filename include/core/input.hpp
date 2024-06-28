#include "core/glfwHandler.hpp"
#include "events/command.hpp"

class Camera;

class InputHandler{
public:
  void init(GLFWHandler &hwnd, Camera *camera);
  void processInput(float dt, GLFWwindow *window);
private:
  Command* terminate;
  Command* panDown;
  Command* panRight;
  Command* panUp;
  Command* panLeft;
};
