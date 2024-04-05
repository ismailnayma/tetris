#ifndef BRICKBAG_H
#define BRICKBAG_H

#include "Brick.h"
#include "Position.h"
#include <vector>
#include <random>

class BrickBag {
private:
    std::vector<Brick> bricks;
    int currentBrickIndex;
    std::mt19937 randomEngine;

    void shuffleBricks();

public:
    BrickBag(Position start);
    Brick getNextBrick();
};

#endif // BRICKBAG_H
