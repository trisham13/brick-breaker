#include "brick_breaker_app.h"

#include "game_container.h"

namespace brickbreaker {

brickbreaker::BrickBreakerApp::BrickBreakerApp()
    : score_(0), lives_(kInitialLives), has_won_(false) {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BrickBreakerApp::draw() {
  ci::Color background_color(104, 178, 222);
  ci::gl::clear(background_color);

  container_.Display();

}

void BrickBreakerApp::update() {
  AppBase::update();
}

void BrickBreakerApp::keyDown(cinder::app::KeyEvent event) {
  AppBase::keyDown(event);
}

void BrickBreakerApp::mouseMove(ci::app::MouseEvent event) {
  AppBase::mouseMove(event);
}

size_t BrickBreakerApp::GetScore() const {
  return score_;
}

size_t BrickBreakerApp::GetLives() const {
  return lives_;
}

const Paddle& BrickBreakerApp::GetPaddle() const {
  return paddle_;
}

const Ball& BrickBreakerApp::GetBall() const {
  return ball_;
}

bool BrickBreakerApp::HasPlayerWon() const {
  return has_won_;
}

}  // namespace brickbreaker