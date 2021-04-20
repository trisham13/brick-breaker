#pragma once

#include "cinder/gl/gl.h"
#include "paddle.h"
#include "physics_engine.h"

namespace brickbreaker {

using glm::vec2;

/**
 * TODO
 */
    class GameContainer {
    public:
        /**
         * TODO
         */
        GameContainer();
        /**
         * TODO
         */
        void Display() const;
        /**
         * TODO
         */
        void AdvanceOneFrame();
    private:
      std::vector<brickbreaker::Ball> balls_;

      const size_t kDistanceFromOrigin = 25;
      const size_t kSideLength = 700;
    };

}  // namespace brickbreaker