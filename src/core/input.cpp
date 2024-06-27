#include "core/glfwHandler.hpp"
#include "core/input.hpp"
#include "events/inotify.hpp"
#include "GLFW/glfw3.h"

namespace ProjectName{

void InputHandler::init(Program &program, GLFWHandler &hwnd, const char* vShaderSrc, const char* fShaderSrc)
{
  ctrl_R = new ReloadProgram(program, vShaderSrc, fShaderSrc, hwnd.aspectRatio); 
  esc = new TerminateWindow(hwnd.getWindow());
}


void InputHandler::processInput(GLFWwindow *window, InotifyHandler &inotifyHwnd)
{
  glfwPollEvents();

  if(inotifyHwnd.isTriggered())
  {
    ctrl_R->execute();
  }
  else if((glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && Command::timer <= 0.0f))
  {
    esc->execute(); 
  }
}
}
