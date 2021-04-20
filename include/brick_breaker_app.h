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

  void mouseMove(ci::app::MouseEvent event) override;

 private:
  const int kWindowSize = 750;
  //const size_t kInitialLives = 3;

//  size_t score_;
  //size_t lives_;

 // bool has_won_;
};

}  // namespace brickbreaker