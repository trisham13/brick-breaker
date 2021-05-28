#include <brick.h>

#include <catch2/catch.hpp>

TEST_CASE("Generate Bricks") {
  std::vector<brickbreaker::Brick> bricks =
      brickbreaker::GenerateBricks("assets/test_level.txt");
  REQUIRE(bricks[0].GetBrickType() == brickbreaker::BrickType::kCracked);
  REQUIRE(bricks[0].GetTopLeftCorner() == glm::vec2(75, 175));
  REQUIRE(bricks[0].GetBottomRightCorner() == glm::vec2(675, 215));
}

TEST_CASE("Erase") {
  brickbreaker::Brick brick =
      brickbreaker::Brick(brickbreaker::BrickType::kUnbreakable,
                          glm::vec2(213, 123), glm::vec2(678, 678));
  brick.Erase();
  REQUIRE(brick.GetTopLeftCorner() == glm::vec2(0, 0));
  REQUIRE(brick.GetBottomRightCorner() == glm::vec2(0, 0));
}