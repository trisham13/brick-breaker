#include "brick.h"

namespace brickbreaker {

Brick::Brick(BrickType type, const glm::vec2& top_left_corner,
             const glm::vec2& bottom_right_corner)
    : type_(type),
      top_left_corner_(top_left_corner),
      bottom_right_corner_(bottom_right_corner) {
}

void Brick::Draw() const {

}

const glm::vec2& Brick::GetTopLeft() const {
  return top_left_corner_;
}

void Brick::SetBrickType(BrickType type) {
  type_ = type;
}

}  // namespace brickbreaker