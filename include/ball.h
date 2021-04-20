#pragma once

#include <cstddef>

#include "cinder/gl/gl.h"

namespace brickbreaker {

/**
 * TODO
 */
struct Ball {
 public:
  Ball();
  /**
   * TODO
   */
  Ball(double velocity_x, double velocity_y);
  /**
   * TODO
   */
  Ball(const glm::vec2 &position, const glm::vec2 &velocity);

  glm::vec2 position_;
  glm::vec2 velocity_;

  const size_t kRadius = 5;

  static const size_t kInitialPosition = 65;
  constexpr static const double kInitialVelocityX = 2;
  constexpr static const double kInitialVelocityY = 1.5;

  const glm::vec2& GetPosition() const;
  const glm::vec2& GetVelocity() const;
  size_t GetRadius() const;
  void SetPosition(double x, double y);
  void SetVelocity(const glm::vec2 &velocity);
  void SetVelocity(double x, double y);
};

}  // namespace brickbreaker