#include "brick_breaker_app.h"

#include "game_container.h"

namespace brickbreaker {

brickbreaker::BrickBreakerApp::BrickBreakerApp()
    //    : container_(kTestLevels) {
    : container_(kLevels) {
  ci::app::setWindowSize(kWindowSize, kWindowSize + 40);
}

void BrickBreakerApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  if (container_.HasPlayerWon()) {
    container_.DisplayWinningScreen();
  } else if (container_.IsGameOver()) {
    container_.DisplayGameOver();
  } else {
    container_.Display();
  }
}

void BrickBreakerApp::update() {
  container_.AdvanceOneFrame();
}

void BrickBreakerApp::keyDown(cinder::app::KeyEvent event) {
  if (event.getCode() == event.KEY_SPACE && container_.HasGameRestarted()) {
    container_.GetBall().SetVelocity(GameContainer::GenerateRandomVelocity());
  }
  if (event.getCode() == event.KEY_LEFT) {
    if (container_.GetPaddle().GetTopLeftCorner().x >= 25 + 2) {
      container_.GetPaddle().MoveBy(-50);
    }
  } else if (event.getCode() == event.KEY_RIGHT) {
    if (container_.GetPaddle().GetBottomRightCorner().x <= 725 - 2) {
      container_.GetPaddle().MoveBy(50);
    }
  }
}

}  // namespace brickbreaker