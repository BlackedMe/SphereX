#include "demo.hpp"
#include "core/glfwHandler.hpp"
#include "helpers/uniform.hpp"
#include "geometry/quad.hpp"
#include <sys/inotify.h>

Demo::Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT) : glfwHwnd(SCR_WIDTH, SCR_HEIGHT) {};

void Demo::init(){
  const char* vShaderSrc = "../examples/assets/shader/vShader.glsl", *fShaderSrc = "../examples/assets/shader/fShader.glsl";

  glfwHwnd.init();

  program.init(vShaderSrc, fShaderSrc, glfwHwnd.aspectRatio);

  inputHwnd.init(program, glfwHwnd, vShaderSrc, fShaderSrc, &camera);

  inotifyHwnd.init("../examples/assets/shader", IN_MODIFY);
  
  const char *src[1];
  src[0] = "../examples/sprites/Sprite-0001.png";
  texture.init(GL_RGBA8, 320, 320, 32);
  texture.load(1, src);

  batchRenderer.init();  
  addQuad(batchRenderer, glm::vec2(0), 0.5, 0);
  addQuad(batchRenderer, glm::vec2(0.5, 0.5), 0.5, 0);
}

void Demo::run(){
  float lastFrame = glfwGetTime(), dt; 
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    float currentTime = glfwGetTime();
    dt = currentTime - lastFrame;
    lastFrame = currentTime; 

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);  

    inputHwnd.processInput(dt, glfwHwnd.getWindow(), inotifyHwnd);

    updateHwnd.update(dt);
    
    glUseProgram(*program.get());

    uniformMatrix4fv(*program.get(), "view", 1, GL_FALSE, &camera.getView()[0][0]);
    // glBindVertexArray(vao);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    batchRenderer.render(*program.get());
    renderer.render(glfwHwnd);    
  }
  glfwTerminate();
}

int main()
{
  Demo demo(200, 200);
  demo.init();
  demo.run();
}
