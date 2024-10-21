#include <coord.h>

namespace hw
{

Coord operator+(const Coord &lhs, const Coord &rhs)
{
  return { lhs.x + rhs.x, lhs.y + rhs.y };
}

bool operator==(const Coord &lhs, const Coord &rhs)
{
  return { lhs.x == rhs.x && lhs.y == rhs.y };
}

} // hw
