#pragma once
#include <cstdint>

class GLFWwindow;

class GLFWHandler{
public:
  GLFWHandler(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT);
  //initalizes glfw
  void init();

  //returns window
  GLFWwindow *getWindow(); 

  //screen dimension
  const uint32_t SCR_WIDTH, SCR_HEIGHT; 

  //aspect ratio of the screen
  const float aspectRatio;
private:
  GLFWwindow *window; 

  void initCallback();
};
