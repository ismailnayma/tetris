#ifndef BOARD_H
#define BOARD_H

#include "enum.hpp"
#include "position.hpp"
#include "Brick.hpp"
#include "ShapesRotation.h"
#include <iostream>
#include <vector>
#include <optional>

class Board {
private:
    int boardWidth;
    int boardHeight;
    std::vector<std::vector<std::optional<TypeShape>>> boardArea;
    const Position startPosition;
    Brick currentBrick;
    const ShapesRotation* shapesRotation;

    bool isCollision(const Brick& brick) const;
    void updateArea(bool addBrick);
    std::vector<Position> getBrickBoardPositions(const Brick& brick) const;
    bool handleBrickAdjustment(const Brick& newCurBrick);

public:
    Board(int width = 10, int height = 20); //=default constructors

    bool setCurrentBrick(const Brick& brick);
    bool moveCurrentBrick(Direction direction);
    bool rotateCurrentBrick(Rotation rotation);
    int dropCurrentBrick();
    bool isCurrentBrickFallen();
    int deletePossibleLines();

};


#endif // BOARD_H
