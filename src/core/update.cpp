#include "core/update.hpp"
#include "events/command.hpp"

namespace ProjectName{

void UpdateHandler::update(float dt)
{
  Command::timer -= dt; 
}
}
