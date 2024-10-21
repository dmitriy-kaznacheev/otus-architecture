#include <gtest/gtest.h>

#include <quadratic_equation.h>
#include <stdexcept>
#include <cmath>


constexpr double eps{ 1e-6 };


TEST(QuadraticEquationTests, NoRealRoots)
{
   const auto actual = hw::solve(1, 0, 1);
   ASSERT_TRUE(actual.empty());
}

TEST(QuadraticEquationTests, TwoDistinctRoots)
{
   const auto expected = hw::roots_t{1, -1};
   const auto actual   = hw::solve(1, 0, -1);
   ASSERT_EQ(expected, actual);
}

TEST(QuadraticEquationTests, OneRealRoot)
{
   const auto expected = hw::roots_t{-1, -1};
   const auto actual   = hw::solve(1, 2, 1);
   ASSERT_EQ(expected, actual);
}

TEST(QuadraticEquationTests, OneRealRootEPS)
{
   const auto expected = hw::roots_t{-1, -1};
   const auto actual   = hw::solve(1, 2, (1 - eps/4));
   ASSERT_EQ(expected, actual);
}

TEST(QuadraticEquationTests, aEqualsZero)
{
   ASSERT_THROW(
      hw::solve(-eps, 2, 1),
      std::invalid_argument
   );

   ASSERT_THROW(
      hw::solve(+eps, 2, 1), 
      std::invalid_argument
   );
}

TEST(QuadraticEquationTests, ParamsIsNAN)
{
   ASSERT_THROW(
      hw::solve(NAN, 2, 1),
      std::invalid_argument
   );

   ASSERT_THROW(
      hw::solve(1, NAN, 1), 
      std::invalid_argument
   );

   ASSERT_THROW(
      hw::solve(1, 2, NAN), 
      std::invalid_argument
   );
}

TEST(QuadraticEquationTests, ParamsIsINF)
{
   ASSERT_THROW(
      hw::solve(INFINITY, 2, 1),
      std::invalid_argument
   );

   ASSERT_THROW(
      hw::solve(1, INFINITY, 1), 
      std::invalid_argument
   );

   ASSERT_THROW(
      hw::solve(1, 2, INFINITY), 
      std::invalid_argument
   );
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
