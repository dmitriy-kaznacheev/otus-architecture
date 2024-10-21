add_executable(
  quadratic_equation_test
  quadratic_equation_test.cpp
)

target_link_libraries(
  quadratic_equation_test
  PRIVATE
  quadratic_equation
  gtest_main
)

add_test(
  01_quadratic_equation_gtest
  quadratic_equation_test
)
