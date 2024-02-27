#ifndef BOARD_H
#define BOARD_H

#include "enum.hpp"
#include "position.hpp"
#include "Brick.hpp"
#include "ShapesRotation.h"
#include <iostream>
#include <vector>

class Board {
private:
    int boardWidth;
    int boardHeight;
    std::vector<std::vector<TypeShape>> boardArea;
    const Position startPosition;
    Brick currentBrick;
    const ShapesRotation* shapesRotation;

    bool isCollision(const Brick& brick) const;
    void removeCurrentBrickOnArea();
    void updateArea();
    std::vector<Position> getBrickBoardPositions(const Brick& brick) const;

public:
    Board(int width = 10, int height = 20); //=default constructors

    bool setCurrentBrick(const Brick& brick);
    bool moveCurrentBrick(Direction direction);
    bool rotateCurrentBrick(Direction direction);
    int dropCurrentBrick();
    bool isCurrentBrickFallen() const;
    int deletePossibleLines();

};


#endif // BOARD_H
