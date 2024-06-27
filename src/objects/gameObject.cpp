#include "objects/gameObject.hpp"

void GameObject::render(GLuint program)
{
  spriteRenderer.render(program, transform.pos);
}
