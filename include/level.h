#pragma once

#include <cstddef>

#include "cinder/app/app.h"
#include "cinder/gl/gl.h"
#include "brick.h"

namespace brickbreaker {

/**
 * A brick that is added to the container with a specific position and type.
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

  size_t CalculateWinningScore();
};

}  // namespace brickbreaker