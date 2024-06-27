#include "geometry/transform.hpp"
#include "rendering/spriteRenderer.hpp"
#include "rendering/renderable.hpp"
class GameObject : public Renderable{
public:
  void render(GLuint program) override;
  Transform transform;
  SpriteRenderer spriteRenderer; 
};
