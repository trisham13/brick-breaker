#include "brick_breaker_app.h"

#include "game_container.h"

namespace brickbreaker {

brickbreaker::BrickBreakerApp::BrickBreakerApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BrickBreakerApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  container_.Display();
  container_.GetPaddle().Draw();
  container_.GetBall().Draw();
}

void BrickBreakerApp::update() {
  container_.AdvanceOneFrame();
}

void BrickBreakerApp::keyDown(cinder::app::KeyEvent event) {
  if (event.getCode() == event.KEY_LEFT) {
    if (container_.GetPaddle().GetTopLeftCorner().x >= 25 + 2) {
      container_.GetPaddle().MoveBy(-5);
    }
  }
  if (event.getCode() == event.KEY_RIGHT) {
    if (container_.GetPaddle().GetBottomRightCorner().x <= 725 - 2) {
      container_.GetPaddle().MoveBy(5);
    }
  }
}

}  // namespace brickbreaker