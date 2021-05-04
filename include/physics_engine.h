#pragma once

#include <cstddef>

#include "ball.h"
#include "brick.h"
#include "cinder/gl/gl.h"
#include "paddle.h"
#include "level.h"

namespace brickbreaker {

struct PhysicsEngine {
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
                                                 const Paddle& paddle);

  /**
   * Updates the velocity if the particle is set to collide with the top or
   * bottom of a brick.
   */
  static size_t UpdateVelocityAndScoreAfterBrickTopOrBottomCollision(
      brickbreaker::Ball& ball, brickbreaker::Brick& brick);

  /**
   * Updates the velocity if the particle is set to collide with the sides of a
   * brick.
   */
  static size_t UpdateVelocityAndScoreAfterBrickSideCollision(brickbreaker::Ball& ball,
                                                    brickbreaker::Brick& brick);

  /**
   * Resets the ball position and velocity of the ball leaves the screen through
   * the bottom.
   */
  static bool HasBallLeftContainer(brickbreaker::Ball& ball, Paddle& paddle);

  static const int kSideLength = 700;
  static const int kDistanceFromOrigin = 25;
  static const int kTopMargin = 25 * 5;

  static const size_t kInitialBallPositionX = 375;
  static const size_t kInitialBallPositionY = 690;
};

}  // namespace brickbreaker