#include "game_container.h"

namespace brickbreaker {

GameContainer::GameContainer()
    : paddle_(kInitialPaddlePositionTopLeft, kInitialPaddlePositionBottomRight),
      ball_(glm::vec2(kInitialBallPositionX, kInitialBallPositionY),
            glm::vec2(0, 0)) {
}

void GameContainer::Display() const {
  // title
  ci::gl::color(ci::Color("lightcyan"));
  ci::gl::drawStringCentered(
      "brick breaker",
      glm::vec2(kDistanceFromOrigin * 15, kDistanceFromOrigin * 2 - 10),
      ci::Color("lightcyan"), cinder::Font("Impact", 75));

  // main container
  ci::gl::color(ci::Color("lightcyan"));
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kDistanceFromOrigin, kDistanceFromOrigin * 5),
                vec2(kSideLength + kDistanceFromOrigin,
                     kSideLength + kDistanceFromOrigin)));
  // lives counter on the left
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kDistanceFromOrigin, kDistanceFromOrigin),
                vec2(kDistanceFromOrigin * 5, kDistanceFromOrigin * 4)));

  // score board on the right
  ci::gl::drawSolidRect(ci::Rectf(
      vec2(kSideLength - kDistanceFromOrigin * 3, kDistanceFromOrigin),
      vec2(kSideLength + kDistanceFromOrigin, kDistanceFromOrigin * 4)));
}

void GameContainer::AdvanceOneFrame() {
  brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(ball_);
  brickbreaker::PhysicsEngine::UpdateVelocityAfterTopHorizontalWallCollision(
      ball_);
  brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(ball_,
                                                                  paddle_);
  brickbreaker::PhysicsEngine::UpdatePosition(ball_);
}

const Paddle GameContainer::GetPaddle() const {
  return paddle_;
}

const Ball& GameContainer::GetBall() const {
  return ball_;
}

}  // namespace brickbreaker