#include <rotatable.h>


class MockRotatable : public hw::Rotatable
{
public:
  MOCK_METHOD(int, angularVelocity, (), (const, override));
  MOCK_METHOD(int, direction, (), (const, override));
  MOCK_METHOD(int, numDirections, (), (const, override));

  MOCK_METHOD(void, setDirection, (int), (override));
};


TEST(AbstractionRotationTests, Rotation)
{
   ASSERT_TRUE(true);
}
