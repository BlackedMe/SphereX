#include "demo.hpp"
#include "core/glfwHandler.hpp"
#include "helpers/definitions.hpp"
#include <sys/inotify.h>

namespace ProjectName{
  Demo::Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT) : glfwHwnd(SCR_WIDTH, SCR_HEIGHT) {};

  void Demo::init(){
    const char* vShaderSrc = "../examples/assets/shader/vShader.glsl", *fShaderSrc = "../examples/assets/shader/fShader.glsl";

    glfwHwnd.init();

    program.init(vShaderSrc, fShaderSrc, glfwHwnd.aspectRatio);

    inputHwnd.init(program, glfwHwnd, vShaderSrc, fShaderSrc);

    inotifyHwnd.init("../examples/assets/shader", IN_MODIFY);

    GLuint vbo = 0, ebo = 0;

    unsigned int indices[] = {0, 1, 2, 2, 3, 0};

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
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

      inputHwnd.processInput(glfwHwnd.getWindow(), inotifyHwnd);

      updateHwnd.update(dt);
      
      glUseProgram(*program.get());
      glBindVertexArray(vao);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
      renderer.render(glfwHwnd);    
    }
    glfwTerminate();
  }
}

int main()
{
  ProjectName::Demo demo(200, 200);
  demo.init();
  demo.run();
}
