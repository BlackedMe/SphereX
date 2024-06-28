#include "geometry/transform.hpp"
#include "rendering/sprite.hpp"
class GameObject{
public:
  GameObject();
  GameObject(const glm::vec3 &pos);
  Transform transform;
  Sprite sprite;
};
