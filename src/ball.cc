#include "ball.h"

namespace brickbreaker {

brickbreaker::Ball::Ball()
    : position_(glm::vec2(kInitialPosition, kInitialPosition)),
      velocity_(glm::vec2(kInitialVelocityX, kInitialVelocityY)) {
}

Ball::Ball(double position_x, double position_y, double velocity_x, double velocity_y)
    : position_(glm::vec2(position_x, position_y)),
      velocity_(glm::vec2(velocity_x, velocity_y)) {
}

Ball::Ball(const glm::vec2& position, const glm::vec2& velocity)
    : position_(position), velocity_(velocity) {}

void Ball::Draw() {
  ci::gl::color(ci::Color("black"));
  ci::gl::drawSolidCircle(position_, kRadius);
}

const glm::vec2& Ball::GetPosition() const {
  return position_;
}

const glm::vec2& Ball::GetVelocity() const {
  return velocity_;
}

size_t Ball::GetRadius() const {
  return kRadius;
}

void Ball::SetPosition(double x, double y) {
  position_ = glm::vec2(x, y);
}

void Ball::SetVelocity(const glm::vec2& velocity) {
  velocity_ = velocity;
}

void Ball::SetVelocity(double x, double y) {
  velocity_ = glm::vec2(x, y);
}

}  // namespace brickbreaker