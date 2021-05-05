#pragma once

#include <cstddef>

#include "brick.h"
#include "cinder/app/app.h"
#include "cinder/gl/gl.h"

namespace brickbreaker {

/**
 * A level that is added to the game for the player to pass through to win.
 */
class Level {
 public:
  Level(const std::string& file_path);
  /**
   * Displays the brick based on the position and type.
   */
  void Draw() const;

  std::vector<Brick>& GetBricks();
  size_t GetMaxScore();

 private:
  std::vector<Brick> bricks_;
  size_t max_score_;

  /**
   * Goes through the vector of bricks and sums the winning score based on each
   * type of brick.
   *
   * @return sum of scores for each brick
   */
  size_t CalculateWinningScore();
};

}  // namespace brickbreaker