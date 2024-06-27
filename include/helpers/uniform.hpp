#include "helpers/definitions.hpp"
#include "glad/glad.h"

namespace ProjectName{
void uniformMatrix4fv(GLuint program, const char* name, GLsizei count, GLboolean transpose, const GLfloat *value);
void uniform1i(GLuint program, const char* name, GLint val);
}
