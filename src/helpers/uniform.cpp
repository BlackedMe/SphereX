#include "helpers/uniform.hpp"
#include "glad/glad.h"

void uniformMatrix4fv(GLuint program, const char* name, GLsizei count, GLboolean transpose, const GLfloat *value)
{
  glUniformMatrix4fv(glGetUniformLocation(program, name), count, transpose, value);
}

void uniform1i(GLuint program, const char* name, GLint val)
{
  glUniform1i(glGetUniformLocation(program, name), val);
}
