#include "physics_engine.h"

namespace brickbreaker {

void PhysicsEngine::UpdatePosition(Ball ball) {
  ball.SetPosition(ball.GetPosition().x + ball.GetVelocity().x,
                   ball.GetPosition().y + ball.GetVelocity().y);
}

void PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(Ball& ball) {
  double distance_from_left_wall = glm::distance(
      ball.GetPosition(), glm::vec2(kDistanceFromOrigin, ball.GetPosition().y));
  double distance_from_right_wall = glm::distance(
      ball.GetPosition(),
      glm::vec2(kDistanceFromOrigin + kSideLength, ball.GetPosition().y));
  if ((distance_from_left_wall <= ball.GetRadius() &&
       ball.GetVelocity().x < 0) ||
      (distance_from_right_wall <= ball.GetRadius() &&
       ball.GetVelocity().x > 0)) {
    ball.SetVelocity(-1 * ball.GetVelocity().x, ball.GetVelocity().y);
  }
}

void PhysicsEngine::UpdateVelocityAfterTopHorizontalWallCollision(Ball& ball) {
  double distance_from_top_wall = glm::distance(
      ball.GetPosition(), glm::vec2(ball.GetPosition().x, kDistanceFromOrigin));
  if ((distance_from_top_wall <= ball.GetRadius() &&
       ball.GetVelocity().y < 0)) {
    ball.SetVelocity(ball.GetVelocity().x, -1 * ball.GetVelocity().y);
  }
}

void PhysicsEngine::UpdateVelocityAfterPaddleCollision(Ball& ball,
                                                       Paddle& paddle) {
  double distance_from_top_of_paddle = glm::distance(
      ball.GetPosition(),
      glm::vec2(paddle.GetPosition().x), paddle.GetPosition().y + );
      if ((ball.GetPosition().x >= paddle.paddle_top_left_corner_.x) &&
          (ball.GetPosition().x <= paddle.paddle_bottom_right_corner_.x) &&
          (ball.GetPosition().y + ball.GetRadius() >= paddle.paddle_top_left_corner_.y)) &&
          ball.GetVelocity().y > 0) {
    ball.SetVelocity(ball.GetVelocity().x, -1 * ball.GetVelocity().y);
  }
}

void PhysicsEngine::UpdateVelocityAfterBrickCollision(Ball& ball) {
}

}  // namespace brickbreaker