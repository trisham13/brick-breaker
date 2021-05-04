#include "physics_engine.h"

namespace brickbreaker {

void PhysicsEngine::UpdatePosition(Ball& ball) {
  ball.SetPosition(ball.GetPosition().x + ceil(ball.GetVelocity().x),
                   ball.GetPosition().y + ceil(ball.GetVelocity().y));
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
      ball.GetPosition(), glm::vec2(ball.GetPosition().x, kTopMargin));
  if ((distance_from_top_wall <= ball.GetRadius() &&
       ball.GetVelocity().y < 0)) {
    ball.SetVelocity(ball.GetVelocity().x, -1 * ball.GetVelocity().y);
  }
}

void PhysicsEngine::UpdateVelocityAfterPaddleCollision(Ball& ball,
                                                       const Paddle& paddle) {
  if ((ball.GetPosition().x >= paddle.GetTopLeftCorner().x) &&
      (ball.GetPosition().x <= paddle.GetBottomRightCorner().x) &&
      (ball.GetPosition().y + ball.GetRadius() >=
       paddle.GetTopLeftCorner().y) &&
      (ball.GetPosition().y + ball.GetRadius() <=
       paddle.GetBottomRightCorner().y) &&
      ball.GetVelocity().y > 0) {
    ball.SetVelocity(ball.GetVelocity().x, ball.GetVelocity().y * -1);
  }
}

size_t PhysicsEngine::UpdateVelocityAndScoreAfterBrickTopOrBottomCollision(
    Ball& ball, Brick& brick) {
  size_t score = 0;
  if (ball.GetPosition().x + ball.GetRadius() >= brick.GetTopLeftCorner().x &&
      ball.GetPosition().x - ball.GetRadius() <=
          brick.GetBottomRightCorner().x &&
      ((glm::distance(
            ball.GetPosition(),
            glm::vec2(ball.GetPosition().x, brick.GetTopLeftCorner().y)) <
            ball.GetRadius() &&
        ball.GetVelocity().y > 0) ||
       (glm::distance(
            ball.GetPosition(),
            glm::vec2(ball.GetPosition().x, brick.GetBottomRightCorner().y)) <
            ball.GetRadius() &&
        ball.GetVelocity().y < 0))) {
    ball.SetVelocity(ball.GetVelocity().x, -1 * ball.GetVelocity().y);
    if (brick.GetBrickType() == BrickType::kStrong) {
      brick.SetBrickType(BrickType::kCracked);
      score += 20;
    } else if (brick.GetBrickType() == BrickType::kCracked) {
      brick.SetBrickType(BrickType::kBroken);
      score += 50;
      brick.Erase();
    }
  }
  return score;
}

size_t PhysicsEngine::UpdateVelocityAndScoreAfterBrickSideCollision(
    Ball& ball, Brick& brick) {
  size_t score = 0;
  if (ball.GetPosition().y - ball.GetRadius() >= brick.GetTopLeftCorner().y &&
      ball.GetPosition().y + ball.GetRadius() <=
          brick.GetBottomRightCorner().y &&
      ((glm::distance(ball.GetPosition(), glm::vec2(brick.GetTopLeftCorner().x,
                                                    ball.GetPosition().y)) <=
            ball.GetRadius() &&
        ball.GetVelocity().x > 0) ||
       (glm::distance(ball.GetPosition(),
                      glm::vec2(brick.GetBottomRightCorner().x,
                                ball.GetPosition().y)) <= ball.GetRadius() &&
        ball.GetVelocity().x < 0))) {
    ball.SetVelocity(-1 * ball.GetVelocity().x, ball.GetVelocity().y);
    if (brick.GetBrickType() == BrickType::kStrong) {
      brick.SetBrickType(BrickType::kCracked);
      score += 20;
    } else if (brick.GetBrickType() == BrickType::kCracked) {
      brick.SetBrickType(BrickType::kBroken);
      score += 50;
      brick.Erase();
    }
  }
  return score;
}

bool PhysicsEngine::HasBallLeftContainer(Ball& ball, Paddle& paddle) {
  if (ball.GetPosition().y >= kSideLength + kDistanceFromOrigin) {
    ball.SetPosition(kInitialBallPositionX, kInitialBallPositionY);
    ball.SetVelocity(0, 0);
    paddle.SetTopLeftCorner(glm::vec2(275, 700));
    paddle.SetBottomRightCorner(glm::vec2(475, 715));
    return true;
  }
  return false;
}

}  // namespace brickbreaker