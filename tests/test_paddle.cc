#include <game_container.h>

#include <catch2/catch.hpp>

using brickbreaker::GameContainer;

TEST_CASE("Move by") {
  brickbreaker::Paddle paddle =
      brickbreaker::Paddle(glm::vec2(10, 20), glm::vec2(20, 25));
  paddle.MoveBy(5);
  REQUIRE(paddle.GetTopLeftCorner() == glm::vec2(15, 20));
  REQUIRE(paddle.GetBottomRightCorner() == glm::vec2(25, 25));
}