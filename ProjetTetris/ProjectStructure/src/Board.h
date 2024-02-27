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
    int boardHeight;
    int boardWidth;
    Position startPosition;
    std::vector<std::vector<TypeShape>> boardArea;
    Brick currentBrick;
    ShapesRotation shapesRotation;

    bool isCollision(const Brick& brick) const;
    void removeCurrentBrickOnArea();
    void updateArea();
    std::vector<Position> getBrickBoardPositions(const Brick& brick) const;

public:
    Board(int height, int width);

    bool setCurrentBrick(const Brick& brick);
    bool moveCurrentBrick(Direction direction);
    bool rotateCurrentBrick(Direction direction);
    int dropCurrentBrick();
    bool isCurrentBrickFallen() const;
    int deletePossibleLines();

};


#endif // BOARD_H
