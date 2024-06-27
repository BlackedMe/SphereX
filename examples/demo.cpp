#include "demo.hpp"
#include "core/glfwHandler.hpp"
#include "helpers/uniform.hpp"
#include <sys/inotify.h>

Demo::Demo(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT) : glfwHwnd(SCR_WIDTH, SCR_HEIGHT) {};

void Demo::init(){
  const char* vShaderSrc = "../examples/assets/shader/vShader.glsl", *fShaderSrc = "../examples/assets/shader/fShader.glsl";

  glfwHwnd.init();

  program.init(vShaderSrc, fShaderSrc, glfwHwnd.aspectRatio);

  inputHwnd.init(program, glfwHwnd, vShaderSrc, fShaderSrc, &camera);

  inotifyHwnd.init("../examples/assets/shader", IN_MODIFY);
  
  
  float vertices[] = {
    -0.5, -0.5,
     0.5, -0.5,
     0.5,  0.5,
    -0.5,  0.5,
  };

  unsigned int indices[6] = {
    0, 1, 2,
    2, 3, 0
  };

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  GLuint vbo, ebo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
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
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
