#pragma once

#include <cstddef>

#include "cinder/gl/gl.h"

namespace brickbreaker {

/**
 * TODO
 */
class Paddle {
 public:
  Paddle();
  /**
   * TODO
   */
  Paddle(const glm::vec2& paddle_top_left_corner,
         const glm::vec2& paddle_bottom_right_corner, glm::vec2 position);

  const glm::vec2& GetPosition() const;
  void SetPosition(double x, double y);

 private:
  glm::vec2 position_;
  glm::vec2 top_left_corner_;
  glm::vec2 bottom_right_corner_;
};

}  // namespace brickbreaker