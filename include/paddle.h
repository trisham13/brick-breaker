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
         const glm::vec2& paddle_bottom_right_corner);

  void Draw() const;

  const glm::vec2& GetTopLeftCorner() const;
  void SetTopLeftCorner(const glm::vec2& topLeftCorner);
  const glm::vec2& GetBottomRightCorner() const;
  void SetBottomRightCorner(const glm::vec2& bottomRightCorner);

 private:
  glm::vec2 top_left_corner_;
  glm::vec2 bottom_right_corner_;
};

}  // namespace brickbreaker