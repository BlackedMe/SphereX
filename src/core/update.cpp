#include "core/update.hpp"
#include "events/command.hpp"

void UpdateHandler::update(float dt)
{
  Command::timer -= dt; 
}
