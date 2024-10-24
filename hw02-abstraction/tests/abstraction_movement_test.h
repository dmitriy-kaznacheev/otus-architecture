#include <movement.h>
#include <movable.h>


using ::testing::Return;
using ::testing::Throw;


class MockMovable : public hw::Movable
{
public:
  MOCK_METHOD(std::optional<hw::Coord>, position, (), (const, override));
  MOCK_METHOD(std::optional<hw::Coord>, velocity, (), (const, override));

  MOCK_METHOD(void, setPosition, (hw::Coord), (override));
};


TEST(AbstractionMovementTests, TryInitializeWithNullObject)
{
  auto movable_mock = nullptr;

  EXPECT_THROW(
    {
      try
      {
        hw::Movement{ movable_mock };
      }
      catch (const std::invalid_argument &e)
      {
        EXPECT_STREQ("Object is null", e.what());
        throw;
      }
    }, 
    std::invalid_argument
  );
}

TEST(AbstractionMovementTests, MoveObjectToCorrectPosition)
{
  auto movable_mock = std::make_unique<MockMovable>();
  auto movement = hw::Movement{ movable_mock.get() };

  ON_CALL(*movable_mock, position()).WillByDefault(Return(hw::Coord{ 12, 5 }));
  ON_CALL(*movable_mock, velocity()).WillByDefault(Return(hw::Coord{ -7, 3 }));
  EXPECT_CALL(*movable_mock, setPosition(hw::Coord{ 5, 8 })).Times(1);
  movement.execute();
}

TEST(AbstractionMovementTests, TryToMoveObjectWithIncorrectPosition)
{
  auto movable_mock = std::make_unique<MockMovable>();
  auto movement = hw::Movement{ movable_mock.get() };

  ON_CALL(*movable_mock, position()).WillByDefault(Return(std::nullopt));
  ON_CALL(*movable_mock, velocity()).WillByDefault(Return(hw::Coord{ -7, 3 }));
  EXPECT_THROW(
    {
      try
      {
        movement.execute();
      }
      catch (const std::runtime_error &e)
      {
        EXPECT_STREQ("Can not get position", e.what());
        throw;
      }
    }, 
    std::runtime_error
  );
}

TEST(AbstractionMovementTests, TryToMoveObjectWithIncorrectVelocity)
{
  auto movable_mock = std::make_unique<MockMovable>();
  auto movement = hw::Movement{ movable_mock.get() };

  ON_CALL(*movable_mock, position()).WillByDefault(Return(hw::Coord{ 12, 5 }));
  ON_CALL(*movable_mock, velocity()).WillByDefault(Return(std::nullopt));
  EXPECT_THROW(
    {
      try
      {
        movement.execute();
      }
      catch (const std::runtime_error &e)
      {
        EXPECT_STREQ("Can not get velocity", e.what());
        throw;
      }
    }, 
    std::runtime_error
  );
}

TEST(AbstractionMovementTests, TryToMoveObjectThatCantChangePosition)
{
  auto movable_mock = std::make_unique<MockMovable>();
  auto movement = hw::Movement{ movable_mock.get() };

  ON_CALL(*movable_mock, position()).WillByDefault(Return(hw::Coord{ 12, 5 }));
  ON_CALL(*movable_mock, velocity()).WillByDefault(Return(hw::Coord{ -7, 3 }));
  EXPECT_CALL(*movable_mock, setPosition(hw::Coord{ 5, 8 })).Times(1)
    .WillRepeatedly(Throw(std::runtime_error("Can not set position")));
  EXPECT_THROW(
    {
      try
      {
        movement.execute();
      }
      catch (const std::runtime_error &e)
      {
        EXPECT_STREQ("Can not set position", e.what());
        throw;
      }
    }, 
    std::runtime_error
  );
}

