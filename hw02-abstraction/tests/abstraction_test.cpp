#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "abstraction_movement_test.h"
#include "abstraction_rotation_test.h"

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   ::testing::InitGoogleMock(&argc, argv);
   ::testing::FLAGS_gmock_verbose = "error";
   return RUN_ALL_TESTS();
}
