#include "scene/world.hpp"
#include "core/glfwHandler.hpp"

void World::init()
{
  batchRenderer.init();
}

void World::loadShader(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio)
{
  program.init(vShaderSrc, fShaderSrc, aspectRatio);
  program.use();
}

void World::update(float dt)
{
  camera.update(*program.get());
}

void World::render(GLFWwindow *window)
{
  batchRenderer.render(*program.get(), window);
}

void World::addGameObject(const glm::vec3 &pos)
{
  gameObjects.push_back(GameObject(pos));
  batchRenderer.addQuad(pos);
}

Camera *World::getCamera()
{
  return &camera;
}
