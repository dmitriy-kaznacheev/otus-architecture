#pragma once

#include <optional>

namespace hw
{

class Rotatable
{
public:
  virtual ~Rotatable() = default;
  
  virtual int angularVelocity() const = 0;
  virtual int direction() const = 0;
  virtual int numDirections() const = 0;

  virtual void setDirection(int direction) = 0;
};

} // hw
