#pragma once

#include <cstddef>

#include "cinder/app/app.h"
#include "cinder/gl/gl.h"

namespace brickbreaker {

enum BrickType {
  kUnbreakable,  // Cannot be broken
  kStrong,       // Has not yet been hit, needs to be hit twice
  kCracked,      // Only needs to be hit one more time to be broken
  kBroken        // Brick has been hit at least once and is broken
};

/**
 * A brick that is added to the container with a specific position and type.
 */
class Brick {
 public:
  /**
   * Creates a Brick object at a position with the given top left and bottom
   * right corners, and of the given type.
   *
   * @param type kCracked, kStrong, kUnbreakable, kBroken
   * @param top_left_corner vector for the top left coordinate
   * @param bottom_right_corner vector for the bottom right coordinate
   */
  Brick(BrickType type, const glm::vec2 &top_left_corner,
        const glm::vec2 &bottom_right_corner);

  /**
   * Displays the brick based on the position and type.
   */
  void Draw();

  /**
   * Creates a Brick object vector based on a data file, reading every 5 lines
   * to get the brick type and the x and y coordinates for the corners.
   *
   * @param is stream to be extracting lines from
   * @param brick vector to add brick objects to
   * @return stream
   */
  friend std::istream &operator>>(std::istream &is,
                                  std::vector<brickbreaker::Brick> &bricks);

  /**
   * Changes the top left and bottom right corners of the brick to (0,0) and
   * changes the type to broken.
   */
  void Erase();

  const glm::vec2 &GetTopLeftCorner() const;
  const glm::vec2 &GetBottomRightCorner() const;
  BrickType GetBrickType() const;
  void SetBrickType(BrickType type);

 private:
  BrickType type_;
  glm::vec2 top_left_corner_;
  glm::vec2 bottom_right_corner_;
};

/**
 * Creates a vector of brick objects from the file of a given path.
 *
 * @param file_path string for the file path to be read
 * @return
 */
std::vector<brickbreaker::Brick> GenerateBricks(const std::string &file_path);

}  // namespace brickbreaker