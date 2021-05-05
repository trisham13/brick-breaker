#pragma once

#include <cstddef>

#include "cinder/gl/gl.h"

namespace brickbreaker {

/**
 * A ball  that is added to the container with a specific location and velocity.
 */
struct Ball {
 public:
  Ball();
  /**
   * Creates a ball with a specific location and velocity.
   */
  Ball(double position_x, double position_y, double velocity_x,
       double velocity_y);
  /**
   * Creates a ball with a specific location and velocity.
   */
  Ball(const glm::vec2 &position, const glm::vec2 &velocity);

  /**
   * Displays the ball based on the position and radius.
   */
  void Draw() const;

  glm::vec2 position_;
  glm::vec2 velocity_;

  const size_t kRadius = 7;

  static const size_t kInitialPosition = 62;
  constexpr static const double kInitialVelocityX = 2;
  constexpr static const double kInitialVelocityY = 1.5;

  const glm::vec2 &GetPosition() const;
  const glm::vec2 &GetVelocity() const;
  size_t GetRadius() const;
  void SetPosition(double x, double y);
  void SetVelocity(const glm::vec2 &velocity);
  void SetVelocity(double x, double y);
};

}  // namespace brickbreaker