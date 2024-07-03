#pragma once
#include "geometry/transform.hpp"
#include "rendering/sprite.hpp"
#include <string>
class GameObject{
public:
  GameObject();
  GameObject(const glm::vec3 &pos, const std::string &name);
  Transform transform;
  Sprite sprite;
  const std::string &getName() const;
private:
  std::string name;
};
