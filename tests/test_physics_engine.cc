#include <game_container.h>

#include <catch2/catch.hpp>

using brickbreaker::GameContainer;

double kDelta = 0.0005;

TEST_CASE("Update position") {
  brickbreaker::Ball ball =
      brickbreaker::Ball(glm::vec2(100, 100), glm::vec2(1, 0));
  brickbreaker::PhysicsEngine::UpdatePosition(ball);
  REQUIRE(ball.GetPosition() == glm::vec2(101, 100));
}

TEST_CASE("Updating velocity after collisions") {
  SECTION("Against Walls") {
    SECTION("Left vertical") {
      brickbreaker::Ball ball =
          brickbreaker::Ball(glm::vec2(30, 250), glm::vec2(1, 0));
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(1, 0));
    }
    SECTION("Right vertical") {
      brickbreaker::Ball ball =
          brickbreaker::Ball(glm::vec2(724, 250), glm::vec2(1, 0));
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(-1, 0));
    }
    SECTION("Top horizontal") {
      brickbreaker::Ball ball =
          brickbreaker::Ball(glm::vec2(250, 126), glm::vec2(0, -1));
      brickbreaker::PhysicsEngine::
          UpdateVelocityAfterTopHorizontalWallCollision(ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(0, 1));
    }
    SECTION("Bottom horizontal") {
      brickbreaker::Ball ball =
          brickbreaker::Ball(glm::vec2(250, 800), glm::vec2(0, 1));
//      brickbreaker::PhysicsEngine::HasBallLeftContainer(ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(0, 0));
    }
  }
  SECTION("Against corners") {
    SECTION("Top-left") {
      brickbreaker::Ball ball = brickbreaker::Ball(26, 126, -1, -1);
      brickbreaker::PhysicsEngine::
          UpdateVelocityAfterTopHorizontalWallCollision(ball);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(1, 1));
    }
    SECTION("Top-right") {
      brickbreaker::Ball ball = brickbreaker::Ball(724, 126, 1, -1);
      brickbreaker::PhysicsEngine::
          UpdateVelocityAfterTopHorizontalWallCollision(ball);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(-1, 1));
    }
  }
  SECTION("Against the paddle") {
    SECTION("Top of the paddle") {
      GameContainer container_;
      brickbreaker::Ball ball = brickbreaker::Ball(375, 705, 0, 2);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(
          ball, container_.GetPaddle());
      REQUIRE(ball.GetVelocity() == glm::vec2(0, -2));
    }
  }
}

TEST_CASE("No collisions because dot product is a positive number.") {
  SECTION("Against walls") {
    SECTION("Left vertical") {
      brickbreaker::Ball ball = brickbreaker::Ball(26, 250, 1, 0);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(1, 0));
    }
    SECTION("Right vertical") {
      brickbreaker::Ball ball = brickbreaker::Ball(724, 250, -1, 0);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(-1, 0));
    }
    SECTION("Top horizontal") {
      brickbreaker::Ball ball = brickbreaker::Ball(250, 126, 0, 1);
      brickbreaker::PhysicsEngine::
          UpdateVelocityAfterTopHorizontalWallCollision(ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(0, 1));
    }
    SECTION("Bottom horizontal") {
      brickbreaker::Ball ball = brickbreaker::Ball(250, 724, 0, -1);
      brickbreaker::PhysicsEngine::
          UpdateVelocityAfterTopHorizontalWallCollision(ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(0, -1));
    }
  }
  SECTION("Against corners") {
    SECTION("Top-left") {
      brickbreaker::Ball ball = brickbreaker::Ball(32, 32, 1, 1);
      brickbreaker::PhysicsEngine::
          UpdateVelocityAfterTopHorizontalWallCollision(ball);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(1, 1));
    }
    SECTION("Top-right") {
      brickbreaker::Ball ball = brickbreaker::Ball(724, 126, -1, 1);
      brickbreaker::PhysicsEngine::
          UpdateVelocityAfterTopHorizontalWallCollision(ball);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(
          ball);
      REQUIRE(ball.GetVelocity() == glm::vec2(-1, 1));
    }
  }
  SECTION("Against the paddle") {
    SECTION("Top of the paddle") {
      GameContainer container_;
      brickbreaker::Ball ball = brickbreaker::Ball(375, 705, 0, -2);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(
          ball, container_.GetPaddle());
      REQUIRE(ball.GetVelocity() == glm::vec2(0, -2));
    }
  }
}


