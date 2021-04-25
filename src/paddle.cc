#include "paddle.h"

namespace brickbreaker {

Paddle::Paddle() {
}

Paddle::Paddle(const glm::vec2& top_left_corner,
               const glm::vec2& bottom_right_corner)
    : top_left_corner_(top_left_corner),
      bottom_right_corner_(bottom_right_corner) {
}

void Paddle::Draw() {
  ci::gl::color(ci::Color("darksalmon"));
  ci::gl::drawSolidRect(ci::Rectf(top_left_corner_, bottom_right_corner_));
}

void Paddle::MoveBy(int increment) {
  top_left_corner_.x += increment;
  bottom_right_corner_.x += increment;
}

const glm::vec2& Paddle::GetTopLeftCorner() const {
  return top_left_corner_;
}

void Paddle::SetTopLeftCorner(const glm::vec2& topLeftCorner) {
  top_left_corner_ = topLeftCorner;
}

const glm::vec2& Paddle::GetBottomRightCorner() const {
  return bottom_right_corner_;
}

void Paddle::SetBottomRightCorner(const glm::vec2& bottomRightCorner) {
  bottom_right_corner_ = bottomRightCorner;
}

}  // namespace brickbreaker