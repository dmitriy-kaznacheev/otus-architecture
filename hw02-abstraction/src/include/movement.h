#pragma once


namespace hw
{

class Movable;

class Movement final
{
public:
  Movement(Movable *movable);
  void execute();

private:
  Movable *movable_;
};

} // hw
