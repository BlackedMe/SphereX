#include "scene/gameObject.hpp"

GameObject::GameObject(const glm::vec3 &pos, const std::string &name) : transform(pos), name(name) {};

const std::string &GameObject::getName() const
{
  return name;
}
