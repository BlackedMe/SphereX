#pragma once
#include "core/program.hpp"
#include "helpers/definitions.hpp"
#include "GLFW/glfw3.h"

namespace ProjectName{

class Command{
public:
  virtual void execute() = 0;

  //command cooldown;
  static float timer;
};

class ReloadProgram : public Command{
public:
  ReloadProgram(Program &program, const char* vShaderSrc, const char* fShaderSrc, float aspectRatio);
  virtual void execute();
private:
  Program &program;
  const char* vShaderSrc, *fShaderSrc;
  float aspectRatio;
};

class TerminateWindow : public Command{
public:
  TerminateWindow(GLFWwindow *window);
  virtual void execute();
private:
  GLFWwindow *window;
};
}
