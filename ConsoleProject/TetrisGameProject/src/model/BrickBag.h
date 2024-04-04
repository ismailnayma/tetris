#ifndef BRICKBAG_H
#define BRICKBAG_H

#include "Brick.h"
#include "Position.h"
#include <vector>
#include <random>

class BrickBag {
private:
    std::vector<Brick> bricks;
    int currentBrickIndex;  // Index to track the current position in the bricks vector
    std::mt19937 randomEngine;  // Random engine

    void shuffleBricks();
public:
    BrickBag(Position start);
    Brick getNextBrick();
};

#endif // BRICKBAG_H
