#include "game_container.h"

namespace brickbreaker {

    GameContainer::GameContainer() {

    }

    void GameContainer::Display() const {
      ci::gl::color(ci::Color(104, 178, 222));
      ci::gl::drawStrokedRect(
          ci::Rectf(vec2(kDistanceFromOrigin, kDistanceFromOrigin),
                    vec2(kSideLength + kDistanceFromOrigin,
                         kSideLength + kDistanceFromOrigin)));
    }

    void GameContainer::AdvanceOneFrame() {

    }

}  // namespace brickbreaker