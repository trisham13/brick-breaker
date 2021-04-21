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

  const Paddle GetPaddle() const;
  const Ball& GetBall() const;

 private:
  const glm::vec2 kInitialPaddlePositionTopLeft = glm::vec2(325, 700);
  const glm::vec2 kInitialPaddlePositionBottomRight = glm::vec2(425, 715);
  const size_t kInitialBallPositionX = 375;
  const size_t kInitialBallPositionY = 690;

  Paddle paddle_;
  Ball ball_;

  const size_t kDistanceFromOrigin = 25;
  const size_t kSideLength = 700;
};

}  // namespace brickbreaker