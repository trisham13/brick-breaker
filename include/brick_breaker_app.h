#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_container.h"

namespace brickbreaker {

/**
 * TODO
 */
class BrickBreakerApp : public ci::app::App {
 public:
  BrickBreakerApp();

  /**
   * TODO
   */
  void draw() override;
  /**
   * TODO
   */
  void update() override;
  /**
   * TODO
   * @param event type that determines the action performed
   */
  void keyDown(cinder::app::KeyEvent event) override;

 private:
  const int kWindowSize = 750;
//  const size_t kPaddleWidth = 15;

  GameContainer container_;


};

}  // namespace brickbreaker