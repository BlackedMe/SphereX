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
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), 0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void *) offsetof(QuadVertex, texCoord));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void *) offsetof(QuadVertex, texIndex));
}

void BatchRenderer::render(GLuint program, GLFWwindow *window)
{
  glBindVertexArray(vao); 

  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  for(int i = 0; i < quad.size(); i++)
  {
    glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(QuadVertex) * 4, sizeof(QuadVertex) * 4, &quad[i].quadVertex);
  }
  glDrawElements(GL_TRIANGLES, quad.size() * 6, GL_UNSIGNED_INT, 0); 
}

void BatchRenderer::addQuad(const glm::vec3 &pos, const glm::vec3 &rotation, const glm::vec3 &scale, float sideLength, float texIndex)
{
  quad.push_back(Quad(pos, rotation, scale, sideLength, texIndex));
}

void BatchRenderer::modifyQuad(int index, const glm::vec3 &pos, const glm::vec3 &rotation, const glm::vec3 &scale)
{
  Quad newQuad(pos, rotation, scale, quad[index].sideLength, quad[index].quadVertex[0].texIndex);

  quad[index] = newQuad;
}
