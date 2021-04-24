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
  ci::gl::drawStringCentered("brick breaker",
                             glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                                       kDistanceFromOrigin + 15),
                             ci::Color("lightcyan"),
                             cinder::Font("Impact", 75));

  // main container
  ci::gl::drawSolidRect(ci::Rectf(vec2(kDistanceFromOrigin, kTopMargin),
                                  vec2(kSideLength + kDistanceFromOrigin,
                                       kSideLength + kDistanceFromOrigin)));

  // lives counter box on the left
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kDistanceFromOrigin, kDistanceFromOrigin),
                vec2(kTopMargin, kSmallBoxesWidth)));
  ci::gl::drawStringCentered(
      "Lives:",
      glm::vec2(kDistanceFromOrigin + kSmallBoxesWidth / 2,
                kDistanceFromOrigin + 5),
      ci::Color("black"), cinder::Font("Impact", 25));
  ci::gl::drawStringCentered(
      std::to_string(lives_),
      glm::vec2(kDistanceFromOrigin + kSmallBoxesWidth / 2,
                kDistanceFromOrigin + kSmallBoxesHeight / 2),
      ci::Color("black"), cinder::Font("Impact", 40));

  // score board on the right
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kSideLength - kSmallBoxesWidth + kDistanceFromOrigin,
                     kDistanceFromOrigin),
                vec2(kSideLength + kDistanceFromOrigin,
                     kTopMargin - kDistanceFromOrigin)));
  ci::gl::drawStringCentered(
      "Score:",
      glm::vec2(kDistanceFromOrigin + kSideLength - kSmallBoxesWidth / 2,
                kDistanceFromOrigin + 5),
      ci::Color("black"), cinder::Font("Impact", 25));
  ci::gl::drawStringCentered(
      std::to_string(score_),
      glm::vec2(kDistanceFromOrigin + kSideLength - kSmallBoxesWidth / 2,
                kDistanceFromOrigin + kSmallBoxesHeight / 2),
      ci::Color("black"), cinder::Font("Impact", 40));

  // instructions text
  ci::gl::drawStringCentered(
      "Press the right and left arrow keys to move the paddle.",
      glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                kDistanceFromOrigin + kSideLength + 5),
      ci::Color("lightcyan"), cinder::Font("Arial", 15));
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
  std::uniform_real_distribution<double> y_velocity(-5.0, 0.5);

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

std::vector<Brick> GameContainer::GetBricks() const {
  return bricks_;
}

}  // namespace brickbreaker