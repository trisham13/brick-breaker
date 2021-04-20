#pragma once

#include <cstddef>

#include "cinder/gl/gl.h"

namespace brickbreaker {

/**
 * TODO
 */
struct Ball {
 public:
  /**
   * TODO
   */
  Ball(double velocity_x, double velocity_y);
  /**
   * TODO
   */
  Ball(float radius, const glm::vec2 &position, const glm::vec2 &velocity);

  glm::vec2 position_;
  glm::vec2 velocity_;

  const size_t kRadius = 5;

  static const size_t kInitialPosition = 65;
  constexpr static const double kInitialVelocityX = 2;
  constexpr static const double kInitialVelocityY = 1.5;

  glm::vec2 GetPosition() const;
  glm::vec2 GetVelocity() const;
  size_t GetRadius();
  void SetPosition(double x, double y);
  void SetVelocity(const glm::vec2 &velocity);
  void SetVelocity(double x, double y);
};

}  // namespace brickbreaker