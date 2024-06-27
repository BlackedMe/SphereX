#include "events/command.hpp"
#include "helpers/shader.hpp"
#include "GLFW/glfw3.h"

float Command::timer = 0.0f;

//ReloadProgram

ReloadProgram::ReloadProgram(Program &program, const char* vShaderSrc, const char* fShaderSrc, float aspectRatio) : program(program), vShaderSrc(vShaderSrc), fShaderSrc(fShaderSrc), aspectRatio(aspectRatio) {};

void ReloadProgram::execute(float dt)
{
  program.reload(vShaderSrc, fShaderSrc, aspectRatio);
}


//TerminateWindow

TerminateWindow::TerminateWindow(GLFWwindow *window) : window(window) {};

void TerminateWindow::execute(float dt)
{
  glfwDestroyWindow(window);
}
