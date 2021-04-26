#pragma once

#include <cstddef>

#include "cinder/gl/gl.h"

namespace brickbreaker {

enum BrickType {
  kUnbreakable,  // Cannot be broken
  kStrong,       // Has not yet been hit, needs to be hit twice
  kCracked,      // Only needs to be hit one more time to be broken
  kBroken        // Brick has been hit at least once and is broken
};

/**
 * TODO
 */
class Brick {
 public:
  /**
   * TODO
   * @param condition
   * @param top_left_corner
   * @param bottom_right_corner
   */
  Brick(BrickType type, const glm::vec2 &top_left_corner,
        const glm::vec2 &bottom_right_corner);

  /**
   * Displays the brick based on the position and type.
   */
  void Draw();

  /**
   * Creates Image objects based on a data file, reading every so lines, based
   * on the image size of the model.
   *
   * @param is stream to be extracting lines from
   * @param image to create and add to vector of images
   * @return stream
   */
  friend std::istream &operator>>(std::istream &is,
                                  std::vector<brickbreaker::Brick> &bricks);

  void Erase();

  const glm::vec2 &GetTopLeftCorner() const;
  const glm::vec2 &GetBottomRightCorner() const;
  BrickType GetBrickType() const;
  void SetBrickType(BrickType type);

 private:
  BrickType type_;
  glm::vec2 top_left_corner_;
  glm::vec2 bottom_right_corner_;

//  size_t kBrickWidth = 100;
//  size_t kBrickHeight = 40;
};

std::vector<brickbreaker::Brick> GenerateBricks(const std::string &file_path);

}  // namespace brickbreaker