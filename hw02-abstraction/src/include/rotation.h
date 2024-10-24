#pragma once

namespace hw
{

class Rotatable;

class Rotation final
{
public:
  Rotation(Rotatable *rotatable);
  void execute();

private:
  Rotatable *rotatable_;
};

} // hw
