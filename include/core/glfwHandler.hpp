#pragma once
#include "helpers/framebuffer.hpp"
#include <cstdint>



class Camera;
class GLFWwindow;

struct CallBackParams{
  Camera *camera;
};

class GLFWHandler{
public:
  GLFWHandler(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT);
  //initalizes glfw
  void init();

  //initalizes callbacks
  void initCallBack(Camera *camera);

  //returns window
  GLFWwindow *getWindow(); 

  //screen dimension
  const uint32_t SCR_WIDTH, SCR_HEIGHT; 

  //aspect ratio of the screen
  const float aspectRatio;
private:
  GLFWwindow *window; 

  FrameBuffer *frameBuffer;

  void frameBufferSizeCallBack(GLFWwindow *window, int w, int h);
};
