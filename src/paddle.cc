#include "paddle.h"

namespace brickbreaker {

Paddle::Paddle() {
}

Paddle::Paddle(const glm::vec2& top_left_corner,
               const glm::vec2& bottom_right_corner, glm::vec2 position)
    : position_(position),
      top_left_corner_(top_left_corner),
      bottom_right_corner_(bottom_right_corner) {
}
const glm::vec2& Paddle::GetPosition() const {
  return position_;
}

void Paddle::SetPosition(double x, double y) {
  position_ = glm::vec2(x, y);
}

}  // namespace brickbreaker