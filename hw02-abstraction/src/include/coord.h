#pragma once

namespace hw
{

struct Coord final
{
  int x, y;
};

Coord operator+(const Coord &lhs, const Coord &rhs);
bool operator==(const Coord &lhs, const Coord &rhs);

} // hw
