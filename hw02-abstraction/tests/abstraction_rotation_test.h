#include <rotation.h>
#include <rotatable.h>


using ::testing::Return;
using ::testing::Throw;


class MockRotatable : public hw::Rotatable
{
public:
  MOCK_METHOD(int, angularVelocity, (), (const, override));
  MOCK_METHOD(int, direction, (), (const, override));
  MOCK_METHOD(int, numDirections, (), (const, override));

  MOCK_METHOD(void, setDirection, (int), (override));
};


TEST(AbstractionRotationTests, TryInitializeWithNullObject)
{
  auto rotatable_mock = nullptr;

  EXPECT_THROW(
    {
      try
      {
        hw::Rotation{ rotatable_mock };
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

TEST(AbstractionRotationTests, RotateObjectToCorrectPositionWhenLessThanNumDirections)
{
  auto rotatable_mock = std::make_unique<MockRotatable>();
  auto rotation = hw::Rotation{ rotatable_mock.get() };

  ON_CALL(*rotatable_mock, numDirections()).WillByDefault(Return(360));
  ON_CALL(*rotatable_mock, direction()).WillByDefault(Return(130));
  ON_CALL(*rotatable_mock, angularVelocity()).WillByDefault(Return(20));
  EXPECT_CALL(*rotatable_mock, setDirection(150)).Times(1);
  rotation.execute();
}

TEST(AbstractionRotationTests, RotateObjectToCorrectPositionWhenMoreThanNumDirections)
{
  auto rotatable_mock = std::make_unique<MockRotatable>();
  auto rotation = hw::Rotation{ rotatable_mock.get() };

  ON_CALL(*rotatable_mock, numDirections()).WillByDefault(Return(360));
  ON_CALL(*rotatable_mock, direction()).WillByDefault(Return(350));
  ON_CALL(*rotatable_mock, angularVelocity()).WillByDefault(Return(20));
  EXPECT_CALL(*rotatable_mock, setDirection(10)).Times(1);
  rotation.execute();
}

TEST(AbstractionRotationTests, TryToRotateObjectWithIncorrectNumDirections)
{
  auto rotatable_mock = std::make_unique<MockRotatable>();
  auto rotation = hw::Rotation{ rotatable_mock.get() };

  ON_CALL(*rotatable_mock, numDirections()).WillByDefault(Return(0));
  ON_CALL(*rotatable_mock, direction()).WillByDefault(Return(130));
  ON_CALL(*rotatable_mock, angularVelocity()).WillByDefault(Return(20));
  EXPECT_THROW(
    {
      try
      {
        rotation.execute();
      }
      catch (const std::runtime_error &e)
      {
        EXPECT_STREQ("Number of directions is zero", e.what());
        throw;
      }
    }, 
    std::runtime_error
  );
}

TEST(AbstractionRotationTests, TryToRotateObjectWithIncorrectGetDirection)
{
  auto rotatable_mock = std::make_unique<MockRotatable>();
  auto rotation = hw::Rotation{ rotatable_mock.get() };

  ON_CALL(*rotatable_mock, numDirections()).WillByDefault(Return(360));
  EXPECT_CALL(*rotatable_mock, direction()).Times(1)
    .WillRepeatedly(Throw(std::runtime_error("Can not get direction")));
  ON_CALL(*rotatable_mock, angularVelocity()).WillByDefault(Return(20));
  EXPECT_THROW(
    {
      try
      {
        rotation.execute();
      }
      catch (const std::runtime_error &e)
      {
        EXPECT_STREQ("Can not get direction", e.what());
        throw;
      }
    }, 
    std::runtime_error
  );
}

TEST(AbstractionRotationTests, TryToRotateObjectWithIncorrectGetAngularVelocity)
{
  auto rotatable_mock = std::make_unique<MockRotatable>();
  auto rotation = hw::Rotation{ rotatable_mock.get() };

  ON_CALL(*rotatable_mock, numDirections()).WillByDefault(Return(360));
  ON_CALL(*rotatable_mock, direction()).WillByDefault(Return(130));
  EXPECT_CALL(*rotatable_mock, angularVelocity()).Times(1)
    .WillRepeatedly(Throw(std::runtime_error("Can not get angular velocity")));
  EXPECT_THROW(
    {
      try
      {
        rotation.execute();
      }
      catch (const std::runtime_error &e)
      {
        EXPECT_STREQ("Can not get angular velocity", e.what());
        throw;
      }
    }, 
    std::runtime_error
  );
}

TEST(AbstractionRotationTests, TryToRotateObjectThatCantChangeDirection)
{
  auto rotatable_mock = std::make_unique<MockRotatable>();
  auto rotation = hw::Rotation{ rotatable_mock.get() };

  ON_CALL(*rotatable_mock, numDirections()).WillByDefault(Return(360));
  ON_CALL(*rotatable_mock, direction()).WillByDefault(Return(130));
  ON_CALL(*rotatable_mock, angularVelocity()).WillByDefault(Return(20));
  EXPECT_CALL(*rotatable_mock, setDirection(150)).Times(1)
    .WillRepeatedly(Throw(std::runtime_error("Can not set direction")));
  EXPECT_THROW(
    {
      try
      {
        rotation.execute();
      }
      catch (const std::runtime_error &e)
      {
        EXPECT_STREQ("Can not set direction", e.what());
        throw;
      }
    }, 
    std::runtime_error
  );
}

