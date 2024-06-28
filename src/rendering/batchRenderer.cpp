#include "rendering/batchRenderer.hpp"
#include "GLFW/glfw3.h"

void BatchRenderer::init()
{
  GLuint ebo;
  unsigned int indices[6 * maxNumQuad];

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(QuadVertex) * 4 * maxNumQuad, 0, GL_DYNAMIC_DRAW);

  for(int i = 0, j = 0; i < 6 * maxNumQuad; i += 6, j += 4)
  {
    indices[i] = j;  
    indices[i + 1] = j + 1;
    indices[i + 2] = j + 2;

    indices[i + 3] = j + 2;
    indices[i + 4] = j + 3;
    indices[i + 5] = j;
  }

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), 0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void *) offsetof(QuadVertex, texCoord));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void *) offsetof(QuadVertex, texIndex));
}

void BatchRenderer::render(GLuint program, GLFWwindow *window)
{
  glBindVertexArray(vao); 

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(QuadVertex) * lastIndex, &quads[0]);
  glDrawElements(GL_TRIANGLES, (lastIndex/4) * 6, GL_UNSIGNED_INT, 0); 
  glfwSwapBuffers(window);
}

void BatchRenderer::addQuad(const glm::vec2 &pos, float sideLength, float texIndex)
{
  sideLength /= 2;
  QuadVertex quadVertex[4];
  quadVertex[0] = {glm::vec2(pos.x - sideLength, pos.y - sideLength), glm::vec2(0, 0), texIndex};
  quadVertex[1] = {glm::vec2(pos.x + sideLength, pos.y - sideLength), glm::vec2(1, 0), texIndex};
  quadVertex[2] = {glm::vec2(pos.x + sideLength, pos.y + sideLength), glm::vec2(1, 1), texIndex};
  quadVertex[3] = {glm::vec2(pos.x - sideLength, pos.y + sideLength), glm::vec2(0, 1), texIndex};

  for(int i = 0; i < 4; i++)
  {
    quads[lastIndex + i] = quadVertex[i];
  }
  lastIndex += 4;
}

