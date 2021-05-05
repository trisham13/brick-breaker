#pragma once

#include "cinder/app/app.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_container.h"

namespace brickbreaker {

/**
 * An app for visualizing a game of brick breaker.
 */
class BrickBreakerApp : public ci::app::App {
 public:
  BrickBreakerApp();

  /**
   * Produces the display when first run.
   */
  void draw() override;
  /**
   * Calls AdvanceOneFrame to update the entire application.
   */
  void update() override;
  /**
   * Moves the paddle left or right depending on the event key.
   * @param event type that determines the action performed
   */
  void keyDown(cinder::app::KeyEvent event) override;

 private:
  const int kWindowSize = 750;
  const std::vector<Level> kLevels {Level("assets/level_1.txt"),
                                         Level("assets/level_2.txt"),
                                         Level("assets/level_3.txt")};
  const std::vector<Level> kTestLevels {Level("assets/test_level.txt")};

  GameContainer container_;


};

}  // namespace brickbreaker