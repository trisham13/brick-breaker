#pragma once

#include "cinder/gl/gl.h"
#include "paddle.h"
#include "physics_engine.h"
#include "brick.h"

namespace brickbreaker {

using glm::vec2;

/**
 * The container in which all of the bricks, ball and paddle are contained. This
 * class stores all of the player's data, like score and number of lives, as
 * well as updating the ball and paddle positions as the game is played.
 */
class GameContainer {
 public:
  /**
   * Create a new container and initializes the paddle, ball, score, and number
   * of lives.
   */
  GameContainer();
  /**
   * Displays the container walls, title, lives box, and score box.
   */
  void Display() const;
  /**
   * Updates the positions and velocities of the ball (based on the rules
   * described in the assignment documentation).
   */
  void AdvanceOneFrame();

  /**
   * Generates random doubles from -5 to 5 for the initial velocity of the ball.
   * @return a vector for the velocity
   */
  static glm::vec2 GenerateRandomVelocity();

  Paddle& GetPaddle();
  Ball& GetBall();
  size_t GetScore() const;
  size_t GetLives() const;
  std::vector<Brick> GetBricks();
  bool HasGameRestarted() const;
  bool HasPlayerWon() const;

 private:
  const glm::vec2 kInitialPaddlePositionTopLeft = glm::vec2(325, 700);
  const glm::vec2 kInitialPaddlePositionBottomRight = glm::vec2(425, 715);
  const glm::vec2 kInitialBallPosition = glm::vec2(375, 690);

  const size_t kInitialLives = 3;
  const size_t kDistanceFromOrigin = 25;
  const size_t kSideLength = 700;
  const size_t kTopMargin = 125;
  const size_t kSmallBoxesWidth = 100;
  const size_t kSmallBoxesHeight = 75;

  std::vector<Brick> bricks_;
  Paddle paddle_;
  Ball ball_;
  bool has_won_;
  size_t score_;
  size_t lives_;
  bool hasGameRestarted_;
};

}  // namespace brickbreaker