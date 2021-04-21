#include "game_container.h"

#include <random>

namespace brickbreaker {

GameContainer::GameContainer()
    : paddle_(kInitialPaddlePositionTopLeft, kInitialPaddlePositionBottomRight),
      ball_(kInitialBallPosition, GenerateRandomVelocity()),
      has_won_(false),
      score_(0),
      lives_(kInitialLives) {
}

void GameContainer::Display() const {
  ci::gl::color(ci::Color("lightcyan"));

  // title
  ci::gl::drawStringCentered(
      "brick breaker", glm::vec2(kTopMargin, kDistanceFromOrigin * 2 - 11),
      ci::Color("lightcyan"), cinder::Font("Impact", 75));

  // main container
  ci::gl::drawSolidRect(ci::Rectf(vec2(kDistanceFromOrigin, kTopMargin),
                                  vec2(kSideLength + kDistanceFromOrigin,
                                       kSideLength + kDistanceFromOrigin)));

  // lives counter on the left
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kDistanceFromOrigin, kDistanceFromOrigin),
                vec2(kTopMargin, kTopMargin - kDistanceFromOrigin)));

  // score board on the right
  ci::gl::drawSolidRect(ci::Rectf(
      vec2(kSideLength - kDistanceFromOrigin * 3, kDistanceFromOrigin),
      vec2(kSideLength + kDistanceFromOrigin,
           kTopMargin - kDistanceFromOrigin)));
}

void GameContainer::AdvanceOneFrame() {
  brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(ball_);
  brickbreaker::PhysicsEngine::UpdateVelocityAfterTopHorizontalWallCollision(
      ball_);
  brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(ball_,
                                                                  paddle_);
  brickbreaker::PhysicsEngine::UpdatePosition(ball_);
}

glm::vec2 GameContainer::GenerateRandomVelocity() {
  // random library implementation taken from:
  // https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
  std::random_device rd;
  std::mt19937 mt1(rd());
  std::mt19937 mt2(rd());
  std::uniform_real_distribution<double> x_velocity(-5.0, 5.0);
  std::uniform_real_distribution<double> y_velocity(-5.0, 0.0);

  return glm::vec2(x_velocity(mt1), y_velocity(mt2));
}

Paddle& GameContainer::GetPaddle() {
  return paddle_;
}

Ball& GameContainer::GetBall() {
  return ball_;
}

size_t GameContainer::GetScore() const {
  return score_;
}

size_t GameContainer::GetLives() const {
  return lives_;
}

bool GameContainer::HasPlayerWon() const {
  return has_won_;
}

}  // namespace brickbreaker