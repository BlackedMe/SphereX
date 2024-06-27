#include "core/glfwHandler.hpp"
#include "events/command.hpp"
#include "events/inotify.hpp"
#include "helpers/definitions.hpp"

namespace ProjectName{

class InputHandler{
public:
  void init(Program &program, GLFWHandler &hwnd, const char* vShaderSrc, const char* fShaderSrc);
  void processInput(GLFWwindow *window, InotifyHandler &inotifyhwnd);
private:
  Command* ctrl_R;
  Command* esc;
};
}
