#include <rotation.h>
#include <rotatable.h>

#include <stdexcept>

namespace hw
{

using namespace std::string_literals;

Rotation::Rotation(Rotatable *rotatable)
  : rotatable_{ rotatable }
{
  if (!rotatable_) {
    throw std::invalid_argument{"Object is null"s};
  }
}

void Rotation::execute()
{
  auto numDirections = rotatable_->numDirections();
  if (numDirections == 0) {
    throw std::runtime_error("Number of directions is zero"s);
  }

  auto direction = rotatable_->direction();
  auto angular = rotatable_->angularVelocity();
  auto newDirection = (direction + angular) % numDirections;
  rotatable_->setDirection(newDirection);
}

} // hw
