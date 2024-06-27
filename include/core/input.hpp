#include "core/glfwHandler.hpp"
#include "events/command.hpp"
#include "events/inotify.hpp"

class Camera;

class InputHandler{
public:
  void init(Program &program, GLFWHandler &hwnd, const char* vShaderSrc, const char* fShaderSrc, Camera *camera);
  void processInput(float dt, GLFWwindow *window, InotifyHandler &inotifyhwnd);
private:
  Command* reload;
  Command* terminate;
  Command* panDown;
  Command* panRight;
  Command* panUp;
  Command* panLeft;
};
