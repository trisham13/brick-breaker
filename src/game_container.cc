#include "game_container.h"

#include <random>
#include <utility>

namespace brickbreaker {

GameContainer::GameContainer(const std::vector<Level>& levels)
    : paddle_(kInitialPaddlePositionTopLeft, kInitialPaddlePositionBottomRight),
      ball_(kInitialBallPosition, GenerateRandomVelocity()),
      levels_(levels),
      has_won_(false),
      is_game_over(false),
      score_(0),
      lives_(kInitialLives),
      has_game_restarted_(true),
      current_level_(1) {
  current_winning_score_ = levels_[current_level_ - 1].GetMaxScore();
  for (Level level : levels_) {
    max_score_ += level.GetMaxScore();
  }
}

void GameContainer::Display() const {
  ci::gl::color(ci::Color("lightcyan"));

  // title
  ci::gl::drawStringCentered("brick breaker",
                             glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                                       kDistanceFromOrigin + 15),
                             ci::Color("lightcyan"),
                             cinder::Font("Impact", 75));

  // main container
  ci::gl::drawSolidRect(ci::Rectf(vec2(kDistanceFromOrigin, kTopMargin),
                                  vec2(kSideLength + kDistanceFromOrigin,
                                       kSideLength + kDistanceFromOrigin)));

  // lives counter box on the left
  DisplayCounters("Lives:", lives_,
                  glm::vec2(kDistanceFromOrigin, kDistanceFromOrigin));

  // score board on the right
  DisplayCounters(
      "Score:", score_,
      glm::vec2(kDistanceFromOrigin + kSideLength - kSmallBoxesWidth,
                kDistanceFromOrigin));

  // instructions text
  ci::gl::drawStringCentered(
      "Press the right and left arrow keys to move the paddle.",
      glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                kDistanceFromOrigin + kSideLength + 5),
      ci::Color("lightcyan"), cinder::Font("Arial", 15));
  ci::gl::drawStringCentered("Press the space bar to get your ball moving.",
                             glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                                       kDistanceFromOrigin + kSideLength + 25),
                             ci::Color("lightcyan"), cinder::Font("Arial", 15));
  levels_[current_level_ - 1].Draw();
  paddle_.Draw();
  ball_.Draw();
}

void GameContainer::DisplayWinningScreen() const {
  ci::gl::color(ci::Color("lightcyan"));

  // title
  ci::gl::drawStringCentered("brick breaker",
                             glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                                       kDistanceFromOrigin + 15),
                             ci::Color("lightcyan"),
                             cinder::Font("Impact", 75));

  // main container
  ci::gl::drawSolidRect(ci::Rectf(vec2(kDistanceFromOrigin, kTopMargin),
                                  vec2(kSideLength + kDistanceFromOrigin,
                                       kSideLength + kDistanceFromOrigin)));

  ci::gl::Texture2dRef image = ci::gl::Texture::create(
      ci::loadImage(ci::app::loadAsset("confetti.png")));
  ci::gl::draw(image, ci::Rectf(vec2(kDistanceFromOrigin * 1.05, kTopMargin),
                                vec2(kSideLength * 1.07 + kDistanceFromOrigin,
                                     kSideLength + kDistanceFromOrigin)));

  // winning message
  ci::gl::drawStringCentered(
      "YOU WON!",
      glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                kDistanceFromOrigin + (kSideLength / 2) - 50),
      ci::Color("black"), cinder::Font("Impact", 100));
  ci::gl::drawStringCentered(
      "CONGRATS!!",
      glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                kDistanceFromOrigin + (kSideLength / 2) + 60),
      ci::Color("black"), cinder::Font("Impact", 100));
}

void GameContainer::DisplayGameOver() const {
  ci::gl::color(ci::Color("lightcyan"));

  // title
  ci::gl::drawStringCentered("brick breaker",
                             glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                                       kDistanceFromOrigin + 15),
                             ci::Color("lightcyan"),
                             cinder::Font("Impact", 75));

  // main container
  ci::gl::drawSolidRect(ci::Rectf(vec2(kDistanceFromOrigin, kTopMargin),
                                  vec2(kSideLength + kDistanceFromOrigin,
                                       kSideLength + kDistanceFromOrigin)));

  // winning message
  ci::gl::drawStringCentered(
      "YOU RAN OUT",
      glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                kDistanceFromOrigin + (kSideLength / 2) - 50),
      ci::Color("black"), cinder::Font("Impact", 100));
  ci::gl::drawStringCentered(
      "OF LIVES!!",
      glm::vec2(kDistanceFromOrigin + kSideLength / 2,
                kDistanceFromOrigin + (kSideLength / 2) + 60),
      ci::Color("black"), cinder::Font("Impact", 100));
}

void GameContainer::AdvanceOneFrame() {
  brickbreaker::PhysicsEngine::UpdateVelocityAfterVerticalWallCollision(ball_);
  brickbreaker::PhysicsEngine::UpdateVelocityAfterTopHorizontalWallCollision(
      ball_);
  brickbreaker::PhysicsEngine::UpdateVelocityAfterPaddleCollision(ball_,
                                                                  paddle_);
  for (Brick& brick : levels_[current_level_ - 1].GetBricks()) {
    score_ += brickbreaker::PhysicsEngine::
        UpdateVelocityAndScoreAfterBrickTopOrBottomCollision(ball_, brick);
    score_ += brickbreaker::PhysicsEngine::
        UpdateVelocityAndScoreAfterBrickSideCollision(ball_, brick);
    if (score_ == current_winning_score_ && lives_ >= 0 &&
        lives_ <= kInitialLives + levels_.size() &&
        current_level_ < levels_.size()) {
      lives_++;
      current_level_++;
      current_winning_score_ += levels_[current_level_ - 1].GetMaxScore();
      has_game_restarted_ = true;
      ball_.SetPosition(PhysicsEngine::kInitialBallPositionX,
                        PhysicsEngine::kInitialBallPositionY);
      ball_.SetVelocity(0, 0);
      paddle_.SetTopLeftCorner(glm::vec2(275, 700));
      paddle_.SetBottomRightCorner(glm::vec2(475, 715));
      return;
    }
    if (score_ == max_score_ && lives_ >= 0 &&
        lives_ <= kInitialLives + levels_.size() &&
        current_level_ == levels_.size()) {
      has_won_ = true;
      return;
    }
  }
  if (ball_.GetVelocity().x == 0 && abs(ball_.GetVelocity().y) > 0) {
    ball_.SetVelocity(ball_.GetVelocity().x - 1, ball_.GetVelocity().y);
  }
  brickbreaker::PhysicsEngine::UpdatePosition(ball_);
  if (ball_.GetPosition() != kInitialBallPosition) {
    has_game_restarted_ =
        brickbreaker::PhysicsEngine::HasBallLeftContainer(ball_, paddle_);
    if (has_game_restarted_) {
      if (lives_ > 0 && lives_ <= kInitialLives + levels_.size()) {
        lives_--;
      } else {
        is_game_over = true;
        return;
      }
    }
  }
}

glm::vec2 GameContainer::GenerateRandomVelocity() {
  // random library implementation taken from:
  // https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> velocity_x(-5.0, 5.0);
  std::uniform_real_distribution<double> velocity_y(-5, -2);

  return glm::vec2(velocity_x(mt), velocity_y(mt));
}

Paddle& GameContainer::GetPaddle() {
  return paddle_;
}

Ball& GameContainer::GetBall() {
  return ball_;
}

size_t GameContainer::GetScore() const {
  return score_;
}

size_t GameContainer::GetLives() const {
  return lives_;
}

bool GameContainer::HasPlayerWon() const {
  return has_won_;
}

bool GameContainer::HasGameRestarted() const {
  return has_game_restarted_;
}

bool GameContainer::IsGameOver() const {
  return is_game_over;
}

void GameContainer::DisplayCounters(const std::string& title, size_t count,
                                    const glm::vec2& top_left) const {
  glm::vec2 bottom_right =
      glm::vec2(top_left.x + kSmallBoxesWidth, top_left.y + kSmallBoxesHeight);
  ci::gl::drawSolidRect(ci::Rectf(top_left, bottom_right));
  ci::gl::drawStringCentered(
      title,
      glm::vec2(top_left.x + kSmallBoxesWidth / (float)2, top_left.y + 5),
      ci::Color("black"), cinder::Font("Impact", 25));
  ci::gl::drawStringCentered(
      std::to_string(count),
      glm::vec2(top_left.x + kSmallBoxesWidth / (float)2, top_left.y + 35),
      ci::Color("black"), cinder::Font("Impact", 40));
}

}  // namespace brickbreaker