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
  static void UpdatePosition(Ball& ball);

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

  /**
   * Updates the velocity if the particle is set to collide with the paddle.
   */
  static void UpdateVelocityAfterPaddleCollision(brickbreaker::Ball& ball,
                                                 brickbreaker::Paddle& paddle);

  /**
   * Resets the ball position and velocity of the ball leaves the screen through
   * the bottom.
   */
  static void HasBallLeftContainer(brickbreaker::Ball& ball);

 private:
  static const int kSideLength = 700;
  static const int kDistanceFromOrigin = 25;
  static const int kTopMargin = 25 * 5;

  static const size_t kInitialBallPositionX = 375;
  static const size_t kInitialBallPositionY = 690;
};

}  // namespace brickbreaker