#include <game_container.h>

#include <catch2/catch.hpp>

using brickbreaker::GameContainer;

TEST_CASE("Advance One Frame") {
  SECTION("Testing velocity update after paddle collision") {
    GameContainer container(std::vector<brickbreaker::Level>{
        brickbreaker::Level("assets/test_level.txt")});
    brickbreaker::Ball ball = brickbreaker::Ball(380, 705, -1, 2);
    brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(
        ball, container.GetPaddle());
    REQUIRE(ball.GetVelocity() == glm::vec2(-1, -2));
  }
  SECTION("Testing score update after a brick collision") {
    GameContainer container(std::vector<brickbreaker::Level>{
        brickbreaker::Level("assets/test_level.txt")});
    container.GetBall().SetPosition(375, 217);
    container.GetBall().SetVelocity(0, -2);
    container.AdvanceOneFrame();
    REQUIRE(container.GetScore() == 50);
    REQUIRE(container.GetLives() == 5);
  }
  SECTION("Testing life update after leaving the container") {
    GameContainer container(std::vector<brickbreaker::Level>{
        brickbreaker::Level("assets/test_level.txt")});
    container.GetBall().SetPosition(375, 1000);
    container.GetBall().SetVelocity(0, -2);
    container.AdvanceOneFrame();
    REQUIRE(container.GetScore() == 0);
    REQUIRE(container.GetLives() == 4);
  }
  SECTION("Testing winning status after breaking all bricks") {
    GameContainer container(std::vector<brickbreaker::Level>{
        brickbreaker::Level("assets/test_level.txt")});
    container.GetBall().SetPosition(375, 217);
    container.GetBall().SetVelocity(0, -2);
    container.AdvanceOneFrame();
    REQUIRE(container.HasPlayerWon());
  }
}
