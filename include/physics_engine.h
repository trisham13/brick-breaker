#pragma once

#include <cstddef>

#include "ball.h"
#include "cinder/gl/gl.h"
#include "paddle.h"

namespace brickbreaker {

class PhysicsEngine {
 public:
  /**
   * Adds the velocity to the particle's position.
   */
  static void UpdatePosition(Ball ball);

  /**
   * Updates the velocity if the particle is set to collide with the vertical
   * wall.
   */
  static void UpdateVelocityAfterVerticalWallCollision(
      brickbreaker::Ball& ball);

  /**
   * Updates the velocity if the particle is set to collide with the horizontal
   * wall.
   */
  static void UpdateVelocityAfterTopHorizontalWallCollision(
      brickbreaker::Ball& ball);
  static void UpdateVelocityAfterPaddleCollision(brickbreaker::Ball& ball,
                                                 brickbreaker::Paddle& paddle);
  static void UpdateVelocityAfterBrickCollision(brickbreaker::Ball& ball);

 private:
  static const int kSideLength = 500;
  static const int kDistanceFromOrigin = 25;
};

}  // namespace brickbreaker