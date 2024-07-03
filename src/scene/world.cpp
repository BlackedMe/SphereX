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
  batchRenderer.addQuad(gameObjects.back().transform.pos, gameObjects.back().transform.rotation, gameObjects.back().transform.scale);
}

void World::modifyGameObject(int index)
{
  batchRenderer.modifyQuad(index, gameObjects[index].transform.pos, gameObjects[index].transform.rotation, gameObjects[index].transform.scale);
}

std::vector<GameObject> &World::getGameObjects()
{
  return gameObjects;
}

Camera *World::getCamera()
{
  return &camera;
}
