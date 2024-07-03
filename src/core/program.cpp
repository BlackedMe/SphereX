#include "core/program.hpp"
#include "helpers/shader.hpp"
#include "helpers/uniform.hpp"
#include "glm/ext/matrix_float4x4.hpp"
#include <iostream>

void Program::init(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio)
{
  GLuint vShader = Shader::compileShader(GL_VERTEX_SHADER, vShaderSrc);
  GLuint fShader = Shader::compileShader(GL_FRAGMENT_SHADER, fShaderSrc);
  
  program = glCreateProgram();
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);

  GLint linkStatus;
  glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
  
  if(linkStatus != GL_TRUE)
  {
    GLsizei length;
    GLchar *infoLog = new GLchar[1024];
    glGetProgramInfoLog(program, 1024, &length, infoLog);
    std::cout << infoLog << '\n';
  }
  
  //initalizes default uniform values
  glm::mat4 model(1.0f);
  glUseProgram(program);
  uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]); 
  glUseProgram(0);
}

void Program::reload(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio)
{
  Program reloadedProgram;
  reloadedProgram.init(vShaderSrc, fShaderSrc, aspectRatio);

  if(reloadedProgram.program)
  {
    glDeleteProgram(program);
    program = reloadedProgram.program;
  }
}

void Program::use() 
{
  glUseProgram(program);
}

GLuint *Program::get()
{
  return &program;
}
