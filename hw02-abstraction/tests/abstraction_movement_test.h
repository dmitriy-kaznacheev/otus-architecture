#include <movement.h>
#include <movable.h>


using ::testing::Return;


class MockMovable : public hw::Movable
{
public:
  MOCK_METHOD(std::optional<hw::Coord>, position, (), (const, override));
  MOCK_METHOD(std::optional<hw::Coord>, velocity, (), (const, override));

  MOCK_METHOD(void, setPosition, (hw::Coord), (override));
};


TEST(AbstractionMovementTests, MoveObjectToCorrectPosition)
{
  auto movable_mock = std::make_unique<MockMovable>();
  auto movement = hw::Movement{ movable_mock.get() };

  ON_CALL(*movable_mock, position()).WillByDefault(Return(hw::Coord{ 12, 5 }));
  ON_CALL(*movable_mock, velocity()).WillByDefault(Return(hw::Coord{ -7, 3 }));
  EXPECT_CALL(*movable_mock, setPosition(hw::Coord{ 5, 8 })).Times(1);
  movement.execute();

  ASSERT_TRUE(true);
}
