#ifndef BRICKBAG_HPP
#define BRICKBAG_HPP

#include "Brick.hpp"
#include "position.hpp"
#include "enum.hpp"
#include <vector>
#include <random>

class BrickBag {
    const Position startPosition;
    std::vector<Brick> bricks;
    std::mt19937 randomEngine;  // Random engine
    int currentBrickIndex;  // Index to track the current position in the bricks vector


    void shuffleBricks() {
        std::shuffle(bricks.begin(), bricks.end(), randomEngine);
        currentBrickIndex = 0;  // Reset the index after shuffling
    }

public:
    BrickBag(Position start = Position(4, 1)) : startPosition(start), randomEngine(std::random_device{}()) {
        for (int i = 0; i < 7; ++i) {
            TypeShape type = static_cast<TypeShape>(i);
            Orientation orientation = Orientation::UP;  // Initialize with a default orientation
            bricks.emplace_back(type, orientation, startPosition);
        }
        shuffleBricks();
    }

    Brick getNextBrick() {
        if (currentBrickIndex == bricks.size()) {
            // If we reached the end of the bricks list, shuffle and reset the index
            shuffleBricks();
        }

        // Extract the next brick from the bag
        Brick nextBrick = bricks[currentBrickIndex];
        ++currentBrickIndex;

        return nextBrick;
    }
};

#endif // BRICKBAG_HPP



