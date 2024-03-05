#ifndef BRICKBAG_HPP
#define BRICKBAG_HPP

#include "Brick.hpp"
#include "position.hpp"
#include "enum.hpp"
#include <vector>
#include <random>

class BrickBag{
    const Position startPosition;
    std::vector<Brick> bricks;
    std::mt19937 randomEngine;  // Random engine
public:
    BrickBag(Position position):startPosition(position), randomEngine(std::random_device{}()){
        // Fill the bag with the seven types of bricks
            for (int i = 0; i < 7; ++i) {
                TypeShape type = static_cast<TypeShape>(i);
                Orientation orientation = Orientation::DOWN;  // Initialize with a default orientation
                bricks.emplace_back(type, orientation, startPosition);
            }

            // Shuffle the bricks in the bag
            std::shuffle(bricks.begin(), bricks.end(), randomEngine);
    }

    Brick getNextBrick() {
        if (bricks.empty()) {
            // Refill the bag if necessary
            bricks.clear();
            for (int i = 0; i < 7; ++i) {
                TypeShape type = static_cast<TypeShape>(i);
                Orientation orientation = Orientation::DOWN;  // Initialize with a default orientation
                bricks.emplace_back(type, orientation, startPosition);
            }

            // Shuffle the bricks in the bag
            std::shuffle(bricks.begin(), bricks.end(), randomEngine);
        }

        // Extract the next brick from the bag
        Brick nextBrick = bricks.back();
        bricks.pop_back();

        return nextBrick;
    }

};

#endif // BRICKBAG_HPP
