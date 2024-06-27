#include "core/renderer.hpp"
#include "core/glfwHandler.hpp"
#include "GLFW/glfw3.h"

namespace ProjectName{

void Renderer::render(GLFWHandler &hwnd)
{
  glfwSwapBuffers(hwnd.getWindow());
}
}
