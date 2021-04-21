#include <game_container.h>

#include <catch2/catch.hpp>

using brickbreaker::GameContainer;

TEST_CASE("Advance One Frame") {
  SECTION("Testing velocity update after paddle collision.") {
    GameContainer container_;
    brickbreaker::Ball ball = brickbreaker::Ball(380, 705, -1, 2);
    brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(
        ball, container_.GetPaddle());
    REQUIRE(ball.GetVelocity() == glm::vec2(-1, -2));
  }
}
