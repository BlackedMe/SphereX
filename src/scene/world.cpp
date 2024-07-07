#include "scene/world.hpp"
#include "core/glfwHandler.hpp"
#include <string>

void World::init(float aspectRatio)
{
  batchRenderer.init();
  camera.updateOrtho(aspectRatio);
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
  std::string name = "GameObject " +  std::to_string(gameObjects.size());
  gameObjects.push_back(GameObject(pos, name));

  GameObject &gameObject = gameObjects.back();
  batchRenderer.addQuad(gameObject.transform, gameObject.texture);
}

void World::modifyGameObject(int index)
{
  GameObject &gameObject = gameObjects[index];
  batchRenderer.modifyQuad(index, gameObject.transform, gameObject.texture);
}

std::vector<GameObject> &World::getGameObjects()
{
  return gameObjects;
}

Camera *World::getCamera()
{
  return &camera;
}
