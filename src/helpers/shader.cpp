#include "helpers/parser.hpp"
#include "helpers/shader.hpp"
#include <iostream>

GLuint Shader::compileShader(GLenum type, const char* src)
{
  const char* shaderSrc = parseFromFile(src);
  GLuint shaderObj = glCreateShader(type);
  glShaderSource(shaderObj, 1, &shaderSrc, 0);
  glCompileShader(shaderObj);

  GLint compileStatus;
  glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &compileStatus);

  if(compileStatus != GL_TRUE)
  {
    GLsizei length;
    GLchar *infoLog = new GLchar[1024];
    glGetShaderInfoLog(shaderObj, 1024, &length, infoLog);
    std::cout << infoLog << '\n';
  }
  return shaderObj;
}
