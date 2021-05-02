#include "brick.h"

namespace brickbreaker {

Brick::Brick(BrickType type, const glm::vec2 &top_left_corner,
             const glm::vec2 &bottom_right_corner)
    : type_(type),
      top_left_corner_(top_left_corner),
      bottom_right_corner_(bottom_right_corner) {
}

void Brick::Draw() {
  if (type_ == BrickType::kStrong) {
    ci::gl::color(ci::Color("darksalmon"));
  } else if (type_ == BrickType::kCracked) {
    ci::gl::color(ci::Color("peachpuff"));
  } else if (type_ == BrickType::kBroken){
    Erase();
    return;
  } else {
    ci::gl::color(ci::Color("lightgrey"));
  }
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_corner_, bottom_right_corner_));
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(
      ci::Rectf(top_left_corner_, bottom_right_corner_), 2);
}

void Brick::SetBrickType(BrickType type) {
  type_ = type;
}

std::istream &operator>>(std::istream &is,
                         std::vector<brickbreaker::Brick> &bricks) {
  std::string line;
  size_t count = 1;
  BrickType type;
  std::vector<size_t> coordinates;
  std::vector<brickbreaker::Brick> new_bricks;


  while (getline(is, line)) {
    if (count == 1) {
      if (line == "kStrong") {
        type = BrickType::kStrong;
      } else if (line == "kCracked") {
        type = BrickType::kCracked;
      } else {
        type = BrickType::kUnbreakable;
      }

    } else if (count < 5) {
      coordinates.emplace_back(stoi(line));
    } else {
      coordinates.emplace_back(stoi(line));
      new_bricks.emplace_back(Brick(type, glm::vec2(coordinates[0], coordinates[1]),
                                glm::vec2(coordinates[2], coordinates[3])));
      count = 0;
      coordinates.clear();
    }
    count++;
  }

  bricks = new_bricks;
  return is;
}

void Brick::Erase() {
  top_left_corner_ = glm::vec2(0,0);
  bottom_right_corner_ = glm::vec2(0,0);
}

const glm::vec2 &Brick::GetTopLeftCorner() const {
  return top_left_corner_;
}

const glm::vec2 &Brick::GetBottomRightCorner() const {
  return bottom_right_corner_;
}
BrickType Brick::GetBrickType() const {
  return type_;
}

std::vector<Brick> GenerateBricks(const std::string &file_path) {
  std::ifstream file(file_path);
  std::vector<Brick> bricks;

  if (file.is_open()) {
    file >> bricks;
    file.close();
  }

  return bricks;
}

}  // namespace brickbreaker