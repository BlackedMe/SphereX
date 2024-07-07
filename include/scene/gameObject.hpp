#pragma once
#include "rendering/texture.hpp"
#include "geometry/transform.hpp"
#include <string>
class GameObject{
public:
  GameObject();
  GameObject(const glm::vec3 &pos, const std::string &name);
  Transform transform;
  Texture texture;
  const std::string &getName() const;

  int textureID = 0;
private:
  std::string name;
};
