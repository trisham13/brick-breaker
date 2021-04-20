#include "brick_breaker_app.h"

#include "game_container.h"

namespace brickbreaker {

brickbreaker::BrickBreakerApp::BrickBreakerApp()
//    : score_(0), lives_(kInitialLives), has_won_(false)
{
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BrickBreakerApp::draw() {
  ci::Color background_color(104, 178, 222);
  ci::gl::clear(background_color);
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

}  // namespace brickbreaker