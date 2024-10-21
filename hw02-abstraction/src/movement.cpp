#include <movement.h>
#include <movable.h>

#include <stdexcept>

namespace hw
{

using namespace std::string_literals;

Movement::Movement(Movable *movable)
  : movable_{ movable }
{
  if (!movable_) {
    throw std::invalid_argument{"Object is null"s};
  }
}

void Movement::execute()
{
  auto position = movable_->position();
  if (!position.has_value()) {
    throw std::runtime_error("Can not get position"s);
  }
  
  auto velocity = movable_->velocity();
  if (!velocity.has_value()) {
    throw std::runtime_error("Can not get velocity"s);
  }

  movable_->setPosition(position.value() + velocity.value());
}

} // hw
