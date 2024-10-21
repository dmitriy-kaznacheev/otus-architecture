#include <quadratic_equation.h>

#include <cmath>
#include <stdexcept>
 

namespace hw
{

using namespace std::string_literals;

constexpr double eps{ 1e-5 };

void check(double param)
{
   if (std::isnan(param)) {
      throw std::invalid_argument{"Coefficients can not be NAN"s};
   } 
  
   if (std::isinf(param)) {
      throw std::invalid_argument{"Coefficients can not be INF"s};
   }
}

roots_t solve(double a, double b, double c)
{
   check(a); check(b); check(c);

   if (std::abs(a) <= eps) {
     throw std::invalid_argument{"Coefficient 'a' can not equal zero"s};
   }

   double discriminant = b*b - 4*a*c;

   if (discriminant < -eps) {
      return {};
   }

   if (std::abs(discriminant) <= eps) {
      double x = (-b) / (2*a);
      return {x, x};
   }
    
   double x1 = (-b + std::sqrt(discriminant)) / (2*a);
   double x2 = (-b - std::sqrt(discriminant)) / (2*a);
   return {x1, x2};
}

} // hw
