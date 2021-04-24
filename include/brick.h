#pragma once

#include <cstddef>

#include "cinder/gl/gl.h"

namespace brickbreaker {

enum BrickType {
  kUnbreakable,  // Cannot be broken
  kStrong,       // Has not yet been hit, needs to be hit twice
  kCracked       // Only needs to be hit one more time to be broken
};

/**
 * TODO
 */
struct Brick {
 public:
  /**
   * TODO
   * @param condition
   * @param top_left_corner
   * @param bottom_right_corner
   */
  Brick(BrickType type, const glm::vec2 &top_left_corner,
        const glm::vec2 &bottom_right_corner);

  /**
   * Displays the brick based on the position and type.
   */
  void Draw() const;

  BrickType type_;
  glm::vec2 top_left_corner_;
  glm::vec2 bottom_right_corner_;

  size_t kBrickWidth = 25;
  size_t kBrickHeight = 10;

  const glm::vec2 &GetTopLeft() const;
  void SetBrickType(BrickType type);
};

}  // namespace brickbreaker