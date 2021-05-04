#include "level.h"

namespace brickbreaker {
Level::Level(const std::string& file_path)
    : bricks_(GenerateBricks(file_path)), max_score_(CalculateWinningScore()) {
}

void Level::Draw() const {
  for (Brick brick : bricks_) {
    brick.Draw();
  }
}

std::vector<Brick>& Level::GetBricks() {
  return bricks_;
}

size_t Level::GetMaxScore() {
  return max_score_;
}

size_t Level::CalculateWinningScore() {
  size_t sum = 0;
  for (const Brick& brick : bricks_) {
    if (brick.GetBrickType() == BrickType::kStrong) {
      sum += 70;
    } else if (brick.GetBrickType() == BrickType::kCracked) {
      sum += 50;
    }
  }
  return sum;
}

}  // namespace brickbreaker