#pragma once
#include "core/glfwHandler.hpp"
#include "rendering/batchRenderer.hpp"
#include "scene/gameObject.hpp"
#include "scene/camera.hpp"
#include "core/program.hpp"
#include <vector>
class World{
public:
  void init(float aspectRatio);

  void loadShader(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio);

  void update(float dt);

  void render(GLFWwindow *window);

  void addGameObject(const glm::vec3 &pos);

  void modifyGameObject(int index);

  std::vector<GameObject> &getGameObjects();

  Camera *getCamera();

  std::vector<GameObject> gameObjects;
private:
  BatchRenderer batchRenderer;
  Camera camera;
  Program program;
};
