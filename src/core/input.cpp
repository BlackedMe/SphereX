#include "core/glfwHandler.hpp"
#include "core/input.hpp"
#include "scene/cameraController.hpp"
#include "GLFW/glfw3.h"

class Camera;

void InputHandler::init(GLFWHandler &hwnd, Camera *camera)
{
  terminate = new TerminateWindow(hwnd.getWindow());
  panDown = new PanDown(camera);
  panRight = new PanRight(camera);
  panUp = new PanUp(camera);
  panLeft = new PanLeft(camera);
}


void InputHandler::processInput(float dt, GLFWwindow *window) 
{
  glfwPollEvents();

  if((glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && Command::timer <= 0.0f))
  {
    terminate->execute(dt); 
  }

  if((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS))
  {
    panDown->execute(dt); 
  }
  if((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS))
  {
    panRight->execute(dt); 
  }
  if((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS))
  {
    panUp->execute(dt); 
  }
  if((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS))
  {
    panLeft->execute(dt); 
  }
}
