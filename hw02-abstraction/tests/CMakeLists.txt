add_executable(
  abstraction_test
  abstraction_test.cpp
)

target_link_libraries(
  abstraction_test
  PRIVATE
  abstraction
  gtest_main
  gmock_main
)

add_test(
  02_abstraction_gtest
  abstraction_test
)
