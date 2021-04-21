#pragma once

#include "cinder/gl/gl.h"
#include "paddle.h"
#include "physics_engine.h"

namespace brickbreaker {

using glm::vec2;

/**
 * TODO
 */
class GameContainer {
 public:
  /**
   * TODO
   */
  GameContainer();
  /**
   * TODO
   */
  void Display() const;
  /**
   * TODO
   */
  void AdvanceOneFrame();

  Paddle& GetPaddle();
  Ball& GetBall();
  size_t GetScore() const;
  size_t GetLives() const;
  bool HasPlayerWon() const;

 private:
  const glm::vec2 kInitialPaddlePositionTopLeft = glm::vec2(325, 700);
  const glm::vec2 kInitialPaddlePositionBottomRight = glm::vec2(425, 715);
  const glm::vec2 kInitialBallPosition = glm::vec2(375, 690);

  const size_t kInitialLives = 3;
  const size_t kDistanceFromOrigin = 25;
  const size_t kSideLength = 700;
  const size_t kTopMargin = 125;

  Paddle paddle_;
  Ball ball_;
  bool has_won_;
  size_t score_;
  size_t lives_;

  static glm::vec2 GenerateRandomVelocity();
};

}  // namespace brickbreaker