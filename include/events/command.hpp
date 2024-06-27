#pragma once
#include "core/program.hpp"
#include "GLFW/glfw3.h"

class Command{
public:
  virtual void execute(float dt) = 0;

  //command cooldown;
  static float timer;
};

class ReloadProgram : public Command{
public:
  ReloadProgram(Program &program, const char* vShaderSrc, const char* fShaderSrc, float aspectRatio);
  void execute(float dt) override;
private:
  Program &program;
  const char* vShaderSrc, *fShaderSrc;
  float aspectRatio;
};

class TerminateWindow : public Command{
public:
  TerminateWindow(GLFWwindow *window);
  void execute(float dt) override;
private:
  GLFWwindow *window;
};
