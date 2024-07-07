#include "demo.hpp"
#include "GLFW/glfw3.h"
#include "core/glfwHandler.hpp"
#include "core/editorLayout.hpp"
#include "helpers/uniform.hpp"
#include "helpers/textureHandler.hpp"
#include "rendering/textureAtlas.hpp"
#include <sys/inotify.h>

Demo::Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT) : glfwHwnd(SCR_WIDTH, SCR_HEIGHT) {};

void Demo::init(){
  glfwHwnd.init();
  
  frameBuffer.init(0, 0);

  imGuiHandler.init(glfwHwnd.getWindow());

  world->init(glfwHwnd.aspectRatio);

  glfwHwnd.initCallBack(world->getCamera());

  world->loadShader("../examples/assets/shader/vShader.glsl", "../examples/assets/shader/fShader.glsl", glfwHwnd.aspectRatio);

  inputHwnd.init(glfwHwnd, world->getCamera());

  textureHandler.init(GL_RGBA8, 320, 320, 32);

  TextureAtlas textureAtlas(glm::ivec2(32, 32));
  textureAtlas.loadData("../examples/sprites/icons.png");

  textureHandler.load(1, &textureAtlas);

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

    imGuiHandler.startNewFrame();

    inputHwnd.processInput(dt, glfwHwnd.getWindow());

    world->update(dt);

    frameBuffer.bind();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);  

    world->render(glfwHwnd.getWindow());

    frameBuffer.unbind();
    editor.render(frameBuffer, textureHandler, *world);
    imGuiHandler.render();

    glfwSwapBuffers(glfwHwnd.getWindow());
  }
  glfwTerminate();
  imGuiHandler.terminate();
}

int main()
{
  Demo demo(800,400);
  demo.init();
  demo.run();
}
