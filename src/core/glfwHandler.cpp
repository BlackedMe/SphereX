#include "core/glfwHandler.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>


namespace ProjectName{

GLFWHandler::GLFWHandler(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT) : SCR_WIDTH(SCR_WIDTH), SCR_HEIGHT(SCR_HEIGHT), aspectRatio((float) SCR_WIDTH/SCR_HEIGHT) {};

void GLFWHandler::init()
{
  //initalizes glfw
  if(!glfwInit()) std::cout << "Failed to initalize GLFW!";
  
  //window hints
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

  //initalizes the window
  window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Program", 0, 0);
  if(!window)
  {
    glfwTerminate();
    std::cout << "Failed to initalize window!";
  }

  glfwMakeContextCurrent(window);
  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) std::cout << "Failed to initalize glad!";
  initCallback();
}

void GLFWHandler::initCallback()
{
  glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int w, int h) { glViewport(0, 0, w, h);});
}

GLFWwindow *GLFWHandler::getWindow()
{
  return window;
}
}
