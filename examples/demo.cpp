#include "demo.hpp"
#include "GLFW/glfw3.h"
#include "core/glfwHandler.hpp"
#include "helpers/uniform.hpp"
#include <sys/inotify.h>

Demo::Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT) : glfwHwnd(SCR_WIDTH, SCR_HEIGHT) {};

void Demo::init(){
  glfwHwnd.init();

  world->init();
  world->loadShader("../examples/assets/shader/vShader.glsl", "../examples/assets/shader/fShader.glsl", glfwHwnd.aspectRatio);

  inputHwnd.init(glfwHwnd, world->getCamera());

  const char *src[1];
  src[0] = "../examples/sprites/Sprite-0001.png";
  texture.init(GL_RGBA8, 320, 320, 32);
  texture.load(1, src);

  world->addGameObject(glm::vec3(0.0f));
  world->addGameObject(glm::vec3(1.0f, 0.0f, 0.0f));
}

void Demo::run(){
  float lastFrame = glfwGetTime(), dt; 
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    float currentTime = glfwGetTime();
    dt = currentTime - lastFrame;
    lastFrame = currentTime; 

    inputHwnd.processInput(dt, glfwHwnd.getWindow());

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);  

    world->update(dt);

    world->render(glfwHwnd.getWindow());
  }
  glfwTerminate();
}

int main()
{
  Demo demo(200, 200);
  demo.init();
  demo.run();
}
