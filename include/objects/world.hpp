#include "rendering/renderable.hpp"
#include <vector>
class World : public Renderable{
public:
  void render(GLuint program) override;
private:
  std::vector<Renderable *> renderable;
};
