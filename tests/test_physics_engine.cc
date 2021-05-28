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
      GameContainer container = GameContainer(std::vector<brickbreaker::Level>{
          brickbreaker::Level("assets/test_level.txt")});
      brickbreaker::Ball ball =
          brickbreaker::Ball(glm::vec2(250, 800), glm::vec2(0, 1));
      brickbreaker::PhysicsEngine::HasBallLeftContainer(ball,
                                                        container.GetPaddle());
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
      GameContainer container = GameContainer(std::vector<brickbreaker::Level>{
          brickbreaker::Level("assets/test_level.txt")});
      brickbreaker::Ball ball = brickbreaker::Ball(375, 705, 0, 2);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(
          ball, container.GetPaddle());
      REQUIRE(ball.GetVelocity() == glm::vec2(0, -2));
    }
  }
  SECTION("Against the bricks") {
    SECTION("Top of the brick") {
      GameContainer container = GameContainer(std::vector<brickbreaker::Level>{
          brickbreaker::Level("assets/test_level.txt")});
      container.GetBall().SetVelocity(0, 2);
      container.GetBall().SetPosition(375, 73);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      for (brickbreaker::Brick brick : bricks) {
        brickbreaker::PhysicsEngine::
            UpdateVelocityAndScoreAfterBrickTopOrBottomCollision(
                container.GetBall(), brick);
      }
      REQUIRE(container.GetBall().GetVelocity() == glm::vec2(0, 2));
    }
    SECTION("Bottom of the brick") {
      brickbreaker::Ball ball = brickbreaker::Ball(375, 218, 0, -2);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      brickbreaker::PhysicsEngine::
          UpdateVelocityAndScoreAfterBrickTopOrBottomCollision(ball, bricks[0]);
      REQUIRE(ball.GetVelocity() == glm::vec2(0, 2));
    }
    SECTION("Left side of the brick") {
      brickbreaker::Ball ball = brickbreaker::Ball(73, 190, 2, 0);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      brickbreaker::PhysicsEngine::
          UpdateVelocityAndScoreAfterBrickSideCollision(ball, bricks[0]);
      REQUIRE(ball.GetVelocity() == glm::vec2(-2, 0));
    }
    SECTION("Right side of the brick") {
      brickbreaker::Ball ball = brickbreaker::Ball(678, 190, -2, 0);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      brickbreaker::PhysicsEngine::
          UpdateVelocityAndScoreAfterBrickSideCollision(ball, bricks[0]);
      REQUIRE(ball.GetVelocity() == glm::vec2(2, 0));
    }
  }
}

TEST_CASE("No collisions because velocity is not in direction of object") {
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
      GameContainer container = GameContainer(std::vector<brickbreaker::Level>{
          brickbreaker::Level("assets/test_level.txt")});
      brickbreaker::Ball ball = brickbreaker::Ball(375, 705, 0, -2);
      brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(
          ball, container.GetPaddle());
      REQUIRE(ball.GetVelocity() == glm::vec2(0, -2));
    }
  }
  SECTION("Against the bricks") {
    SECTION("Top of the brick") {
      brickbreaker::Ball ball = brickbreaker::Ball(375, 73, 0, -2);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      brickbreaker::PhysicsEngine::
          UpdateVelocityAndScoreAfterBrickTopOrBottomCollision(ball, bricks[0]);
      REQUIRE(ball.GetVelocity() == glm::vec2(0, -2));
    }
    SECTION("Bottom of the brick") {
      brickbreaker::Ball ball = brickbreaker::Ball(375, 218, 0, 2);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      brickbreaker::PhysicsEngine::
          UpdateVelocityAndScoreAfterBrickTopOrBottomCollision(ball, bricks[0]);
      REQUIRE(ball.GetVelocity() == glm::vec2(0, 2));
    }
    SECTION("Left side of the brick") {
      brickbreaker::Ball ball = brickbreaker::Ball(73, 190, -2, 0);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      brickbreaker::PhysicsEngine::
          UpdateVelocityAndScoreAfterBrickSideCollision(ball, bricks[0]);
      REQUIRE(ball.GetVelocity() == glm::vec2(-2, 0));
    }
    SECTION("Right side of the brick") {
      brickbreaker::Ball ball = brickbreaker::Ball(678, 190, 2, 0);
      std::vector<brickbreaker::Brick> bricks =
          brickbreaker::GenerateBricks("assets/test_level.txt");
      brickbreaker::PhysicsEngine::
          UpdateVelocityAndScoreAfterBrickSideCollision(ball, bricks[0]);
      REQUIRE(ball.GetVelocity() == glm::vec2(2, 0));
    }
  }
}

TEST_CASE("Has ball left container") {
  GameContainer container = GameContainer(std::vector<brickbreaker::Level>{
      brickbreaker::Level("assets/test_level.txt")});
  brickbreaker::Ball ball = brickbreaker::Ball(234, 1000, 2, 0);
  brickbreaker::PhysicsEngine::HasBallLeftContainer(ball,
                                                    container.GetPaddle());
  REQUIRE(ball.GetVelocity() == glm::vec2(0, 0));
  REQUIRE(ball.GetPosition() == glm::vec2(375, 690));
  REQUIRE(container.GetPaddle().GetTopLeftCorner() == glm::vec2(275, 700));
  REQUIRE(container.GetPaddle().GetBottomRightCorner() == glm::vec2(475, 715));
}
