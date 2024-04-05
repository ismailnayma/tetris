#include "BrickBag.h"
#include <algorithm>

void BrickBag::shuffleBricks() {
    std::shuffle(bricks.begin(), bricks.end(), randomEngine);
    currentBrickIndex = 0;  // Reset the index after shuffling
}

BrickBag::BrickBag(Position start) : randomEngine(std::random_device{}()) {
    for (int i = 0; i < static_cast<int>(TypeShape::TYPESHAPE_NUMBER); ++i) {
        TypeShape type = static_cast<TypeShape>(i);
        Orientation orientation = Orientation::UP;  // Initialize with a default orientation
        bricks.emplace_back(type, orientation, start);
    }

    shuffleBricks();
}

Brick BrickBag::getNextBrick() {
    if (currentBrickIndex == bricks.size()) {
        // If we reached the end of the bricks list, shuffle and reset the index
        shuffleBricks();
    }

    // Extract the next brick from the bag
    Brick nextBrick = bricks[currentBrickIndex];
    ++currentBrickIndex;

    return nextBrick;
}
