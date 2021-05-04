#pragma once

#include "brick.h"
#include "cinder/app/app.h"
#include "cinder/gl/gl.h"
#include "paddle.h"
#include "physics_engine.h"
#include "level.h"

namespace brickbreaker {

using glm::vec2;

/**
 * The container in which all of the bricks, ball and paddle are contained. This
 * class stores all of the player's data, like score and number of lives, as
 * well as updating the ball and paddle positions as the game is played.
 */
class GameContainer {
 public:
  /**
   * Create a new container and initializes the paddle, ball, score, and number
   * of lives.
   */
  GameContainer();
  /**
   * Displays the container walls, title, lives box, and score box.
   */
  void Display() const;

  void DisplayWinningScreen() const;
  void DisplayGameOver() const;
  /**
   * Updates the positions and velocities of the ball (based on the rules
   * described in the assignment documentation).
   */
  void AdvanceOneFrame();

  /**
   * Generates random doubles from -5 to 5 for the initial velocity of the ball.
   * @return a vector for the velocity
   */
  static glm::vec2 GenerateRandomVelocity();

  Paddle& GetPaddle();
  Ball& GetBall();
  size_t GetScore() const;
  size_t GetLives() const;
  std::vector<std::vector<Brick>> GetBricks();
  bool HasGameRestarted() const;
  bool HasPlayerWon() const;
  bool IsGameOver() const;

 private:
  const glm::vec2 kInitialPaddlePositionTopLeft = glm::vec2(275, 700);
  const glm::vec2 kInitialPaddlePositionBottomRight = glm::vec2(475, 715);
  const glm::vec2 kInitialBallPosition = glm::vec2(375, 690);

  const size_t kInitialLives = 5;
  const size_t kDistanceFromOrigin = 25;
  const size_t kSideLength = 700;
  const size_t kTopMargin = 125;
  const int kSmallBoxesWidth = 100;
  const int kSmallBoxesHeight = 75;
  const std::vector<std::string> kLevelFiles{"assets/level_1.txt",
                                             "assets/level_2.txt"};

  Paddle paddle_;
  Ball ball_;
  std::vector<Level> levels_;
  bool has_won_;
  bool is_game_over;
  size_t score_;
  size_t lives_;
  bool has_game_restarted_;
  size_t current_level_;
  size_t current_winning_score_;
  size_t max_score_;

  void DisplayCounters(const std::string& title, size_t count,
                       const glm::vec2& top_left) const;
};

}  // namespace brickbreaker