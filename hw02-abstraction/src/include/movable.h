#pragma once

#include <optional>
#include <coord.h>

namespace hw
{

class Movable 
{
public:
  virtual ~Movable() = default;

  virtual std::optional<Coord> position() const = 0;
  virtual std::optional<Coord> velocity() const = 0;
  
  virtual void setPosition(Coord pos) = 0;
};

} // hw
