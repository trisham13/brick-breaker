#pragma once

#include <cstddef>

#include "cinder/gl/gl.h"

namespace brickbreaker {

/**
 * A paddle that is added to the container with a specific initial location that
 * changes as the player presses certain keys.
 */
class Paddle {
 public:
  Paddle();
  /**
   * Creates a new paddle with corresponding left and right corners.
   */
  Paddle(const glm::vec2& top_left_corner,
         const glm::vec2& bottom_right_corner);

  /**
   * Produces the display for the paddle
   */
  void Draw() const;

  /**
   * Moves the paddle by a given increment.
   * @param increment int value for how much the paddle should move
   */
  void MoveBy(int increment);

  const glm::vec2& GetTopLeftCorner() const;
  void SetTopLeftCorner(const glm::vec2& topLeftCorner);
  const glm::vec2& GetBottomRightCorner() const;
  void SetBottomRightCorner(const glm::vec2& bottomRightCorner);

 private:
  glm::vec2 top_left_corner_;
  glm::vec2 bottom_right_corner_;
};

}  // namespace brickbreaker